#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <assert.h>

#include "ht.h"

#define BOX_SIZE (1ULL << 32)
#define BOX_ALIGN (BOX_SIZE - 1)
#define BOX_ROUND(x) (((x) + (BOX_ALIGN)) & ~(BOX_ALIGN))
#define BOX_TRUNC(x) ((x) & ~(BOX_ALIGN))

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

#define ALIGN (PAGE_SIZE - 1)
#define ROUND_PG(x) (((x) + (ALIGN)) & ~(ALIGN))
#define TRUNC_PG(x) ((x) & ~(ALIGN))
#define PFLAGS(x)                                                     \
    ((((x) &PF_R) ? PROT_READ : 0) | (((x) &PF_W) ? PROT_WRITE : 0) | \
     (((x) &PF_X) ? PROT_EXEC : 0))
#define LOAD_ERR ((unsigned long) -1)

#define BASE_VA (BOX_SIZE * 2 + PAGE_SIZE)

#define STACK_SIZE (1 << 21)

#define BUDDY_ALLOC_ALIGN (PAGE_SIZE)
#define BUDDY_ALLOC_IMPLEMENTATION
#include "buddy_alloc.h"
#undef BUDDY_ALLOC_IMPLEMENTATION

static int check_ehdr(Elf64_Ehdr* ehdr) {
    unsigned char* e_ident = ehdr->e_ident;
    return (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
            e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3 ||
            e_ident[EI_CLASS] != ELFCLASS64 ||
            e_ident[EI_VERSION] != EV_CURRENT ||
            (ehdr->e_type != ET_EXEC && ehdr->e_type != ET_DYN))
               ? 0
               : 1;
}

static unsigned long loadelf_anon(int fd, Elf64_Ehdr* ehdr, Elf64_Phdr* phdr, unsigned long* brk) {
    unsigned long minva, maxva;
    Elf64_Phdr* iter;
    ssize_t sz;
    int flags, dyn = ehdr->e_type == ET_DYN;
    unsigned char *p, *base, *hint;

    minva = (unsigned long) -1;
    maxva = 0;

    for (iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
        if (iter->p_type != PT_LOAD)
            continue;
        if (iter->p_vaddr < minva)
            minva = iter->p_vaddr;
        if (iter->p_vaddr + iter->p_memsz > maxva)
            maxva = iter->p_vaddr + iter->p_memsz;
    }

    unsigned long brkva = maxva;
    minva = BOX_TRUNC(minva);
    maxva = BOX_ROUND(maxva);

    // For dynamic ELF let the kernel chose the address.
    hint = dyn ? (void*) BASE_VA : (void*) minva;
    flags = dyn ? 0 : MAP_FIXED;
    flags |= (MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE | MAP_FIXED);

    // Check that we can hold the whole image.
    base = mmap(hint, maxva - minva, PROT_NONE, flags, -1, 0);
    if (base == (void*) -1)
        return -1;
    munmap(base, maxva - minva);

    // Now map each segment separately in precalculated address.
    flags = MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE | MAP_NORESERVE;
    for (iter = phdr; iter < &phdr[ehdr->e_phnum]; iter++) {
        unsigned long off, start;
        if (iter->p_type != PT_LOAD)
            continue;
        off = iter->p_vaddr & ALIGN;
        start = dyn ? (unsigned long) base : 0;
        start += TRUNC_PG(iter->p_vaddr);
        sz = ROUND_PG(iter->p_memsz + off);

        p = mmap((void*) start, sz, PROT_WRITE, flags, -1, 0);
        if (p == (void*) -1)
            goto err;
        if (lseek(fd, iter->p_offset, SEEK_SET) < 0)
            goto err;
        if (read(fd, p + off, iter->p_filesz) != (ssize_t) iter->p_filesz)
            goto err;
        mprotect(p, sz, PFLAGS(iter->p_flags));
    }

    *brk = (unsigned long) base + brkva;
    return (unsigned long) base;
err:
    munmap(base, maxva - minva);
    return LOAD_ERR;
}

