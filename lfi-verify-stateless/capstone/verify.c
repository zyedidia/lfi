#include "op.h"
#include "verify.h"

enum {
    BASE_REG = AArch64_REG_X21,
};

static bool add_uxtw(cs_insn* insn, cs_detail* detail) {
    if (insn->id != AArch64_INS_ADD)
        return false;
    if (detail->aarch64.op_count != 4)
        return false;
    if (detail->aarch64.operands[1].reg != BASE_REG)
        return false;
    if (!is_uxtw(&detail->aarch64.operands[3]))
        return false;
    return true;
}

static bool fixed_reg(aarch64_reg reg) {
    switch (reg) {
    case AArch64_REG_X21:
    case AArch64_REG_W21:
    case AArch64_REG_X22:
    case AArch64_REG_W23:
    case AArch64_REG_W24:
    case AArch64_REG_W30:
    case AArch64_REG_SP:
    case AArch64_REG_WSP:
        return true;
    default:
        return false;
    }
}

static bool addr_reg(aarch64_reg reg) {
    switch (reg) {
    case AArch64_REG_X18:
    case AArch64_REG_X23:
    case AArch64_REG_X24:
    case AArch64_REG_X30:
    case AArch64_REG_SP:
        return true;
    default:
        return false;
    }
}

static bool legal_msr(aarch64_sysreg reg) {
    switch (reg) {
    case AArch64_SYSREG_TPIDR_EL0:
    case AArch64_SYSREG_FPSR:
    case AArch64_SYSREG_FPCR:
        return true;
    default:
        return false;
    }
}

// Check that register modifications are legal.
static bool check_mod(csh handle, cs_insn* insn) {
    cs_detail* detail = insn->detail;
    uint8_t regs_read_count, regs_write_count;
    cs_regs regs_read, regs_write;
    cs_regs_access(handle, insn, regs_read, &regs_read_count, regs_write, &regs_write_count);
    for (int i = 0; i < regs_write_count; i++) {
        aarch64_reg reg = regs_write[i];
        if (fixed_reg(reg)) {
            return false;
        }
        if (addr_reg(reg)) {
            // can only modify with add dst, x21, src, uxtw or bl
            if (!add_uxtw(insn, detail) && insn->id != AArch64_INS_BL) {
                return false;
            }
        }
    }
    return true;
}

// Check that memory addresses are correctly formed (must use a reserved
// register or guarded addressing mode).
static bool check_mem(cs_insn* insn) {
    cs_detail* detail = insn->detail;
    for (int i = 0; i < detail->aarch64.op_count; i++) {
        cs_aarch64_op* op = &detail->aarch64.operands[i];
        switch (detail->aarch64.operands[i].type) {
        case AArch64_OP_MEM_REG:
            printf("mem_reg\n");
            return false;
        case AArch64_OP_MEM_IMM:
            printf("mem_imm\n");
            return false;
        case AArch64_OP_IMM:
            // not allowed if this is a ldr_imm
            return !is_ldr_imm(insn);
        case AArch64_OP_MEM:
            if (op->mem.index == AArch64_REG_INVALID) {
                if (!addr_reg(op->mem.base)) {
                    return false;
                }
                return true;
            } else {
                if (op->mem.base == BASE_REG && is_lo(op->mem.index) && is_uxtw(op)) {
                    return true;
                }
                return false;
            }
            break;
        default:
            continue;
        }
    }
    return true;
}

// Check that a branch is correctly formed (must use a reserved register).
static bool check_branch(cs_insn* insn) {
    if (is_indbranch(insn)) {
        cs_detail* detail = insn->detail;
        if (!addr_reg(detail->aarch64.operands[0].reg)) {
            return false;
        }
    }
    return true;
}

// Check that an opcode is legal.
static bool check_opcode(cs_insn* insn) {
    return is_legal(insn);
}

// Check that an MSR modification is valid.
static bool check_msr(cs_insn* insn) {
    if (is_msr(insn)) {
        cs_detail* detail = insn->detail;
        if (!legal_msr(detail->aarch64.operands[0].sysop.reg.sysreg)) {
            return false;
        }
    }
    return true;
}

static aarch64_insn_group groups[] = {
    AArch64_GRP_JUMP,
    AArch64_GRP_CALL,
    AArch64_GRP_RET,
    AArch64_GRP_BRANCH_RELATIVE,
    AArch64_FEATURE_HasNEON,
    AArch64_FEATURE_HasFPARMv8,
};

static size_t n_groups = 6;

static bool verify_cs_insn(csh handle, cs_insn* insn) {
    size_t n = 0;
    for (size_t i = 0; i < n_groups; i++) {
        if (cs_insn_group(handle, insn, groups[i])) {
            n++;
        }
    }
    if (insn->detail->groups_count != n)
        return false;
    if (!check_opcode(insn))
        return false;
    if (!check_msr(insn))
        return false;
    if (!check_branch(insn))
        return false;
    if (!check_mem(insn))
        return false;
    if (!check_mod(handle, insn))
        return false;

    return true;
}

csh handle;

bool verify_init() {
    if (cs_open(CS_ARCH_AARCH64, CS_MODE_ARM, &handle) != CS_ERR_OK) {
        return false;
    }
    cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);
    return true;
}

bool verify_insn(uint32_t insn) {
    cs_insn* csi;
    size_t count = cs_disasm(handle, (const uint8_t*) &insn, sizeof(uint32_t), 0, 1, &csi);
    if (count != 1)
        return false;
    bool v = verify_cs_insn(handle, csi);
    cs_free(csi, 1);
    return v;
}
