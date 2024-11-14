#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <argp.h>

#include "args.h"
#include "runner.h"
#include "generator.h"
#include "disarm64.h"
#include "rand.h"

static char doc[] = "lfi-fuzz: LFI fuzzer";

static char args_doc[] = "[OPTIONS]";

static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "dump",           'd',               0,      0, "dump generated instructions", -1 },
    { "disasm",         'D',               0,      0, "dump disassembled instructions (use with --dump)", -1 },
    { "run",            'r',               0,      0, "run generated instructions", -1 },
    { "seed",           's',               "HEXNUM", 0, "generator seed (hex)", -1 },
    { "n",              'n',               "NUM",  0, "number of instructions to generate", -1 },
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
    case 'd':
        args->dump = true;
        break;
    case 'D':
        args->disasm = true;
        break;
    case 'r':
        args->run = true;
        break;
    case 'n':
        args->n = atoi(arg);
        break;
    case 's':
        args->seed = strtoll(arg, NULL, 16);
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

Args args;

void dumpasm(uint8_t*, size_t, size_t);

int
main(int argc, char** argv)
{
    argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &args);

    if (args.seed == 0) {
        args.seed = 2463534242;
    }

    rand_init();

    uint8_t* buf;
    size_t size = codegen(&buf, args.n, (struct Options){0});

    if (args.dump && args.disasm) {
        dumpasm(buf, size, args.n);
    } else if (args.dump) {
        fwrite(buf, 1, size, stdout);
    }

    if (args.run) {
        if (!runprog(buf, size))
            exit(1);
    }

    return 0;
}
