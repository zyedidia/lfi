#include <argp.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "args.h"

static char doc[] = "lfi-gen: rewrite assembly files to be compatible with LFI";

static char args_doc[] = "INPUT";

static struct argp_option options[] = {
    { "output", 'o', "FILE", 0, "Output to FILE instead of standard output" },
    { "poc",    'p', 0,      0, "Produce position-oblivious code" },
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

bool lfigen();

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

int
main(int argc, char** argv)
{
    args.output = "-";
    args.input = "-";

    argp_parse(&argp, argc, argv, 0, 0, &args);

    input = argopen(args.input, "r", stdin);
    output = argopen(args.output, "w", stdout);

    if (!lfigen()) {
        fprintf(stderr, "%s: parse failed\n", args.input);
        return 1;
    }

    fclose(input);
    fclose(output);

    return 0;
}
