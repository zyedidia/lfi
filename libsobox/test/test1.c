#include <assert.h>
#include <stdio.h>

#include "sobox.h"

int
main()
{
    Sobox sbx;
    bool b;
    b = sbx_init(&sbx);
    assert(b);

    void* lib = sbx_dlopen(&sbx, "libsobox/test/libtest.so", 0);
    printf("handle: %p\n", lib);
    assert(lib != NULL);

    void* symbol = sbx_dlsymfn(lib, "add", "");
    printf("add symbol: %p\n", symbol);
    assert(symbol != NULL);

    int result = sbx_dlinvoke(lib, symbol, 12, 30);
    printf("result: %d\n", result);
}
