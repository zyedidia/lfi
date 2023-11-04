#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <assert.h>

#include "lfi.h"

enum {
    GB         = (uint64_t) 1024 * 1024 * 1024,
    PAGE_SIZE  = (uint64_t) 4096,
    ALIGN      = (uint64_t) PAGE_SIZE - 1,
    BOX_SIZE   = (uint64_t) 4 * GB,
    GUARD_SIZE = (uint64_t) 4 * GB,
};

static int pflags(int prot) {
    return ((prot & PF_R) ? PROT_READ : 0) |
        ((prot & PF_W) ? PROT_WRITE : 0) |
        ((prot & PF_X) ? PROT_EXEC : 0);
}

static uintptr_t truncpg(uintptr_t addr) {
    return addr & ~ALIGN;
}

static uintptr_t ceilpg(uintptr_t addr) {
    return (addr + ALIGN) & ~ALIGN;
}

static int check_ehdr(Elf64_Ehdr* ehdr) {
    unsigned char* e_ident = ehdr->e_ident;
    return !(e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
            e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3 ||
            e_ident[EI_CLASS] != ELFCLASS64 ||
            e_ident[EI_VERSION] != EV_CURRENT ||
            ehdr->e_type != ET_DYN);
}

static struct mem_region mem_map(uintptr_t base, size_t len, int prot, int flags) {
    void* m = mmap((void*) base, len, prot, flags, -1, 0);
    return (struct mem_region){
        .base = m,
        .len = len,
    };
}

static void mem_unmap(struct mem_region* mem) {
    munmap(mem->base, mem->len);
}

int manager_load(struct manager* m, int fd, Elf64_Ehdr* ehdr, Elf64_Phdr* phdr) {
    struct proc proc;

    uintptr_t base = 8ULL * GB;
    int flags = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
    proc.sys = mem_map(base, PAGE_SIZE, PROT_READ | PROT_WRITE, flags);
    if (proc.sys.base == (void*) -1) {
        return -1;
    }
    proc.mem = mem_map(base + PAGE_SIZE, BOX_SIZE - PAGE_SIZE, PROT_READ | PROT_WRITE, flags);
    if (proc.mem.base == (void*) -1) {
        mem_unmap(&proc.sys);
        return -1;
    }
    proc.guard = mem_map(base + BOX_SIZE, GUARD_SIZE, PROT_NONE, flags);
    if (proc.guard.base == (void*) -1) {
        mem_unmap(&proc.sys);
        mem_unmap(&proc.mem);
        return -1;
    }

    for (Elf64_Phdr* iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
        if (iter->p_type != PT_LOAD)
            continue;
        uintptr_t start = truncpg(iter->p_vaddr);
        uintptr_t end = ceilpg(iter->p_vaddr + iter->p_memsz);
        memset(&proc.mem.base[start], 0, end - start);

        if (lseek(fd, iter->p_offset, SEEK_SET) < 0)
            goto err;
        if (read(fd, &proc.mem.base[iter->p_vaddr], iter->p_filesz) != (ssize_t) iter->p_filesz)
            goto err;
        mprotect(proc.mem.base, end - start, pflags(iter->p_flags));
    }

    memset(proc.sys.base, 0, proc.sys.len);
    // TODO: set syscall entry
    mprotect(proc.sys.base, proc.sys.len, PROT_READ);

    proc.entry = base + PAGE_SIZE + ehdr->e_entry;
    m->proc = proc;
    return 0;

err:
    mem_unmap(&proc.sys);
    mem_unmap(&proc.mem);
    mem_unmap(&proc.guard);
    return -1;
}

struct manager manager;

int main(int argc, char* argv[], char* envp[]) {
    if (argc <= 1) {
        printf("no input\n");
        return 1;
    }

    char* file = argv[1];
    int fd;
    if ((fd = open(file, O_RDONLY)) < 0) {
        printf("could not open file\n");
        return 1;
    }

    Elf64_Ehdr ehdr;
    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
        printf("can't read ELF header\n");
        return 1;
    }
    if (!check_ehdr(&ehdr)) {
        printf("bad ELF header\n");
        return 1;
    }

    ssize_t sz = ehdr.e_phnum * sizeof(Elf64_Phdr);
    Elf64_Phdr* phdr = malloc(sz);
    if (lseek(fd, ehdr.e_phoff, SEEK_SET) < 0) {
        printf("seek to program header failed\n");
        return 1;
    }
    if (read(fd, phdr, sz) != sz) {
        printf("read program header failed\n");
        return 1;
    }
    if (manager_load(&manager, fd, &ehdr, phdr) < 0) {
        printf("failed to load sandbox\n");
        return 1;
    }
    printf("done\n");
}
