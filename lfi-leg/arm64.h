#pragma once

#include <string.h>
#include <stdbool.h>

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

static bool
isload(const char* inst)
{
    return true;
}

static bool
isres(const char* reg)
{
    if (strncmp(reg, "x21", 3) == 0)
        return true;
    if (strncmp(reg, "x18", 3) == 0)
        return true;
    if (strncmp(reg, "x30", 3) == 0)
        return true;
    if (strncmp(reg, "sp", 2) == 0)
        return true;
    return false;
}
