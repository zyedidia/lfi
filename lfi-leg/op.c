#define _GNU_SOURCE

#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "arm64/arm64.h"
#include "op.h"
#include "util.h"

struct op* ops;
static struct op* ops_last;
static struct op* location;

static struct op*
mkop()
{
    struct op* op = calloc(1, sizeof(struct op));
    assert(op != NULL);

    return opinsert(op);
}

struct op*
opinsert(struct op* op)
{
    if (!ops) {
        ops = op;
        ops_last = op;
        location = ops_last;
        return op;
    }

    struct op* n = location ? location : ops_last;

    op->next = n->next;
    op->prev = n;

    if (n->next) {
        n->next->prev = op;
    } else {
        ops_last = op;
    }
    n->next = op;
    location = op;
    return op;
}

struct op*
mkdirective(char* text)
{
    struct op* op = mkop();
    op->text = strdup(text);
    return op;
}

struct op*
mkcomment(char* text)
{
    struct op* op = mkop();
    op->text = strdup(text);
    return op;
}

struct op*
mkinsn(char* fmt, ...)
{
    va_list ap;
    char* strp = NULL;
    struct op* op = mkop();
    va_start(ap, fmt);
    int error = vasprintf(&strp, fmt, ap);
    va_end(ap);
    if (error == -1) {
        perror("mkinsn");
        exit(1);
    }

    op->text = strp;
    op->insn = true;

    return op;
}

struct op*
mklabel(char* name)
{
    struct op* op = mkop();
    op->text = xasprintf("%s:", name);
    op->label = strdup(name);
    return op;
}

enum {
    TBZ_DIST = 6000,
    BCC_DIST = 190000,
};

static int fixup_count;

static char*
tbzextra()
{
    if (args.meter == METER_NONE)
        return "";
    else if (args.meter == METER_TIMER)
        return ".bundle_unlock\n"
            ".bundle_lock\n"
            "nop\n";

    return ".bundle_unlock\n"
        ".bundle_lock\n"
        "nop\nnop\nnop\n";
}

struct op*
mktbz(char* tbz, char* reg, char* imm, char* label)
{
    struct op* op = mkop();
    op->shortbr = TBZ_DIST;
    op->insn = true;
    op->text = xasprintf("%s %s, %s, %s", tbz, reg, imm, label);
    op->target = strdup(label);
    op->branch = true;

    op->replace = xasprintf(
        "%s %s, %s, .LFI_FIXUP%d\n"
        "%s"
        "b %s\n"
        ".LFI_FIXUP%d:\n",
        opp(tbz), reg, imm, fixup_count,
        tbzextra(),
        label,
        fixup_count
    );

    fixup_count++;

    return op;
}

struct op*
mkbcc(char* bcc, char* label)
{
    struct op* op = mkop();
    op->shortbr = BCC_DIST;
    op->insn = true;
    op->text = xasprintf("%s %s", bcc, label);
    op->target = strdup(label);
    op->branch = true;

    op->replace = xasprintf(
        "%s .LFI_FIXUP%d\n"
        "b .LFI_NT%d\n"
        ".LFI_FIXUP%d:\n"
        "b %s\n"
        ".LFI_NT%d:\n",
        bcc, fixup_count,
        fixup_count,
        fixup_count,
        label,
        fixup_count
    );

    fixup_count++;

    return op;
}

void
opremove(struct op* n)
{
    if (n->next) {
        n->next->prev = n->prev;
    } else {
        ops_last = n->prev;
    }
    if (n->prev) {
        n->prev->next = n->next;
    } else {
        ops = n->next;
    }
}

void
oplocate(struct op* op)
{
    location = op;
}

void
opfree(struct op* op)
{
    free(op->text);
    free(op->label);
    free(op->replace);
    free(op->target);
    free(op);
}

void
opfreeall()
{
    struct op* op = ops;
    while (op) {
        struct op* next = op->next;
        opfree(op);
        op = next;
    }
    ops = NULL;
    ops_last = NULL;
    location = NULL;
}
