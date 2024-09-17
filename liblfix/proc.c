#include <assert.h>
#include <errno.h>
#include <unistd.h>

#include <sys/mman.h>

#include "lfix.h"
#include "elf.h"
#include "proc.h"

static bool procsetup(LFIXProc* p, int progfd, int interpfd, int argc, const char** argv);
static bool procfile(LFIXProc* p, int fd, int argc, const char** argv);
static void procfree(LFIXProc*);

uintptr_t
procaddr(LFIXProc* proc, uintptr_t addr)
{
    return ((uint32_t) addr) | proc->base;
}

uintptr_t
procuseraddr(LFIXProc* proc, uintptr_t addr)
{
    return procaddr(proc, addr);
}

static LFIXProc*
procnewempty()
{
    LFIXProc* p = malloc(sizeof(LFIXProc));
    if (!p)
        return NULL;
    *p = (LFIXProc){0};
    return p;
}

static LFIXProc*
procnewfile(LFIXEngine* lfix, int fd, int argc, const char** argv)
{
    LFIXProc* p = procnewempty();
    if (!p)
        return NULL;
    p->lfix = lfix;
    int err = lfi_addproc(lfix->l_engine, &p->l_proc, p);
    if (err < 0)
        goto err;
    p->base = lfi_proc_base(p->l_proc);
    p->size = lfi_proc_size(p->l_proc);

    if (!procfile(p, fd, argc, argv))
        return NULL;
    lfix_fdinit(&p->fdtable);
    return p;
err:
    procfree(p);
    return NULL;
}

static bool
procfile(LFIXProc* p, int fd, int argc, const char** argv)
{
    int interpfd = -1;
    char* interp = elfinterpfd(fd);
    if (interp) {
        FILE* f = fopen(interp, "rb");
        if (f) {
            interpfd = fileno(f);
        } else {
            fprintf(stderr, "error opening dynamic linker %s: %s\n", interp, strerror(errno));
            free(interp);
            return false;
        }
        free(interp);
    }

    bool success = true;
    if (!procsetup(p, fd, interpfd, argc, argv))
        success = false;

    if (interpfd >= 0)
        close(interpfd);

    return success;
}

enum {
    ARGC_MAX = 1024,
    ARGV_MAX = 1024,

    ARG_BLOCK = 4096,
};

static bool
stacksetup(LFIXProc* p, int argc, const char** argv, LFIProcInfo* info, uintptr_t* newsp)
{
    char* argv_ptrs[ARGC_MAX];
    char* stack_top = (char*) info->stack + info->stacksize;
    char* p_argv = (char*) stack_top - ARG_BLOCK;

    // Write argv string values to the stack.
    for (int i = 0; i < argc; i++) {
        size_t len = strnlen(argv[i], ARGV_MAX) + 1;

        if (p_argv + len >= stack_top) {
            return false;
        }

        memcpy(p_argv, argv[i], len);
        p_argv[len - 1] = 0;
        argv_ptrs[i] = p_argv;
        p_argv += len;
    }

    // Write argc and argv pointers to the stack.
    long* p_argc = (long*) (stack_top - 2 * ARG_BLOCK);
    *newsp = (uintptr_t) p_argc;
    *p_argc++ = argc;
    char** p_argvp = (char**) p_argc;
    for (int i = 0; i < argc; i++) {
        if ((uintptr_t) p_argvp >= (uintptr_t) stack_top - ARG_BLOCK) {
            return false;
        }
        p_argvp[i] = (char*) procuseraddr(p, (uintptr_t) argv_ptrs[i]);
    }
    p_argvp[argc] = NULL;
    // Empty envp.
    char** p_envp = (char**) &p_argvp[argc + 1];
    *p_envp++ = NULL;

    Auxv* av = (Auxv*) p_envp;
    *av++ = (Auxv) { AT_SECURE, 0 };
    *av++ = (Auxv) { AT_BASE, procuseraddr(p, info->ldbase) };
    *av++ = (Auxv) { AT_PHDR, procuseraddr(p, info->elfbase + info->elfphoff) };
    *av++ = (Auxv) { AT_PHNUM, info->elfphnum };
    *av++ = (Auxv) { AT_PHENT, info->elfphentsize };
    *av++ = (Auxv) { AT_ENTRY, procuseraddr(p, info->elfentry) };
    *av++ = (Auxv) { AT_EXECFN, procuseraddr(p, (uintptr_t) p_argvp[0]) };
    *av++ = (Auxv) { AT_PAGESZ, getpagesize() };
    *av++ = (Auxv) { AT_HWCAP, 0 };
    *av++ = (Auxv) { AT_HWCAP2, 0 };
    *av++ = (Auxv) { AT_RANDOM, procuseraddr(p, info->elfentry) }; // TODO
    *av++ = (Auxv) { AT_FLAGS, 0 };
    *av++ = (Auxv) { AT_UID, 1000 };
    *av++ = (Auxv) { AT_EUID, 1000 };
    *av++ = (Auxv) { AT_GID, 1000 };
    *av++ = (Auxv) { AT_EGID, 1000 };
    *av++ = (Auxv) { AT_NULL, 0 };

    return true;
}

