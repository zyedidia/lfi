#include <stdbool.h>
#include <stdio.h>

#include "args.h"
#include "op.h"
#include "output.h"

bool arm64_parseinit(FILE*);

extern struct op* ops;

typedef void (*PassFn)(struct op* op);

typedef struct pass {
    PassFn fn;
    bool disabled;
} Pass;

void arm64_specialpass(struct op*);
void arm64_pocpass(struct op*);
void arm64_branchpass(struct op*);
void arm64_loadspass(struct op*);
void arm64_storespass(struct op*);
void arm64_meterpass(struct op*);
void arm64_syscallpass(struct op*);
void arm64_tlspass(struct op*);

void arm64_guardelim(struct op* ops);

static Pass passes[] = {
    (Pass) { .fn = &arm64_specialpass },
    (Pass) { .fn = &arm64_pocpass, .disabled = true },
    (Pass) { .fn = &arm64_branchpass },
    (Pass) { .fn = &arm64_loadspass },
    (Pass) { .fn = &arm64_storespass },
    (Pass) { .fn = &arm64_meterpass, .disabled = true },
    (Pass) { .fn = &arm64_tlspass },
    (Pass) { .fn = &arm64_syscallpass },
};

void arm64_display(struct output* output, struct op* ops);

static void
warnargs()
{
    if (args.nosegue)
        fprintf(stderr, "warning: --no-segue has no effect on arm64\n");
    if (args.cfi != 0) // default value
        fprintf(stderr, "warning: --cfi has no effect on arm64\n");
    if (args.singlethread)
        fprintf(stderr, "warning: --single-thread has no effect on arm64\n");
    if (args.p2size != 32)
        fprintf(stderr, "warning: --p2size must be 32 on arm64\n");
}

bool
arm64_rewrite(FILE* input, struct output* output)
{
    if (!arm64_parseinit(input)) {
        fprintf(stderr, "%s: parser failed to initialize\n", args.input);
        return false;
    }

    warnargs();

    const size_t npass = sizeof(passes) / sizeof(passes[0]);

    for (size_t i = 0; i < npass; i++) {
        passes[i].disabled = false;
        if (args.boxtype < BOX_FULL && passes[i].fn == &arm64_loadspass)
            passes[i].disabled = true;
        if (args.boxtype < BOX_STORES && passes[i].fn == &arm64_storespass)
            passes[i].disabled = true;
        if (args.boxtype < BOX_BUNDLEJUMPS && passes[i].fn == &arm64_branchpass)
            passes[i].disabled = true;
        if (args.boxtype == BOX_SYSCALLS && passes[i].fn == &arm64_specialpass) {
            passes[i].disabled = true;
            args.noguardelim = true;
        }
        if (args.poc && passes[i].fn == &arm64_pocpass)
            passes[i].disabled = false;
        else if (passes[i].fn == &arm64_pocpass)
            passes[i].disabled = true;
        if (args.meter != METER_NONE && passes[i].fn == &arm64_meterpass)
            passes[i].disabled = false;
        else if (passes[i].fn == &arm64_meterpass)
            passes[i].disabled = true;
        if (args.allowtls && passes[i].fn == &arm64_tlspass)
            passes[i].disabled = true;
        else if (passes[i].fn == &arm64_tlspass)
            passes[i].disabled = false;
        if (args.syscall && passes[i].fn == &arm64_syscallpass)
            passes[i].disabled = true;
        else if (passes[i].fn == &arm64_syscallpass)
            passes[i].disabled = false;
    }

    for (size_t i = 0; i < npass; i++) {
        if (passes[i].disabled)
            continue;
        struct op* op = ops;
        bool trusted = false;
        while (op) {
            struct op* next = op->next;
            if (op->truststart)
                trusted = true;
            if (op->notruststart)
                trusted = false;

            if (!trusted)
                passes[i].fn(op);

            op = next;
        }
    }

    if (!args.noguardelim)
        arm64_guardelim(ops);

    arm64_display(output, ops);

    opfreeall();

    return true;
}
