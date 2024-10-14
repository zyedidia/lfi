#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

#include "sobox.h"
#include "proc.h"
#include "elf.h"
#include "io.h"

#include "stub/stub.inc"

static bool procsetup(SoboxProc* p, uint8_t* buf, size_t bufsize, uint8_t* interp, size_t interpsz, int argc, const char** argv);
static bool procfile(SoboxProc* p, int argc, const char** argv);
static void procfree(SoboxProc*);

uintptr_t
procaddr(SoboxProc* proc, uintptr_t addr)
{
    return ((uint32_t) addr) | proc->base;
}

uintptr_t
procuseraddr(SoboxProc* proc, uintptr_t addr)
{
    return procaddr(proc, addr);
}

static SoboxProc*
procnewempty()
{
    SoboxProc* p = malloc(sizeof(SoboxProc));
    if (!p)
        return NULL;
    *p = (SoboxProc){0};
    return p;
}

static SoboxProc*
procnewfile(Sobox* sbx, int argc, const char** argv)
{
    SoboxProc* p = procnewempty();
    if (!p)
        return NULL;
    p->sbx = sbx;
    int err = lfi_addproc(sbx->lfimgr, &p->proc, p);
    if (err < 0)
        goto err;
    p->base = lfi_proc_base(p->proc);

    if (!procfile(p, argc, argv))
        return NULL;
    fdinit(&p->fdtable);
    return p;
err:
    procfree(p);
    return NULL;
}

