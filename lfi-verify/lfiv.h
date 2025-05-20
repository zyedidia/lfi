#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    LFI_BOX_FULL,
    LFI_BOX_STORES,
    LFI_BOX_BUNDLEJUMPS,
} LFIBoxType;

typedef enum {
    LFI_BUNDLE_NONE,
    LFI_BUNDLE8,
    LFI_BUNDLE16,
    LFI_BUNDLE32,
} LFIBundleType;

typedef enum {
    LFI_METER_NONE,
    LFI_METER_BRANCH,
    LFI_METER_FP,
    LFI_METER_TIMER,
} LFIMeterType;

typedef struct {
    // Eliminates nondeterministic instructions and,
    // in x86, prevents undefined behavior via control flags.
    bool decl;
    // position-oblivious code
    bool poc;
    LFIBoxType box;
    size_t p2size;
    LFIBundleType bundle;
    LFIMeterType meter;
    bool nobranches;
    bool noundefined;
    bool nomemops;

    void (*err)(char* msg, size_t sz);
} LFIvOpts;

typedef struct {
    LFIvOpts opts;
    bool (*verify)(void* code, size_t size, uintptr_t addr, LFIvOpts* opts);
} LFIVerifier;

bool lfiv_verify_arm64(void* code, size_t size, uintptr_t addr, LFIvOpts* opts);

bool lfiv_verify_amd64(void* code, size_t size, uintptr_t addr, LFIvOpts* opts);

bool lfiv_verify_insn_arm64(uint32_t insn, LFIvOpts* opts);

static inline bool
lfiv_verify(LFIVerifier* v, void* code, size_t size, uintptr_t addr)
{
    if (!v->verify)
        return false;
    return v->verify(code, size, addr, &v->opts);
}

#ifdef __cplusplus
}
#endif
