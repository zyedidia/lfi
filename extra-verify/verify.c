#include <capstone/capstone.h>

#include "op.h"

enum {
    BASE_REG = AArch64_REG_X21,
};

enum {
    NOP = 0xd503201f,
    BRK_0 = 0xd4200000,
    TBZ = 0xb6f80057,
    BTI_JC = 0xd50324df,
    OP_SUB = (0b110100010UL << 23),
    OP_ADD = (0b100100010UL << 23),
};

static uint32_t ceilimm(uint32_t imm, uint32_t align) {
    uint32_t mask = align - 1;
    return (imm + mask) & ~mask;
}

static uint32_t arm64_sub_x23(int64_t imm) {
    if (imm < 4096) {
        return OP_SUB | (imm << 10) | (23 << 5) | (23);
    }
    if (imm % 4096 != 0) {
        imm = ceilimm(imm, 4096);
    }
    return OP_SUB | (1 << 22) | ((imm >> 12) << 10) | (23 << 5) | (23);
}

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
        //// TODO
    //case AArch64_REG_X22:
    case AArch64_REG_W23:
    case AArch64_REG_W24:
    case AArch64_REG_W25:
    case AArch64_REG_X25:
    case AArch64_REG_W30:
    case AArch64_REG_SP:
    case AArch64_REG_WSP:
        return true;
    case AArch64_REG_X23:
        return true;
    default:
        return false;
    }
}

static bool addr_reg(aarch64_reg reg) {
    switch (reg) {
    case AArch64_REG_X18:
    case AArch64_REG_X30:
    case AArch64_REG_X25:
    case AArch64_REG_W25:
    case AArch64_REG_X21:
    case AArch64_REG_SP:
        return true;
    default:
        return false;
    }
}

