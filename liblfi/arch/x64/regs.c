#include <assert.h>

#include "arch_regs.h"

void
regs_init(struct TuxRegs* regs, lfiptr_t entry, lfiptr_t sp)
{
    regs->rsp = sp;
    // Assumes pal_ctx_entry will jump to %r11
    regs->r11 = entry;
}

uintptr_t*
regs_return(struct TuxRegs* regs)
{
    return &regs->rax;
}

uintptr_t*
regs_sp(struct TuxRegs* regs)
{
    return &regs->rsp;
}