static bool
procfile(SoboxProc* p, int argc, const char** argv)
{
    uint8_t* prog = libsobox_stub_stub;
    size_t progsz = libsobox_stub_stub_len;

    int interpfd = -1;
    char* interppath = elfinterp(prog, progsz);
    Buf interp = (Buf){NULL, 0};
    if (interppath) {
        interp = bufreadfile(interppath);
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

    if (interpfd >= 0)
        close(interpfd);

    return success;
}

static bool
stacksetup(SoboxProc* p, int argc, const char** argv, LFIProcInfo* info, uintptr_t* newsp)
{
    // TODO: do we actually want to support argc/argv? Technically not
    // necessary for procraries since they are not used by the stub.
    argc = 1;

    void* stack_top = info->stack + info->stacksize;
    memcpy(stack_top - 1024, "stub", strlen("stub") + 1);
    long* p_argc = (long*) (stack_top - 4096);
    *newsp = (uintptr_t) p_argc;
    *p_argc++ = argc;
    char** p_argvp = (char**) p_argc;
    p_argvp[0] = stack_top - 1024;
    p_argvp[1] = NULL;

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
procsetup(SoboxProc* p, uint8_t* buf, size_t bufsize, uint8_t* interp, size_t interpsz, int argc, const char** argv)
{
    LFIProcInfo info = {0};
    bool b = lfi_proc_loadelf(p->proc, buf, bufsize, interp, interpsz, &info);
    if (!b)
        return false;

    uintptr_t sp;
    if (!stacksetup(p, argc, argv, &info, &sp))
        return false;

    uintptr_t entry = info.elfentry;
    if (interp != NULL)
        entry = info.ldentry;

    lfi_proc_init(p->proc, entry, sp);

    p->brkbase = info.lastva;
    p->brksize = 0;

    // Reserve the brk region.
    const int mapflags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED;
    void* brkregion = lfi_proc_mapat(p->proc, p->brkbase, BRKMAXSIZE, PROT_NONE, mapflags, -1, 0);
    if (brkregion == (void*) -1)
        return false;

    return true;
}

int
procmapany(SoboxProc* p, size_t size, int prot, int flags, int fd, off_t offset, uintptr_t* o_mapstart)
{
    if (fd >= 0) {
        FDFile* f = fdget(&p->fdtable, fd);
        if (!f)
            return -EBADF;
        if (!f->mapfd)
            return -EACCES;
        fd = f->mapfd(f->dev);
    }
    void* addr = lfi_proc_mapany(p->proc, size, prot, flags, fd, offset);
    if (addr == (void*) -1)
        return -EINVAL;
    *o_mapstart = (uintptr_t) addr;
    return 0;
}

int
procmapat(SoboxProc* p, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
{
    if (fd >= 0) {
        FDFile* f = fdget(&p->fdtable, fd);
        if (!f)
            return -EBADF;
        if (!f->mapfd)
            return -EACCES;
        fd = f->mapfd(f->dev);
    }
    void* addr = lfi_proc_mapat(p->proc, start, size, prot, flags, fd, offset);
    if (addr == (void*) -1)
        return -EINVAL;
    return 0;
}

int
procunmap(SoboxProc* p, uintptr_t start, size_t size)
{
    return lfi_proc_munmap(p->proc, start, size);
}

static void
procfree(SoboxProc* proc)
{
    (void) proc;
    // TODO
}

void*
sbx_dlopen(Sobox* sbx, const char* filename, int flags)
{
    SoboxProc* proc = procnewfile(sbx, 0, NULL);
    if (!proc)
        return NULL;
    int code = lfi_proc_start(proc->proc);
    assert(code == 0);
    assert(proc->fns);

    // allocate the filename in the sandbox
    size_t namelen = strlen(filename);
    LFIRegs* regs = lfi_proc_regs(proc->proc);
    *lfi_regs_arg(regs, 0) = namelen + 1;
    uint64_t s_filename = lfi_proc_invoke(proc->proc, proc->fns->malloc, proc->fns->ret);
    memcpy((void*) s_filename, filename, namelen);

    // call dlopen in the sandbox
    *lfi_regs_arg(regs, 0) = s_filename;
    *lfi_regs_arg(regs, 1) = 0;
    uint64_t handle = lfi_proc_invoke(proc->proc, proc->fns->dlopen, proc->fns->ret);
    proc->libhandle = (void*) handle;

    *lfi_regs_arg(regs, 0) = s_filename;
    lfi_proc_invoke(proc->proc, proc->fns->free, proc->fns->ret);
    return proc;
}

void*
sbx_dlsymfn(void* handle, const char* symbol, const char* ty)
{
    (void) ty;
    SoboxProc* proc = (SoboxProc*) handle;

    // allocate the filename in the sandbox
    size_t symlen = strlen(symbol);
    LFIRegs* regs = lfi_proc_regs(proc->proc);
    *lfi_regs_arg(regs, 0) = symlen + 1;

    uint64_t s_symbol = lfi_proc_invoke(proc->proc, proc->fns->malloc, proc->fns->ret);
    memcpy((void*) s_symbol, symbol, symlen);

    *lfi_regs_arg(regs, 0) = (uint64_t) proc->libhandle;
    *lfi_regs_arg(regs, 1) = s_symbol;
    void* sym = (void*) lfi_proc_invoke(proc->proc, proc->fns->dlsym, proc->fns->ret);

    *lfi_regs_arg(regs, 0) = s_symbol;
    lfi_proc_invoke(proc->proc, proc->fns->free, proc->fns->ret);

    return sym;
}

void*
sbx_malloc(void* handle, size_t size)
{
    SoboxProc* proc = (SoboxProc*) handle;
    LFIRegs* regs = lfi_proc_regs(proc->proc);
    *lfi_regs_arg(regs, 0) = size;
    return (void*) lfi_proc_invoke(proc->proc, proc->fns->malloc, proc->fns->ret);
}

void
sbx_free(void* handle, void* ptr)
{
    SoboxProc* proc = (SoboxProc*) handle;
    LFIRegs* regs = lfi_proc_regs(proc->proc);
    *lfi_regs_arg(regs, 0) = (uint64_t) ptr;
    lfi_proc_invoke(proc->proc, proc->fns->free, proc->fns->ret);
}

// this function is temporary and will be removed in a future version
uint64_t
sbx_dlinvoke(void* handle, void* symbol, uint64_t a0, uint64_t a1)
{
    SoboxProc* proc = (SoboxProc*) handle;
    LFIRegs* regs = lfi_proc_regs(proc->proc);
    *lfi_regs_arg(regs, 0) = a0;
    *lfi_regs_arg(regs, 1) = a1;
    return lfi_proc_invoke(proc->proc, symbol, proc->fns->ret);
}
