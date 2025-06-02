// See Intel manual Table A-2

#include "ht.h"

// Flags read by instructions. This table must be complete.
static flagset_t flagread[FDI_XTEST + 1] = {
    [FDI_AAA] = F_AF,
    [FDI_AAS] = F_AF,
    [FDI_ADC] = F_CF,

    [FDI_CMOVO]  = CC_O,
    [FDI_CMOVNO] = CC_NO,
    [FDI_CMOVC]  = CC_C,
    [FDI_CMOVNC] = CC_NC,
    [FDI_CMOVZ]  = CC_Z,
    [FDI_CMOVNZ] = CC_NZ,
    [FDI_CMOVBE] = CC_BE,
    [FDI_CMOVA]  = CC_A,
    [FDI_CMOVS]  = CC_S,
    [FDI_CMOVNS] = CC_NS,
    [FDI_CMOVP]  = CC_P,
    [FDI_CMOVNP] = CC_NP,
    [FDI_CMOVL]  = CC_L,
    [FDI_CMOVGE] = CC_GE,
    [FDI_CMOVLE] = CC_LE,
    [FDI_CMOVG]  = CC_G,

    [FDI_CMPS] = F_DF,
    [FDI_DAA]  = F_AF | F_CF,
    [FDI_DAS]  = F_AF | F_CF,

    [FDI_FCMOVB]   = CC_B,
    [FDI_FCMOVBE]  = CC_BE,
    [FDI_FCMOVE]   = CC_E,
    [FDI_FCMOVNB]  = CC_NB,
    [FDI_FCMOVNBE] = CC_NBE,
    [FDI_FCMOVNE]  = CC_NE,
    [FDI_FCMOVNU]  = CC_NU,
    [FDI_FCMOVU]   = CC_U,

    [FDI_INS]  = F_DF,
    [FDI_INTO] = F_OF,
    [FDI_IRET] = F_NT,

    [FDI_JO]  = CC_O,
    [FDI_JNO] = CC_NO,
    [FDI_JC]  = CC_C,
    [FDI_JNC] = CC_NC,
    [FDI_JZ]  = CC_Z,
    [FDI_JNZ] = CC_NZ,
    [FDI_JBE] = CC_BE,
    [FDI_JA]  = CC_A,
    [FDI_JS]  = CC_S,
    [FDI_JNS] = CC_NS,
    [FDI_JP]  = CC_P,
    [FDI_JNP] = CC_NP,
    [FDI_JL]  = CC_L,
    [FDI_JGE] = CC_GE,
    [FDI_JLE] = CC_LE,
    [FDI_JG]  = CC_G,

    [FDI_LODS]   = F_DF,
    [FDI_LOOPZ]  = F_ZF,
    [FDI_LOOPNZ] = F_ZF,
    [FDI_MOVS]   = F_DF,
    [FDI_MOVSX]  = F_DF,
    [FDI_MOVZX]  = F_DF,
    [FDI_OUTS]   = F_DF,

    [FDI_RCL] = F_CF,
    [FDI_RCR] = F_CF,

    [FDI_SBB]   = F_CF,

    [FDI_SCAS] = F_DF,

    [FDI_SETO]  = CC_O,
    [FDI_SETNO] = CC_NO,
    [FDI_SETC]  = CC_C,
    [FDI_SETNC] = CC_NC,
    [FDI_SETZ]  = CC_Z,
    [FDI_SETNZ] = CC_NZ,
    [FDI_SETBE] = CC_BE,
    [FDI_SETA]  = CC_A,
    [FDI_SETS]  = CC_S,
    [FDI_SETNS] = CC_NS,
    [FDI_SETP]  = CC_P,
    [FDI_SETNP] = CC_NP,
    [FDI_SETL]  = CC_L,
    [FDI_SETGE] = CC_GE,
    [FDI_SETLE] = CC_LE,
    [FDI_SETG]  = CC_G,

    [FDI_STOS] = F_DF,

    [FDI_PUSHF] = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF | F_DF,
    [FDI_LAHF]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF | F_DF,
};

