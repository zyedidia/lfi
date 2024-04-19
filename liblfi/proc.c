#define _GNU_SOURCE

#include "arm64.h"
#include "lfi_internal.h"
#include "elf.h"

#include <unistd.h>
#include <assert.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

enum {
    GUARD_SIZE = 48ULL * 1024,
    CODE_MAX   = 1ULL * 1024 * 1024 * 1024,
    EXEC_SIZE = 20ULL * 1024 * 1024, // 20mib of executable code
    CODE_SIZE = 40ULL * 1024 * 1024, // 40mib of code
};

static uintptr_t proc_addr(uintptr_t base, uintptr_t addr) {
    return base | ((uint32_t) addr);
}

static void regs_validate(struct lfi_proc* proc) {
    proc->regs.x21 = proc->base;
    proc->regs.x30 = proc_addr(proc->base, proc->regs.x30);
    proc->regs.x18 = proc_addr(proc->base, proc->regs.x18);
    if (proc->lfi->opts.gas == 0) {
        proc->regs.x23 = proc_addr(proc->base, proc->regs.x23);
    }
    proc->regs.x24 = proc_addr(proc->base, proc->regs.x24);
    proc->regs.sp = proc_addr(proc->base, proc->regs.sp);
}

static int elf_check(struct elf_file_header* ehdr) {
    return ehdr->magic == ELF_MAGIC &&
        ehdr->width == ELFCLASS64 &&
        ehdr->version == EV_CURRENT &&
        (ehdr->type == ET_DYN || ehdr->type == ET_EXEC);
}

static int prot_exec(int flags) {
    return (flags & PROT_EXEC) != 0;
}

static int prot_write(int flags) {
    return (flags & PROT_WRITE) != 0;
}

static int prot_read(int flags) {
    return (flags & PROT_READ) != 0;
}

static int pflags(int prot) {
    return ((prot & PF_R) ? PROT_READ : 0) |
        ((prot & PF_W) ? PROT_WRITE : 0) |
        ((prot & PF_X) ? PROT_EXEC : 0);
}

static struct lfi_mem lfi_mem_map(uintptr_t base, size_t size, int prot) {
    if (prot_exec(prot)) {
        return (struct lfi_mem) {
            .base = (uintptr_t) -1,
        };
    }
    base = (uintptr_t) mmap((void*) base, size, prot, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0);
    return (struct lfi_mem) {
        .base = (uintptr_t) base,
        .size = size,
        .prot = prot,
    };
}

static int lfi_mem_protect(struct lfi_mem* mem, uintptr_t proc_base, int prot, int noverify) {
    if (prot_exec(prot)) {
        if (prot_write(prot)) {
            return LFI_ERR_PROTECTION;
        }
        if (!noverify) {
            if (mem->base + mem->size - proc_base >= CODE_MAX) {
                return LFI_ERR_PROTECTION;
            }
            if (lfi_verify_bytes((void*) mem->base, mem->size, NULL) == 0) {
                return LFI_ERR_VERIFY;
            }
        }
    }
    if (mprotect((void*) mem->base, mem->size, prot) != 0) {
        return LFI_ERR_PROTECTION;
    }
    mem->prot = prot;
    return 0;
}

static int lfi_mem_valid(struct lfi_mem* mem) {
    return mem->base != (uintptr_t) -1;
}

static int lfi_mem_unmap(struct lfi_mem* mem) {
    if (!lfi_mem_valid(mem)) {
        return 0;
    }
    munmap((void*) mem->base, mem->size);
    mem->base = (uintptr_t) -1;
    return 0;
}

