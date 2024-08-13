// This is the library entrypoint for the LFI rewriter, meant to be used in a
// browser and compiled via emscripten.

#include "args.h"
#include "op.h"
#include "output.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

struct arguments args;

bool amd64_rewrite(FILE* input, struct output* output);
bool arm64_rewrite(FILE* input, struct output* output);
bool riscv64_rewrite(FILE* input, struct output* output);

char* arm64_getflags(enum flags);
char* amd64_getflags(enum flags);
char* riscv64_getflags(enum flags);

static struct arguments
argsdefault()
{
    return (struct arguments) {
        .boxtype = BOX_FULL,
        .p2size = 32,
        .arch = "arm64",
    };
}

static void
setargs(char* arch, char* sandbox, char* cfi, char* p2size, char* segue)
{
    args.arch = arch;
    if (strcmp(sandbox, "stores") == 0)
        args.boxtype = BOX_STORES;
    if (strcmp(sandbox, "bundle-jumps") == 0)
        args.boxtype = BOX_BUNDLEJUMPS;
    if (strcmp(sandbox, "none") == 0)
        args.boxtype = BOX_NONE;
    if (strcmp(cfi, "bundle32") == 0)
        args.cfi = CFI_BUNDLE32;
    if (strcmp(p2size, "variable") == 0)
        args.p2size = 0;
    if (strcmp(segue, "nosegue") == 0)
        args.nosegue = true;
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
char*
lfi_rewrite(char* inputstr, char* arch, char* sandbox, char* cfi, char* p2size, char* segue)
{
    args = argsdefault();
    setargs(arch, sandbox, cfi, p2size, segue);

    FILE* input = fmemopen(inputstr, strlen(inputstr), "r");

    struct output out = (struct output) {};
    if (args.boxtype == BOX_NONE) {
        // nothing to do
        char buf[4096];
        size_t n;
        while ((n = fread(buf, 1, 4096, input)) != 0)
            outwritebuf(&out, buf, n);
    } else if (strcmp(args.arch, "arm64") == 0) {
        if (!arm64_rewrite(input, &out))
            return "<error>";
    } else if (strcmp(args.arch, "amd64") == 0) {
        if (!amd64_rewrite(input, &out))
            return "<error>";
    } else if (strcmp(args.arch, "riscv64") == 0) {
        if (!riscv64_rewrite(input, &out))
            return "<error>";
    }

    return outstr(&out);
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE
#endif
char*
lfi_flags(char* arch, char* sandbox, char* cfi, char* p2size, char* segue)
{
    args = argsdefault();
    setargs(arch, sandbox, cfi, p2size, segue);

    if (strcmp(args.arch, "arm64") == 0) {
        return arm64_getflags(FLAGS_GCC);
    } else if (strcmp(args.arch, "amd64") == 0) {
        return amd64_getflags(FLAGS_GCC);
    } else if (strcmp(args.arch, "riscv64") == 0) {
        return riscv64_getflags(FLAGS_GCC);
    }
    return "<error>";
}
