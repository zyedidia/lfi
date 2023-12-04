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
#include "buddy.h"
#include "queue.h"

static int rdstdin(void* proc, void* device, uint8_t* buf, int n) {
    (void) proc;
    (void) device;
    return fread(buf, 1, n, stdin);
}
static int wrstdout(void* proc, void* device, uint8_t* buf, int n) {
    (void) proc;
    (void) device;
    return fwrite(buf, 1, n, stdout);
}
static int wrstderr(void* proc, void* device, uint8_t* buf, int n) {
    (void) proc;
    (void) device;
    return fwrite(buf, 1, n, stderr);
}

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

void syscall_entry();
void yield_fast(int pid);
void enter_sandbox(struct proc* p);

static void proc_setup(struct proc* proc, Elf64_Ehdr* ehdr, int argc, char* argv[], char* envp[]) {
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

    proc->fdtable[0] = (struct file){
        .allocated = true,
        .read = rdstdin,
        .write = NULL,
    };
    proc->fdtable[1] = (struct file){
        .allocated = true,
        .read = NULL,
        .write = wrstdout,
    };
    proc->fdtable[2] = (struct file){
        .allocated = true,
        .read = NULL,
        .write = wrstderr,
    };
}

static int proc_load(uintptr_t base, struct proc* proc, int fd, int argc, char* argv[], char* envp[]) {
    Elf64_Ehdr ehdr;
    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
        printf("can't read ELF header\n");
        return -1;
    }
    if (!check_ehdr(&ehdr)) {
        printf("bad ELF header\n");
        return -1;
    }

    ssize_t sz = ehdr.e_phnum * sizeof(Elf64_Phdr);
    Elf64_Phdr* phdr = malloc(sz);
    if (lseek(fd, ehdr.e_phoff, SEEK_SET) < 0) {
        printf("seek to program header failed\n");
        return -1;
    }
    if (read(fd, phdr, sz) != sz) {
        printf("read program header failed\n");
        return -1;
    }

    uintptr_t maxva = 0;

    for (Elf64_Phdr* iter = phdr; iter < &phdr[ehdr.e_phnum]; iter++) {
        if (iter->p_type != PT_LOAD)
            continue;
        uintptr_t end = ceilpg(iter->p_vaddr + iter->p_memsz);
        if (end > maxva)
            maxva = end;
    }

    int flags = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
    proc->sys = mem_map(base, PAGE_SIZE, PROT_READ | PROT_WRITE, flags);
    if (proc->sys.base == (uint64_t) -1) {
        return -1;
    }
    proc->bin = mem_map(base + PAGE_SIZE, maxva, PROT_READ | PROT_WRITE, flags);
    if (proc->bin.base == (uint64_t) -1) {
        mem_unmap(&proc->sys);
        return -1;
    }
    proc->guard = mem_map(base + BOX_SIZE, GUARD_SIZE, PROT_NONE, flags);
    if (proc->guard.base == (uint64_t) -1) {
        mem_unmap(&proc->sys);
        mem_unmap(&proc->bin);
        return -1;
    }

    for (Elf64_Phdr* iter = phdr; iter < &phdr[ehdr.e_phnum]; iter++) {
        if (iter->p_type != PT_LOAD)
            continue;
        uint64_t start = truncpg(iter->p_vaddr);
        uint64_t end = ceilpg(iter->p_vaddr + iter->p_memsz);

        fprintf(stderr, "LOAD [%lx:%lx] -> [%lx:%lx]\n", start, end, proc->bin.base + start, proc->bin.base + end);

        if (lseek(fd, iter->p_offset, SEEK_SET) < 0)
            goto err;
        if (read(fd, (char*) proc->bin.base + iter->p_vaddr, iter->p_filesz) !=
            (ssize_t) iter->p_filesz)
            goto err;
        mprotect((char*) proc->bin.base + start, end - start, pflags(iter->p_flags));
    }

    proc->brk = (uint64_t) proc->bin.base + maxva;

    char* kstack = aligned_alloc(PAGE_SIZE, KSTACK_SIZE);
    memset(kstack, 0, KSTACK_SIZE);
    mprotect(kstack, PAGE_SIZE, PROT_NONE);
    proc->kstack_ptr = (uintptr_t) kstack + KSTACK_SIZE;

    proc->regs = (struct regs){
        .x21 = base,
        .x30 = base + PAGE_SIZE + ehdr.e_entry,
        .x18 = base,
        .x23 = base,
        .x24 = base,
    };

    proc->context = (struct context){
        .sp = proc->kstack_ptr,
        .x30 = (uintptr_t) enter_sandbox,
        .sp_base = kstack,
    };

    proc->stack = mem_map(base + BOX_SIZE - STACK_SIZE, STACK_SIZE, PROT_READ | PROT_WRITE, flags);
    if (proc->stack.base == (uint64_t) -1) {
        goto err;
    }

    proc->brk_heap = mem_map(proc->brk, BRK_SIZE, PROT_READ | PROT_WRITE, flags);
    if (proc->brk_heap.base == (uint64_t) -1) {
        mem_unmap(&proc->stack);
        goto err;
    }

    uint64_t mmap_base = proc->brk_heap.base + proc->brk_heap.len;
    bool ok = proc_mmap_init(proc, mmap_base, proc->stack.base - mmap_base);
    if (!ok) {
        mem_unmap(&proc->stack);
        mem_unmap(&proc->brk_heap);
        goto err;
    }

    uintptr_t* ptrs = (uintptr_t*) proc->sys.base;
    ptrs[0] = (uintptr_t) syscall_entry;
    ptrs[1] = (uintptr_t) yield_fast;
    ptrs[16+0] = (uintptr_t) proc;
    uintptr_t tpidr;
    asm volatile ("mrs %0, tpidr_el0" : "=r"(tpidr));
    ptrs[16+1] = tpidr;
    mprotect((char*) proc->sys.base, proc->sys.len, PROT_READ);

    proc_setup(proc, &ehdr, argc, argv, envp);

    return 0;

