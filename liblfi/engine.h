#pragma once

#include "lfi.h"
#include "buddy.h"

enum {
    LFI_ADDR_SPACE_MAX = 16,
};

typedef struct {
    void* base;
    size_t size;
    size_t active;
    struct buddy* alloc;
} LFIAddrSpace;

typedef struct LFIEngine {
    LFIAddrSpace spaces[LFI_ADDR_SPACE_MAX];
    size_t nspaces;
    LFIOptions opts;
} LFIEngine;
