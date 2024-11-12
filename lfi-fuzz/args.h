#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    bool dump;
    bool disasm;
    bool run;
    size_t n;
    uint64_t seed;
} Args;

extern Args args;
