#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "sobox.h"
#include "lib.h"
#include "elf.h"

#include "stub/stub.inc"

static bool libsetup(SoboxLib* l, uint8_t* buf, size_t bufsize, int argc, const char** argv);
static bool libfile(SoboxLib* l, int argc, const char** argv);
static void libfree(SoboxLib*);

uintptr_t
libaddr(SoboxLib* lib, uintptr_t addr)
{
    return ((uint32_t) addr) | lib->base;
}

uintptr_t
libuseraddr(SoboxLib* lib, uintptr_t addr)
{
    return libaddr(lib, addr);
}

static SoboxLib*
libnewempty()
{
    SoboxLib* l = malloc(sizeof(SoboxLib));
    if (!l)
        return NULL;
    *l = (SoboxLib){0};
    return l;
}

static SoboxLib*
libnewfile(Sobox* sbx, int argc, const char** argv)
{
    SoboxLib* l = libnewempty();
    if (!l)
        return NULL;
    l->sbx = sbx;
    int err = lfi_add_proc(sbx->lfimgr, &l->proc, l);
    if (err < 0)
        goto err;
    l->base = lfi_proc_base(l->proc);

    if (!libfile(l, argc, argv))
        return NULL;
    fdinit(&l->fdtable);
    return l;
err:
    libfree(l);
    return NULL;
}

static bool
libfile(SoboxLib* l, int argc, const char** argv)
{
    uint8_t* buf = libsobox_stub_stub;
    size_t bufsize = libsobox_stub_stub_len;

    if (!libsetup(l, buf, bufsize, argc, argv))
        return false;

    return true;
}

static bool
stacksetup(SoboxLib* l, int argc, const char** argv, struct lfi_proc_info* info, uintptr_t* newsp)
{
    // TODO: do we actually want to support argc/argv? Technically not
    // necessary for libraries since they are not used by the stub.
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
    *av++ = (Auxv) { AT_BASE, libuseraddr(l, info->ldbase) };
    *av++ = (Auxv) { AT_PHDR, libuseraddr(l, info->elfbase + info->elfphoff) };
    *av++ = (Auxv) { AT_PHNUM, info->elfphnum };
    *av++ = (Auxv) { AT_PHENT, info->elfphentsize };
    *av++ = (Auxv) { AT_ENTRY, libuseraddr(l, info->elfentry) };
    *av++ = (Auxv) { AT_EXECFN, libuseraddr(l, (uintptr_t) p_argvp[0]) };
    *av++ = (Auxv) { AT_PAGESZ, getpagesize() };
    *av++ = (Auxv) { AT_HWCAP, 0 };
    *av++ = (Auxv) { AT_HWCAP2, 0 };
    *av++ = (Auxv) { AT_RANDOM, libuseraddr(l, info->elfentry) }; // TODO
    *av++ = (Auxv) { AT_FLAGS, 0 };
    *av++ = (Auxv) { AT_UID, 1000 };
    *av++ = (Auxv) { AT_EUID, 1000 };
    *av++ = (Auxv) { AT_GID, 1000 };
    *av++ = (Auxv) { AT_EGID, 1000 };
    *av++ = (Auxv) { AT_NULL, 0 };

    return true;
}

static bool
libsetup(SoboxLib* l, uint8_t* buf, size_t bufsize, int argc, const char** argv)
{
    struct lfi_proc_info info;

    int r;
    char* ldfile = elfinterp(buf);
    if (ldfile) {
        // TODO: fix this
        ldfile = "/opt/lfi-amd64/x86_64-lfi-linux-musl/lib/ld-musl-x86_64.so.1";
        size_t ldsize;
        assert(l->sbx->readfile);
        uint8_t* ld = l->sbx->readfile(ldfile, &ldsize);
        if (!ld)
            return false;
        r = lfi_proc_exec_dyn(l->proc, (uint8_t*) buf, bufsize, (uint8_t*) ld, ldsize, &info);
        free(ld);
    } else {
        return false;
    }

    if (r < 0)
        return false;

    uintptr_t sp;
    if (!stacksetup(l, argc, argv, &info, &sp))
        return false;

    uintptr_t entry = info.elfentry;
    if (ldfile)
        entry = info.ldentry;

    lfi_proc_init_regs(l->proc, entry, sp);

    // TODO: map setup

    return true;
}

static void libfree(SoboxLib* lib)
{
    (void) lib;
    // TODO
}

SoboxLib*
sbx_dlopen(Sobox* sbx, const char* filename, int flags)
{
    SoboxLib* lib = libnewfile(sbx, 0, NULL);
    if (!lib)
        return NULL;
    int code = lfi_proc_start(lib->proc);
    printf("library stub exited with code %d\n", code);
    return lib;
}
