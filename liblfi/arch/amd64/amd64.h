#pragma once

#include <assert.h>
#include <immintrin.h>
#include <stdlib.h>

#include "arch/amd64/regs.h"

static uint64_t r_tpidr() {
    return _readfsbase_u64();
}

static void w_tpidr(uint64_t val) {
    _writefsbase_u64(val);
}

static uint64_t regs_sysno(struct lfi_regs* regs) {
    return regs->rax;
}

static uint64_t regs_sysarg(struct lfi_regs* regs, int arg) {
    switch (arg) {
    case 0:
        return regs->rdi;
    case 1:
        return regs->rsi;
    case 2:
        return regs->rdx;
    case 3:
        return regs->r10;
    case 4:
        return regs->r8;
    case 5:
        return regs->r9;
    }
    assert(0);
}

static uint64_t* regs_sysret(struct lfi_regs* regs) {
    return &regs->rax;
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

static void regs_init(struct lfi_regs* regs, uint64_t entry, uint64_t sp) {
    regs->rsp = sp - 8;
    *((uint64_t*) regs->rsp) = entry;
}
