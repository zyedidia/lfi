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
};

extern struct arguments args;
