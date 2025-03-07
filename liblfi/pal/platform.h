#pragma once

#include <assert.h>

#include "lfiv.h"
#include "lfi.h"
#include "lfi_arch.h"
#include "mmap.h"
#include "boxmap.h"
#include "types.h"

struct LFIPlatform {
    struct BoxMap* bm;
    struct LFIPlatOptions opts;
    LFIVerifier* verifier;
    SysHandlerFn syshandler;
};

struct LFIAddrSpace {
    uintptr_t base;
    size_t size;
    uintptr_t minaddr;
    uintptr_t maxaddr;

    MMAddrSpace mm;

    struct LFIPlatform* plat;
};

struct Sys {
    uintptr_t rtcalls[256];
    uintptr_t base;
    uintptr_t ctx;
};

struct LFIContext {
    void* kstackp;
    uintptr_t tp;
    struct TuxRegs regs;
    void* ctxp;
    struct Sys* sys;
    struct LFIAddrSpace* as;
};

static inline size_t
gb(size_t x)
{
    return x * 1024 * 1024 * 1024;
}

static inline size_t
kb(size_t x)
{
    return x * 1024;
}

_Thread_local extern struct LFIContext* lfi_myctx;

_Thread_local extern struct LFIContext* lfi_newctx;

extern struct LFIContext* lfi_clonectx;

void pal_register_clonectx(struct LFIContext* ctx);

static inline uintptr_t
l2p(struct LFIAddrSpace* as, lfiptr_t l)
{
    if (as->plat->opts.poc) {
        assert(as->plat->opts.vmsize == gb(4));
        return as->base | (uintptr_t) l;
    }
    return (uintptr_t) l;
}

static inline lfiptr_t
p2l(struct LFIAddrSpace* as, uintptr_t p)
{
    if (as->plat->opts.poc) {
        assert(as->plat->opts.vmsize == gb(4));
        return (lfiptr_t) ((uint32_t) p);
    }
    return (lfiptr_t) p;
}
