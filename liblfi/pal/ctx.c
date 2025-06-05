#include <assert.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "config.h"
#include "host.h"
#include "thread.h"
#include "pal/platform.h"
#include "pal/regs.h"

// context for injecting clone calls
pthread_mutex_t lfi_clonectx_lk = PTHREAD_MUTEX_INITIALIZER;
struct LFIContext* lfi_clonectx;
// for newly cloned thread contexts
_Thread_local struct LFIContext* lfi_newctx;

_Thread_local struct LFIContext* lfi_myctx;

#define asm __asm__

extern uint64_t lfi_ctx_entry(struct LFIContext* ctx, void** kstackp)
    asm ("lfi_ctx_entry");

extern void lfi_asm_ctx_exit(void* kstackp, uint64_t val)
    asm ("lfi_asm_ctx_exit");

static struct Sys*
sysalloc(struct LFIPlatform* plat, uintptr_t base)
{
    struct Sys* sys;
    if (plat->opts.sysexternal) {
        sys = malloc(sizeof(struct Sys));
        if (!sys)
            return NULL;
    } else {
        sys = host_mmap((void*) base, plat->opts.pagesize, LFI_PROT_READ | LFI_PROT_WRITE,
                LFI_MAP_PRIVATE | LFI_MAP_ANONYMOUS | LFI_MAP_FIXED, NULL, 0);
        if (sys == (void*) -1)
            return NULL;
    }
    return sys;
}

extern void lfi_syscall_entry(void)
    asm ("lfi_syscall_entry");
extern void lfi_get_tp(void)
    asm ("lfi_get_tp");
extern void lfi_set_tp(void)
    asm ("lfi_set_tp");
extern void lfi_ret(void)
    asm ("lfi_ret");

static void
syssetup(struct LFIPlatform* plat, struct Sys* sys, uintptr_t base)
{
    sys->rtcalls[0] = (uintptr_t) &lfi_syscall_entry;
    sys->rtcalls[1] = (uintptr_t) &lfi_get_tp;
    sys->rtcalls[2] = (uintptr_t) &lfi_set_tp;
    sys->rtcalls[3] = (uintptr_t) &lfi_ret;
    sys->base = base;
    // Only used in sysexternal mode (where there is a syspage per context)
    if (plat->opts.sysexternal)
        sys->ctxp = (uintptr_t) &lfi_myctx;
    int err = host_mprotect((void*) base, plat->opts.pagesize, LFI_PROT_READ);
    assert(err == 0);
}

EXPORT struct LFIContext*
lfi_ctx_new(struct LFIAddrSpace* as, void* ctxp, bool main)
{
#if defined(SYS_EXTERNAL)
    as->plat->opts.sysexternal = true;
#endif

    struct LFIContext* ctx = malloc(sizeof(struct LFIContext));
    if (!ctx)
        return NULL;

    struct Sys* sys;
    if (main || as->plat->opts.sysexternal) {
        sys = sysalloc(as->plat, as->base);
        if (!sys)
            goto err;
        syssetup(as->plat, sys, as->base);
    } else {
        sys = (struct Sys*) as->base;
    }

    *ctx = (struct LFIContext) {
        .ctxp = ctxp,
        .sys = sys,
        .as = as,
    };

    lfi_regs_init(&ctx->regs, as, ctx);

    return ctx;
err:
    free(ctx);
    return NULL;
}

EXPORT uint64_t
lfi_ctx_run(struct LFIContext* ctx, struct LFIAddrSpace* as)
{
    (void) as;
    lfi_myctx = ctx;

    uint64_t ret = lfi_ctx_entry(ctx, &ctx->kstackp);

    return ret;
}

EXPORT void
lfi_ctx_free(struct LFIContext* ctx)
{
    free(ctx);
}

EXPORT struct TuxRegs*
lfi_ctx_regs(struct LFIContext* ctx)
{
    return &ctx->regs;
}

EXPORT void*
lfi_ctx_data(struct LFIContext* ctx)
{
    return ctx->ctxp;
}

EXPORT void
lfi_ctx_exit(struct LFIContext* ctx, uint64_t val)
{
    lfi_myctx = NULL;
    lfi_asm_ctx_exit(ctx->kstackp, val);
}

EXPORT void
lfi_ctx_pause(struct LFIContext* ctx, uint64_t val)
{
    lfi_asm_ctx_exit(ctx->kstackp, val);
}

EXPORT void
lfi_ctx_tpset(struct LFIContext* ctx, lfiptr_t tp)
{
    ctx->tp = tp;
}

EXPORT struct LFIAddrSpace*
lfi_ctx_as(struct LFIContext* ctx)
{
    return ctx->as;
}

void
pal_register_clonectx(struct LFIContext* ctx)
{
    assert(lfi_clonectx == NULL);
    LOCK_WITH_DEFER(&lfi_clonectx_lk, lk);
    lfi_clonectx = ctx;
}

EXPORT void
lfi_thread_init(void (*thread_create)(void*), void* pausefn)
{
    // invoke sbx_thread_create(&_lfi_pause) with the clone context
    LOCK_WITH_DEFER(&lfi_clonectx_lk, lk);
    assert(lfi_myctx == NULL);
#ifdef SYS_EXTERNAL
    lfi_clonectx->sys->ctxp = (uintptr_t) &lfi_myctx;
#endif
    lfi_myctx = lfi_clonectx;
    thread_create(pausefn);
    lfi_myctx = lfi_newctx;
    lfi_newctx = NULL;
}

EXPORT bool
lfi_ctx_validptr(struct LFIContext* ctx, lfiptr_t ptr)
{
    return ptr >= ctx->as->minaddr && ptr < ctx->as->maxaddr;
}

EXPORT struct LFIContext*
lfi_get_myctx(void)
{
    return lfi_myctx;
}
