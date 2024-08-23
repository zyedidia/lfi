#pragma once

#include "lfi.h"

enum {
    CODEMAX = 1ULL * 1024 * 1024 * 1024,

    GUARD1SZ = 80 * 1024,
    GUARD2SZ = 80 * 1024,
};

typedef struct {
    uintptr_t rtcalls[256];
    uintptr_t base;
} LFISys;

typedef struct LFIMem {
    uintptr_t base;
    size_t size;
    int prot;

    struct LFIMem* next;
    struct LFIMem* prev;
} LFIMem;

typedef struct LFIProc {
    void* kstackp;
    void* tp;
    LFIRegs regs;
    uintptr_t base;
    size_t size;

    LFISys* sys;
    void* stack;

    LFIEngine* lfi;
    void* ctxp;
} LFIProc;

void lfi_proc_free(LFIProc* proc);
