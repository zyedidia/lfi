#include "flags.h"

#include "fadec.h"

// See Intel manual Table A-2

// Flags read by instructions. This table must be complete.
enum flags flagread[FDI_XTEST + 1] = {
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
};

// Flags assigned by instruction. This table can be incomplete. For each
// mnemonic, 1 indicates flag defined, 0 indicates flag undefined.
enum flags flagassign[FDI_XTEST + 1] = {
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
};
