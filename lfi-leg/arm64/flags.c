#include <assert.h>

#include "args.h"
#include "util.h"

char*
arm64_getflags(enum flags compiler)
{
    if (args.boxtype == BOX_NONE)
        return "";
    char* flags = "";
    switch (compiler) {
    case FLAGS_CLANG:
        flags = xasprintf("-mllvm --aarch64-enable-compress-jump-tables=false");
        break;
    case FLAGS_GCC:
        break;
    default:
        assert(0);
    }
    flags = xasprintf("%s -ffixed-x18 -ffixed-x21 -ffixed-x22 -ffixed-x30", flags);
    if (args.meter == METER_BRANCH || args.meter == METER_TIMER)
        flags = xasprintf("%s -ffixed-x23", flags);
    else if (args.meter == METER_FP)
        flags = xasprintf("%s -ffixed-x23 -ffixed-d31", flags);
    if (args.sysexternal)
        flags = xasprintf("%s -ffixed-x25", flags);
    return flags;
}
