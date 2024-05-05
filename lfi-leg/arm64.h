#pragma once

#include <string.h>

static const char*
lo(const char* reg)
{
    if (strncmp(reg, "sp", 2) == 0) {
        return "wsp";
    } else if (reg[0] == 'x') {
        char* s = strndup(reg, 3);
        s[0] = 'w';
        return s;
    }
    return reg;
}
