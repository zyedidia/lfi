#include <assert.h>
#include <stdio.h>

#include "sobox.h"

static uint8_t*
readfile(const char* filename, size_t* size) {
    FILE* f = fopen(filename, "rb");
    if (!f)
        return NULL;
    if (fseek(f, 0, SEEK_END) != 0) {
        perror("fseek");
        exit(1);
    }
    long sz = ftell(f);
    if (fseek(f, 0, SEEK_SET) != 0) {
        perror("fseek");
        exit(1);
    }
    void* b = malloc(sz);
    assert(b);
    size_t n = fread(b, sz, 1, f);
    assert(n == 1);
    fclose(f);

    *size = sz;
    return b;
}

int
main()
{
    Sobox sbx;
    bool b;
    b = sbx_init(&sbx, readfile);
    assert(b);

    void* lib = sbx_dlopen(&sbx, "libsobox/test/libtest.so", 0);
    printf("handle: %p\n", lib);
    assert(lib != NULL);
}
