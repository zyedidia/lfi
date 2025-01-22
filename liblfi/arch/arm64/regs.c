#include <assert.h>

#include "arch_regs.h"

void
regs_init(struct TuxRegs* regs, lfiptr_t entry, lfiptr_t sp)
{
    regs->sp = sp;
    regs->x30 = entry;
}

uintptr_t*
regs_return(struct TuxRegs* regs)
{
    return (uintptr_t*) &regs->x0;
}

uintptr_t*
regs_sp(struct TuxRegs* regs)
{
    return (uintptr_t*) &regs->sp;
}
