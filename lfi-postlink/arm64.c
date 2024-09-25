#include <assert.h>
#include <stdlib.h>

#include "elf.h"
#include "postlink.h"

#include <capstone/capstone.h>

enum {
    NOP  = 0xd503201f,
    FMOV = 0x9e6702ff,
    FNEG = 0x1e6143ff,
    TBZ  = 0xb6f80057,
    BLR  = 0xd63f0320,

    CNTD_X0   = 0x04e0e3e0,
    BTI_C     = 0xd503245f,
    AUTIB1716 = 0xd50321df,
    AUTIA1716 = 0xd503219f,
    XPACLRI   = 0xd50320ff,

    OP_SUB = (0b110100010UL << 23),
    OP_ADD = (0b100100010UL << 23),
};

static uint32_t
ceilimm(uint32_t imm, uint32_t align)
{
    uint32_t mask = align - 1;
    return (imm + mask) & ~mask;
}

static uint32_t
subx23(int64_t imm)
{
    if (imm < 4096) {
        return OP_SUB | (imm << 10) | (23 << 5) | (23);
    }
    if (imm % 4096 != 0) {
        imm = ceilimm(imm, 4096);
    }
    return OP_SUB | (1 << 22) | ((imm >> 12) << 10) | (23 << 5) | (23);
}

static bool
issub(uint32_t insn)
{
    return insn == 0xd10002f7;
}

static bool
isnop(uint32_t insn)
{
    return insn == NOP;
}

