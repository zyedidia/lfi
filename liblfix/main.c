#include <assert.h>
#include <errno.h>

#include "lfix.h"

int
main(int argc, char** argv)
{
    LFIXEngine engine;
    bool b = lfix_init(&engine);
    if (!b) {
        fprintf(stderr, "error initializing: %s\n", lfi_strerror());
        return 1;
    }

    if (argc <= 1) {
        fprintf(stderr, "no input file\n");
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");
    if (!f) {
        fprintf(stderr, "error opening %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    LFIXProc* p = lfix_proc_newfile(&engine, fileno(f), 0, NULL);
    if (!p) {
        fprintf(stderr, "error creating process: %s\n", lfi_strerror());
        return 1;
    }

    fclose(f);

    uint64_t r = lfi_proc_start(p->l_proc);
    printf("returned: %ld\n", r);

    return 0;
}
