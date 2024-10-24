// See Intel manual Table A-2

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

    [FDI_FUCOMIP] = F_OF | F_ZF | F_PF,
    [FDI_FUCOMI]  = F_OF | F_ZF | F_PF,
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
static flagset_t analyzeblock(Verifier* v, flagset_t in, FdInstr* instrs, size_t n) {
    for (size_t i = 0; i < n; i++) {
        FdInstr* instr = &instrs[i];

        flagset_t undef = flagundef[FD_TYPE(instr)];
        flagset_t modify = flagmodify[FD_TYPE(instr)];
        flagset_t read = flagread[FD_TYPE(instr)];

        // Undef and modify cannot overlap.
        assert((undef & modify) == 0);

        if ((in & read) != 0) {
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

static ssize_t findinstr(FdInstr* instrs, size_t n, size_t addr) {
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        if (count == addr)
            return i;
        count += instrs[i].size;
    }
    return -1;
}

// Types of leaders.
enum {
    L_NONE        = 0,
    L_TARGET      = 1,
    L_FALLTHROUGH = 2,
};

static void analyzecfg(Verifier* v, FdInstr* instrs, size_t n, size_t addr) {
    uint8_t* leaders = calloc(n * sizeof(uint8_t), 1);
    if (!leaders) {
        verrmin(v, "cannot allocate: out of memory");
        return;
    }
    leaders[0] = L_TARGET;

    v->addr = addr;
    for (size_t i = 0; i < n; i++) {
        FdInstr* instr = &instrs[i];
        int64_t target;
        bool indirect;
        bool branch = branchinfo(v, instr, &target, &indirect);
        // We don't consider indirect branches in our CFG analysis because
        // their correct usage is enforced by a different mechanism.
        branch = branch && !indirect;
        if (branch && i + 1 < n) {
            // Instruction after a branch is a leader.
            if (leaders[i + 1] == L_NONE)
                leaders[i + 1] = L_FALLTHROUGH; // fallthrough leader if not already a leader
        }
        // Target is a leader.
        if (branch) {
            ssize_t i = findinstr(instrs, n, target - addr);
            if (i >= 0)
                leaders[i] = L_TARGET;
        }
        v->addr += instr->size;
    }

    // All flags in an undefined state except F_DF.
    flagset_t undef = F_CF | F_OF | F_SF | F_ZF | F_PF | F_AF;
    ssize_t lastleader = -1;
    size_t lastloc = addr;
    size_t loc = addr;
    for (size_t i = 0; i < n; i++) {
        if (leaders[i]) {
            v->addr = lastloc;
            if (lastleader != -1)
                analyzeblock(v, undef, &instrs[lastleader], i - lastleader);
            if (leaders[i] != L_FALLTHROUGH) {
                // Only update for non-fallthrough leaders.
                lastleader = i;
                lastloc = loc;
            }
        }
        loc += instrs[i].size;
    }
    // final basic block
    v->addr = lastloc;
    analyzeblock(v, undef, &instrs[lastleader], n - lastleader);
}
