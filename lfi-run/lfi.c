#include <assert.h>
#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include "lfi.h"
#include "heap.h"

enum {
    GB = (uint64_t) 1024 * 1024 * 1024,
    MB = (uint64_t) 1024 * 1024,
    BOX_SIZE = (uint64_t) 4 * GB,
    GUARD_SIZE = (uint64_t) 4 * GB,
    BRK_SIZE = (uint64_t) 512 * MB,
};

static int pflags(int prot) {
    return ((prot & PF_R) ? PROT_READ : 0) | ((prot & PF_W) ? PROT_WRITE : 0) |
           ((prot & PF_X) ? PROT_EXEC : 0);
}

static int check_ehdr(Elf64_Ehdr* ehdr) {
    unsigned char* e_ident = ehdr->e_ident;
    return !(e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
             e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3 ||
             e_ident[EI_CLASS] != ELFCLASS64 ||
             e_ident[EI_VERSION] != EV_CURRENT || ehdr->e_type != ET_DYN);
}

static struct mem_region mem_map(uintptr_t base,
                                 size_t len,
                                 int prot,
                                 int flags) {
    void* m = mmap((void*) base, len, prot, flags, -1, 0);
    return (struct mem_region){
        .base = m,
        .len = len,
    };
}

static void mem_unmap(struct mem_region* mem) {
    munmap(mem->base, mem->len);
}

void syscall_entry();
void enter_sandbox(struct proc* proc);

int manager_load(struct manager* m,
                 int fd,
                 Elf64_Ehdr* ehdr,
                 Elf64_Phdr* phdr) {
    struct proc proc;

    uintptr_t base = 8ULL * GB;
    int flags = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
    proc.sys = mem_map(base, PAGE_SIZE, PROT_READ | PROT_WRITE, flags);
    if (proc.sys.base == (void*) -1) {
        return -1;
    }
    proc.mem = mem_map(base + PAGE_SIZE, BOX_SIZE - PAGE_SIZE,
                       PROT_READ | PROT_WRITE, flags);
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

    uintptr_t maxva = 0;

    for (Elf64_Phdr* iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
        if (iter->p_type != PT_LOAD)
            continue;
        uintptr_t start = truncpg(iter->p_vaddr);
        uintptr_t end = ceilpg(iter->p_vaddr + iter->p_memsz);
        memset(&proc.mem.base[start], 0, end - start);

        printf("LOAD [%lx:%lx] -> [%p:%p]\n", start, end, &proc.mem.base[start], &proc.mem.base[end]);

        if (lseek(fd, iter->p_offset, SEEK_SET) < 0)
            goto err;
        if (read(fd, &proc.mem.base[iter->p_vaddr], iter->p_filesz) !=
            (ssize_t) iter->p_filesz)
            goto err;
        mprotect(&proc.mem.base[start], end - start, pflags(iter->p_flags));
        if (end > maxva)
            maxva = end;
    }

    m->proc = proc;
    m->proc.brk = (uint64_t) m->proc.mem.base + maxva;
    uint64_t brk_end = m->proc.brk + BRK_SIZE;
    proc_heap_init(&m->proc, (void*) brk_end, (uint64_t) (m->proc.mem.base + m->proc.mem.len) - brk_end);

    memset(m->proc.sys.base, 0, m->proc.sys.len);
    memset(m->proc.kstack.data, 0, sizeof(m->proc.kstack.data));
    m->proc.kstack_canary = KSTACK_CANARY;
    m->proc.kstack_ptr = (uintptr_t) &m->proc.kstack.data[sizeof(m->proc.kstack.data)-16];

    m->proc.regs = (struct regs){
        .x21 = base,
        .x30 = base + PAGE_SIZE + ehdr->e_entry,
        .sp = (uint64_t) &m->proc.mem.base[m->proc.mem.len-16],
        .x18 = base,
        .x23 = base,
        .x24 = base,
    };

    uintptr_t* ptrs = (uintptr_t*) m->proc.sys.base;
    ptrs[0] = (uintptr_t) syscall_entry;
    ptrs[1] = (uintptr_t) &m->proc;
    mprotect(m->proc.sys.base, m->proc.sys.len, PROT_READ);

    return 0;

err:
    mem_unmap(&proc.sys);
    mem_unmap(&proc.mem);
    mem_unmap(&proc.guard);
    return -1;
}

void proc_setup(struct proc* proc, Elf64_Ehdr* ehdr, int argc, char* argv[], char* envp[]) {
    char* args[argc];
    char* sp_max = (char*) proc->regs.sp;
    char* sp_args = sp_max - PAGE_SIZE;
    // Write argv string values to stack
    for (int i = 0; i < argc; i++) {
        size_t len = strnlen(argv[i], 1024) + 1;
        memcpy(sp_args, argv[i], len);
        args[i] = sp_args;
        sp_args += len;
    }
    // Write argc and argv pointers to stack
    uint64_t* sp_new = (uint64_t*) (sp_max - 2 * PAGE_SIZE);
    proc->regs.sp = (uint64_t) sp_new;
    (*sp_new) = argc;
    char** proc_argv = (char**) (sp_new + 1);
    for (int i = 0; i < argc; i++) {
        proc_argv[i] = args[i];
    }
    proc_argv[argc] = NULL;
    char** proc_envp = (char**) &proc_argv[argc + 1];
    *proc_envp++ = NULL;

    Elf64_auxv_t* av = (void*) proc_envp;

    *av++ = (Elf64_auxv_t){ .a_type = AT_ENTRY, .a_un.a_val = proc->regs.x30, };
    *av++ = (Elf64_auxv_t){ .a_type = AT_RANDOM, .a_un.a_val = proc->regs.sp };
    *av++ = (Elf64_auxv_t){ .a_type = AT_EXECFN, .a_un.a_val = (uint64_t) proc_argv[0] };
    *av++ = (Elf64_auxv_t){ .a_type = AT_PHDR, .a_un.a_val = (uint64_t) proc->mem.base + ehdr->e_phoff };
    *av++ = (Elf64_auxv_t){ .a_type = AT_PHNUM, .a_un.a_val = ehdr->e_phnum };
    *av++ = (Elf64_auxv_t){ .a_type = AT_PHENT, .a_un.a_val = ehdr->e_phentsize };
}

void manager_schedule(struct manager* m) {
    enter_sandbox(&m->proc);
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
    free(phdr);
    close(fd);

    proc_setup(&manager.proc, &ehdr, argc - 1, &argv[1], envp);

    manager_schedule(&manager);
}
