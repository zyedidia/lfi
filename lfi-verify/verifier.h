#pragma once

#include <stdbool.h>

#include "lfiv.h"

// internal
typedef struct {
    bool failed;
    bool abort;
    uintptr_t addr;
    void (*err)(char*, size_t);
    LFIvOpts* opts;
} Verifier;