static struct lfi_mem lfi_mem_copy_to(struct lfi_mem* mem, uintptr_t newbase) {
    // Force writable so that we can copy to into it.
    int prot = mem->prot;
    if (prot_read(prot)) {
        prot |= PROT_WRITE;
        prot &= ~PROT_EXEC;
    }
    struct lfi_mem copy = lfi_mem_map(proc_addr(newbase, mem->base), mem->size, prot);
    if (!lfi_mem_valid(&copy)) {
        return copy;
    }
    if (prot_read(mem->prot)) {
        // Copy and reset permissions.
        memcpy((void*) copy.base, (void*) mem->base, mem->size);
        if (mem->prot != prot) {
            // No verification necessary since we are copying from an existing
            // region (already verified).
            lfi_mem_protect(&copy, newbase, mem->prot, 1);
        }
    }
    return copy;
}

static int lfi_mem_append(struct lfi_mem** mem, struct lfi_mem add) {
    struct lfi_mem* new = malloc(sizeof(struct lfi_mem));
    if (!new) {
        return LFI_ERR_NOMEM;
    }
    *new = add;
    if (*mem) {
        struct lfi_mem* m = *mem;
        while (m->next) {
            m = m->next;
        }
        m->next = new;
    } else {
        *mem = new;
    }
    return 0;
}

struct lfi_sys {
    uintptr_t rtcalls[256];
    struct lfi_proc* proc;
    uintptr_t k_tpidr;
};

extern void lfi_syscall_entry() asm ("lfi_syscall_entry");
extern void lfi_yield_entry() asm ("lfi_yield_entry");

// Stub for dynarmic syscalls
uint32_t syshandler_stub[2] = {
    0xd4000001, // svc #0
    0xd65f03c0, // ret
};

static void sys_setup(struct lfi_mem sys, struct lfi_proc* proc) {
    lfi_mem_protect(&sys, proc->base, PROT_READ | PROT_WRITE, 0);
    struct lfi_sys* table = (struct lfi_sys*) sys.base;
    table->rtcalls[0] = (uintptr_t) &lfi_syscall_entry;
    if (proc->lfi->opts.fastyield) {
        table->rtcalls[1] = (uintptr_t) &lfi_yield_entry;
    }
    table->proc = proc;
    // TODO: problem for multi-threading with thread locals
    table->k_tpidr = rd_tpidr();
    lfi_mem_protect(&sys, proc->base, PROT_READ, 0);
}

static void lfi_proc_clear(struct lfi_mem** mems) {
    struct lfi_mem* mem = *mems;
    while (mem) {
        lfi_mem_unmap(mem);
        struct lfi_mem* next = mem->next;
        free(mem);
        mem = next;
    }
    *mems = NULL;
}

static void lfi_proc_clear_regions(struct lfi_proc* proc) {
    /* lfi_mem_unmap(&proc->guards[0]); */
    /* lfi_mem_unmap(&proc->guards[1]); */
    /* lfi_mem_unmap(&proc->sys); */
    /* lfi_mem_unmap(&proc->stack); */
    /* lfi_proc_clear(&proc->segments); */
    if (proc->guards[0].base != 0) {
        memset(proc->codealias, 0, proc->code.size);
        memset((void*) proc->stack.base, 0, proc->stack.size);
    }
}

