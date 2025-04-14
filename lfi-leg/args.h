#pragma once

#include <stdbool.h>

enum cfi {
    CFI_BUNDLE32 = 0,
    CFI_BUNDLE16 = 1,
    CFI_HW       = 2,
};

enum boxtype {
    BOX_NONE        = 0,
    BOX_SYSCALLS    = 1,
    BOX_BUNDLEJUMPS = 2,
    BOX_JUMPS       = 3,
    BOX_STORES      = 4,
    BOX_FULL        = 5,
};

enum meter {
    METER_NONE          = 0,
    METER_BRANCH        = 1,
    METER_BRANCH_RESUME = 2,
    METER_FP            = 3,
    METER_TIMER         = 4,
};

enum flags {
    FLAGS_NONE,
    FLAGS_CLANG,
    FLAGS_GCC,
    FLAGS_POSTLINK,
};

struct arguments {
    char* input;
    char* output;
    bool poc;
    bool sysexternal;
    bool noguardelim;
    bool nopextelim;
    bool nosegue;
    char* arch;
    enum cfi cfi;
    enum boxtype boxtype;
    bool singlethread;
    bool decl;
    enum meter meter;
    enum flags flags;
    int p2size; // 0 means variable (size stored in register)
    bool bundlecall;
    bool useret;
    bool allowtls;
    bool nopie;
    bool syscall;
    bool largeguard;
    bool zerobase;
};

extern struct arguments args;
