#pragma once

#include <assert.h>
#include <immintrin.h>
#include <stdlib.h>

#include "lfi.h"

static uint64_t
r_tpidr()
{
    return _readfsbase_u64();
}

static void
w_tpidr(uint64_t val)
{
    _writefsbase_u64(val);
}

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
    (void) regs;
    return NULL;
}

static void
regs_init(LFIRegs* regs, uint64_t entry, uint64_t sp)
{
    regs->rsp = sp - 8;
    *((uint64_t*) regs->rsp) = entry;
}