void lfi_proc_init(struct lfi_proc* proc) {
    proc->guards[0] = lfi_mem_map(proc->base + proc->lfi->opts.pagesize, GUARD_SIZE, PROT_NONE);
    assert(lfi_mem_valid(&proc->guards[0]));
    proc->guards[1] = lfi_mem_map(proc->base + LFI_PROC_SIZE - GUARD_SIZE, GUARD_SIZE, PROT_NONE);
    assert(lfi_mem_valid(&proc->guards[1]));

    size_t stack_size = proc->lfi->opts.stacksize;
    proc->stack = lfi_mem_map(proc->guards[1].base - stack_size, stack_size, PROT_READ | PROT_WRITE);
    if (!lfi_mem_valid(&proc->stack)) {
        assert(0);
    }

    proc->sys = lfi_mem_map(proc->base, proc->lfi->opts.pagesize, PROT_READ | PROT_WRITE);
    assert(lfi_mem_valid(&proc->sys));
    sys_setup(proc->sys, proc);

    int fd = memfd_create("", 0);
    assert(fd > 0);
    int r = ftruncate(fd, CODE_SIZE);
    assert(r >= 0);

    void* c = mmap(NULL, CODE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    assert(c != (void*) -1);

    proc->codefd = fd;
    proc->codealias = c;

    proc->code = (struct lfi_mem) {
        .base = proc->guards[0].base + proc->guards[0].size,
        .size = CODE_SIZE,
        .prot = PROT_READ | PROT_EXEC,
    };
    int* m = mmap((void*) proc->code.base, proc->code.size, proc->code.prot, MAP_SHARED | MAP_FIXED, proc->codefd, 0);
    assert(m != (void*) -1);
}

int lfi_proc_exec(struct lfi_proc* proc, uint8_t* prog, size_t size, struct lfi_proc_info* info) {
    if (proc->guards[0].base != 0) {
        lfi_proc_clear_regions(proc);
    }

    int err = LFI_ERR_INVALID_ELF;

    struct elf_file_header* ehdr = (struct elf_file_header*) prog;

    if (!elf_check(ehdr)) {
        return LFI_ERR_INVALID_ELF;
    }

    if (ehdr->phoff >= size || ehdr->phoff + ehdr->phnum * sizeof(struct elf_prog_header) >= size) {
        return LFI_ERR_INVALID_ELF;
    }

    struct elf_prog_header* phdr = (struct elf_prog_header*) &prog[ehdr->phoff];

    uintptr_t base = proc->guards[0].base + proc->guards[0].size;
    uintptr_t last = 0;

    if (ehdr->entry >= CODE_MAX) {
        goto err1;
    }

    for (int i = 0; i < ehdr->phnum; i++) {
        struct elf_prog_header* p = &phdr[i];
        if (p->type != PT_LOAD) {
            continue;
        }

        uintptr_t start = trunc_p(p->vaddr, p->align);
        uintptr_t end = ceil_p(p->vaddr + p->memsz, p->align);
        uintptr_t offset = p->vaddr - start;

        if (ehdr->type == ET_EXEC) {
            start = start - (base - proc->base);
            end = end - (base - proc->base);
        }

        if (p->memsz < p->filesz) {
            goto err1;
        }
        if (end <= start || start >= CODE_MAX || end >= CODE_MAX) {
            goto err1;
        }

        uintptr_t seg = (uintptr_t) proc->codealias;

        memcpy((void*) (seg + start + offset), &prog[p->offset], p->filesz);
        memset((void*) (seg + start + offset + p->filesz), 0, p->memsz - p->filesz);

        if (pflags(p->flags) != (PROT_READ | PROT_WRITE) && pflags(p->flags) != PROT_READ) {
            assert(seg + start + offset >= EXEC_SIZE);
            /* mprotect((void*) (seg + start), end - start, pflags(p->flags)); */
            /* if ((err = lfi_mem_protect(&seg, proc->base, pflags(p->flags), proc->lfi->opts.noverify)) < 0) { */
            /*     goto err1; */
            /* } */
        } else {
            assert(seg + start + offset < CODE_SIZE);
        }

        /* if ((err = lfi_mem_append(&proc->segments, seg)) < 0) { */
        /*     goto err1; */
        /* } */

        if (base == 0) {
            base = seg + start;
        }
        if (seg + start + end > last) {
            last = seg + start + end;
        }
    }

    *info = (struct lfi_proc_info) {
        .stack = (void*) proc->stack.base,
        .stacksize = proc->stack.size,
        .lastva = last,
        .extradata = proc->code.base + proc->code.size - last,
        .elfentry = ehdr->type == ET_DYN ? base + ehdr->entry : proc->base + ehdr->entry,
        .elfbase = base,
        .elfphoff = ehdr->phoff,
        .elfphnum = ehdr->phnum,
        .elfphentsize = ehdr->phentsize,
    };

    return 0;

err1:
    lfi_proc_clear_regions(proc);
    return err;
}

struct lfi_regs* lfi_proc_get_regs(struct lfi_proc* proc) {
    return &proc->regs;
}

int lfi_proc_copy(struct lfi* lfi, struct lfi_proc** childp, struct lfi_proc* proc, void* new_ctxp) {
    if (lfi_is_full(lfi)) {
        return LFI_ERR_NOSLOT;
    }
    struct lfi_proc* child = lfi_new_proc();
    if (!child) {
        return LFI_ERR_NOMEM;
    }
    *child = (struct lfi_proc) {
        .base = lfi_alloc_slot(lfi),
        .lfi = lfi,
        .ctxp = new_ctxp,
        .regs = proc->regs,
    };
    *childp = child;

    child->guards[0] = lfi_mem_copy_to(&proc->guards[0], child->base);
    child->guards[1] = lfi_mem_copy_to(&proc->guards[1], child->base);
    child->stack = lfi_mem_copy_to(&proc->stack, child->base);
    struct lfi_mem* segment = proc->segments;
    while (segment) {
        lfi_mem_append(&child->segments, lfi_mem_copy_to(segment, child->base));
        segment = segment->next;
    }
    child->sys = lfi_mem_copy_to(&proc->sys, child->base);
    sys_setup(child->sys, child);
    regs_validate(child);

    return 0;
}

void lfi_proc_free(struct lfi_proc* proc) {
    lfi_proc_clear_regions(proc);
    free(proc);
}

void lfi_syscall_handler(struct lfi_proc* proc) asm ("lfi_syscall_handler");

void lfi_syscall_handler(struct lfi_proc* proc) {
    uint64_t sysno = proc->regs.x8;

    uint64_t a0 = proc->regs.x0;
    uint64_t a1 = proc->regs.x1;
    uint64_t a2 = proc->regs.x2;
    uint64_t a3 = proc->regs.x3;
    uint64_t a4 = proc->regs.x4;
    uint64_t a5 = proc->regs.x5;

    assert(proc->lfi->opts.syshandler);

    uint64_t ret = proc->lfi->opts.syshandler(proc->ctxp, sysno, a0, a1, a2, a3, a4, a5);

    proc->regs.x0 = ret;
}

extern int lfi_proc_entry(struct lfi_proc*, void** kstackp) asm ("lfi_proc_entry");

void lfi_proc_init_regs(struct lfi_proc* proc, uintptr_t entry, uintptr_t sp) {
    proc->regs.x30 = entry;
    proc->regs.x21 = proc->base;
    proc->regs.x18 = proc->base;
    if (proc->lfi->opts.gas != 0) {
        proc->regs.x23 = proc->lfi->opts.gas;
    } else {
        proc->regs.x23 = proc->base;
    }
    proc->regs.x24 = proc->base;
    proc->regs.sp = sp;
}

int lfi_proc_start(struct lfi_proc* proc) {
    return lfi_proc_entry(proc, &proc->kstackp);
}

extern void lfi_asm_proc_exit(void* kstackp, int code) asm ("lfi_asm_proc_exit");

void lfi_proc_exit(struct lfi_proc* proc, int code) {
    lfi_asm_proc_exit(proc->kstackp, code);
}

uintptr_t lfi_proc_base(struct lfi_proc* proc) {
    return proc->base;
}

static uint64_t r_tpidr() {
    uint64_t val;
    asm volatile ("mrs %0, tpidr_el0" : "=r"(val));
    return val;
}

static void w_tpidr(uint64_t val) {
    asm volatile ("msr tpidr_el0, %0" :: "r"(val));
}

uint64_t lfi_signal_start(uint64_t syspage) {
    struct lfi_sys* sys = (struct lfi_sys*) syspage;
    uint64_t saved = r_tpidr();
    w_tpidr(sys->k_tpidr);
    return saved;
}

struct lfi_proc* lfi_sys_proc(uint64_t syspage) {
    struct lfi_sys* sys = (struct lfi_sys*) syspage;
    return sys->proc;
}

void lfi_signal_end(uint64_t saved) {
    w_tpidr(saved);
}
