#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef void (*ErrFn)(char* msg, size_t sz);

typedef bool (*VerifyVFn)(void* code, size_t size, uintptr_t addr, ErrFn err);

typedef bool (*VerifyFn)(void* code, size_t size);

bool lfiv_verify_verbose_arm64(void* code, size_t size, uintptr_t addr, ErrFn err);
bool lfiv_verify_arm64(void* code, size_t size);

bool lfiv_verify_verbose_amd64(void* code, size_t size, uintptr_t addr, ErrFn err);
bool lfiv_verify_amd64(void* code, size_t size);

typedef enum {
    BOX_FULL,
    BOX_STORES,
    BOX_BUNDLEJUMPS,
} BoxType;

typedef enum {
    CFI_BUNDLE16,
    CFI_BUNDLE32,
} CFIType;

typedef struct {
    BoxType box;
    size_t p2size;
    CFIType bundle;
} VerifyOpts;

// internal
typedef struct {
    bool failed;
    bool abort;
    uintptr_t addr;
    ErrFn err;
} Verifier;
