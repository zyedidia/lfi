#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "arm64.h"
#include "op.h"
#include "util.h"

struct op* ops;
static struct op* ops_last;

static struct op*
mkop()
{
    struct op* op = calloc(1, sizeof(struct op));
    assert(op != NULL);

    if (!ops) {
        ops = op;
    } else {
        ops_last->next = op;
    }
    ops_last = op;

    return op;
}

struct op*
mkdirective(char* text)
{
    struct op* op = mkop();
    op->text = text;
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
    op->text = xasprintf("%s: ", name);
    op->label = name;
    return op;
}

static int fixup_count;

struct op*
mktbz(char* tbz, char* reg, char* imm, char* label)
{
    struct op* op = mkop();
    op->shortbr = true;
    op->insn = true;
    op->text = xasprintf("%s %s, %s, %s\n", tbz, reg, imm, label);
    op->target = strdup(label);

    op->replace = xasprintf(
        "%s %s, %s, .LFI_FIXUP%d\n"
        "b %s\n"
        ".LFI_FIXUP%d:\n",
        opp(tbz), reg, imm, fixup_count,
        label,
        fixup_count
    );

    fixup_count++;

    return op;
}
