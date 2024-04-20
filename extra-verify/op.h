#pragma once

#include <capstone/capstone.h>

static inline bool is_lo(aarch64_reg reg) {
    switch (reg) {
    case AArch64_REG_W0:
    case AArch64_REG_W1:
    case AArch64_REG_W2:
    case AArch64_REG_W3:
    case AArch64_REG_W4:
    case AArch64_REG_W5:
    case AArch64_REG_W6:
    case AArch64_REG_W7:
    case AArch64_REG_W8:
    case AArch64_REG_W9:
    case AArch64_REG_W10:
    case AArch64_REG_W11:
    case AArch64_REG_W12:
    case AArch64_REG_W13:
    case AArch64_REG_W14:
    case AArch64_REG_W15:
    case AArch64_REG_W16:
    case AArch64_REG_W17:
    case AArch64_REG_W18:
    case AArch64_REG_W19:
    case AArch64_REG_W20:
    case AArch64_REG_W21:
    case AArch64_REG_W22:
    case AArch64_REG_W23:
    case AArch64_REG_W24:
    case AArch64_REG_W25:
    case AArch64_REG_W26:
    case AArch64_REG_W27:
    case AArch64_REG_W28:
    case AArch64_REG_W29:
    case AArch64_REG_W30:
        return true;
    default:
        return false;
    }
}

static inline bool is_uxtw(cs_aarch64_op* op) {
    if (op->shift.value == 0 && op->ext == AArch64_EXT_UXTW) {
        return true;
    }
    return false;
}

static inline bool is_indbranch(cs_insn* insn) {
    switch (insn->id) {
    case AArch64_INS_BLR:
    case AArch64_INS_RET:
    case AArch64_INS_BR:
        return true;
    default:
        return false;
    }
}
