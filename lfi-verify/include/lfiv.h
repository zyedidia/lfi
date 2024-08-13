#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef void (*ErrFn)(char* msg, size_t sz);

bool lfiv_verify_verbose(void* code, size_t size, uintptr_t addr, ErrFn err);

bool lfiv_verify(void* code, size_t size, uintptr_t addr);

// internal
typedef struct {
    bool failed;
    uintptr_t addr;
    ErrFn err;
} Verifier;
