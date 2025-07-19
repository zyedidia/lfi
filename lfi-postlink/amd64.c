#include <stdbool.h>
#include <stdio.h>
#include <Zydis/Zydis.h>

#include "fadec.h"
#include "elf.h"
#include "postlink.h"

enum {
    INSN_MAX = 15,
    PREFIX_MAX = 4,
    CS_PREFIX = 0x2e,
    GS_PREFIX = 0x65,
    FS_PREFIX = 0x64,
};

static bool
isjmp(ZydisMnemonic mnemonic)
{
    switch (mnemonic) {
    case ZYDIS_MNEMONIC_JB:
    case ZYDIS_MNEMONIC_JBE:
    case ZYDIS_MNEMONIC_JL:
    case ZYDIS_MNEMONIC_JLE:
    case ZYDIS_MNEMONIC_JMP:
    case ZYDIS_MNEMONIC_JNB:
    case ZYDIS_MNEMONIC_JNBE:
    case ZYDIS_MNEMONIC_JNL:
    case ZYDIS_MNEMONIC_JNLE:
    case ZYDIS_MNEMONIC_JNP:
    case ZYDIS_MNEMONIC_JNS:
    case ZYDIS_MNEMONIC_JNZ:
    case ZYDIS_MNEMONIC_JO:
    case ZYDIS_MNEMONIC_JP:
    case ZYDIS_MNEMONIC_JS:
    case ZYDIS_MNEMONIC_JZ:
    case ZYDIS_MNEMONIC_CALL:
    case ZYDIS_MNEMONIC_RET:
        return true;
    default:
        return false;
    }
}

static uint8_t nops[12][12] = {
    [1]  = {0x90},
    [2]  = {0x66, 0x90},
    [3]  = {0xf, 0x1f, 0x00},
    [4]  = {0x0f, 0x1f, 0x40, 0x00},
    [5]  = {0x0f, 0x1f, 0x44, 0x00, 0x00},
    [6]  = {0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00},
    [7]  = {0x0f, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00},
    [8]  = {0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00},
    [9]  = {0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00},
    [10] = {0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00},
    [11] = {0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00},
};

static void
makenop(uint8_t* buf, size_t size)
{
    assert(size <= 11);
    memcpy(buf, nops[size], size);
}

// Creates a nop chunk of size 'size' where no nops cross bundle boundaries.
static void
nopbundle(uintptr_t addr, uint8_t* buf, size_t size, size_t bsz)
{
    size_t nextnop = 0;
    size_t lastnop = 0;
    for (size_t i = 0; i < size; i++) {
        if (addr % bsz == 0 || nextnop >= 11) {
            if (nextnop > 0) {
                makenop(&buf[lastnop], nextnop);
            }
            lastnop = i;
            nextnop = 0;
        }

        addr++;
        nextnop++;
    }
    if (nextnop > 0)
        makenop(&buf[lastnop], nextnop);
}

static void
nopfix(uint8_t* insns, size_t n, size_t bsz, size_t addr)
{
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

    ZydisDecoderContext context;
    ZydisDecodedInstruction instr;
    size_t count = 0;
    size_t nopchunk = 0;
    size_t nopstart;
    while (count < n) {
        ZyanStatus status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count], n-count, &instr);
        if (ZYAN_FAILED(status)) {
            fprintf(stderr, "nopfix failed %lx\n", addr);
            return;
        }
        if (instr.mnemonic == ZYDIS_MNEMONIC_NOP) {
            if (nopchunk == 0)
                nopstart = count;
            nopchunk += instr.length;
        } else {
            if (nopchunk > 0)
                nopbundle(addr + nopstart, &insns[nopstart], nopchunk, bsz);
            nopchunk = 0;
        }
        count += instr.length;
    }
    if (nopchunk > 0)
        nopbundle(addr + nopstart, &insns[nopstart], nopchunk, bsz);
}

