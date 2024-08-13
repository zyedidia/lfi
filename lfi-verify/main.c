#define _POSIX_C_SOURCE 199309L

#include <argp.h>
#include <stdio.h>
#include <time.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "args.h"
#include "elf.h"
#include "lfiv.h"

static char doc[] = "lfiv: LFI verifier";

static char args_doc[] = "INPUT...";

enum {
    ARG_n = 0x80,
};

static struct argp_option options[] = {
    { "help",           'h',               0,      0, "show this message", -1 },
    { "n",              'n',               "NUM",  0, "run the verifier n times (for benchmarking)" },
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
verify(const char* file)
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

            if (!lfiv_verify_verbose(&buf[p->offset], p->filesz, p->vaddr, errfn)) {
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

Args args;

int
main(int argc, char** argv)
{
    argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &args);

    if (args.n == 0)
        args.n = 1;

    bool failed = false;
    for (size_t i = 0; i < args.ninputs; i++) {
        if (!verify(args.inputs[i]))
            failed = true;
    }
    if (failed)
        exit(1);
}
