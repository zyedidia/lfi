#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

#include "lfi.h"
#include "lfi_tux.h"

struct Buf {
    void* data;
    size_t size;
};

static struct Buf
readfile(char* path)
{
    FILE* f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Cannot open %s\n", path);
        return (struct Buf){0};
    }
    fseek(f, 0, SEEK_END);
    size_t sz = ftell(f);
    void* p = mmap(NULL, sz, PROT_READ, MAP_PRIVATE, fileno(f), 0);
    assert(p != (void*) -1);
    fclose(f);
    return (struct Buf) {
        .data = p,
        .size = sz,
    };
}

int
main(int argc, char** argv)
{
    if (argc <= 1) {
        fprintf(stderr, "no input\n");
        return 1;
    }

    size_t pagesize = getpagesize();
    struct LFIPlatform* plat = lfi_new_plat((struct LFIPlatOptions) {
        .pagesize = pagesize,
        .vmsize = 4UL * 1024 * 1024 * 1024,
    });
    struct Tux* tux = lfi_tux_new(plat, (struct TuxOptions) {
        .pagesize = pagesize,
        .stacksize = 2 * 1024 * 1024,
    });
    assert(tux);

    struct Buf prog = readfile(argv[1]);

    struct TuxThread* p = lfi_tux_proc_new(tux, prog.data, prog.size, argc - 1, &argv[1]);
    assert(p);

    uint64_t ret = lfi_tux_proc_run(p);
    return ret;
}
