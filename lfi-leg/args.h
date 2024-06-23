#pragma once

#include <stdbool.h>

struct arguments {
    char* input;
    char* output;
    bool poc;
    bool storesonly;
    bool sysexternal;
    bool noguardelim;
    bool nosegue;
    char* arch;
};

extern struct arguments args;
