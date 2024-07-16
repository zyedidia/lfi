#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "args.h"

static bool
isfixed(const char* reg)
{
    if (strcmp(reg, "x18") == 0)
        return true;
    if (strcmp(reg, "x21") == 0)
        return true;
    if (args.sysexternal && strcmp(reg, "x25") == 0)
        return true;
    return false;
}

static bool
isres(const char* reg)
{
    if (strcmp(reg, "x1") == 0)
        return true;
    if (strcmp(reg, "sp") == 0)
        return true;
    if (strcmp(reg, "x2") == 0)
        return true;
    if (strcmp(reg, "ra") == 0)
        return true;
    return false;
}

