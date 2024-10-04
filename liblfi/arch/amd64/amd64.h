#pragma once

#include <assert.h>
#include <stdlib.h>

#include "lfi.h"

static inline void
wr_regs_base(LFIRegs* regs, uint64_t val)
{
    regs->gs = val;
    regs->r14 = val;
}

static inline uint64_t*
regs_addr(LFIRegs* regs, int n)
{
    switch (n) {
    case 0:
        return &regs->rsp;
    }
    return NULL;
}

static inline uint64_t*
regs_sys(LFIRegs* regs)
{
    (void) regs;
    return NULL;
}

static inline uint64_t*
regs_sp(LFIRegs* regs)
{
    return &regs->rsp;
}

static inline void
regs_init(LFIRegs* regs, uint64_t entry, uint64_t sp)
{
    regs->rsp = sp;
    regs->r11 = entry;
    // *((uint64_t*) regs->rsp) = entry;
}