void trampoline(void*, void*, void*, uint64_t);
void syscall_entry();
void instcall_entry();

struct regs {
    uint64_t x0;
    uint64_t x1;
    uint64_t x2;
    uint64_t x3;
    uint64_t x4;
    uint64_t x5;
    uint64_t x6;
    uint64_t x7;
    uint64_t x8;
    uint64_t x9;
    uint64_t x10;
    uint64_t x11;
    uint64_t x12;
    uint64_t x13;
    uint64_t x14;
    uint64_t x15;
    uint64_t x16;
    uint64_t x17;
    uint64_t x18;
    uint64_t x29;
    uint64_t x21;
    uint64_t x22;
    uint64_t x30;
    uint64_t x24;
    uint64_t vector[32];
};

struct proc_state {
    uintptr_t brk;
    uintptr_t next_mmap;
    struct buddy* buddy;
    ht_t ht;
};

struct proc_state pstate;

void instcall_handler(struct regs* regs) {
    /* printf("%p\n", regs->x30); */
    uint64_t count = ht_get(&pstate.ht, regs->x30, NULL);
    ht_put(&pstate.ht, regs->x30, count + 1);
}

int syscall_handler(struct regs* regs) {
    switch (regs->x8) {
    case 215: // munmap
        memset((void*) regs->x0, 0, regs->x1);
        buddy_free(pstate.buddy, (void*) regs->x0);
        regs->x0 = 0;
        return 1;
    case 216: // mremap
        regs->x0 = (uint64_t) -1;
        return 1;
    case 222: // mmap
        if (regs->x0 == 0) {
            size_t size = ROUND_PG(regs->x1);
            void* p = buddy_malloc(pstate.buddy, size);
            if (!p) {
                regs->x0 = (uint64_t) -1;
                return 1;
            }
            regs->x0 = (uint64_t) p;
            return 1;
        } else {
            return 0;
        }
    case 214: // brk
        if (regs->x0 != 0) {
            assert(mmap((void*) pstate.brk, regs->x0 - pstate.brk, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0) != (void*) -1);
            pstate.brk = regs->x0;
        }
        regs->x0 = pstate.brk;
        return 1;
    case 94: // exit_group
    case 93: // exit
        for (size_t i = 0; i < pstate.ht.cap; i++) {
            if (pstate.ht.entries[i].filled) {
                ht_entry_t* ent = &pstate.ht.entries[i];
                fprintf(stderr, "%lx %ld\n", ent->key, ent->val);
            }
        }
        return 0;
    }
    return 0;
}

static void fini(void) {}

