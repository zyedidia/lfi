#include "lfi_arch.h"
#include "pal/platform.h"
#include "pal/arch/arm64/regs.h"

EXPORT void
lfi_regs_init(struct TuxRegs* regs, struct LFIAddrSpace* as, struct LFIContext* ctx)
{
    regs->REG_BASE = as->base;
    regs->REG_ADDR = as->base;
    regs->sp = as->base;
    regs->x30 = as->base;
    regs->REG_SYS = (uintptr_t) ctx->sys;
}

EXPORT void
lfi_ctx_init_sys(struct LFIContext* ctx)
{
    if (ctx->as->plat->opts.sysexternal)
        ctx->regs.REG_SYS = (uintptr_t) ctx->sys;
}

uintptr_t*
lfi_regs_entry(struct TuxRegs* regs)
{
    return (uintptr_t*) &regs->x30;
}

uintptr_t*
lfi_regs_arg0(struct TuxRegs* regs)
{
    return (uintptr_t*) &regs->x0;
}
