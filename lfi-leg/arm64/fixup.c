#include <assert.h>
#include <stdio.h>

#include "op.h"
#include "ht.h"

enum {
    FIXUP_DIST = 6000,
};

static int
dist(int a, int b)
{
    int d = a - b;
    if (d < 0)
        d = -d;
    return d;
}

// Display the ops, and do any final fixups (short branches, and .tlsdesccall)
void
display(FILE* output, struct op* ops)
{
    struct ht labels;
    int icount = 0;
    int r = ht_alloc(&labels, 1024);
    assert(r == 0);

    struct op* op = ops;
    while (op) {
        if (op->label != NULL) {
            ht_put(&labels, op->label, icount);
        }
        icount += op->insn ? 1 : 0;
        op = op->next;
    }

    icount = 0;
    op = ops;
    while (op) {
        if (!op->relocated && !op->insn && strncmp(op->text, ".tlsdesccall", strlen(".tlsdesccall")) == 0) {
            // swap with the next instruction
            oplocate(op->next);
            struct op* n = op->next;
            opremove(op);
            opinsert(op);
            op->relocated = true;
            op = n;
        }
        if (op->shortbr) {
            bool found;
            int tcount = ht_get(&labels, op->target, &found);
            if (found && op->replace && dist(tcount, icount) > FIXUP_DIST) {
                fprintf(output, "%s\n", op->replace);
            } else {
                fprintf(output, "%s\n", op->text);
            }
        } else {
            fprintf(output, "%s\n", op->text);
        }
        icount += op->insn ? 1 : 0;
        op = op->next;
    }
}
