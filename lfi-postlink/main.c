#include <argp.h>
#include <stdio.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "elf.h"
#include "postlink.h"

static char doc[] = "lfi-postlink: perform LFI transformations after linking";

static char args_doc[] = "INPUT";

enum {
    ARG_bundle    = 0x80,
    ARG_meter     = 0x81,
    ARG_noprefix  = 0x82,
};

static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "arch",           'a',               "ARCH", 0, "set the target architecture (arm64,amd64)" },
    { "bundle",         ARG_bundle,        "SIZE", 0, "set the bundle size" },
    { "meter",          ARG_meter,         "TYPE", 0, "set the metering type (branch,fp,timer)" },
    { "no-prefix-pad",  ARG_noprefix,      0,      0, "disable prefix padding" },
    { 0 },
};

static error_t
parse_opt(int key, char* arg, struct argp_state* state)
{
    struct arguments* args = state->input;

    switch (key) {
    case 'h':
        argp_state_help(state, state->out_stream, ARGP_HELP_STD_HELP);
        break;
    case 'a':
        if (strcmp(arg, "amd64") != 0 && strcmp(arg, "arm64") != 0 && strcmp(arg, "riscv64") != 0) {
            fprintf(stderr, "unknown architecture: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        args->arch = arg;
        break;
    case ARG_bundle:
        args->bundle = atoi(arg);
        break;
    case ARG_meter:
        if (strcmp(arg, "branch") == 0)
            args->meter = METER_BRANCH;
        else if (strcmp(arg, "branch-resume") == 0)
            args->meter = METER_BRANCH;
        else if (strcmp(arg, "fp") == 0)
            args->meter = METER_FP;
        else if (strcmp(arg, "timer") == 0)
            args->meter = METER_TIMER;
        break;
    case ARG_noprefix:
        args->noprefix = true;
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

static char*
getarch()
{
#if defined(__x86_64__) || defined(_M_X64)
    return "amd64";
#elif defined(__aarch64__) || defined(_M_ARM64)
    return "arm64";
#elif defined(__riscv__)
    return "riscv64";
#else
    fprintf(stderr, "running on unsupported architecture, use --arch to specify target\n");
    exit(1);
#endif
}

struct arguments args;

int
main(int argc, char** argv)
{
    args.input = "";
    argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &args);

    if (strcmp(args.input, "") == 0) {
        fprintf(stderr, "error: no input file\n");
        return 1;
    }

    if (args.arch == NULL) {
        args.arch = getarch();
    }
    if (strcmp(args.arch, "amd64") == 0 && args.bundle == 0) {
        // default bundle size for x86-64
        args.bundle = 16;
    }

    FILE* f = fopen(args.input, "r+");
    if (!f) {
        fprintf(stderr, "error opening %s: %s\n", args.input, strerror(errno));
        exit(1);
    }

    if (fseek(f, 0, SEEK_END) != 0) {
        perror("fseek");
        exit(1);
    }
    long sz = ftell(f);
    if (fseek(f, 0, SEEK_SET) != 0) {
        perror("fseek");
        exit(1);
    }

    uint8_t* buf = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(f), 0);
    if (buf == (uint8_t*) -1) {
        perror("mmap");
        exit(1);
    }
    fclose(f);

    if (strcmp(args.arch, "amd64") == 0)
        amd64_postlink(buf, sz);
    else if (strcmp(args.arch, "arm64") == 0)
        arm64_postlink(buf, sz);

    munmap(buf, sz);

    return 0;
}
