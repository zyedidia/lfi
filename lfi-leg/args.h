#pragma once

#include <stdbool.h>

enum cfi {
    CFI_BUNDLE16,
    CFI_BUNDLE32,
    CFI_HW,
};

struct arguments {
    char* input;
    char* output;
    bool poc;
    bool storesonly;
    bool sysexternal;
    bool noguardelim;
    bool nosegue;
    char* arch;
    enum cfi cfi;
};

extern struct arguments args;
