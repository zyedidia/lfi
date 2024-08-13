#include <assert.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lfi_internal.h"
#include "elf.h"

#if defined(ARCH_arm64)
#include "arch/arm64/arm64.h"
#elif defined(ARCH_amd64)
#include "arch/amd64/amd64.h"
#endif

enum {
    GUARD_SIZE = 80ULL * 1024,
    CODE_MAX   = 1ULL * 1024 * 1024 * 1024,
};

static uintptr_t proc_addr(uintptr_t base, uintptr_t addr) {
    return base | ((uint32_t) addr);
}

static uint64_t mask(int size) {
    return (~0ULL) >> (64 - size);
}

static void regs_validate(struct lfi_proc* proc) {
    uint64_t* r;

    // base
    wr_regs_base(&proc->regs, proc->base);

    // address registers
    int n = 0;
    while ((r = regs_addr(&proc->regs, n++)))
        *r = proc_addr(proc->base, *r);

    // sys register (if used for this arch)
    if ((r = regs_sys(&proc->regs)))
        *r = (uintptr_t) proc->sys;

    if (proc->lfi->opts.p2size != 32 && proc->lfi->opts.p2size != 0)
        /* *regs_mask(&proc->regs) = 64 - proc->lfi->opts.p2size; */
        *regs_mask(&proc->regs) = mask(proc->lfi->opts.p2size);
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

static int lfi_mem_protect(struct lfi_mem* mem, uintptr_t proc_base, int prot, int noverify, lfi_verifier verify) {
    if (prot_exec(prot)) {
        if (prot_write(prot)) {
            return LFI_ERR_PROTECTION;
        }
        if (!noverify) {
            if (mem->base + mem->size - proc_base >= CODE_MAX) {
                return LFI_ERR_PROTECTION;
            }
            if (verify((void*) mem->base, mem->size) == 0) {
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

int lfi_mprotect(struct lfi_proc* p, uintptr_t ptr, size_t size, int prot) {
    struct lfi_mem mem = (struct lfi_mem) {
        .base = ptr,
        .size = size,
        .prot = prot,
    };
    return lfi_mem_protect(&mem, p->base, prot, p->lfi->opts.noverify, p->lfi->opts.verifier);
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

static struct lfi_mem lfi_mem_copy_to(struct lfi_mem* mem, uintptr_t newbase, lfi_verifier verify) {
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
            lfi_mem_protect(&copy, newbase, mem->prot, 1, verify);
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

extern void lfi_syscall_entry() asm ("lfi_syscall_entry");

#ifdef DYNARMIC
// Stub for dynarmic syscalls
static uint32_t syshandler_stub[2] = {
    0xd4000001, // svc #0
    0xd65f03c0, // ret
};
#endif

static struct lfi_sys* sys_alloc(uintptr_t base, int hidesys, size_t pagesize) {
    struct lfi_sys* sys;
    if (hidesys) {
        sys = mmap(NULL, pagesize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    } else {
        sys = mmap((void*) base, pagesize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    }
    if (sys == (void*) -1)
        return NULL;
    return sys;
}

static void sys_free(struct lfi_sys* sys, size_t pagesize) {
    munmap(sys, pagesize);
}

static void sys_setup(struct lfi_sys* table, struct lfi_proc* proc) {
#ifdef DYNARMIC
    table->rtcalls[0] = (uintptr_t) &syshandler_stub[0];
#else
    table->rtcalls[0] = (uintptr_t) &lfi_syscall_entry;
    // TODO: problem for multi-threading with thread locals
    table->k_tpidr = r_tpidr();
#endif
    table->proc = proc;
    table->base = proc->base;
    mprotect(table, proc->lfi->opts.pagesize, PROT_READ);
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
    lfi_mem_unmap(&proc->guards[0]);
    lfi_mem_unmap(&proc->guards[1]);
    sys_free(proc->sys, proc->lfi->opts.pagesize);
    lfi_mem_unmap(&proc->stack);
    lfi_proc_clear(&proc->segments);
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
    proc->guards[0] = lfi_mem_map(proc->base + proc->lfi->opts.pagesize, GUARD_SIZE, PROT_NONE);
    assert(lfi_mem_valid(&proc->guards[0]));
    proc->guards[1] = lfi_mem_map(proc->base + LFI_PROC_SIZE - GUARD_SIZE, GUARD_SIZE, PROT_NONE);
    assert(lfi_mem_valid(&proc->guards[1]));

    size_t stack_size = proc->lfi->opts.stacksize;
    proc->stack = lfi_mem_map(proc->guards[1].base - stack_size, stack_size, PROT_READ | PROT_WRITE);
    if (!lfi_mem_valid(&proc->stack)) {
        err = LFI_ERR_INVALID_STACK;
        goto err1;
    }

    uintptr_t base = proc->guards[0].base + proc->guards[0].size;
    uintptr_t last = 0;

    proc->sys = sys_alloc(proc->base, proc->lfi->opts.hidesys, proc->lfi->opts.pagesize);
    if (!proc->sys) {
        goto err1;
    }
    sys_setup(proc->sys, proc);

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

        struct lfi_mem seg = lfi_mem_map(base + start, end - start, PROT_READ | PROT_WRITE);
        if (!lfi_mem_valid(&seg)) {
            goto err1;
        }

        memcpy((void*) (seg.base + offset), &prog[p->offset], p->filesz);
        memset((void*) (seg.base + offset + p->filesz), 0, p->memsz - p->filesz);

        if ((err = lfi_mem_protect(&seg, proc->base, pflags(p->flags), proc->lfi->opts.noverify, proc->lfi->opts.verifier)) < 0) {
            goto err1;
        }

        if ((err = lfi_mem_append(&proc->segments, seg)) < 0) {
            goto err1;
        }

        if (base == 0) {
            base = seg.base;
        }
        if (base + end > last) {
            last = base + end;
        }
    }

    *info = (struct lfi_proc_info) {
        .stack = (void*) proc->stack.base,
        .stacksize = proc->stack.size,
        .lastva = last,
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
    struct lfi_sys* sys = sys_alloc(child->base, lfi->opts.hidesys, lfi->opts.pagesize);
    if (!sys) {
        lfi_delete_slot(lfi, child->base);
        return LFI_ERR_NOMEM;
    }
    child->sys = sys;
    *childp = child;

    child->guards[0] = lfi_mem_copy_to(&proc->guards[0], child->base, lfi->opts.verifier);
    child->guards[1] = lfi_mem_copy_to(&proc->guards[1], child->base, lfi->opts.verifier);
    child->stack = lfi_mem_copy_to(&proc->stack, child->base, lfi->opts.verifier);
    struct lfi_mem* segment = proc->segments;
    while (segment) {
        lfi_mem_append(&child->segments, lfi_mem_copy_to(segment, child->base, lfi->opts.verifier));
        segment = segment->next;
    }
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
    uint64_t sysno = regs_sysno(&proc->regs);

    uint64_t a0 = regs_sysarg(&proc->regs, 0);
    uint64_t a1 = regs_sysarg(&proc->regs, 1);
    uint64_t a2 = regs_sysarg(&proc->regs, 2);
    uint64_t a3 = regs_sysarg(&proc->regs, 3);
    uint64_t a4 = regs_sysarg(&proc->regs, 4);
    uint64_t a5 = regs_sysarg(&proc->regs, 5);

    assert(proc->lfi->opts.syshandler);

    uint64_t ret = proc->lfi->opts.syshandler(proc->ctxp, sysno, a0, a1, a2, a3, a4, a5);

    *regs_sysret(&proc->regs) = ret;
}

extern int lfi_proc_entry(struct lfi_proc*, void** kstackp) asm ("lfi_proc_entry");

void lfi_proc_init_regs(struct lfi_proc* proc, uintptr_t entry, uintptr_t sp) {
    regs_init(&proc->regs, entry, sp);
    regs_validate(proc);
    if (proc->lfi->opts.gas != 0) {
        uint64_t* r;
        if ((r = regs_gas(&proc->regs)))
            *r = proc->lfi->opts.gas;
        else
            fprintf(stderr, "warning: architecture does not support gas\n");
    }
}

int lfi_proc_start(struct lfi_proc* proc) {
#ifdef DYNARMIC
    return lfi_proc_entry_dynarmic(proc);
#else
    return lfi_proc_entry(proc, &proc->kstackp);
#endif
}

extern void lfi_asm_proc_exit(void* kstackp, int code) asm ("lfi_asm_proc_exit");

void lfi_proc_exit(struct lfi_proc* proc, int code) {
#ifdef DYNARMIC
    // TODO: halt the JIT
    fprintf(stderr, "EXITING\n");
    exit(1);
#else
    lfi_asm_proc_exit(proc->kstackp, code);
#endif
}

uintptr_t lfi_proc_base(struct lfi_proc* proc) {
    return proc->base;
}

uint64_t lfi_signal_start(uint64_t syspage) {
#ifndef DYNARMIC
    struct lfi_sys* sys = (struct lfi_sys*) syspage;
    uint64_t saved = r_tpidr();
    w_tpidr(sys->k_tpidr);
    return saved;
#else
    return 0;
#endif
}

void* lfi_sys_ctx(uint64_t syspage) {
    struct lfi_sys* sys = (struct lfi_sys*) syspage;
    return sys->proc->ctxp;
}

void lfi_signal_end(uint64_t saved) {
#ifndef DYNARMIC
    w_tpidr(saved);
#endif
}
