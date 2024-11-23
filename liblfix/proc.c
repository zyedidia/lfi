// for O_PATH
#define _GNU_SOURCE

#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include <sys/mman.h>

#include "lfix.h"
#include "elf.h"
#include "proc.h"
#include "io.h"
#include "fd.h"

#include "cwalk/cwalk.h"

static bool procsetup(LFIXProc* p, uint8_t* prog, size_t progsz, uint8_t* interp, size_t interpsz, int argc, char** argv);
static bool procfile(LFIXProc* p, uint8_t* prog, size_t progsz, int argc, char** argv);
static void procfree(LFIXProc*);

uintptr_t
procaddr(LFIXProc* proc, uintptr_t addr)
{
    return ((uint32_t) addr) | proc->base;
}

uintptr_t
procuseraddr(LFIXProc* proc, uintptr_t addr)
{
    if (proc->lfix->poc)
        return (uintptr_t) ((uint32_t) addr);
    return procaddr(proc, addr);
}

// unused for now
static inline bool
cwdcopy(Cwd* cwd, Cwd* to)
{
    int fd = open(cwd->name, O_DIRECTORY | O_PATH);
    if (fd < 0)
        return false;
    memcpy(to->name, cwd->name, LFI_PATH_MAX);
    to->fd = fd;
    return true;
}

static LFIXProc*
procnewempty()
{
    LFIXProc* p = malloc(sizeof(LFIXProc));
    if (!p)
        return NULL;
    *p = (LFIXProc){0};
    p->cwd.fd = AT_FDCWD;
    char* cwd = getcwd(p->cwd.name, LFI_PATH_MAX);
    if (!cwd) {
        free(p);
        return NULL;
    }
    return p;
}

static LFIXProc*
procnewfile(LFIXEngine* lfix, uint8_t* prog, size_t progsz, int argc, char** argv)
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

    if (!procfile(p, prog, progsz, argc, argv))
        goto err;
    lfix_fdinit(&p->fdtable);
    return p;
err:
    procfree(p);
    return NULL;
}

static bool
procfile(LFIXProc* p, uint8_t* prog, size_t progsz, int argc, char** argv)
{
    char* interppath = elfinterp(prog, progsz);
    Buf interp = (Buf){NULL, 0};
    if (interppath) {
        if (p->lfix->readfile && p->lfix->readfile(interppath, &interp.data, &interp.size)) {
            // good
        } else {
            interp = bufreadfile(interppath);
        }
        if (!interp.data) {
            fprintf(stderr, "error opening dynamic linker %s: %s\n", interppath, strerror(errno));
            free(interppath);
            return false;
        }
        free(interppath);
    }

    bool success = true;
    if (!procsetup(p, prog, progsz, interp.data, interp.size, argc, argv))
        success = false;

    return success;
}

enum {
    ARGC_MAX = 1024,
    ARGV_MAX = 1024,

    ARG_BLOCK = 4096,
};

static bool
stacksetup(LFIXProc* p, int argc, char** argv, LFIProcInfo* info, uintptr_t* newsp)
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
procsetup(LFIXProc* p, uint8_t* prog, size_t progsz, uint8_t* interp, size_t interpsz, int argc, char** argv)
{
    LFIProcInfo info = {0};
    bool b = lfi_proc_loadelf(p->l_proc, prog, progsz, interp, interpsz, &info);
    if (!b)
        return false;

    uintptr_t sp;
    if (!stacksetup(p, argc, argv, &info, &sp))
        return false;

    uintptr_t entry = info.elfentry;
    if (interp != NULL)
        entry = info.ldentry;

    lfi_proc_init(p->l_proc, entry, sp);

    p->brkbase = info.lastva;
    p->brksize = 0;

    // Reserve the brk region.
    const int mapflags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED;
    void* brkregion = lfi_proc_mapat(p->l_proc, p->brkbase, BRKMAXSIZE, PROT_NONE, mapflags, -1, 0);
    if (brkregion == (void*) -1)
        return false;

    return true;
}

int
procmapany(LFIXProc* p, size_t size, int prot, int flags, int fd, off_t offset, uintptr_t* o_mapstart)
{
    if (fd >= 0) {
        FDFile* f = lfix_fdget(&p->fdtable, fd);
        if (!f)
            return -EBADF;
        if (!f->mapfd)
            return -EACCES;
        fd = f->mapfd(f->dev);
    }
    void* addr = lfi_proc_mapany(p->l_proc, size, prot, flags, fd, offset);
    if (addr == (void*) -1)
        return -EINVAL;
    *o_mapstart = (uintptr_t) addr;
    return 0;
}

int
procmapat(LFIXProc* p, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
{
    if (fd >= 0) {
        FDFile* f = lfix_fdget(&p->fdtable, fd);
        if (!f)
            return -EBADF;
        if (!f->mapfd)
            return -EACCES;
        fd = f->mapfd(f->dev);
    }
    void* addr = lfi_proc_mapat(p->l_proc, start, size, prot, flags, fd, offset);
    if (addr == (void*) -1)
        return -EINVAL;
    return 0;
}

int
procunmap(LFIXProc* p, uintptr_t start, size_t size)
{
    return lfi_proc_munmap(p->l_proc, start, size);
}

static void
procfree(LFIXProc* proc)
{
    (void) proc;
    // TODO: free l_proc
}

LFIXProc*
lfix_proc_newfile(LFIXEngine* lfix, uint8_t* prog, size_t progsz, int argc, char** argv)
{
    return procnewfile(lfix, prog, progsz, argc, argv);
}

int
procchdir(LFIXProc* p, const char* path)
{
    int fd = openat(p->cwd.fd, path, O_DIRECTORY | O_PATH);
    if (fd < 0)
        return fd;
    if (p->cwd.fd >= 0)
        close(p->cwd.fd);

    char buffer[LFI_PATH_MAX];
    if (!cwk_path_is_absolute(path)) {
        cwk_path_join(p->cwd.name, path, buffer, LFI_PATH_MAX);
        path = buffer;
    }
    strncpy(p->cwd.name, path, LFI_PATH_MAX);
    p->cwd.fd = fd;
    return 0;
}
