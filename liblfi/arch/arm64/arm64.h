#pragma once

#include "lfi.h"

static void
wr_regs_base(LFIRegs* regs, uint64_t val)
{
    regs->x21 = val;
}

static uint64_t*
regs_addr(LFIRegs* regs, int n)
{
    switch (n) {
    case 0:
        return &regs->x18;
    case 1:
        return &regs->sp;
    case 2:
        return &regs->x30;
    }
    return NULL;
}

static uint64_t*
regs_sys(LFIRegs* regs)
{
#ifdef SYSEXTERNAL
    return &regs->x25;
#else
    (void) regs;
    return NULL;
#endif
}
static void
regs_init(struct lfi_regs* regs, uint64_t entry, uint64_t sp)
{
    regs->x30 = entry;
    regs->sp = sp;
}
