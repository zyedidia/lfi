#include <stdbool.h>
#include <stdio.h>

#include "args.h"
#include "op.h"

bool amd64_parseinit();

extern struct op* ops;

typedef void (*PassFn)(struct op* op);

typedef struct pass {
    PassFn fn;
    bool disabled;
} Pass;

void amd64_specialpass(struct op*);
void amd64_branchpass(struct op*);
void amd64_loadspass(struct op*);
void amd64_storespass(struct op*);
void amd64_syscallpass(struct op*);

static Pass passes[] = {
    (Pass) { .fn = &amd64_specialpass },
    (Pass) { .fn = &amd64_loadspass },
    (Pass) { .fn = &amd64_storespass },
    (Pass) { .fn = &amd64_branchpass },
    (Pass) { .fn = &amd64_syscallpass },
};

void amd64_display(FILE* output, struct op* ops);

static void
warnargs()
{
    if (args.poc)
        fprintf(stderr, "warning: --poc has no effect on amd64\n");
    if (args.noguardelim)
        fprintf(stderr, "warning: --no-guard-elim has no effect on amd64\n");
    if (args.sysexternal)
        fprintf(stderr, "warning: --sys-external has no effect on amd64\n");
}

bool
amd64_rewrite(FILE* input, FILE* output)
{
    if (!amd64_parseinit()) {
        fprintf(stderr, "%s: parser failed to initialize\n", args.input);
        return false;
    }

    warnargs();

    const size_t npass = sizeof(passes) / sizeof(passes[0]);

    for (size_t i = 0; i < npass; i++) {
        if (args.storesonly && passes[i].fn == &amd64_loadspass)
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

    amd64_display(output, ops);

    return true;
}
