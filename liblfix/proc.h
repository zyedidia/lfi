#include <stdint.h>

#include "lfix.h"

enum {
    BRKMAXSIZE = 512ULL * 1024 * 1024,
};

uintptr_t procaddr(LFIXProc* proc, uintptr_t addr);

uintptr_t procuseraddr(LFIXProc* proc, uintptr_t addr);
