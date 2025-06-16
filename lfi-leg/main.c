#include <argp.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "args.h"
#include "op.h"
#include "output.h"

static char doc[] = "lfi-leg: rewrite assembly files to be compatible with LFI";

static char args_doc[] = "INPUT";

enum {
    ARG_poc           = 0x80,
    ARG_sys_external  = 0x81,
    ARG_no_guard_elim = 0x82,
    ARG_no_segue      = 0x84,
    ARG_cfi           = 0x85,
    ARG_single_thread = 0x86,
    ARG_decl          = 0x87,
    ARG_meter         = 0x88,
    ARG_flags         = 0x89,
    ARG_p2size        = 0x8a,
    ARG_bundlecall    = 0x8b,
    ARG_useret        = 0x8c,
    ARG_no_pext_elim  = 0x8d,
    ARG_allowtls      = 0x8e,
    ARG_nopie         = 0x8f,
    ARG_syscall       = 0x90,
    ARG_largeguard    = 0x91,
    ARG_zerobase      = 0x92,
};

// options (TODO):
// poc
// sys-external
// no-guard-elim
// metering=precise,imprecise
// cfi=bundle16,bundle32,hwcfi
// decl
// variable-size
// sandbox=full,stores,jumps,bundle-jumps,none
// no-segue
// single threaded
// stateless (stack optimizations)
// arch=arm64,amd64

