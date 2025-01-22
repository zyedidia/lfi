#include "lfi_arch.h"
#include "pal/platform.h"

EXPORT void
lfi_regs_init(struct TuxRegs* regs, struct LFIAddrSpace* as, struct LFIContext* ctx)
{
    regs->r14 = as->base;
    regs->gs  = as->base;
    regs->rsp = as->base;
    regs->r13 = (uintptr_t) ctx->sys;
}
