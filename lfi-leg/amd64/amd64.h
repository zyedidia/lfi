#pragma once

#include <assert.h>
#include <string.h>

#include "args.h"
#include "result.h"
#include "op.h"
#include "util.h"

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
rtcall(unsigned offset)
{
    if (args.sysexternal) {
        return xasprintf("*%d(%%r13)", offset);
    } else if (args.zerobase) {
        return xasprintf("*%%gs:%d", offset);
    } else {
        return xasprintf("*%d(%%r14)", offset);
    }
}

static char
suffix(char* op)
{
    size_t len = strlen(op);
    return op[len - 1];
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
stripdollar(char* op)
{
    if (op[0] == '$')
        return op + 1;
    return op;
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
bundle_lock()
{
    switch (args.cfi) {
    case CFI_BUNDLE16:
    case CFI_BUNDLE32:
        return ".bundle_lock";
    case CFI_HW:
        return "";
    }
    assert(0);
}

static char*
bundle_unlock()
{
    switch (args.cfi) {
    case CFI_BUNDLE16:
    case CFI_BUNDLE32:
        return ".bundle_unlock";
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
bundle_mask_constant()
{
    switch (args.cfi) {
    case CFI_BUNDLE16:
        return "fffffff0";
    case CFI_BUNDLE32:
        return "ffffffe0";
    case CFI_HW:
        // no mask (just clear top 32 bits)
        return "ffffffff";
    }
    assert(0);
}

static void
bundle_mask(const char* reg)
{
    if (args.boxtype > BOX_BUNDLEJUMPS && args.p2size == 0) {
        mkinsn("andq %%r15, %s", reg);
        mkinsn("andq $0xffffffff%s, %s", bundle_mask_constant(), reg);
        mkinsn("orq %%r14, %s", reg);
    } else if (args.boxtype > BOX_BUNDLEJUMPS) {
        mkinsn("andl $0x%s, %s", bundle_mask_constant(), lo(reg));
        mkinsn("orq %%r14, %s", reg);
    } else {
        mkinsn("andq $0xffffffff%s, %s", bundle_mask_constant(), reg);
    }
}

static void
bundle_nop_indcall()
{
    // If bundlecall was used, we don't insert call padding before the call.
    // Instead it will be inserted afterwards by the assembler, and
    // lfi-postlink will fix it up.
    if (!args.bundlecall) {
        return;
    }
    switch (args.cfi) {
    case CFI_BUNDLE16:
        if (args.boxtype > BOX_BUNDLEJUMPS) {
            if (args.p2size == 0)
                mkdirective(".byte 0x0f, 0x1f, 0x00"); // 3-byte nop
            else
                mkdirective(".byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00"); // 6-byte nop
        } else {
            if (args.decl)
                mkdirective(".byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00"); // 6-byte nop
            else
                mkdirective(".byte 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 9-byte nop
        }
        break;
    case CFI_BUNDLE32:
        if (args.boxtype > BOX_BUNDLEJUMPS) {
            if (args.p2size == 0) {
                mkdirective(".byte 0x66, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 9-byte nop
                mkdirective(".byte 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 10-byte nop
            } else {
                mkdirective(".byte 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 11-byte nop
                mkdirective(".byte 0x65, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 11-byte nop
            }
        } else {
            if (args.decl)
                mkdirective(".byte 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 8-byte nop
            else
                mkdirective(".byte 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 11-byte nop
            mkdirective(".byte 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 10-byte nop
            mkdirective(".byte 0x0f, 0x1f, 0x40, 0x00"); // 4-byte nop
        }
        break;
    case CFI_HW:
        break;
    default:
        assert(0);
    }
}

static void
bundle_nop_call()
{
    if (!args.bundlecall)
        return;
    switch (args.cfi) {
    case CFI_BUNDLE16:
        mkdirective(".byte 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 11-byte nop
        return;
    case CFI_BUNDLE32:
        mkdirective(".byte 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 10-byte nop
        mkdirective(".byte 0x65, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00"); // 11-byte nop
        mkdirective(".byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00"); // 6-byte nop
        return;
    case CFI_HW:
        return;
    }
    assert(0);
}

static void
mkguards(Result r)
{
    for (size_t i = 0; i < sizeof(r.premulti) / sizeof(*r.premulti); i++) {
        if (r.premulti[i]) {
            if (r.premulti[i][0] == '.')
                if (r.premulti[i][1] == 'L')
                    mklabel(r.premulti[i]);
                else
                    mkdirective(r.premulti[i]);
            else
                mkinsn("%s", r.premulti[i]);
        }
    }
    if (r.pre)
        mkinsn("%s", r.pre);
}

static void
mkpost(Result r)
{
    if (r.post)
        mkinsn("%s", r.post);
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

// labels
extern char* funcret;

static inline void
mkfuncret(void)
{
    if (args.poc)
        mklabel(funcret);
}
