#include <stdio.h>
#include <errno.h>
#include <argp.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "lfi_tux.h"
#include "lfi.h"

typedef struct {
    uint8_t* data;
    size_t size;
} buf_t;

buf_t bufreadfile(struct Tux* tux, const char* filename);

enum {
    INPUTMAX = 256,
};

enum {
    ARG_strace   = 0x80,
    ARG_pagesize = 0x81,
};

struct Args {
    char* inputs[INPUTMAX];
    size_t ninputs;
    struct TuxOptions opts;
};

static char doc[] = "lfi-run: LFI Linux emulator";

static char args_doc[] = "INPUT...";

static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "verbose",        'V',               0,      0, "show verbose output", -1 },
    { "perf",        	'p',             	   0,      0, "enable perf support", -1 },
    { "strace",         ARG_strace,        0,      0, "show system call trace", -1 },
    { "pagesize",       ARG_pagesize,      "SIZE", 0, "system page size", -1 },
    { 0 },
};

static error_t
parse_opt(int key, char* arg, struct argp_state* state)
{
    struct Args* args = state->input;

    switch (key) {
    case 'h':
        argp_state_help(state, state->out_stream, ARGP_HELP_STD_HELP);
        break;
    case 'V':
        args->opts.verbose = true;
        break;
    case 'p':
        args->opts.perf = true;
        break;
    case ARG_strace:
        args->opts.strace = true;
        break;
    case ARG_pagesize:
        args->opts.pagesize = atoi(arg);
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

static struct argp argp = { .options = options, .parser = parse_opt, .args_doc = args_doc, .doc = doc };

struct Args args;

static size_t
mb(size_t x)
{
    return x * 1024 * 1024;
}

int
main(int argc, char** argv)
{
    argp_parse(&argp, argc, argv, ARGP_NO_HELP | ARGP_IN_ORDER, 0, &args);

    if (args.ninputs <= 0) {
        fprintf(stderr, "no input file provided\n");
        return 1;
    }

    size_t pagesize = getpagesize();
    if (args.opts.pagesize == 0)
        args.opts.pagesize = pagesize;
    if (args.opts.pagesize % pagesize != 0) {
        fprintf(stderr, "invalid pagesize %ld (host pagesize %ld)\n", args.opts.pagesize, pagesize);
        return 1;
    }

    struct LFIPlatform* plat = lfi_new_plat(args.opts.pagesize);

    args.opts.stacksize = mb(2);

    struct Tux* tux = lfi_tux_new(plat, args.opts);

    buf_t f = bufreadfile(tux, args.inputs[0]);
    if (!f.data) {
        fprintf(stderr, "error opening: %s: %s\n", args.inputs[0], strerror(errno));
        return 1;
    }

    struct TuxThread* p = lfi_tux_proc_new(tux, f.data, f.size, args.ninputs, &args.inputs[0]);
    if (!p) {
        fprintf(stderr, "error creating process\n");
        return 1;
    }

    uint64_t code = lfi_tux_proc_run(p);

    if (args.opts.verbose)
        fprintf(stderr, "[lfi-run] exited with code: %ld\n", (long) code);

    return (int) code;
}