static void
bundlefix(uint8_t* insns, size_t n, size_t bsz, size_t addr)
{
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

    ZydisDecoderContext context;
    ZydisDecodedInstruction instr;
    size_t count = 0;
    while (count < bsz) {
        ZyanStatus status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count], n-count, &instr);
        if (ZYAN_FAILED(status)) {
            fprintf(stderr, "bundlefix failed %lx\n", addr);
            return;
        }
        count += instr.length;
    }
    if (count > bsz && bsz > 0) {
        memset(&insns[count - instr.length], 0x90, instr.length - (count - bsz));
    }
}

static void
callrewrite(uint8_t* insns, size_t bsz, size_t addr)
{
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

    ZydisDecoderContext context;
    ZydisDecodedInstruction instr;
    size_t count = 0;
    size_t curbundle = 0;
    while (count < bsz) {
        ZyanStatus status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count], bsz-count, &instr);
        if (ZYAN_FAILED(status)) {
            // fprintf(stderr, "call rewrite failed %lx\n", addr);
            return;
        }

        if (instr.mnemonic == ZYDIS_MNEMONIC_CALL) {
            ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT];
            status = ZydisDecoderDecodeOperands(&decoder, &context, &instr,
                    operands, instr.operand_count);
            assert(!ZYAN_FAILED(status));

            if (operands[0].type == ZYDIS_OPERAND_TYPE_MEMORY && operands[0].mem.base == ZYDIS_REGISTER_R14) {
            } else {
                if ((addr + instr.length) % bsz != 0) {
                    ZydisDecodedInstruction next;
                    size_t noplen = 0;
                    do {
                        status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count+instr.length+noplen], bsz-count-instr.length-noplen, &next);
                        if (ZYAN_FAILED(status) || next.mnemonic != ZYDIS_MNEMONIC_NOP)
                            return;
                        noplen += next.length;
                    } while ((addr + instr.length + noplen) % bsz != 0);

                    char* nop = malloc(noplen);
                    memcpy(nop, &insns[count+instr.length], noplen);

                    char* call = malloc(instr.length);
                    memcpy(call, &insns[count], instr.length);

                    if (operands[0].type == ZYDIS_OPERAND_TYPE_IMMEDIATE && instr.length == 5) {
                        operands[0].imm.value.u -= noplen;
                        ZydisEncoderRequest req;
                        memset(&req, 0, sizeof(req));
                        ZydisEncoderDecodedInstructionToEncoderRequest(&instr, operands, instr.operand_count_visible, &req);
                        ZyanUSize encoded_length = instr.length;
                        if (ZYAN_FAILED(ZydisEncoderEncodeInstruction(&req, call, &encoded_length))) {
                            fprintf(stderr, "error: zyan failed\n");
                            exit(1);
                        }
                    }

                    memcpy(&insns[count], nop, noplen);
                    memcpy(&insns[count+noplen], call, instr.length);
                    addr += noplen;
                    count += noplen;
                    free(nop);
                    free(call);
                }
            }
        }

        addr += instr.length;
        count += instr.length;

        if (count - curbundle >= bsz) {
            addr = addr - (addr % bsz);
            count = count - (count % bsz);
            curbundle = count;
        }
    }
}

static ZyanI8
GetRelativeOperandIndex(const ZydisEncoderRequest* req)
{
    for (ZyanU8 i = 0; i < req->operand_count; ++i) {
        const ZyanBool is_rip_rel = (req->operands[i].type == ZYDIS_OPERAND_TYPE_MEMORY) &&
            ((req->operands[i].mem.base == ZYDIS_REGISTER_EIP) ||
             (req->operands[i].mem.base == ZYDIS_REGISTER_RIP));
        if (is_rip_rel || (req->operands[i].type == ZYDIS_OPERAND_TYPE_IMMEDIATE)) {
            return (ZyanI8)i;
        }
    }
    return -1;
}

