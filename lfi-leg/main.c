#include <argp.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "args.h"
#include "op.h"

static char doc[] = "lfi-gen: rewrite assembly files to be compatible with LFI";

static char args_doc[] = "INPUT";

enum {
    ARG_poc           = 0x80,
    ARG_sys_external  = 0x81,
    ARG_no_guard_elim = 0x82,
    ARG_stores_only   = 0x83,
    ARG_no_segue      = 0x84,
};

// options (TODO):
// poc
// sys-external
// no-guard-elim
// metering=precise,imprecise
// cfi=bundle16,bundle32,hwcfi
// deterministic
// variable-size
// sandbox=full,stores,jumps,bundle-jumps,none
// no-segue
// single threaded
// arch=arm64,amd64

static struct argp_option options[] = {
    { "output",         'o',               "FILE", 0, "Output to FILE instead of standard output" },
    { "poc",            ARG_poc,           0,      0, "Produce position-oblivious code (implies --sys-external)" },
    { "sys-external",   ARG_sys_external,  0,      0, "Store runtime call table outside sandbox"},
    { "no-guard-elim",  ARG_no_guard_elim, 0,      0, "Do not run redundant guard elimination"},
    { "stores-only",    ARG_stores_only,   0,      0, "Only sandbox stores/jumps (allow unsandboxed loads)" },
    { "no-segue",       ARG_no_segue,      0,      0, "Do not use segment register to store the sandbox base" },
    { "arch",           'a',               "ARCH", 0, "Set the target architecture (arm64,amd64)" },
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
    case 'a':
        if (strcmp(arg, "amd64") != 0 && strcmp(arg, "arm64") != 0) {
            fprintf(stderr, "unknown architecture: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        args->arch = arg;
        break;
    case ARG_poc:
        args->poc = true;
        args->sysexternal = true;
        break;
    case ARG_stores_only:
        args->storesonly = true;
        break;
    case ARG_no_guard_elim:
        args->noguardelim = true;
        break;
    case ARG_sys_external:
        args->sysexternal = true;
        break;
    case ARG_no_segue:
        args->nosegue = true;
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

static char*
getarch()
{
#if defined(__x86_64__) || defined(_M_X64)
    return "amd64";
#elif defined(__aarch64__) || defined(_M_ARM64)
    return "arm64";
#else
    fprintf(stderr, "running on unsupported architecture, use --arch to specify target\n");
    exit(1);
#endif
}

struct arguments args;

bool amd64_rewrite(FILE* input, FILE* output);
bool arm64_rewrite(FILE* input, FILE* output);

int
main(int argc, char** argv)
{
    args.output = "-";
    args.input = "-";

    argp_parse(&argp, argc, argv, 0, 0, &args);

    input = argopen(args.input, "r", stdin);
    output = argopen(args.output, "w", stdout);

    if (args.arch == NULL) {
        args.arch = getarch();
    }

    if (strcmp(args.arch, "arm64") == 0) {
        if (!arm64_rewrite(input, output))
            return 1;
    } else if (strcmp(args.arch, "amd64") == 0) {
        if (!amd64_rewrite(input, output))
            return 1;
    }

    fclose(input);
    fclose(output);

    return 0;
}
