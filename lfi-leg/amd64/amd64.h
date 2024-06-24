#pragma once

#include <assert.h>
#include <string.h>

#include "args.h"
#include "result.h"
#include "op.h"

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
    if (strcmp(reg, "%rdi") == 0)
        return "%edi";
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

static char*
lop(char* op)
{
    size_t len = strlen(op);
    char* ret = strdup(op);
    if (op[len - 1] == 'q')
        ret[len - 1] = 'l';
    return ret;
}

static char*
bundle_align_mode()
{
    switch (args.cfi) {
    case CFI_BUNDLE16:
        return ".bundle_align_mode 4\n";
    case CFI_BUNDLE32:
        return ".bundle_align_mode 5\n";
    case CFI_HW:
        return "";
    }
    assert(0);
}

static char*
bundle_align()
{
    switch (args.cfi) {
    case CFI_BUNDLE16:
        return ".p2align 4";
    case CFI_BUNDLE32:
        return ".p2align 5";
    case CFI_HW:
        return ".p2align 0";
    }
    assert(0);
}

static char*
bundle_mask()
{
    switch (args.cfi) {
    case CFI_BUNDLE16:
        return "0xfffffff0";
    case CFI_BUNDLE32:
        return "0xffffffe0";
    case CFI_HW:
        // no mask (just clear top 32 bits)
        return "0xffffffff";
    }
    assert(0);
}

static void
mkguards(Result r)
{
    if (r.pre)
        mkinsn("%s", r.pre);
}

static char*
strclean(char* s, size_t n)
{
    char* sdup = strndup(s, n);
    for (size_t i = 0; i < n; i++) {
        if (sdup[i] == ';' || sdup[i] == '\n' || sdup[i] == '\r')
            sdup[i] = ' ';
    }
    return sdup;
}