// make sure that address registers are not read, except by loads and stores in the address mode (POC)
static bool check_read(csh handle, cs_insn* insn) {
    cs_detail* detail = insn->detail;
    for (int i = 0; i < detail->aarch64.op_count; i++) {
        if (detail->aarch64.operands[i].type == AArch64_OP_REG && detail->aarch64.operands[i].access == CS_AC_READ) {
            if (addr_reg(detail->aarch64.operands[i].reg)) {
                uint8_t regs_read_count, regs_write_count;
                cs_regs regs_read, regs_write;
                cs_regs_access(handle, insn, regs_read, &regs_read_count, regs_write, &regs_write_count);

                // cannot write to non-addr register if read from addr register
                for (int j = 0; j < regs_write_count; j++) {
                    aarch64_reg reg = regs_write[j];
                    if (!addr_reg(reg)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

static bool check_adr(cs_insn* insn) {
    cs_detail* detail = insn->detail;
    switch (insn->id) {
    case AArch64_INS_ADR:
    case AArch64_INS_ADRP:
        // TODO:
        if (detail->aarch64.operands[0].reg != AArch64_REG_X22) {
            return false;
        }
    }
    return true;
}

static bool verify_poc(csh handle, cs_insn* csi, uint32_t* insns, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (!check_read(handle, &csi[i])) {
            printf("fail read: %x, 0x%"PRIx64":\t%s\t\t%s\n", insns[i], csi[i].address, csi[i].mnemonic,
                    csi[i].op_str);
            return false;
        }

        if (!check_adr(&csi[i])) {
            printf("fail adr check: %x, 0x%"PRIx64":\t%s\t\t%s\n", insns[i], csi[i].address, csi[i].mnemonic,
                    csi[i].op_str);
            return false;
        }
    }
    return true;
}

static bool check_gas_mod(csh handle, cs_insn* insn) {
    cs_detail* detail = insn->detail;
    uint8_t regs_read_count, regs_write_count;
    cs_regs regs_read, regs_write;
    cs_regs_access(handle, insn, regs_read, &regs_read_count, regs_write, &regs_write_count);
    for (int i = 0; i < regs_write_count; i++) {
        aarch64_reg reg = regs_write[i];
        if (reg == AArch64_REG_X23) {
            return false;
        }
    }
    return true;
}

static bool verify_gas(csh handle, cs_insn* csinsns, uint32_t* insns, size_t n, uintptr_t base_addr) {
    bool* leaders = calloc(sizeof(bool) * n, 1);
    assert(leaders);

    bool* updates = calloc(sizeof(bool) * n, 1);
    assert(updates);

    leaders[0] = true;

    // calculate basic blocks
    for (size_t i = 0; i < n; i++) {
        cs_insn* csi = &csinsns[i];
        // target of a branch is a leader
        int64_t target = 0;
        switch (csi->id) {
        case AArch64_INS_RET:
            // for BTI ret is completely disallowed
            return false;
        case AArch64_INS_B:
        case AArch64_INS_BL:
            target = csi->detail->aarch64.operands[0].imm - base_addr;
            leaders[target / 4] = true;
            break;
        case AArch64_INS_CBZ:
        case AArch64_INS_CBNZ:
            target = csi->detail->aarch64.operands[1].imm - base_addr;
            leaders[target / 4] = true;
            break;
        case AArch64_INS_TBZ:
        case AArch64_INS_TBNZ:
            if (insns[i] == TBZ) {
                // part of a gas update sequence
                continue;
            }
            target = csi->detail->aarch64.operands[2].imm - base_addr;
            leaders[target / 4] = true;
            break;
        case AArch64_INS_BLR:
        case AArch64_INS_BR:
            break;
        case AArch64_BTI_JC:
        case AArch64_BTI_C:
        case AArch64_BTI_J:
            // rewrite bti c and bti j into bti jc
            leaders[i] = true;
            continue;
        default:
            continue;
        }
        // instruction immediately following a branch is a leader
        if (i + 1 < n) {
            leaders[i + 1] = true;
        }
    }

    // every leader must be preceded by the right sequence
    size_t cur_leader = 0;

    for (size_t i = 0; i < n; i++) {
        cs_insn* csi = &csinsns[i];
        if (leaders[i]) {
            cur_leader = i;
        }

        // direct branches: check forward or backward
        int64_t target = 0;
        bool cond = false;
        bool branch = false;
        bool indbranch = false;
        switch (csi->id) {
        case AArch64_INS_B:
            cond = csi->detail->aarch64.cc != AArch64CC_AL && csi->detail->aarch64.cc != AArch64CC_NV && csi->detail->aarch64.cc != AArch64CC_Invalid;
            target = csi->detail->aarch64.operands[0].imm;
            branch = true;
            break;
        case AArch64_INS_BL:
            target = csi->detail->aarch64.operands[0].imm;
            branch = true;
            break;
        case AArch64_INS_CBZ:
        case AArch64_INS_CBNZ:
            target = csi->detail->aarch64.operands[1].imm;
            cond = true;
            branch = true;
            break;
        case AArch64_INS_TBZ:
        case AArch64_INS_TBNZ:
            if (insns[i] == TBZ) {
                // part of a gas update sequence
                continue;
            }
            target = csi->detail->aarch64.operands[2].imm;
            cond = true;
            branch = true;
            break;
        case AArch64_INS_BR:
        case AArch64_INS_BLR:
        case AArch64_INS_RET: // should not happen
            if (csi->id == AArch64_INS_BLR && csi->detail->aarch64.operands[0].reg == AArch64_REG_X30) {
                // runtime calls don't need to be charged
                continue;
            }
            indbranch = true;
            branch = true;
            break;
        }

        // index of the first instruction after a required gas update sequence
        size_t idx = i;
        if (branch) {
            // current instruction is branch
        } else if (i + 1 < n && leaders[i + 1]) {
            idx = i + 1;
            // next instruction is a leader
        } else {
            // no gas check necessary
            continue;
        }

        // check that (may be nop for forwards branch)
        // idx - 3: sub x23, x23, #n
        // idx - 2: tbz x23, #63, 2
        // idx - 1: brk #0
        // Note: we allow the brk #0 to not exist, and note that the location
        // is no longer a leader. If the next gas check does not include this
        // instruction/block in the amount that it is charging, then an error
        // will be caused there.
        if (idx == 0) {
            continue;
        }
        /* if (insns[idx - 1] == 0) { */
        /*     updates[idx - 1] = true; */
        /*     continue; */
        /* } */
        if (idx < 3) {
            printf("no space for gas update?: %x, 0x%"PRIx64":\t%s\t\t%s\n", insns[idx], csinsns[idx].address, csinsns[idx].mnemonic,
                    csi[idx].op_str);
            return false;
        }
        if ((target - (int64_t) csi->address) > 0) {
            // forwards branch
            if (insns[idx - 1] != BRK_0 && insns[idx - 1] != NOP) {
                // maybe this is not a leader after all
                leaders[idx] = false;
                continue;
            }
            if (insns[idx - 2] != TBZ && insns[idx - 1] != NOP) {
                printf("fail tbz check: %x, 0x%"PRIx64":\t%s\t\t%s\n", insns[idx], csinsns[idx].address, csinsns[idx].mnemonic,
                        csinsns[idx].op_str);
                return false;
            }
            int64_t sub = idx - cur_leader + (branch ? 1 : 0);
            if (insns[idx - 3] != arm64_sub_x23(sub)) {
                printf("fail forwards sub check (should be %ld): %x, 0x%"PRIx64":\t%s\t\t%s\n", sub, insns[idx], csinsns[idx].address, csinsns[idx].mnemonic,
                        csinsns[idx].op_str);
                return false;
            }
        } else {
            // backwards branch
            if (insns[idx - 1] != BRK_0) {
                // maybe this is not a leader after all
                leaders[idx] = false;
                continue;
            }
            if (insns[idx - 2] != TBZ) {
                printf("fail tbz check: %x, 0x%"PRIx64":\t%s\t\t%s\n", insns[idx], csinsns[idx].address, csinsns[idx].mnemonic,
                        csinsns[idx].op_str);
                return false;
            }
            int64_t sub = idx - cur_leader - 1 + (branch ? 1 : 0);
            if (insns[idx - 3] != arm64_sub_x23(sub)) {
                printf("%ld %ld\n", idx, cur_leader);
                printf("fail backwards sub check (should be %ld): %x, 0x%"PRIx64":\t%s\t\t%s\n", sub, insns[idx], csinsns[idx].address, csinsns[idx].mnemonic,
                        csinsns[idx].op_str);
                return false;
            }
        }
        updates[idx - 1] = true;
        updates[idx - 2] = true;
        updates[idx - 3] = true;
    }

    for (size_t i = 0; i < n; i++) {
        cs_insn* csi = &csinsns[i];
        if (insns[i] == TBZ && !updates[i]) {
            printf("tbz outside update sequence: %x, 0x%"PRIx64":\t%s\t\t%s\n", insns[i], csinsns[i].address, csinsns[i].mnemonic,
                    csi[i].op_str);
            return false;
        }
        if (!check_gas_mod(handle, csi) && !updates[i]) {
            printf("modifying gas outside update sequence: %x, 0x%"PRIx64":\t%s\t\t%s\n", insns[i], csinsns[i].address, csinsns[i].mnemonic,
                    csi[i].op_str);
            return false;
        }
    }
    free(leaders);
    free(updates);
    return true;
}

int verify(csh handle, uint32_t* insns, size_t n, uintptr_t addr) {
    cs_insn* csi;
    size_t count = cs_disasm(handle, (const uint8_t*) insns, sizeof(uint32_t) * n, addr, 0, &csi);
    if (count != n) {
        printf("disassembly failure\n");
        return 0;
    }

    if (!verify_poc(handle, csi, insns, n)) {
        return 0;
    }

    if (!verify_gas(handle, csi, insns, n, addr)) {
        return 0;
    }

    cs_free(csi, count);

    return 1;
}
