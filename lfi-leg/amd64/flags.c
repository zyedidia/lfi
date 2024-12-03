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
    case FLAGS_POSTLINK:
        if (args.boxtype <= BOX_SYSCALLS)
            return "--bundle=0";
        else if (args.cfi == CFI_BUNDLE16)
            return "--bundle=16";
        else if (args.cfi == CFI_BUNDLE32)
            return "--bundle=32";
        return "";
    case FLAGS_CLANG:
        if (args.boxtype > BOX_BUNDLEJUMPS)
            flags = xasprintf("-mllvm --reserve-r14 -mllvm --reserve-r11");
        else if (args.boxtype == BOX_BUNDLEJUMPS)
            flags = xasprintf("-mllvm --reserve-r11");
        else if (args.boxtype == BOX_SYSCALLS)
            flags = xasprintf("-mllvm --reserve-r14");
        if (args.cfi == CFI_BUNDLE16)
            flags = xasprintf("%s -mllvm -align-labels=16", flags);
        else if (args.cfi == CFI_BUNDLE32)
            flags = xasprintf("%s -mllvm -align-labels=32", flags);
        if (args.meter != METER_NONE)
            flags = xasprintf("%s -mllvm --reserve-r12", flags);
        break;
    case FLAGS_GCC:
        if (args.boxtype > BOX_BUNDLEJUMPS)
            flags = xasprintf("-ffixed-r11 -ffixed-r14");
        else if (args.boxtype == BOX_BUNDLEJUMPS)
            flags = xasprintf("-ffixed-r11");
        else if (args.boxtype == BOX_SYSCALLS)
            flags = xasprintf("-ffixed-r14 -ffixed-r11");
        if (args.cfi == CFI_BUNDLE16)
            flags = xasprintf("%s -falign-labels=16 -falign-functions=16", flags);
        else if (args.cfi == CFI_BUNDLE32)
            flags = xasprintf("%s -falign-labels=32 -falign-functions=32", flags);
        if (args.p2size == 0)
            flags = xasprintf("%s -ffixed-r15", flags);
        if (args.meter != METER_NONE)
            flags = xasprintf("%s -ffixed-r12", flags);
        if (args.poc)
            flags = xasprintf("%s -fno-plt", flags);
        break;
    default:
        assert(0);
    }
    if (!args.allowtls && compiler != FLAGS_POSTLINK) {
        flags = xasprintf("%s -mno-tls-direct-seg-refs -mtls-dialect=gnu2", flags);
    }
    if (args.sysexternal)
        flags = xasprintf("%s -ffixed-r13", flags);
    return flags;
}
