#include <argp.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "args.h"
#include "op.h"

static char doc[] = "lfi-gen: rewrite assembly files to be compatible with LFI";

static char args_doc[] = "INPUT";

static struct argp_option options[] = {
    { "output",         'o', "FILE", 0, "Output to FILE instead of standard output" },
    { "poc",            'p', 0,      0, "Produce position-oblivious code (implies -e)" },
    { "sys-external",   'e', 0,      0, "Store runtime call table outside sandbox"},
    { "no-guard-elim",  'g', 0, 0, "Do not run redundant guard elimination"},
    // { "meter",          'm', 0,      0, "Enable gas metering for preemption (TODO)" },
    // bundle sizes
    // deterministic
    // configure registers? configure sysreg x25?
    { "stores-only",    's', 0,      0, "Only sandbox stores/jumps (allow unsandboxed loads)" },
    { 0 },
};

static error_t
parse_opt(int key, char* arg, struct argp_state* state)
{
    struct arguments* args = state->input;

    switch (key) {
    case 'o':
        args->output = arg;
        break;
    case 'p':
        args->poc = true;
        args->sysexternal = true;
        break;
    case 's':
        args->storesonly = true;
        break;
    case 'g':
        args->noguardelim = true;
        break;
    case 'e':
        args->sysexternal = true;
        break;
    case ARGP_KEY_ARG:
        args->input = arg;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

FILE* input;
FILE* output;

static FILE*
argopen(char* arg, const char* mode, FILE* std)
{
    if (strcmp(arg, "-") == 0) {
        return std;
    }
    FILE* f = fopen(arg, mode);
    if (!f) {
        perror("fopen");
        exit(1);
    }
    return f;
}

struct arguments args;

bool parseinit();

extern struct op* ops;

typedef void (*PassFn)(struct op* op);

typedef struct pass {
    PassFn fn;
    bool disabled;
} Pass;

void specialpass(struct op*);
void pocpass(struct op*);
void branchpass(struct op*);
void loadspass(struct op*);
void storespass(struct op*);
void syscallpass(struct op*);

void guardelim(struct op* ops);

Pass passes[] = {
    (Pass) { .fn = &specialpass },
    (Pass) { .fn = &pocpass, .disabled = true },
    (Pass) { .fn = &branchpass },
    (Pass) { .fn = &loadspass },
    (Pass) { .fn = &storespass },
    (Pass) { .fn = &syscallpass },
};

void display(FILE* output, struct op* ops);

int
main(int argc, char** argv)
{
    args.output = "-";
    args.input = "-";

    argp_parse(&argp, argc, argv, 0, 0, &args);

    input = argopen(args.input, "r", stdin);
    output = argopen(args.output, "w", stdout);

    if (!parseinit()) {
        fprintf(stderr, "%s: parser failed to initialize\n", args.input);
        return 1;
    }

    const size_t npass = sizeof(passes) / sizeof(passes[0]);

    for (size_t i = 0; i < npass; i++) {
        if (args.storesonly && passes[i].fn == &loadspass)
            passes[i].disabled = true;
        if (args.poc && passes[i].fn == &pocpass)
            passes[i].disabled = false;
    }
    printf("init\n");

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

    if (!args.noguardelim)
        guardelim(ops);

    display(output, ops);

    fclose(input);
    fclose(output);

    return 0;
}
