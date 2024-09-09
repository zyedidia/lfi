#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

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
    if (strncmp(reg, "x30", 3) == 0)
        return true;
    if (strncmp(reg, "sp", 2) == 0)
        return true;
    return false;
}

static bool
isaligned(const char* reg)
{
    if (strcmp(reg, "sp") == 0 && args.decl)
        return true;
    return false;
}

static const char*
opp(const char* tbz) {
    if (strcmp(tbz, "tbz") == 0)
        return "tbnz";
    return "tbz";
}

static char*
bundle_align()
{
    switch (args.meter) {
    case METER_BRANCH:
    case METER_BRANCH_RESUME:
    case METER_FP:
        return ".p2align 4";
    case METER_TIMER:
        return ".p2align 3";
    default:
        return "";
    }
    assert(0);
}

static char*
bundle_align_mode()
{
    switch (args.meter) {
    case METER_BRANCH:
    case METER_BRANCH_RESUME:
    case METER_FP:
        return ".bundle_align_mode 4\n";
    case METER_TIMER:
        return ".bundle_align_mode 3\n";
    default:
        return "";
    }
    assert(0);
}

static char*
bundle_bicmask()
{
    switch (args.meter) {
    case METER_BRANCH:
    case METER_BRANCH_RESUME:
        return "0xf";
    case METER_FP:
        return "0xf";
    case METER_TIMER:
        return "0x7";
    default:
        return NULL;
    }
}
