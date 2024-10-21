#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <argp.h>

#include "args.h"
#include "runner.h"
#include "generator.h"
#include "disarm64.h"

static char doc[] = "lfi-fuzz: LFI fuzzer";

static char args_doc[] = "[OPTIONS]";

static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "dump",           'd',               0,      0, "dump generated instructions", -1 },
    { "disasm",         'D',               0,      0, "dump disassembled instructions (use with --dump)", -1 },
    { "run",            'r',               0,      0, "run generated instructions", -1 },
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
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

Args args;

static size_t
ceilp(size_t x, size_t align)
{
    size_t align_mask = align - 1;
    return (x + align_mask) & ~align_mask;
}

enum {
    LDR0 = 0xf9400000,
};

int
main(int argc, char** argv)
{
    argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &args);

    if (args.n % pagesize() != 0) {
        args.n = ceilp(args.n, pagesize());
        fprintf(stderr, "info: raising instruction count to %ld\n", args.n);
    }

    size_t bufsz = args.n * sizeof(uint32_t);
    uint32_t* buf = malloc(bufsz);
    assert(buf);
    size_t ninsn = codegen(buf, args.n, (struct Options){0});

    if (args.dump && args.disasm) {
        char fmtbuf[128];
        for (size_t i = 0; i < ninsn; i++) {
            struct Da64Inst inst;
            da64_decode(buf[i], &inst);
            da64_format(&inst, fmtbuf);
            printf("%lx: %08x: %s\n", i * sizeof(uint32_t), buf[i], fmtbuf);
        }
    } else if (args.dump) {
        fwrite(buf, sizeof(uint32_t), ninsn, stdout);
    }

    if (args.run) {
        if (!runprog(buf, bufsz))
            exit(1);
    }

    return 0;
}
