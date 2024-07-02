#include <assert.h>

#include "args.h"
#include "util.h"

char*
amd64_getflags(enum flags compiler)
{
    if (args.boxtype == BOX_NONE)
        return "";
    char* flags = "";
    switch (compiler) {
    case FLAGS_CLANG:
        if (args.boxtype > BOX_BUNDLEJUMPS)
            flags = xasprintf("-mllvm --reserve-r14 -mllvm --reserve-r15");
        if (args.cfi == CFI_BUNDLE16)
            flags = xasprintf("%s -mllvm -align-labels=16", flags);
        else if (args.cfi == CFI_BUNDLE32)
            flags = xasprintf("%s -mllvm -align-labels=32", flags);
        break;
    case FLAGS_GCC:
        if (args.boxtype > BOX_BUNDLEJUMPS)
            flags = xasprintf("-ffixed-r15 -ffixed-r14");
        if (args.cfi == CFI_BUNDLE16)
            flags = xasprintf("%s -falign-labels=16 -falign-functions=16", flags);
        else if (args.cfi == CFI_BUNDLE32)
            flags = xasprintf("%s -falign-labels=32 -falign-functions=32", flags);
        if (args.p2size == 0)
            flags = xasprintf("%s -ffixed-r13", flags);
        break;
    default:
        assert(0);
    }
    return flags;
}