static void
padrewrite(uint8_t* insns, size_t bsz, size_t addr)
{
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

    ZydisDecoderContext contexts[32];
    ZydisDecodedInstruction instrs[32];

    size_t count = 0;
    size_t i = 0;
    while (count < bsz) {
        ZyanStatus status = ZydisDecoderDecodeInstruction(&decoder, &contexts[i], &insns[count], bsz-count, &instrs[i]);
        if (ZYAN_FAILED(status)) {
            // fprintf(stderr, "pad rewrite failed %lx\n", addr + count);
            return;
        }

        count += instrs[i].length;
        i++;
    }

    int prefixes[32];
    uint8_t pretypes[32];
    memset(prefixes, 0, sizeof(prefixes));
    memset(pretypes, CS_PREFIX, sizeof(pretypes));
    if (i >= 2 && instrs[i - 1].mnemonic == ZYDIS_MNEMONIC_NOP) {
        // goal: add up to 5 segment prefixes on non-jump instructions
        size_t nopsz = instrs[i - 1].length;
        while (nopsz > 0) {
            size_t prenopsz = nopsz;
            for (int j = 0; j < i - 1; j++) {
                if (nopsz == 0)
                    break;
                if (isjmp(instrs[j].mnemonic))
                    continue;
                if (instrs[j].mnemonic == ZYDIS_MNEMONIC_LEA)
                    continue;
                if (instrs[j].mnemonic == ZYDIS_MNEMONIC_NOP) {
                    continue;
                }
                ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT];
                ZydisDecoderDecodeOperands(&decoder, &contexts[j], &instrs[j], operands, instrs[j].operand_count);
                for (int op = 0; op < instrs[j].operand_count; op++) {
                    if (operands[op].type == ZYDIS_OPERAND_TYPE_MEMORY) {
                        if (operands[op].mem.segment == ZYDIS_REGISTER_GS)
                            pretypes[j] = GS_PREFIX;
                        else if (operands[op].mem.segment == ZYDIS_REGISTER_FS)
                            pretypes[j] = FS_PREFIX;
                    }
                }
                if (instrs[j].length + prefixes[j] < INSN_MAX && prefixes[j] < PREFIX_MAX) {
                    prefixes[j]++;
                    nopsz--;
                }
            }
            if (prenopsz == nopsz)
                break;
        }
        // could not delete nop -- just leave it
        if (nopsz > 0)
            return;
        uint8_t* newbundle = malloc(bsz);
        assert(newbundle);
        uint8_t* curb = newbundle;
        size_t adjust = 0;
        count = 0;
        for (int j = 0; j < i - 1; j++) {
            for (int p = 0; p < prefixes[j]; p++) {
                *curb++ = pretypes[j];
                assert(pretypes[j] == CS_PREFIX || pretypes[j] == FS_PREFIX || pretypes[j] == GS_PREFIX);
            }
            adjust += prefixes[j];
            char* insn = malloc(instrs[j].length);
            memcpy(insn, &insns[count], instrs[j].length);

            if ((instrs[j].attributes & ZYDIS_ATTRIB_IS_RELATIVE) != 0) {
                ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT];
                ZydisDecoderDecodeOperands(&decoder, &contexts[j], &instrs[j], operands, instrs[j].operand_count);
                ZydisEncoderRequest req;
                memset(&req, 0, sizeof(req));
                ZydisEncoderDecodedInstructionToEncoderRequest(&instrs[j], operands, instrs[j].operand_count_visible, &req);
                int idx = GetRelativeOperandIndex(&req);
                if (req.operands[idx].type == ZYDIS_OPERAND_TYPE_IMMEDIATE) {
                    req.operands[idx].imm.u -= adjust;
                } else if (req.operands[idx].type == ZYDIS_OPERAND_TYPE_MEMORY) {
                    // don't adjust lea 0x3(%rip)/0x4(%rip) used for runtime calls
                    if (!(instrs[j].mnemonic == ZYDIS_MNEMONIC_LEA && (req.operands[idx].mem.displacement == 3 || req.operands[idx].mem.displacement == 4)))
                        req.operands[idx].mem.displacement -= adjust;
                }
                ZyanUSize encoded_len = instrs[j].length;
                if (ZYAN_FAILED(ZydisEncoderEncodeInstruction(&req, insn, &encoded_len))) {
                    fprintf(stderr, "error: zyan encode failed\n");
                    exit(1);
                }
            }
            memcpy(curb, insn, instrs[j].length);
            free(insn);
            count += instrs[j].length;
            curb += instrs[j].length;
        }

        memcpy(insns, newbundle, bsz);
        free(newbundle);
    }
}

