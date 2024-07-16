#include <stdio.h>

#include "riscv64.h"
#include "op.h"

void
riscv64_display(FILE* output, struct op* ops)
{
    struct op* op = ops;
    while (op) {
        fprintf(output, "%s\n", op->text);
        op = op->next;
    }
}
