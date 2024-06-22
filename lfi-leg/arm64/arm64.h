#pragma once

#include <string.h>
#include <stdbool.h>

#include "args.h"

static const char*
num(const char* reg)
{
    if (reg[0] == 'x' || reg[0] == 'w') {
        return &reg[1];
    }
    return reg;
}

static bool
isfixed(const char* reg)
{
    if (strncmp(reg, "x18", 3) == 0)
        return true;
    if (strncmp(reg, "x21", 3) == 0)
        return true;
    if (args.sysexternal && strncmp(reg, "x25", 3) == 0)
        return true;
    return false;
}

static bool
isres(const char* reg)
{
    if (strncmp(reg, "x30", 3) == 0)
        return true;
    if (strncmp(reg, "sp", 2) == 0)
        return true;
    return false;
}

static const char*
opp(const char* tbz) {
    if (strcmp(tbz, "tbz") == 0)
        return "tbnz";
    return "tbz";
}
