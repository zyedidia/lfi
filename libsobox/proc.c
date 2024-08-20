#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

#include "sobox.h"
#include "proc.h"
#include "elf.h"

#include "stub/stub.inc"

static bool procsetup(SoboxProc* p, uint8_t* buf, size_t bufsize, int argc, const char** argv);
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
    int err = lfi_add_proc(sbx->lfimgr, &p->proc, p);
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
    uint8_t* buf = libsobox_stub_stub;
    size_t bufsize = libsobox_stub_stub_len;

    if (!procsetup(p, buf, bufsize, argc, argv))
        return false;

    return true;
}

static bool
stacksetup(SoboxProc* p, int argc, const char** argv, struct lfi_proc_info* info, uintptr_t* newsp)
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
procmapsetup(SoboxProc* p, uintptr_t mapstart, uintptr_t mapend)
{
    return mm_init(&p->mm, mapstart, mapend - mapstart, getpagesize());
}

static bool
procsetup(SoboxProc* p, uint8_t* buf, size_t bufsize, int argc, const char** argv)
{
    struct lfi_proc_info info;

    int r;
    char* ldfile = elfinterp(buf);
    if (ldfile) {
        // TODO: fix this
        ldfile = "/opt/lfi-amd64/x86_64-lfi-linux-musl/lib/ld-musl-x86_64.so.1";
        size_t ldsize;
        assert(p->sbx->readfile);
        uint8_t* ld = p->sbx->readfile(ldfile, &ldsize);
        if (!ld)
            return false;
        r = lfi_proc_exec_dyn(p->proc, (uint8_t*) buf, bufsize, (uint8_t*) ld, ldsize, &info);
        free(ld);
    } else {
        return false;
    }

    if (r < 0)
        return false;

    uintptr_t sp;
    if (!stacksetup(p, argc, argv, &info, &sp))
        return false;

    uintptr_t entry = info.elfentry;
    if (ldfile)
        entry = info.ldentry;

    lfi_proc_init_regs(p->proc, entry, sp);

    p->brkbase = info.lastva;
    p->brksize = 0;

    if (!procmapsetup(p, p->brkbase + BRKMAXSIZE, (uintptr_t) info.stack - getpagesize()))
        return false;

    return true;
}

static int
procmap(SoboxProc* p, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
{
    if (fd >= 0) {
        FDFile* f = fdget(&p->fdtable, fd);
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
procmapany(SoboxProc* p, size_t size, int prot, int flags, int fd, off_t offset, uintptr_t* o_mapstart)
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
procmapat(SoboxProc* p, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
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
procunmap(SoboxProc* p, uintptr_t start, size_t size)
{
    return mm_unmap_cb(&p->mm, start, size, cbunmap, NULL);
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
    struct lfi_regs* regs = lfi_proc_get_regs(proc->proc);
    regs->rdi = namelen + 1;
    uint64_t s_filename = lfi_invoke(proc->proc, proc->fns->malloc, proc->fns->ret);
    memcpy((void*) s_filename, filename, namelen);

    // call dlopen in the sandbox
    regs->rdi = s_filename;
    regs->rsi = 0;
    uint64_t handle = lfi_invoke(proc->proc, proc->fns->dlopen, proc->fns->ret);
    proc->libhandle = (void*) handle;

    regs->rdi = s_filename;
    lfi_invoke(proc->proc, proc->fns->free, proc->fns->ret);
    return proc;
}

void*
sbx_dlsymfn(void* handle, const char* symbol, const char* ty)
{
    (void) ty;
    SoboxProc* proc = (SoboxProc*) handle;

    // allocate the filename in the sandbox
    size_t symlen = strlen(symbol);
    struct lfi_regs* regs = lfi_proc_get_regs(proc->proc);
    regs->rdi = symlen + 1;

    uint64_t s_symbol = lfi_invoke(proc->proc, proc->fns->malloc, proc->fns->ret);
    memcpy((void*) s_symbol, symbol, symlen);

    regs->rdi = (uint64_t) proc->libhandle;
    regs->rsi = s_symbol;
    void* sym = (void*) lfi_invoke(proc->proc, proc->fns->dlsym, proc->fns->ret);

    regs->rdi = s_symbol;
    lfi_invoke(proc->proc, proc->fns->free, proc->fns->ret);

    return sym;
}

void*
sbx_malloc(void* handle, size_t size)
{
    SoboxProc* proc = (SoboxProc*) handle;
    struct lfi_regs* regs = lfi_proc_get_regs(proc->proc);
    regs->rdi = size;
    return (void*) lfi_invoke(proc->proc, proc->fns->malloc, proc->fns->ret);
}

void
sbx_free(void* handle, void* ptr)
{
    SoboxProc* proc = (SoboxProc*) handle;
    struct lfi_regs* regs = lfi_proc_get_regs(proc->proc);
    regs->rdi = (uint64_t) ptr;
    lfi_invoke(proc->proc, proc->fns->free, proc->fns->ret);
}

// this function is temporary and will be removed in a future version
uint64_t
sbx_dlinvoke(void* handle, void* symbol, uint64_t a0, uint64_t a1)
{
    SoboxProc* proc = (SoboxProc*) handle;
    struct lfi_regs* regs = lfi_proc_get_regs(proc->proc);
    regs->rdi = a0;
    regs->rsi = a1;
    return lfi_invoke(proc->proc, symbol, proc->fns->ret);
}