static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "output",         'o',               "FILE", 0, "Output to FILE instead of standard output" },
    { "arch",           'a',               "ARCH", 0, "Set the target architecture (arm64,amd64)" },
    { "sandbox",        's',               "TYPE", 0, "Select sandbox type (full,stores,bundle-jumps,syscalls,none)" },
    { "poc",            ARG_poc,           0,      0, "Produce position-oblivious code (implies --sys-external)" },
    { "sys-external",   ARG_sys_external,  0,      0, "Store runtime call table outside sandbox"},
    { "no-guard-elim",  ARG_no_guard_elim, 0,      0, "Do not run redundant guard elimination"},
    { "no-pext-elim",   ARG_no_pext_elim,  0,      0, "Do not run pext elimination"},
    { "no-segue",       ARG_no_segue,      0,      0, "Do not use segment register to store the sandbox base" },
    { "cfi",            ARG_cfi,           "TYPE", 0, "Select CFI mechanism (bundle16,bundle32)" },
    { "single-thread",  ARG_single_thread, 0,      0, "Specify single-threaded target" },
    { "decl",           ARG_decl,          0,      0, "Produce code for the Deterministic Client" },
    { "meter",          ARG_meter,         "TYPE", 0, "Enable program metering (branch,branch-resume,fp,timer)" },
    { "flags",          ARG_flags,         "TYPE", 0, "Show flags for compiler (clang,gcc)" },
    { "p2size",         ARG_p2size,        "TYPE", 0, "Set power-of-2 sandbox size (32,variable)" },
    { "bundle-call",    ARG_bundlecall,    0,      0, "Dedicate a full bundle for calls (allows use without lfi-postlink)" },
    { "use-ret",        ARG_useret,        0,      0, "Allow return instructions for x86-64 (unsafe)" },
    { "allow-tls",      ARG_allowtls,      0,      0, "Do not rewrite TLS accesses into host calls" },
    { "no-pie",         ARG_nopie,         0,      0, "Generating position-independent code is not required" },
    { "allow-syscall",  ARG_syscall,       0,      0, "Do not rewrite syscalls into host calls" },
    { "large-guard",    ARG_largeguard,    0,      0, "Assume large guard pages" },
    { "zero-base",      ARG_zerobase,      0,      0, "Store zero in base register (used only for testing)" },
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
    case 'o':
        args->output = arg;
        break;
    case 'a':
        if (strcmp(arg, "amd64") != 0 &&
            strcmp(arg, "x64") != 0 &&
            strcmp(arg, "x86-64") != 0 &&
            strcmp(arg, "x86_64") != 0 &&
            strcmp(arg, "arm64") != 0 &&
            strcmp(arg, "aarch64") != 0 &&
            strcmp(arg, "riscv64") != 0) {
            fprintf(stderr, "unknown architecture: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        args->arch = arg;
        break;
    case ARG_poc:
        args->poc = true;
        args->sysexternal = true;
        break;
    case 's':
        if (strcmp(arg, "full") == 0)
            args->boxtype = BOX_FULL;
        else if (strcmp(arg, "stores") == 0)
            args->boxtype = BOX_STORES;
        else if (strcmp(arg, "jumps") == 0)
            args->boxtype = BOX_JUMPS;
        else if (strcmp(arg, "bundle-jumps") == 0)
            args->boxtype = BOX_BUNDLEJUMPS;
        else if (strcmp(arg, "syscalls") == 0)
            args->boxtype = BOX_SYSCALLS;
        else if (strcmp(arg, "none") == 0)
            args->boxtype = BOX_NONE;
        else {
            fprintf(stderr, "unsupported sandbox type: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        break;
    case ARG_no_guard_elim:
        args->noguardelim = true;
        break;
    case ARG_allowtls:
        args->allowtls = true;
        break;
    case ARG_largeguard:
        args->largeguard = true;
        break;
    case ARG_syscall:
        args->syscall = true;
        break;
    case ARG_no_pext_elim:
        args->nopextelim = true;
        break;
    case ARG_useret:
        args->useret = true;
        break;
    case ARG_nopie:
        args->nopie = true;
        break;
    case ARG_zerobase:
        args->zerobase = true;
        break;
    case ARG_meter:
        if (strcmp(arg, "branch") == 0)
            args->meter = METER_BRANCH;
        else if (strcmp(arg, "branch-resume") == 0)
            args->meter = METER_BRANCH_RESUME;
        else if (strcmp(arg, "fp") == 0)
            args->meter = METER_FP;
        else if (strcmp(arg, "timer") == 0)
            args->meter = METER_TIMER;
        else {
            fprintf(stderr, "unsupported metering type: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        break;
    case ARG_bundlecall:
        args->bundlecall = true;
        break;
    case ARG_sys_external:
        args->sysexternal = true;
        break;
    case ARG_no_segue:
        args->nosegue = true;
        break;
    case ARG_cfi:
        if (strcmp(arg, "bundle16") == 0)
            args->cfi = CFI_BUNDLE16;
        else if (strcmp(arg, "bundle32") == 0)
            args->cfi = CFI_BUNDLE32;
        else if (strcmp(arg, "none") == 0)
            args->cfi = CFI_HW;
        else {
            fprintf(stderr, "unsupported cfi type: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        break;
    case ARG_flags:
        if (strcmp(arg, "clang") == 0)
            args->flags = FLAGS_CLANG;
        else if (strcmp(arg, "gcc") == 0)
            args->flags = FLAGS_GCC;
        else if (strcmp(arg, "postlink") == 0)
            args->flags = FLAGS_POSTLINK;
        else {
            fprintf(stderr, "unsupported compiler type: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        break;
    case ARG_single_thread:
        args->singlethread = true;
        break;
    case ARG_decl:
        args->decl = true;
        break;
    case ARG_p2size:
        if (strcmp(arg, "variable") == 0)
            args->p2size = 0;
        else
            args->p2size = atoi(arg);
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
#elif defined(__riscv__) || defined(__riscv)
    return "riscv64";
#else
    fprintf(stderr, "running on unsupported architecture, use --arch to specify target\n");
    exit(1);
#endif
}

struct arguments args;

bool amd64_rewrite(FILE* input, struct output* output);
bool arm64_rewrite(FILE* input, struct output* output);
bool riscv64_rewrite(FILE* input, struct output* output);

char* arm64_getflags(enum flags);
char* amd64_getflags(enum flags);
char* riscv64_getflags(enum flags);

int
main(int argc, char** argv)
{
    args.output = "-";
    args.input = "-";
    args.boxtype = BOX_FULL;
    args.p2size = 32;

    argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &args);

    input = argopen(args.input, "r", stdin);
    output = argopen(args.output, "w", stdout);

    char* lfidebug = getenv("LFIDEBUG");
    if (lfidebug) {
        // write input to a debug location
        FILE* debug = argopen("debug-in.s", "w", NULL);
        char buf[BUFSIZ];
        size_t n;
        while ((n = fread(buf, 1, BUFSIZ, input)) != 0)
            fwrite(buf, 1, n, debug);
        fseek(input, 0, SEEK_SET);
        fclose(debug);
    }

    if (args.arch == NULL) {
        args.arch = getarch();
    }

    struct output out = (struct output) {};
    if (args.boxtype == BOX_NONE) {
        if (args.flags != FLAGS_NONE)
            return 0;
        // nothing to do
        char buf[4096];
        size_t n;
        while ((n = fread(buf, 1, 4096, input)) != 0)
            outwritebuf(&out, buf, n);
    } else if (strcmp(args.arch, "arm64") == 0 || strcmp(args.arch, "aarch64") == 0) {
        if (args.flags != FLAGS_NONE) {
            char* flags = arm64_getflags(args.flags);
            puts(flags);
            return 0;
        }

        if (!arm64_rewrite(input, &out))
            return 1;
    } else if (strcmp(args.arch, "amd64") == 0 ||
            strcmp(args.arch, "x86-64") == 0 ||
            strcmp(args.arch, "x86_64") == 0 ||
            strcmp(args.arch, "x64") == 0) {
        if (args.flags != FLAGS_NONE) {
            char* flags = amd64_getflags(args.flags);
            puts(flags);
            return 0;
        }

        if (!amd64_rewrite(input, &out))
            return 1;
    } else if (strcmp(args.arch, "riscv64") == 0) {
        if (args.flags != FLAGS_NONE) {
            char* flags = riscv64_getflags(args.flags);
            puts(flags);
            return 0;
        }

        if (!riscv64_rewrite(input, &out))
            return 1;
    }

    outsend(&out, output);

    fclose(input);
    fclose(output);

    return 0;
}
