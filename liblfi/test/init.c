#include <assert.h>
#include <unistd.h>
#include <stdio.h>

#include "lfi.h"

static size_t
gb(size_t n)
{
    return n * 1024 * 1024 * 1024;
}

static uint64_t
sys(void* ctxp, uint64_t sysno, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
    return -1;
}

int
main()
{
    LFIEngine* lfi = lfi_new((LFIOptions) {
        .stacksize = 2 * 1024 * 1024,
        .pagesize = getpagesize(),
        .noverify = true,
        .syshandler = sys,
    });
    if (!lfi) {
        fprintf(stderr, "error: %s\n", lfi_strerror());
        return 1;
    }

    bool b = lfi_reserve(lfi, gb(256));
    if (!b) {
        fprintf(stderr, "error: %s\n", lfi_strerror());
        return 1;
    }

    assert(lfi_maxprocs(lfi) >= 1);

    lfi_delete(lfi);

    return 0;
}
