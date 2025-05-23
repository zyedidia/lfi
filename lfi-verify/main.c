#define _POSIX_C_SOURCE 199309L

#include <argp.h>
#include <stdio.h>
#include <time.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "args.h"
#include "elfdefs.h"
#include "lfiv.h"

static char doc[] = "lfiv: LFI verifier";

static char args_doc[] = "INPUT...";

static LFIvOpts opts;

enum {
    ARG_poc   = 0x80,
    ARG_decl  = 0x81,
    ARG_meter = 0x82,
    ARG_cfi   = 0x83,
};

static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "arch",           'a',               "ARCH", 0, "run on architecture (amd64,arm64)" },
    { "n",              'n',               "NUM",  0, "run the verifier n times (for benchmarking)" },
    { "sandbox",        's',               "TYPE", 0, "Select sandbox type (full,stores)" },
    { "poc",            ARG_poc,           0,      0, "require position-oblivious code" },
    { "decl",           ARG_decl,          0,      0, "require deterministic instructions" },
    { "meter",          ARG_meter,         "TYPE", 0, "require metering instructions" },
    { "cfi",            ARG_cfi,           "TYPE", 0, "Select CFI mechanism (bundle16,bundle32)" },
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
    case 'n':
        args->n = atoi(arg);
        break;
    case 'a':
        if (strcmp(arg, "amd64") != 0 && strcmp(arg, "arm64") != 0 && strcmp(arg, "riscv64") != 0) {
            fprintf(stderr, "unknown architecture: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        args->arch = arg;
        break;
    case 's':
        if (strcmp(arg, "full") == 0)
            opts.box = LFI_BOX_FULL;
        else if (strcmp(arg, "stores") == 0)
            opts.box = LFI_BOX_STORES;
        else {
            fprintf(stderr, "unsupported sandbox type: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        break;
    case ARG_poc:
        opts.poc = true;
        break;
    case ARG_decl:
        opts.decl = true;
        break;
    case ARG_meter:
        opts.meter = LFI_METER_NONE;
        if (strcmp(arg, "branch") == 0) {
            opts.meter = LFI_METER_BRANCH;
            opts.bundle = LFI_BUNDLE16;
        } else if (strcmp(arg, "timer") == 0) {
            opts.meter = LFI_METER_TIMER;
            opts.bundle = LFI_BUNDLE8;
        } else {
            fprintf(stderr, "unsupported metering type: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
        break;
    case ARG_cfi:
        if (strcmp(arg, "bundle16") == 0)
            opts.bundle = LFI_BUNDLE16;
        else if (strcmp(arg, "bundle32") == 0)
            opts.bundle = LFI_BUNDLE32;
        else {
            fprintf(stderr, "unsupported cfi type: %s\n", arg);
            return ARGP_ERR_UNKNOWN;
        }
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

static inline
long long unsigned time_ns()
{
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts)) {
        exit(1);
    }
    return ((long long unsigned)ts.tv_sec) * 1000000000LLU +
        (long long unsigned)ts.tv_nsec;
}

static void
errfn(char* msg, size_t sz)
{
    (void) sz;
    fprintf(stderr, "%s\n", msg);
}

static bool
verify(LFIVerifier* v, const char* file)
{
    FILE* f = fopen(file, "r+");
    if (!f) {
        fprintf(stderr, "error opening %s: %s\n", file, strerror(errno));
        return false;
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

    char* buf = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(f), 0);
    if (buf == (char*) -1) {
        perror("mmap");
        exit(1);
    }

    printf("verifying %s\n", file);

    struct elf_file_header* ehdr = (struct elf_file_header*) buf;
    struct elf_prog_header* phdr = (struct elf_prog_header*) &buf[ehdr->phoff];
    size_t total = 0;

    long long unsigned t1 = time_ns();
    for (int n = 0; n < args.n; n++) {
        for (int i = 0; i < ehdr->phnum; i++) {
            struct elf_prog_header* p = &phdr[i];
            if (p->type != PT_LOAD) {
                continue;
            }
            if ((p->flags & PF_X) == 0) {
                continue;
            }

            if (!lfiv_verify(v, &buf[p->offset], p->filesz, p->vaddr)) {
                printf("verification failed\n");
                return false;
            }
            total += p->filesz;
        }
    }
    const long long unsigned elapsed = time_ns() - t1;
    munmap(buf, sz);
    fclose(f);

    printf("verification passed (%.1f MiB/s)\n", ((float) total / ((float) elapsed / 1000 / 1000 / 1000)) / 1024 / 1024);
    return true;
}

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

Args args;

int
main(int argc, char** argv)
{
    argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &args);

    if (args.arch == NULL)
        args.arch = getarch();

    if (args.n == 0)
        args.n = 1;

    if (strcmp(args.arch, "amd64") == 0 && opts.bundle == LFI_BUNDLE_NONE)
        opts.bundle = LFI_BUNDLE32;

    opts.err = errfn;
    LFIVerifier v = (LFIVerifier) {
        .opts = opts,
    };

    if (strcmp(args.arch, "amd64") == 0)
        v.verify = lfiv_verify_amd64;
    else if (strcmp(args.arch, "arm64") == 0)
        v.verify = lfiv_verify_arm64;
    else {
        fprintf(stderr, "verifier for %s does not exist\n", args.arch);
        return 1;
    }

    if (args.ninputs <= 0) {
        fprintf(stderr, "no input\n");
        return 0;
    }

    bool failed = false;
    for (size_t i = 0; i < args.ninputs; i++) {
        if (!verify(&v, args.inputs[i]))
            failed = true;
    }
    if (failed)
        exit(1);
}
