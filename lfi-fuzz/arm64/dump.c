#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "disarm64.h"

void
dumpasm(uint8_t* buf, size_t size, size_t n)
{
    uint32_t* insns = (uint32_t*) buf;
    size_t ninsn = size / sizeof(uint32_t);
    char fmtbuf[128];
    for (size_t i = 0; i < ninsn; i++) {
        struct Da64Inst inst;
        da64_decode(insns[i], &inst);
        da64_format(&inst, fmtbuf);
        printf("%lx: %08x: %s\n", i * sizeof(uint32_t), buf[i], fmtbuf);
        if (i >= n)
            break;
    }
}