static bool
procmapsetup(LFIXProc* p, uintptr_t mapstart, uintptr_t mapend)
{
    return mm_init(&p->mm, mapstart, mapend - mapstart, getpagesize());
}

static bool
procsetup(LFIXProc* p, int progfd, int interpfd, int argc, const char** argv)
{
    LFIProcInfo info = {0};
    bool b = lfi_proc_loadelf(p->l_proc, progfd, interpfd, &info);
    if (!b)
        return false;

    uintptr_t sp;
    if (!stacksetup(p, argc, argv, &info, &sp))
        return false;

    uintptr_t entry = info.elfentry;
    if (interpfd >= 0)
        entry = info.ldentry;

    lfi_proc_init(p->l_proc, entry, sp);

    p->brkbase = info.lastva;
    p->brksize = 0;

    if (!procmapsetup(p, p->brkbase + BRKMAXSIZE, (uintptr_t) info.stack - getpagesize()))
        return false;

    return true;
}

static int
procmap(LFIXProc* p, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
{
    if (fd >= 0) {
        FDFile* f = lfix_fdget(&p->fdtable, fd);
        if (!f)
            return -EBADF;
        if (!f->mapfd)
            return -EACCES;
        fd = f->mapfd(f->dev);
    }
    void* mem = mmap((void*) start, size, prot, flags | MAP_FIXED, fd, offset);
    if (mem == (void*) -1)
        return -errno;
    return 0;
}

int
procmapany(LFIXProc* p, size_t size, int prot, int flags, int fd, off_t offset, uintptr_t* o_mapstart)
{
    uintptr_t addr = mm_mapany(&p->mm, size, prot, flags, fd, offset);
    if (addr == (uint64_t) -1)
        return -EINVAL;
    int r = procmap(p, addr, size, prot, flags, fd, offset);
    if (r < 0) {
        mm_unmap(&p->mm, addr, size);
        return r;
    }
    *o_mapstart = addr;
    return 0;
}

static void
cbunmap(uintptr_t start, size_t len, MMInfo info, void* udata)
{
    (void) udata;
    (void) info;
    int r = munmap((void*) start, len);
    assert(r == 0);
}

int
procmapat(LFIXProc* p, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
{
    uintptr_t addr = mm_mapat_cb(&p->mm, start, size, prot, flags, fd, offset, cbunmap, NULL);
    if (addr == (uint64_t) -1)
        return -EINVAL;
    int r = procmap(p, addr, size, prot, flags, fd, offset);
    if (r < 0) {
        mm_unmap(&p->mm, addr, size);
        return r;
    }
    return 0;
}

int
procunmap(LFIXProc* p, uintptr_t start, size_t size)
{
    return mm_unmap_cb(&p->mm, start, size, cbunmap, NULL);
}

static void
procfree(LFIXProc* proc)
{
    (void) proc;
    // TODO: free l_proc and MMAddrSpace
}

LFIXProc*
lfix_proc_newfile(LFIXEngine* lfix, int fd, int argc, const char** argv)
{
    return procnewfile(lfix, fd, argc, argv);
}
