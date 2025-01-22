#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "lfi_arch.h"
#include "lfi_host.h"

enum {
    LFI_MAP_SHARED    = 1,
    LFI_MAP_PRIVATE   = 2,
    LFI_MAP_FIXED     = 16,
    LFI_MAP_ANONYMOUS = 32,
    LFI_MAP_DENYWRITE = 2048,
    LFI_MAP_NORESERVE = 16384,
};

enum {
    LFI_PROT_NONE  = 0,
    LFI_PROT_READ  = 1,
    LFI_PROT_WRITE = 2,
    LFI_PROT_EXEC  = 4,
};

struct LFIPlatform;

struct LFIPlatform* lfi_new_plat(size_t pagesize);

struct LFIAddrSpace;

struct LFIContext;

struct LFIPlatform;

typedef uintptr_t lfiptr_t;

struct LFIAddrSpaceInfo {
    lfiptr_t base;
    size_t size;

    lfiptr_t minaddr;
    lfiptr_t maxaddr;
};

struct LFILoadInfo {
    lfiptr_t stack;
    size_t stacksize;
    lfiptr_t lastva;
    lfiptr_t elfentry;
    lfiptr_t ldentry;
    lfiptr_t elfbase;
    lfiptr_t ldbase;
    uint64_t elfphoff;
    uint16_t elfphnum;
    uint16_t elfphentsize;
};

typedef void (*SysHandlerFn)(struct LFIContext* ctx);

struct LFIAddrSpace*    lfi_as_new(struct LFIPlatform* plat);
struct LFIAddrSpaceInfo lfi_as_info(struct LFIAddrSpace* as);

lfiptr_t                lfi_as_mapat(struct LFIAddrSpace* as, lfiptr_t addr, size_t size, int prot, int flags, struct HostFile* f, off_t off);
lfiptr_t                lfi_as_mapany(struct LFIAddrSpace* as, size_t size, int prot, int flags, struct HostFile* f, off_t off);
int                     lfi_as_munmap(struct LFIAddrSpace* as, lfiptr_t addr, size_t size);
int                     lfi_as_mprotect(struct LFIAddrSpace* as, lfiptr_t addr, size_t size, int prot);
void                    lfi_as_copyfm(struct LFIAddrSpace* as, void* dst, lfiptr_t src, size_t size);
void                    lfi_as_copyto(struct LFIAddrSpace* as, lfiptr_t dst, void* src, size_t size);
void                    lfi_as_free(struct LFIAddrSpace* as);
lfiptr_t                lfi_as_toptr(struct LFIAddrSpace* as, void* p);
void*                   lfi_as_fmptr(struct LFIAddrSpace* as, lfiptr_t lp);
lfiptr_t                lfi_as_validptr(struct LFIAddrSpace* as, lfiptr_t lp);

struct LFIContext*      lfi_ctx_new(struct LFIAddrSpace* as, void* ctxp, bool mainthread);
uint64_t                lfi_ctx_run(struct LFIContext* ctx, struct LFIAddrSpace* as);
void*                   lfi_ctx_data(struct LFIContext* ctx);
void                    lfi_ctx_free(struct LFIContext* ctx);
struct TuxRegs*         lfi_ctx_regs(struct LFIContext* ctx);
void                    lfi_ctx_exit(struct LFIContext* ctx, uint64_t val);
void                    lfi_ctx_pause(struct LFIContext* ctx, uint64_t val);
void                    lfi_ctx_tpset(struct LFIContext* ctx, lfiptr_t tp);
struct LFIAddrSpace*    lfi_ctx_as(struct LFIContext* ctx);

void                    lfi_sys_handler(struct LFIPlatform* plat, SysHandlerFn fn);

struct LFILoadOpts {
    size_t stacksize;
    size_t pagesize;
    bool perf;
};

bool                    lfi_proc_loadelf(struct LFIAddrSpace* as, uint8_t* prog, size_t progsz, uint8_t* interp, size_t interpsz, struct LFILoadInfo* o_info, struct LFILoadOpts opts);
bool                    lfi_proc_init(struct LFIContext* ctx, struct LFIAddrSpace* as, struct LFILoadInfo info);

char* lfi_strerror(void);
