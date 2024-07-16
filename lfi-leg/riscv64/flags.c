#include <assert.h>

#include "args.h"
#include "util.h"

char*
riscv64_getflags(enum flags compiler)
{
    if (args.boxtype == BOX_NONE)
        return "";
    char* flags = "";
    
    flags = xasprintf("%s -ffixed-x18 -ffixed-x21 -ffixed-x22 -ffixed-x1", flags);
    
    return flags;
}
