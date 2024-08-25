#include <assert.h>
#include <stdio.h>

#include "arm64.h"
#include "args.h"
#include "op.h"
#include "ht.h"
#include "output.h"

static int
dist(int a, int b)
{
    int d = a - b;
    if (d < 0)
        d = -d;
    return d;
}

static struct op*
findbranch(struct op* op)
{
    while (op) {
        if (op->branch)
            return op;
        op = op->next;
    }
    return NULL;
}

// Display the ops, and do any final fixups (short branches, and .tlsdesccall)
void
arm64_display(struct output* out, struct op* ops)
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

    outwrite(out, bundle_align_mode());

    icount = 0;
    op = ops;
    while (op) {
        if (!op->relocated && !op->insn && strncmp(op->text, ".tlsdesccall", strlen(".tlsdesccall")) == 0 && op->next) {
            // swap with the next instruction
            oplocate(op->next);
            struct op* n = op->next;
            opremove(op);
            opinsert(op);
            op->relocated = true;
            op = n;
        }
        if (op->shortbr != 0) {
            bool found;
            int tcount = ht_get(&labels, op->target, &found);
            if (found && op->replace && dist(tcount, icount) > op->shortbr) {
                outwriteln(out, op->replace);
            } else {
                outwriteln(out, op->text);
            }
        } else if (op->rmforward) {
            struct op* b = findbranch(op);
            if (b) {
                bool found;
                int tcount = ht_get(&labels, b->target, &found);
                if (!found || tcount <= icount)
                    outwriteln(out, op->text);
            } else {
                outwriteln(out, op->text);
            }
        } else {
            outwriteln(out, op->text);
        }
        icount += op->insn ? 1 : 0;
        op = op->next;
    }
}