// Flags assigned by instruction. This table can be incomplete. For each
// mnemonic, 1 indicates flag defined, 0 indicates flag undefined.
static flagset_t flagmodify[FDI_XTEST + 1] = {
    [FDI_ADD]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_AND]  = F_OF | F_SF | F_ZF |        F_PF | F_CF,
    [FDI_CMP]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_DEC]  = F_OF | F_SF | F_ZF | F_AF | F_PF,
    [FDI_IMUL] = F_OF |                             F_CF,
    [FDI_INC]  = F_OF | F_SF | F_ZF | F_AF | F_PF,
    [FDI_LSL]  =               F_ZF,
    [FDI_NEG]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_OR]   = F_OF | F_SF | F_ZF |        F_PF | F_CF,
    [FDI_SUB]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_TEST] = F_OF | F_SF | F_ZF |        F_PF | F_CF,
    [FDI_XOR]  = F_OF | F_SF | F_ZF |        F_PF | F_CF,
    [FDI_SHR]  =        F_SF | F_ZF |        F_PF | F_CF,
    [FDI_SHL]  =        F_SF | F_ZF |        F_PF | F_CF,
    [FDI_SAR]  =        F_SF | F_ZF |        F_PF | F_CF,
    [FDI_BT]   =                                    F_CF,
    [FDI_BTS]  =                                    F_CF,
    [FDI_BTR]  =                                    F_CF,
    [FDI_BTC]  =                                    F_CF,

    // Instructions not typically accepted by DeCl, but useful to know about
    // for running flags-verification on arbitrary binaries.
    [FDI_FUCOMIP]     = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_FUCOMI]      = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_FCOMIP]      = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_FCOMI]       = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_SSE_COMISS]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_SSE_COMISD]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_CMPXCHG]     =               F_ZF,
};

// Flags placed in an undefined state by instruction. This table must be
// complete. This is essentially a table of every '-' in A-2.
static flagset_t flagundef[FDI_XTEST + 1] = {
    [FDI_AAA]  = F_OF | F_SF | F_ZF |        F_PF       ,
    [FDI_AAD]  = F_OF |               F_AF |        F_CF,
    [FDI_AAM]  = F_OF |               F_AF |        F_CF,
    [FDI_AAS]  = F_OF | F_SF | F_ZF |        F_PF       ,
    [FDI_AND]  =                      F_AF              ,
    [FDI_BSR]  = F_OF | F_SF |        F_AF | F_PF | F_CF,
    [FDI_BSF]  = F_OF | F_SF |        F_AF | F_PF | F_CF,
    [FDI_BT]   = F_OF | F_SF |        F_AF | F_PF       ,
    [FDI_BTS]  = F_OF | F_SF |        F_AF | F_PF       ,
    [FDI_BTR]  = F_OF | F_SF |        F_AF | F_PF       ,
    [FDI_BTC]  = F_OF | F_SF |        F_AF | F_PF       ,
    [FDI_DIV]  = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_IDIV] = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF,
    [FDI_IMUL] =        F_SF | F_ZF | F_AF | F_PF       ,
    [FDI_MUL]  =        F_SF | F_ZF | F_AF | F_PF       ,
    [FDI_OR]   =                      F_AF              ,
    [FDI_RCL]  = F_OF                                   , // conservative
    [FDI_RCR]  = F_OF                                   , // conservative
    [FDI_ROL]  = F_OF                                   , // conservative
    [FDI_ROR]  = F_OF                                   , // conservative
    [FDI_SAR]  = F_OF |               F_AF              , // conservative
    [FDI_SHL]  = F_OF |               F_AF              , // conservative
    [FDI_SHR]  = F_OF |               F_AF              , // conservative
    [FDI_SHLD] = F_OF |               F_AF              ,
    [FDI_SHRD] = F_OF |               F_AF              ,
    [FDI_TEST] =                      F_AF              ,
    [FDI_XOR]  =                      F_AF              ,

    // MOV control, debug, test puts all flags in an undefined state. I believe
    // this is a system instruction and the variants should already be disabled

    // restoration is tracked as undefined
    [FDI_POPF] = F_OF | F_SF | F_ZF | F_AF | F_PF | F_CF | F_DF,
    [FDI_SAHF] =        F_SF | F_ZF | F_AF | F_PF | F_CF | F_DF,
};

// All instructions that do not modify the flags or put them in an undefined
// state as defined by the tables above are defined to have no effect on the
// flags.
//
// Note: pushf/popf should be generally disallowed in DeCl-mode, but we have
// them in the tables for completeness.

