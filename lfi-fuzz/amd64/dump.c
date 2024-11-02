#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "fadec.h"

void
dumpasm(uint8_t* buf, size_t size, size_t n)
{
    char fmtbuf[64];
    size_t i = 0;
    size_t count = 0;
    while (i < size) {
        FdInstr instr;
        fd_decode(&buf[i], size - i, 64, 0, &instr);
        fd_format(&instr, fmtbuf, sizeof(fmtbuf));
        printf("%lx: %s\n", i, fmtbuf);
        i += instr.size;
        count++;
        if (count >= n)
            break;
    }
}