err:
    mem_unmap(&proc->sys);
    mem_unmap(&proc->bin);
    mem_unmap(&proc->guard);
    return -1;
}

uintptr_t proc_newbase(struct manager* m) {
    return (uintptr_t) buddy_malloc(m->proc_allocator, BOX_SIZE + GUARD_SIZE);
}

static struct proc* proc_new(struct manager* m, char* file, int argc, char* argv[], char* envp[]) {
    int fd;
    if ((fd = open(file, O_RDONLY)) < 0) {
        printf("could not open file %s\n", file);
        return NULL;
    }
    struct proc* proc = calloc(1, sizeof(struct proc));
    if (!proc) {
        close(fd);
        return NULL;
    }

    uintptr_t base = proc_newbase(m);
    if (!base) {
        close(fd);
        return NULL;
    }

    if (proc_load(base, proc, fd, argc, argv, envp) < 0) {
        printf("failed to load sandbox\n");
        free(proc);
        close(fd);
        return NULL;
    }
    close(fd);
    return proc;
}

bool manager_setup(struct manager* m) {
    size_t size = NUM_BOXES * (BOX_SIZE + GUARD_SIZE);
    void* meta = malloc(buddy_sizeof_alignment(size, BOX_SIZE + GUARD_SIZE));
    if (!meta)
        return false;
    m->proc_allocator = buddy_init_alignment(meta, (void*) BOXES_START, size, BOX_SIZE + GUARD_SIZE);
    if (!m->proc_allocator) {
        free(meta);
        return false;
    }
    return true;
}

struct manager manager;

int main(int argc, char* argv[], char* envp[]) {
    if (argc <= 1) {
        printf("no input\n");
        return 1;
    }

    signal_setup();
    manager_setup(&manager);

    char* file = argv[1];
    struct proc* proc = proc_new(&manager, file, argc - 1, &argv[1], envp);
    if (!proc) {
        return 1;
    }

    queue_push_front(&manager.runq, proc);
    manager.init = proc;

    timer_setup();

    schedule(&manager);
}