// Analyzes a block of instructions. Given a flagset of undefined flags,
// returns the new flagset after all the instructions in the block execute.
// Reports an error if an undefined flag is read.
static flagset_t analyzeblock(Verifier* v, flagset_t in, FdInstr* instrs, size_t n, bool report) {
    for (size_t i = 0; i < n; i++) {
        FdInstr* instr = &instrs[i];

        flagset_t undef = flagundef[FD_TYPE(instr)];
        flagset_t modify = flagmodify[FD_TYPE(instr)];
        flagset_t read = flagread[FD_TYPE(instr)];

        // Undef and modify cannot overlap.
        assert((undef & modify) == 0);

        if ((read & F_AF) != 0 && report) {
            verr(v, instr, "instruction reads F_AF, which may always be undefined");
        }

        if ((in & read) != 0 && report) {
            verr(v, instr, "instruction reads a possibly undefined flag");
        }

        // New flags that are undefined.
        in |= undef;
        // New flags that are defined.
        in &= ~modify;

        v->addr += instr->size;
    }
    return in;
}

static ssize_t findinstr(ht_t* tbl, size_t addr) {
    bool found;
    size_t i = ht_get(tbl, addr, &found);
    if (!found)
        return -1;
    return i;
}

struct BasicBlock {
    struct BasicBlock* target;
    struct BasicBlock* fallthrough;
    size_t startaddr;
    size_t size;
    flagset_t in;
};

static void analyzecfg(Verifier* v, FdInstr* instrs, size_t n, size_t addr) {
    uint8_t* leaders = calloc(n * sizeof(uint8_t), 1);
    if (!leaders) {
        verrmin(v, "cannot allocate: out of memory");
        return;
    }
    struct BasicBlock* blocks = calloc(n * sizeof(struct BasicBlock), 1);
    if (!blocks) {
        verrmin(v, "out of memory");
        free(leaders);
        return;
    }

    // All flags in an undefined state except F_DF.
    flagset_t undef = F_CF | F_OF | F_SF | F_ZF | F_PF | F_AF;

    leaders[0] = true;

    v->addr = addr;
    ht_t tbl;
    ht_alloc(&tbl, n);
    for (size_t i = 0; i < n; i++) {
        ht_put(&tbl, v->addr, i);
    }
    v->addr = addr;
    for (size_t i = 0; i < n; i++) {
        FdInstr* instr = &instrs[i];
        int64_t target;
        bool indirect, cond;
        bool branch = branchinfo(v, instr, &target, &indirect, &cond);
        // We don't consider indirect branches in our CFG analysis because
        // their correct usage is enforced by a different mechanism.
        branch = branch && !indirect;
        if (branch && i+1 < n) {
            // Instruction after a branch is a leader.
            leaders[i+1] = true;
        }
        // Target is a leader.
        if (branch) {
            ssize_t i = findinstr(&tbl, target - addr);
            if (i >= 0) {
                leaders[i] = true;
            }
        }
        v->addr += instr->size;
    }

    v->addr = addr;
    size_t leader = 0;
    while (leader < n) {
        size_t bbstart = v->addr;
        v->addr += instrs[leader].size;
        for (size_t i = 1; leader + i <= n; i++) {
            if (leader + i == n || leaders[leader + i]) {
                // basic block is i instructions starting at leader
                FdInstr* instr = &instrs[leader + i - 1];
                int64_t target;
                bool indirect, cond;
                v->addr -= instr->size;
                bool branch = branchinfo(v, instr, &target, &indirect, &cond);
                v->addr += instr->size;
                branch = branch && !indirect;
                blocks[leader] = (struct BasicBlock) {
                    .fallthrough = leader + i < n && (!branch || cond) ? &blocks[leader + i] : NULL,
                    .startaddr = bbstart,
                    .in = 0,
                    .size = i,
                };
                if (branch) {
                    ssize_t targidx = findinstr(&tbl, target - addr);
                    if (targidx >= 0) {
                        blocks[leader].target = &blocks[targidx];
                    }
                }
                leader += i;
                break;
            }
            v->addr += instrs[leader + i].size;
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (blocks[i].size > 0) {
            v->addr = blocks[i].startaddr;
            flagset_t in = undef;
            blocks[i].in = 0;
            flagset_t out = analyzeblock(v, in, &instrs[i], blocks[i].size, false);
            if (blocks[i].fallthrough)
                blocks[i].fallthrough->in |= out;
            if (blocks[i].target)
                blocks[i].target->in |= out;
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (blocks[i].size > 0) {
            v->addr = blocks[i].startaddr;
            flagset_t in = blocks[i].in;
            blocks[i].in = 0;
            flagset_t out = analyzeblock(v, in, &instrs[i], blocks[i].size, true);
            if (blocks[i].fallthrough)
                blocks[i].fallthrough->in |= out;
            if (blocks[i].target)
                blocks[i].target->in |= out;
        }
    }

    free(leaders);
    free(blocks);
}
