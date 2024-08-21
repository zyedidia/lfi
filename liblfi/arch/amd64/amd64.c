#include <assert.h>

#include "lfi.h"

uint64_t* regs_arg(struct lfi_regs* regs, int arg) {
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

uint64_t* regs_ret(struct lfi_regs* regs) {
    return &regs->rax;
}

uint64_t* regs_sysno(struct lfi_regs* regs) {
    return &regs->rax;
}

uint64_t* regs_sysarg(struct lfi_regs* regs, int arg) {
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

uint64_t* regs_sysret(struct lfi_regs* regs) {
    return &regs->rax;
}
