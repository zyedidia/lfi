#pragma once

#include <assert.h>
#include <immintrin.h>
#include <stdlib.h>

#include "lfi.h"

static uint64_t r_tpidr() {
    return _readfsbase_u64();
}

static void w_tpidr(uint64_t val) {
    _writefsbase_u64(val);
}

static void wr_regs_base(struct lfi_regs* regs, uint64_t val) {
    regs->gs = val;
    regs->r14 = val;
}

static uint64_t* regs_addr(struct lfi_regs* regs, int n) {
    switch (n) {
    case 0:
        return &regs->rsp;
    }
    return NULL;
}

static uint64_t* regs_sys(struct lfi_regs* regs) {
    (void) regs;
    return NULL;
}

static uint64_t* regs_gas(struct lfi_regs* regs) {
    (void) regs;
    return NULL;
}

static uint64_t* regs_mask(struct lfi_regs* regs) {
    return &regs->r15;
}

static void regs_init(struct lfi_regs* regs, uint64_t entry, uint64_t sp) {
    regs->rsp = sp - 8;
    *((uint64_t*) regs->rsp) = entry;
}
