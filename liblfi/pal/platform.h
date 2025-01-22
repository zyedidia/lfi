#pragma once

#include "lfi.h"
#include "lfi_arch.h"
#include "mmap.h"
#include "boxmap.h"
#include "types.h"

struct PlatOptions {
    size_t pagesize;
    size_t vmsize;
    bool sysexternal;
};

struct LFIPlatform {
    struct BoxMap* bm;
    struct PlatOptions opts;
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

_Thread_local extern struct LFIContext* lfi_myctx;
