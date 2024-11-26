#include <assert.h>

#include "args.h"
#include "util.h"

static char*
flagalign(enum flags compiler, int amt)
{
    switch (compiler) {
    case FLAGS_CLANG:
        return xasprintf("-mllvm -align-labels=%d -falign-functions=%d", amt, amt);
    case FLAGS_GCC:
        return xasprintf("-falign-labels=%d -falign-functions=%d", amt, amt);
    default:
        return "";
    }
}

char*
arm64_getflags(enum flags compiler)
{
    if (args.boxtype == BOX_NONE)
        return "";
    char* flags = "";
    switch (compiler) {
    case FLAGS_POSTLINK:
        switch (args.meter) {
        case METER_BRANCH:
        case METER_BRANCH_RESUME:
            return "--meter=branch";
        case METER_FP:
            return "--meter=fp";
        case METER_TIMER:
            return "--meter=timer";
        default:
            return "";
        }
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
        flags = xasprintf("%s -ffixed-x24 -ffixed-x23 %s", flags, flagalign(compiler, 16));
        break;
    case METER_FP:
        flags = xasprintf("%s -ffixed-x24 -ffixed-x23 -ffixed-d31 %s", flags, flagalign(compiler, 16));
        break;
    case METER_TIMER:
        flags = xasprintf("%s -ffixed-x24 -ffixed-x23 %s", flags, flagalign(compiler, 8));
        break;
    default:
        break;
    }
    if (args.sysexternal)
        flags = xasprintf("%s -ffixed-x25", flags);
    /* if (args.poc) */
    /*     flags = xasprintf("%s -fno-plt", flags); */
    return flags;
}