static void
meteropt(uint8_t* buf, size_t sz, size_t addr)
{
    csh handle;
    if (cs_open(CS_ARCH_ARM64, CS_MODE_ARM, &handle) != CS_ERR_OK) {
        return;
    }
    cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);

    uint32_t* insns = (uint32_t*) buf;
    size_t n = sz / sizeof(uint32_t);

    bool* leaders = calloc(1, sizeof(bool) * n);
    assert(leaders);

    leaders[0] = true;

    // calculate basic blocks
    for (size_t i = 0; i < n; i++) {
        cs_insn* csi;
        size_t count = cs_disasm(handle, (const uint8_t*) &insns[i], sizeof(uint32_t), i* 4, 1, &csi);
        if (count != 1)
            continue;

        int64_t target = 0;
        bool branch = false;
        switch (csi->id) {
        case ARM64_INS_B:
        case ARM64_INS_BL:
            target = csi->detail->arm64.operands[0].imm;
            branch = true;
            break;
        case ARM64_INS_CBZ:
        case ARM64_INS_CBNZ:
            target = csi->detail->arm64.operands[1].imm;
            branch = true;
            break;
        case ARM64_INS_TBZ:
        case ARM64_INS_TBNZ:
            if (csi->detail->arm64.operands[0].reg == ARM64_REG_X23) {
                cs_free(csi, 1);
                continue;
            }
            target = csi->detail->arm64.operands[2].imm;
            branch = true;
            break;
        case ARM64_INS_BLR:
        case ARM64_INS_BR:
        case ARM64_INS_RET:
            if (csi->id == ARM64_INS_BLR && (csi->detail->arm64.operands[0].reg == ARM64_REG_X25 || csi->detail->arm64.operands[0].reg == ARM64_REG_X30)) {
                cs_free(csi, 1);
                continue;
            }
            break;
        default:
            cs_free(csi, 1);
            continue;
        }

        // target of a branch is a leader (in precise mode only)
        if (args.precise && branch)
            leaders[target / 4] = true;

        // instruction immediately following a branch is a leader
        if (i + 1 < n) {
            leaders[i + 1] = true;
        }

        cs_free(csi, 1);
    }

    size_t cur_leader = 0;
    for (size_t i = 0; i < n; i++) {
        // disasm instruction
        cs_insn* csi;
        size_t count = cs_disasm(handle, (const uint8_t*) &insns[i], sizeof(uint32_t), addr + i * 4, 1, &csi);
        if (count != 1)
            continue;

        if (leaders[i])
            cur_leader = i;

        // direct branches: check forward or backward
        int64_t target = 0;
        bool branch = false;
        bool indbranch = false;
        switch (csi->id) {
        case ARM64_INS_B:
            target = csi->detail->arm64.operands[0].imm;
            branch = true;
            break;
        case ARM64_INS_BL:
            target = csi->detail->arm64.operands[0].imm;
            branch = true;
            break;
        case ARM64_INS_CBZ:
        case ARM64_INS_CBNZ:
            target = csi->detail->arm64.operands[1].imm;
            branch = true;
            break;
        case ARM64_INS_TBZ:
        case ARM64_INS_TBNZ:
            if (csi->detail->arm64.operands[0].reg == ARM64_REG_X23) {
                cs_free(csi, 1);
                continue;
            }
            target = csi->detail->arm64.operands[2].imm;
            branch = true;
            break;
        default:
            switch (csi->id) {
                case ARM64_INS_BR:
                case ARM64_INS_BLR:
                case ARM64_INS_RET:
                    if (csi->id == ARM64_INS_BLR && (csi->detail->arm64.operands[0].reg == ARM64_REG_X25 || csi->detail->arm64.operands[0].reg == ARM64_REG_X30)) {
                        cs_free(csi, 1);
                        continue;
                    }
                    indbranch = true;
                    branch = true;
                    break;
            }
        }

        if (!branch) {
            cs_free(csi, 1);
            continue;
        }

        size_t idx = i;
        if (!indbranch && (target - (int64_t) csi->address) > 0) {
            if (args.meter == METER_BRANCH || args.meter == METER_FP) {
                // forward branches: optimize with nops
                if (insns[idx - 2] == TBZ)
                    insns[idx - 2] = NOP;
                if (insns[idx - 1] == BLR)
                    insns[idx - 1] = NOP;
            }
        }

        // calculate direct gas immediate
        int64_t imm = idx - cur_leader + 1;

        if (args.meter == METER_TIMER) {
            if (!issub(insns[idx - 1]) && !isnop(insns[idx - 1])) {
                fprintf(stderr, "%lx: error: expected gas subtraction relocation, got %x\n", addr + idx * 4, insns[idx - 1]);
            } else {
                insns[idx - 1] = subx23(imm);
            }
        } else {
            if (isnop(insns[idx - 3]) && isnop(insns[idx - 2]) && isnop(insns[idx - 1])) {
                switch (args.meter) {
                case METER_FP:
                    insns[idx - 3] = subx23(imm);
                    insns[idx - 2] = FMOV;
                    insns[idx - 1] = FNEG;
                    break;
                case METER_BRANCH:
                    insns[idx - 3] = subx23(imm);
                    insns[idx - 2] = TBZ;
                    insns[idx - 1] = BLR;
                    break;
                case METER_TIMER:
                    insns[idx - 1] = subx23(imm);
                    break;
                default:
                    assert(false);
                }
            } else if (insns[idx - 3] != 0xd10002f7) {
                if (insns[idx - 1] != 0xd10002f7) {
                    fprintf(stderr, "%lx: error: expected gas subtraction relocation\n", addr + idx * 4);
                } else {
                    insns[idx - 1] = subx23(imm);
                }
            } else {
                insns[idx - 3] = subx23(imm);
            }
        }
    }

    free(leaders);

    cs_close(&handle);
}

static void
removeinvalid(uint8_t* buf, size_t sz)
{
    assert((uintptr_t) buf % 4 == 0 && sz % 4 == 0);
    uint32_t* insns = (uint32_t*) buf;
    for (size_t i = 0; i < sz / 4; i++) {
        uint32_t insn = insns[i];
        switch (insn) {
        case CNTD_X0:
        case BTI_C:
        case AUTIB1716:
        case AUTIA1716:
        case XPACLRI:
            insns[i] = NOP;
            break;
        default:
            break;
        }
    }
}

void
arm64_postlink(uint8_t* buf, size_t sz)
{
    struct elf_file_header* ehdr = (struct elf_file_header*) buf;
    struct elf_prog_header* phdr = (struct elf_prog_header*) &buf[ehdr->phoff];

    for (int i = 0; i < ehdr->phnum; i++) {
        struct elf_prog_header* p = &phdr[i];
        if (p->type != PT_LOAD) {
            continue;
        }
        if ((p->flags & PF_X) == 0) {
            continue;
        }

        removeinvalid(&buf[p->offset], p->filesz);
        if (args.meter != METER_NONE)
            meteropt(&buf[p->offset], p->filesz, p->vaddr);
    }
}
