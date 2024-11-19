#pragma once

#include <assert.h>
#include <stdlib.h>

#include "lfi.h"

static void
wr_regs_base(LFIRegs* regs, uint64_t val)
{
    regs->gs = val;
    regs->r14 = val;
}

static uint64_t*
regs_addr(LFIRegs* regs, int n)
{
    switch (n) {
    case 0:
        return &regs->rsp;
    }
    return NULL;
}

static uint64_t*
regs_sys(LFIRegs* regs)
{
    return &regs->r13;
}

static void
regs_init(LFIRegs* regs, uint64_t entry, uint64_t sp)
{
    regs->rsp = sp - 8;
    *((uint64_t*) regs->rsp) = entry;
}
