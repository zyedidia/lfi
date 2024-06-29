#pragma once

enum flags {
    F_CF = 1 << 0,
    F_OF = 1 << 1,
    F_SF = 1 << 2,
    F_ZF = 1 << 3,
    F_PF = 1 << 4,
    F_AF = 1 << 5,
    F_DF = 1 << 6,
    F_NT = 1 << 7,
};

// Flags observed by condition codes.
enum {
    CC_O   = F_OF,
    CC_NO  = F_OF,
    CC_B   = F_CF,
    CC_C   = F_CF,
    CC_NAE = F_CF,
    CC_NB  = F_CF,
    CC_NC  = F_CF,
    CC_AE  = F_CF,
    CC_E   = F_ZF,
    CC_Z   = F_ZF,
    CC_NE  = F_ZF,
    CC_NZ  = F_ZF,
    CC_BE  = F_CF | F_ZF,
    CC_NA  = F_CF | F_ZF,
    CC_NBE = F_CF | F_ZF,
    CC_A   = F_CF | F_ZF,
    CC_S   = F_SF,
    CC_NS  = F_SF,
    CC_P   = F_PF,
    CC_PE  = F_PF,
    CC_NP  = F_PF,
    CC_PO  = F_PF,
    CC_L   = F_SF | F_OF,
    CC_NGE = F_SF | F_OF,
    CC_NL  = F_SF | F_OF,
    CC_GE  = F_SF | F_OF,
    CC_LE  = F_SF | F_OF | F_ZF,
    CC_NG  = F_SF | F_OF | F_ZF,
    CC_NLE = F_SF | F_OF | F_ZF,
    CC_G   = F_SF | F_OF | F_ZF,
    CC_NU  = F_PF,
    CC_U   = F_PF,
};

extern enum flags flagread[];
extern enum flags flagassign[];
