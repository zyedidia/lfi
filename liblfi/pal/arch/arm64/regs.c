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
