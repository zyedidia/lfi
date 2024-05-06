#pragma once

#include <string.h>

static const char*
lo(const char* reg)
{
    if (strcmp(reg, "%rax") == 0)
        return "%eax";
    if (strcmp(reg, "%rcx") == 0)
        return "%ecx";
    if (strcmp(reg, "%rdx") == 0)
        return "%edx";
    if (strcmp(reg, "%rbx") == 0)
        return "%ebx";
    if (strcmp(reg, "%rsi") == 0)
        return "%esi";
    if (strcmp(reg, "%rsp") == 0)
        return "%esp";
    if (strcmp(reg, "%rbp") == 0)
        return "%ebp";
    if (strcmp(reg, "%r8") == 0)
        return "%r8d";
    if (strcmp(reg, "%r9") == 0)
        return "%r9d";
    if (strcmp(reg, "%r10") == 0)
        return "%r10d";
    if (strcmp(reg, "%r11") == 0)
        return "%r11d";
    if (strcmp(reg, "%r12") == 0)
        return "%r12d";
    if (strcmp(reg, "%r13") == 0)
        return "%r13d";
    if (strcmp(reg, "%r14") == 0)
        return "%r14d";
    if (strcmp(reg, "%r15") == 0)
        return "%r15d";
    return reg;
}
