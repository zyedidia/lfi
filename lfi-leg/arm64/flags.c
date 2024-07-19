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
    case FLAGS_POSTLINK:
        return "";
    case FLAGS_CLANG:
        flags = xasprintf("-mllvm --aarch64-enable-compress-jump-tables=false");
        break;
    case FLAGS_GCC:
        break;
    default:
        assert(0);
    }
    flags = xasprintf("%s -ffixed-x18 -ffixed-x21 -ffixed-x22 -ffixed-x30", flags);
    switch (args.meter) {
    case METER_BRANCH:
    case METER_BRANCH_RESUME:
        flags = xasprintf("%s -ffixed-x24 -ffixed-x23 -falign-functions=16 -falign-labels=16", flags);
        break;
    case METER_FP:
        flags = xasprintf("%s -ffixed-x24 -ffixed-x23 -ffixed-d31 -falign-functions=16 -falign-labels=16", flags);
        break;
    case METER_TIMER:
        flags = xasprintf("%s -ffixed-x24 -ffixed-x23 -falign-functions=8 -falign-labels=8", flags);
        break;
    default:
        break;
    }
    if (args.sysexternal)
        flags = xasprintf("%s -ffixed-x25", flags);
    return flags;
}
