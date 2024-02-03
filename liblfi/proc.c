#include "lfi_internal.h"
#include "elf.h"

#include <assert.h>
#include <sys/mman.h>

static int elf_check(struct elf_file_header* ehdr) {
    return 0;
}

static int prot_exec(int flags) {
    return (flags & PROT_EXEC) != 0;
}

static int prot_write(int flags) {
    return (flags & PROT_WRITE) != 0;
}

static struct lfi_mem lfi_mem_map(uintptr_t base, size_t size, int prot) {
    if (prot_exec(prot) && prot_write(prot)) {
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

static int lfi_mem_valid(struct lfi_mem mem) {
    return mem.base != (uintptr_t) -1;
}

enum {
    GUARD_SIZE = 48ULL * 1024,
};

int lfi_proc_exec(struct lfi_proc* proc, uint8_t* prog, size_t size, struct lfi_proc_info* info) {
    struct elf_file_header* ehdr = (struct elf_file_header*) prog;

    if (!elf_check(ehdr)) {
        return LFI_ERR_INVALID_ELF;
    }

    if (ehdr->phoff >= size || ehdr->phoff + ehdr->phnum * sizeof(struct elf_prog_header) >= size) {
        return LFI_ERR_INVALID_ELF;
    }

    struct elf_prog_header* phdr = (struct elf_prog_header*) &prog[ehdr->phoff];
    proc->guards[0] = lfi_mem_map(proc->base + proc->lfi->opts.pagesize, GUARD_SIZE, PROT_NONE);
    assert(lfi_mem_valid(proc->guards[0]));
    proc->guards[1] = lfi_mem_map(proc->base + LFI_PROC_SIZE - GUARD_SIZE, GUARD_SIZE, PROT_NONE);
    assert(lfi_mem_valid(proc->guards[1]));

    uintptr_t base = proc->guards[0].base + proc->guards[0].size;

    *info = (struct lfi_proc_info) {
        .elf_entry = ehdr->entry,
        .elf_base = base,
        .elf_phoff = ehdr->phoff,
        .elf_phnum = ehdr->phnum,
        .elf_phentsize = ehdr->phentsize,
    };

    return 0;
}

void lfi_proc_get_regs(struct lfi_proc* proc, struct lfi_regs* regs) {
    *regs = proc->regs;
}

void lfi_proc_set_regs(struct lfi_proc* proc, struct lfi_regs* regs) {
    proc->regs = *regs;
}

void lfi_proc_set_stack(struct lfi_proc* proc, void* stack) {
    lfi_regs_set_stack(&proc->regs, (uint64_t) stack);
}

struct lfi_proc* lfi_proc_copy(struct lfi_proc* proc, void* new_ctxp) {
    return NULL;
}

void* lfi_proc_mmap(struct lfi_proc* proc, void* base, size_t size, int prot) {
    return NULL;
}

int lfi_proc_mprotect(struct lfi_proc* proc, void* base, size_t size, int prot) {
    return -1;
}

int lfi_proc_munmap(struct lfi_proc* proc, void* base, size_t size) {
    return -1;
}

void lfi_proc_free(struct lfi_proc* proc) {

}
