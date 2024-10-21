#pragma once

#include <string.h>
#include <stdbool.h>

typedef struct {
    bool dump;
    bool disasm;
    bool run;
    size_t n;
} Args;

extern Args args;
