#include <assert.h>
#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include "lfi.h"
#include "mem.h"

enum {
    GB = (uint64_t) 1024 * 1024 * 1024,
    MB = (uint64_t) 1024 * 1024,
    BOX_SIZE = (uint64_t) 4 * GB,
    GUARD_SIZE = (uint64_t) 4 * GB,
    BRK_SIZE = (uint64_t) 512 * MB,
    STACK_SIZE = (uint64_t) 2 * MB,
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
        .base = (uint64_t) m,
        .len = len,
    };
}

static void mem_unmap(struct mem_region* mem) {
    munmap((void*) mem->base, mem->len);
}

void syscall_entry();
void yield_fast(int pid);
void enter_sandbox(struct proc* proc);

int manager_load(struct manager* m,
                 int fd,
                 Elf64_Ehdr* ehdr,
                 Elf64_Phdr* phdr) {
    struct proc proc;

    uintptr_t maxva = 0;

    for (Elf64_Phdr* iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
        if (iter->p_type != PT_LOAD)
            continue;
        uintptr_t end = ceilpg(iter->p_vaddr + iter->p_memsz);
        if (end > maxva)
            maxva = end;
    }

    uintptr_t base = 8ULL * GB;
    int flags = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
    proc.sys = mem_map(base, PAGE_SIZE, PROT_READ | PROT_WRITE, flags);
    if (proc.sys.base == (uint64_t) -1) {
        return -1;
    }
    proc.bin = mem_map(base + PAGE_SIZE, maxva, PROT_NONE, flags);
    if (proc.bin.base == (uint64_t) -1) {
        mem_unmap(&proc.sys);
        return -1;
    }
    proc.guard = mem_map(base + BOX_SIZE, GUARD_SIZE, PROT_NONE, flags);
    if (proc.guard.base == (uint64_t) -1) {
        mem_unmap(&proc.sys);
        mem_unmap(&proc.bin);
        return -1;
    }

    for (Elf64_Phdr* iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
        if (iter->p_type != PT_LOAD)
            continue;
        uint64_t start = truncpg(iter->p_vaddr);
        uint64_t end = ceilpg(iter->p_vaddr + iter->p_memsz);

        mprotect((char*) proc.bin.base + start, end - start, PROT_READ | PROT_WRITE);
        memset((char*) proc.bin.base + start, 0, end - start);

        fprintf(stderr, "LOAD [%lx:%lx] -> [%lx:%lx]\n", start, end, proc.bin.base + start, proc.bin.base + end);

        if (lseek(fd, iter->p_offset, SEEK_SET) < 0)
            goto err;
        if (read(fd, (char*) proc.bin.base + iter->p_vaddr, iter->p_filesz) !=
            (ssize_t) iter->p_filesz)
            goto err;
        mprotect((char*) proc.bin.base + start, end - start, pflags(iter->p_flags));
    }

    m->proc = proc;
    m->proc.brk = (uint64_t) m->proc.bin.base + maxva;

    memset((char*) m->proc.sys.base, 0, m->proc.sys.len);
    char* kstack = aligned_alloc(PAGE_SIZE, KSTACK_SIZE);
    memset(kstack, 0, KSTACK_SIZE);
    mprotect(kstack, PAGE_SIZE, PROT_NONE);
    m->proc.kstack_ptr = (uintptr_t) kstack + KSTACK_SIZE;

    m->proc.regs = (struct regs){
        .x21 = base,
        .x30 = base + PAGE_SIZE + ehdr->e_entry,
        .x18 = base,
        .x23 = base,
        .x24 = base,
        .tpidr = base,
    };

    m->proc.context = (struct context){
        .sp = m->proc.kstack_ptr,
        .x30 = (uintptr_t) enter_sandbox,
        .sp_base = kstack,
    };

    m->proc.stack = mem_map(base + BOX_SIZE - STACK_SIZE, STACK_SIZE, PROT_READ | PROT_WRITE, flags);
    if (m->proc.stack.base == (uint64_t) -1) {
        goto err;
    }

    m->proc.brk_heap = mem_map(m->proc.brk, BRK_SIZE, PROT_READ | PROT_WRITE, flags);
    if (m->proc.brk_heap.base == (uint64_t) -1) {
        mem_unmap(&m->proc.stack);
        goto err;
    }

    uint64_t mmap_base = m->proc.brk_heap.base + m->proc.brk_heap.len;
    bool ok = proc_mmap_init(&m->proc, mmap_base, m->proc.stack.base - mmap_base);
    if (!ok) {
        mem_unmap(&m->proc.stack);
        mem_unmap(&m->proc.brk_heap);
        goto err;
    }

    uintptr_t* ptrs = (uintptr_t*) m->proc.sys.base;
    ptrs[0] = (uintptr_t) syscall_entry;
    ptrs[1] = (uintptr_t) yield_fast;
    ptrs[16+0] = (uintptr_t) &m->proc;
    uintptr_t tpidr;
    asm volatile ("mrs %0, tpidr_el0" : "=r"(tpidr));
    ptrs[16+1] = tpidr;
    mprotect((char*) m->proc.sys.base, m->proc.sys.len, PROT_READ);

    return 0;

err:
    mem_unmap(&proc.sys);
    mem_unmap(&proc.bin);
    mem_unmap(&proc.guard);
    return -1;
}

void proc_setup(struct proc* proc, Elf64_Ehdr* ehdr, int argc, char* argv[], char* envp[]) {
    char* args[argc];
    char* sp_max = (char*) proc->stack.base + proc->stack.len;
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
    *av++ = (Elf64_auxv_t){ .a_type = AT_EXECFN, .a_un.a_val = (uint64_t) proc_argv[0] };
    *av++ = (Elf64_auxv_t){ .a_type = AT_PHDR, .a_un.a_val = (uint64_t) proc->bin.base + ehdr->e_phoff };
    *av++ = (Elf64_auxv_t){ .a_type = AT_PHNUM, .a_un.a_val = ehdr->e_phnum };
    *av++ = (Elf64_auxv_t){ .a_type = AT_PHENT, .a_un.a_val = ehdr->e_phentsize };
    *av++ = (Elf64_auxv_t){ .a_type = AT_PAGESZ, .a_un.a_val = PAGE_SIZE };
    *av++ = (Elf64_auxv_t){ .a_type = AT_NULL, .a_un.a_val = 0 };
}

struct manager manager;

int main(int argc, char* argv[], char* envp[]) {
    if (argc <= 1) {
        printf("no input\n");
        return 1;
    }

    signal_setup();

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
    runq_push_front(&manager.proc);

    timer_setup(10000); // 10ms time slices
    signal_enable();

    schedule();
}
