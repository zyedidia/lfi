#pragma once

#include "lfi.h"
#include "sobox.h"
#include "mmap.h"
#include "fd.h"
#include "sys.h"

#include "stub/stub.h"

enum {
    BRKMAXSIZE = 512ULL * MB,
    PROCSIZE   = 4ULL * GB,
};

typedef struct SoboxProc {
    Sobox* sbx;
    struct lfi_proc* proc;
    uintptr_t base;

    uintptr_t brkbase;
    size_t brksize;
    MMAddrSpace mm;

    SoboxFns* fns;

    FDTable fdtable;
} SoboxProc;

uintptr_t procaddr(SoboxProc* proc, uintptr_t addr);

uintptr_t procuseraddr(SoboxProc* proc, uintptr_t addr);

int procmapany(SoboxProc* proc, size_t size, int prot, int flags, int fd, off_t offset, uintptr_t* o_mapstart);

int procmapat(SoboxProc* proc, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset);

int procunmap(SoboxProc* proc, uintptr_t start, size_t size);
