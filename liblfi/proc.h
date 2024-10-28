#pragma once

#include "lfi.h"
#include "mmap.h"

enum {
    CODEMAX = 1ULL * 1024 * 1024 * 1024,

    GUARD1SZ = 80 * 1024,
    GUARD2SZ = 80 * 1024,
};

typedef struct {
    uintptr_t rtcalls[256];
    uintptr_t base;
    void* proc;
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
    void* stack;

    // info for micro processes
    uintptr_t ucodebase;
    size_t ucode;
    size_t udata;
    void* ucodealias;

    uintptr_t g1start, g1end;
    uintptr_t g2start, g2end;
    MMAddrSpace mm;

    LFISys* sys;

    LFIEngine* lfi;
    void* ctxp;
} LFIProc;

void lfi_proc_free(LFIProc* proc);

bool lfi_proc_meminit(LFIProc* proc);

bool lfi_uproc_init(LFIProc* proc, uintptr_t codebase, size_t codesize, size_t datasize);
