#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ErrFn)(char* msg, size_t sz);

typedef bool (*VerifyVFn)(void* code, size_t size, uintptr_t addr, ErrFn err);

typedef bool (*VerifyFn)(void* code, size_t size);

bool lfiv_verify_verbose_arm64(void* code, size_t size, uintptr_t addr, ErrFn err);
bool lfiv_verify_arm64(void* code, size_t size);
bool lfiv_verify_insn_arm64(uint32_t insn);

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

typedef enum {
    METER_BRANCH,
    METER_FP,
    METER_COUNT,
} MeterType;

typedef struct {
    bool decl;
    bool poc;
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
    VerifyOpts opts;
} Verifier;

#ifdef __cplusplus
}
#endif
