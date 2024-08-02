#include <stdio.h>

#include "riscv64.h"
#include "op.h"
#include "output.h"

void
riscv64_display(struct output* output, struct op* ops)
{
    struct op* op = ops;
    while (op) {
        outwriteln(output, op->text);
        op = op->next;
    }
}
