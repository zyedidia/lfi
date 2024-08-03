#include <stdbool.h>
#include <stdio.h>

#include "args.h"
#include "op.h"
#include "output.h"

bool riscv64_parseinit(FILE* input);

extern struct op* ops;

typedef void (*PassFn)(struct op* op);

typedef struct pass {
    PassFn fn;
    bool disabled;
} Pass;

void riscv64_specialpass(struct op*);
void riscv64_branchpass(struct op*);
void riscv64_loadspass(struct op*);
void riscv64_storespass(struct op*);
void riscv64_syscallpass(struct op*);

static Pass passes[] = {
    (Pass) { .fn = &riscv64_specialpass },
    (Pass) { .fn = &riscv64_loadspass },
    (Pass) { .fn = &riscv64_storespass },
    (Pass) { .fn = &riscv64_branchpass },
    (Pass) { .fn = &riscv64_syscallpass },
};

void riscv64_display(struct output* output, struct op* ops);

static void
warnargs()
{
    if (args.poc)
        fprintf(stderr, "warning: --poc has no effect on riscv64\n");
    if (args.noguardelim)
        fprintf(stderr, "warning: --no-guard-elim has no effect on riscv64\n");
    if (args.sysexternal)
        fprintf(stderr, "warning: --sys-external has no effect on riscv64\n");
    if (args.singlethread && args.boxtype != BOX_BUNDLEJUMPS)
        fprintf(stderr, "warning: --single-thread has no effect if --sandbox != bundle-jumps\n");
}

bool
riscv64_rewrite(FILE* input, struct output* output)
{
    if (!riscv64_parseinit(input)) {
        fprintf(stderr, "%s: parser failed to initialize\n", args.input);
        return false;
    }

    warnargs();

    const size_t npass = sizeof(passes) / sizeof(passes[0]);

    for (size_t i = 0; i < npass; i++) {
        passes[i].disabled = false;
        if (args.boxtype < BOX_FULL && passes[i].fn == &riscv64_loadspass)
            passes[i].disabled = true;
        if (args.boxtype < BOX_STORES && passes[i].fn == &riscv64_storespass)
            passes[i].disabled = true;
        if (args.boxtype < BOX_STORES && passes[i].fn == &riscv64_specialpass)
            passes[i].disabled = true;
        if (args.boxtype < BOX_BUNDLEJUMPS && passes[i].fn == &riscv64_branchpass)
            passes[i].disabled = true;
    }

    for (size_t i = 0; i < npass; i++) {
        if (passes[i].disabled)
            continue;
        struct op* op = ops;
        while (op) {
            struct op* next = op->next;
            passes[i].fn(op);
            op = next;
        }
    }

    riscv64_display(output, ops);

    opfreeall();

    return true;
}
