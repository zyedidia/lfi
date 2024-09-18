#include <assert.h>
#include <errno.h>
#include <argp.h>

#include "args.h"
#include "lfix.h"

static char doc[] = "lfi-run: LFI runner";

static char args_doc[] = "INPUT...";

enum {
    ARG_max_procs = 0x80,
};

// Future options:
// * --p2size=
// * --poc
// * --max-procs
// * --no-verify
// * --gas=
static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "max-procs",      ARG_max_procs,     0,      0, "show the maximum number of processes", -1 },
    { 0 },
};

static error_t
parse_opt(int key, char* arg, struct argp_state* state)
{
    Args* args = state->input;

    switch (key) {
    case 'h':
        argp_state_help(state, state->out_stream, ARGP_HELP_STD_HELP);
        break;
    case ARG_max_procs:
        args->max_procs = true;
        break;
    case ARGP_KEY_ARG:
        if (args->ninputs < INPUTMAX)
            args->inputs[args->ninputs++] = arg;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

Args args;

int
main(int argc, char** argv)
{
    argp_parse(&argp, argc, argv, ARGP_NO_HELP | ARGP_IN_ORDER, 0, &args);

    LFIXEngine engine;
    bool b = lfix_init(&engine);
    if (!b) {
        fprintf(stderr, "error initializing: %s\n", lfi_strerror());
        return 1;
    }

    if (args.max_procs) {
        printf("max processes: %ld\n", lfi_maxprocs(engine.l_engine));
        return 1;
    }

    if (args.ninputs <= 0) {
        fprintf(stderr, "no input file provided\n");
        return 1;
    }

    FILE* f = fopen(args.inputs[0], "rb");
    if (!f) {
        fprintf(stderr, "error opening %s: %s\n", args.inputs[0], strerror(errno));
        return 1;
    }

    LFIXProc* p = lfix_proc_newfile(&engine, fileno(f), args.ninputs, &args.inputs[0]);
    if (!p) {
        fprintf(stderr, "error creating process: %s\n", lfi_strerror());
        return 1;
    }

    fclose(f);

    uint64_t r = lfi_proc_start(p->l_proc);
    printf("exited: %ld\n", r);

    return 0;
}