int main(int host_argc, char* host_argv[], char* host_envp[]) {
    if (host_argc <= 1) {
        printf("no input\n");
        return 0;
    }

    char* file = host_argv[1];
    int fd;
    if ((fd = open(file, O_RDONLY)) < 0) {
        printf("could not open file\n");
        exit(1);
    }

    Elf64_Ehdr ehdrs, *ehdr = &ehdrs;
    if (read(fd, ehdr, sizeof(*ehdr)) != sizeof(*ehdr)) {
        printf("can't read ELF header\n");
        exit(1);
    }
    if (!check_ehdr(ehdr)) {
        printf("bad ELF header\n");
        exit(1);
    }

    ssize_t sz = ehdr->e_phnum * sizeof(Elf64_Phdr);
    Elf64_Phdr* phdr = malloc(sz);
    if (lseek(fd, ehdr->e_phoff, SEEK_SET) < 0) {
        printf("seek to program header failed\n");
        exit(1);
    }
    if (read(fd, phdr, sz) != sz) {
        printf("read program header failed\n");
        exit(1);
    }
    unsigned long base, entry, brk;
    if ((base = loadelf_anon(fd, ehdr, phdr, &brk)) == LOAD_ERR) {
        printf("can't load ELF file\n");
        exit(1);
    }

    entry = ehdr->e_entry + (ehdr->e_type == ET_DYN ? base : 0);

    close(fd);

    char* args[host_argc - 1];

    // base is now the base of the box (pointing at the syscall table)
    base -= PAGE_SIZE;

    int flags = MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE | MAP_NORESERVE;
    void* sp_base = mmap((void*) (base + BOX_SIZE - STACK_SIZE), STACK_SIZE, PROT_READ | PROT_WRITE, flags, -1, 0);
    if (sp_base == (void*) -1) {
        printf("mapping stack failed\n");
        exit(1);
    }

    char* sp_args = (char*) (base + BOX_SIZE - PAGE_SIZE);
    for (int i = 0; i < host_argc - 1; i++) {
        size_t len = strnlen(host_argv[i + 1], 1024) + 1;
        memcpy(sp_args, host_argv[i + 1], len);
        args[i] = sp_args;
        sp_args += len;
    }
    unsigned long* sp = (unsigned long*) (base + BOX_SIZE - PAGE_SIZE * 2);

    (*sp) = host_argc - 1;
    int argc = (int) *(sp);
    char** argv = (char**) (sp + 1);
    for (int i = 0; i < host_argc - 1; i++) {
        argv[i] = args[i];
    }
    argv[argc] = NULL;
    char **env, **p;
    env = p = (char**) &argv[argc + 1];
    while (*p++ != NULL)
        ;
    while (*host_envp++ != NULL)
        ;
    Elf64_auxv_t* av = (void*) p;
    Elf64_auxv_t* host_av = (void*) host_envp;

    // Reassign some vectors that are important for the dynamic linker and for
    // lib C.
#define AVSET(t, v, expr)         \
    case (t):                     \
        (v)->a_un.a_val = (expr); \
        break
    while (host_av->a_type != AT_NULL) {
        // Skip auxvec types that we don't know about.
        switch (host_av->a_type) {
            case AT_PHDR:
            case AT_PHNUM:
            case AT_PHENT:
            case AT_ENTRY:
            case AT_EXECFN:
            case AT_BASE:
                break;
            case AT_RANDOM:
            case AT_PLATFORM:
            case AT_SYSINFO_EHDR:
                host_av++;
                continue;
            default:
                break;
        }
        *av = *host_av;
        switch (av->a_type) {
            AVSET(AT_PHDR, av, base + PAGE_SIZE + ehdrs.e_phoff);
            AVSET(AT_PHNUM, av, ehdrs.e_phnum);
            AVSET(AT_PHENT, av, ehdrs.e_phentsize);
            AVSET(AT_ENTRY, av, entry);
            AVSET(AT_EXECFN, av, (unsigned long) argv[0]);
            AVSET(AT_BASE, av, av->a_un.a_val);
            AVSET(AT_RANDOM, av, (unsigned long) sp);
        }
        ++av;
        ++host_av;
    }
#undef AVSET
    ++av;

    uintptr_t next_mmap = ((BASE_VA - PAGE_SIZE) + (512 * 1024 * 1024));
    size_t heap_size = (2UL * 1024 * 1024 * 1024 + 512 * 1024 * 1024);
    void* heap_meta = malloc(buddy_sizeof(heap_size));
    assert(heap_meta);
    uintptr_t heap = (uintptr_t) mmap((void*) next_mmap, heap_size, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    assert(heap != (uintptr_t) -1);
    heap = ROUND_PG(heap);
    pstate = (struct proc_state){
        .brk = ROUND_PG(brk),
        .next_mmap = next_mmap,
        .buddy = buddy_init(heap_meta, (void*) heap, heap_size),
    };
    ht_alloc(&pstate.ht, 1024 * 1024);

    void* sysbase = (void*) (BASE_VA & 0xffffffff00000000);
    mmap(sysbase, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    *((void**)sysbase) = (void*) &syscall_entry;
    *((void**)sysbase+1) = (void*) &instcall_entry;
    mprotect(sysbase, PAGE_SIZE, PROT_READ);
    trampoline((void*) entry, sp, fini, (uint64_t) sysbase);

    return 0;
}
