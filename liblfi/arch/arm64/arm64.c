#include <assert.h>

#include "lfi.h"

uint64_t*
lfi_regs_arg(LFIRegs* regs, int arg)
{
    switch (arg) {
    case 0:
        return &regs->x0;
    case 1:
        return &regs->x1;
    case 2:
        return &regs->x2;
    case 3:
        return &regs->x3;
    case 4:
        return &regs->x4;
    case 5:
        return &regs->x5;
    }
    assert(0);
}

uint64_t*
lfi_regs_ret(LFIRegs* regs)
{
    return &regs->x0;
}

uint64_t*
lfi_regs_sysno(LFIRegs* regs)
{
    return &regs->x8;
}

uint64_t*
lfi_regs_sysarg(LFIRegs* regs, int arg)
{
    return lfi_regs_arg(regs, arg);
}

uint64_t*
lfi_regs_sysret(LFIRegs* regs)
{
    return &regs->x0;
}

uint64_t*
lfi_regs_gas(LFIRegs* regs)
{
    return &regs->x23;
}

uint64_t*
lfi_regs_mask(LFIRegs* regs)
{
    return &regs->x24;
}
