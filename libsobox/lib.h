#pragma once

#include "lfi.h"
#include "sobox.h"
#include "mmap.h"
#include "fd.h"

typedef struct SoboxLib {
    Sobox* sbx;
    struct lfi_proc* proc;
    uintptr_t base;
    MMAddrSpace* mm;
    FDTable fdtable;
} SoboxLib;
