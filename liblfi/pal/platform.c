#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

#include "lfi.h"
#include "pal/platform.h"

#define asm __asm__

EXPORT struct LFIPlatform*
lfi_new_plat(size_t pagesize)
{
    struct PlatOptions opts = (struct PlatOptions) {
        .pagesize = pagesize,
        .vmsize = gb(4),
    };
    struct LFIPlatform* plat = malloc(sizeof(struct LFIPlatform));
    if (!plat)
        return NULL;

    struct BoxMap* bm = boxmap_new((struct BoxMapOptions) {
        .minalign = gb(4),
        .maxalign = gb(4),
        .guardsize = 0,
    });
    if (!bm)
        goto err1;
    if (!boxmap_reserve(bm, gb(256)))
        goto err2;

    *plat = (struct LFIPlatform) {
        .bm = bm,
        .opts = opts,
    };
    return plat;

err2:
    boxmap_delete(bm);
err1:
    free(plat);
    return NULL;
}

EXPORT void
lfi_sys_handler(struct LFIPlatform* plat, SysHandlerFn fn)
{
    plat->syshandler = fn;
}

void lfi_syscall_handler(struct LFIContext* ctx)
    asm ("lfi_syscall_handler");

EXPORT void
lfi_syscall_handler(struct LFIContext* ctx)
{
    assert(ctx->as->plat->syshandler && "platform does not have a system call handler");
    ctx->as->plat->syshandler(ctx);
}
