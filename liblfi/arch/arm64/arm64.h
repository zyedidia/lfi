#pragma once

#include "lfi.h"

static inline void
wr_regs_base(LFIRegs* regs, uint64_t val)
{
    regs->x21 = val;
}

static inline uint64_t*
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

static inline uint64_t*
regs_sys(LFIRegs* regs)
{
    return &regs->x25;
}

static inline uint64_t*
regs_sp(LFIRegs* regs, int n)
{
    return &regs->sp;
}

static inline void
regs_init(LFIRegs* regs, uint64_t entry, uint64_t sp)
{
    regs->x30 = entry;
    regs->sp = sp;
}