static bool branchinfo(size_t addr, FdInstr* instr, int64_t* target, bool* indirect, bool* cond) {
    *target = 0;
    *indirect = false;
    *cond = false;

    // TODO: don't count runtime calls as branches

    bool branch = true;
    switch (FD_TYPE(instr)) {
    case FDI_JA:
    case FDI_JBE:
    case FDI_JC:
    case FDI_JCXZ:
    case FDI_JG:
    case FDI_JGE:
    case FDI_JL:
    case FDI_JLE:
    case FDI_JNC:
    case FDI_JNO:
    case FDI_JNP:
    case FDI_JNS:
    case FDI_JNZ:
    case FDI_JO:
    case FDI_JP:
    case FDI_JS:
    case FDI_JZ:
        *cond = true;
    case FDI_JMP:
    case FDI_CALL:
    case FDI_RET:
        if (FD_OP_TYPE(instr, 0) == FD_OT_OFF) {
            int64_t imm = FD_OP_IMM(instr, 0);
            *target = addr + FD_SIZE(instr) + imm;
        } else {
            *indirect = true;
        }
        break;
    default:
        branch = false;
        break;
    }
    return branch;
}

static void
meterupdate(uint8_t* code, size_t size, size_t addr)
{
    size_t count = 0;
    while (count < size) {
        FdInstr instr;
        int ret = fd_decode(&code[count], size - count, 64, 0, &instr);
        if (ret < 0) {
            fprintf(stderr, "%lx: count not decode\n", addr + count);
            return;
        }
        if (FD_TYPE(&instr) == FDI_LEA && FD_OP_REG(&instr, 0) == FD_REG_R12) {
            assert(ret == 8);
            memset(&code[count + 4], 0, 4);
        }
        if (FD_TYPE(&instr) == FDI_SUB && FD_OP_REG(&instr, 0) == FD_REG_R12) {
            assert(ret == 7);
            memset(&code[count + 3], 0, 4);
        }
        bool indirect, cond;
        int64_t target;
        bool branch = branchinfo(addr+count, &instr, &target, &indirect, &cond);
        uint8_t mov[3] = {0x4c, 0x89, 0xd9};   // mov %r11, %rcx
        uint8_t nop1[3] = {0x90, 0x90, 0x90};  // nop; nop; nop
        uint8_t nop3[3] = {0xf, 0x1f, 0x00};   // 3-byte nop
        uint8_t jrcxz[3] = {0xe3, 0x01, 0xcc}; // jrcxz .+3; int3
        uint8_t jns[3] = {0x79, 0x01, 0xcc};   // jns .+3; int3
        if (branch) {
            size_t noploc = 3;
            if (count >= 3 && memcmp(&code[count-3], mov, 3) == 0) {
                noploc = 6;
            }
            if (count >= noploc &&
                    (memcmp(&code[count-noploc], nop1, 3) == 0 || memcmp(&code[count-noploc], nop3, 3) == 0)) {
                if (target <= addr+count) {
                    // fill in the check
                    if (noploc == 6) {
                        memcpy(&code[count-noploc], jrcxz, 3);
                    } else {
                        memcpy(&code[count-noploc], jns, 3);
                    }
                }
            }
        }
        count += ret;
    }
}

void
amd64_postlink(uint8_t* buf, size_t sz)
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

        uint8_t* code = &buf[p->offset];

        if (args.bundle != 0) {
            size_t count = 0;
            nopfix(code, p->filesz, args.bundle, p->vaddr);
            while (count + args.bundle <= p->filesz) {
                /* bundlefix(&code[count], p->filesz - count, args.bundle, p->vaddr + count); */
                if (args.prefix)
                    padrewrite(&code[count], args.bundle, p->vaddr + count);
                callrewrite(&code[count], args.bundle, p->vaddr + count);
                count += args.bundle;
            }
        }

        if (args.meter != METER_NONE) {
            meterupdate(code, p->filesz, p->vaddr);
        }
    }
}
