#include <assert.h>

#include "lfi.h"

uint64_t*
lfi_regs_arg(LFIRegs* regs, int arg)
{
    switch (arg) {
    case 0:
        return &regs->rdi;
    case 1:
        return &regs->rsi;
    case 2:
        return &regs->rdx;
    case 3:
        return &regs->rcx;
    case 4:
        return &regs->r8;
    case 5:
        return &regs->r9;
    }
    assert(0);
}

uint64_t*
lfi_regs_ret(LFIRegs* regs)
{
    return &regs->rax;
}

uint64_t*
lfi_regs_sysno(LFIRegs* regs)
{
    return &regs->rax;
}

uint64_t*
lfi_regs_sysarg(LFIRegs* regs, int arg)
{
    switch (arg) {
    case 0:
        return &regs->rdi;
    case 1:
        return &regs->rsi;
    case 2:
        return &regs->rdx;
    case 3:
        return &regs->r10;
    case 4:
        return &regs->r8;
    case 5:
        return &regs->r9;
    }
    assert(0);
}

uint64_t*
lfi_regs_sysret(LFIRegs* regs)
{
    return &regs->rax;
}

uint64_t*
lfi_regs_mask(LFIRegs* regs)
{
    return &regs->r15;
}

uint64_t*
lfi_regs_gas(LFIRegs* regs)
{
    (void) regs;
    return NULL;
}
