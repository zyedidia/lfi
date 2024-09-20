#define _GNU_SOURCE

#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>

#include "lfi.h"

#include "testprog.inc"

static size_t
gb(size_t n)
{
    return n * 1024 * 1024 * 1024;
}

static uint64_t
sys(void* ctxp, uint64_t sysno, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
    assert(sysno == 42);

    lfi_proc_exit(10);
    assert(!"unreachable");
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

    LFIProc* proc;
    b = lfi_addproc(lfi, &proc, NULL);
    if (!b) {
        fprintf(stderr, "error: %s\n", lfi_strerror());
        return 1;
    }

    LFIProcInfo info;
    b = lfi_proc_loadelf(proc, liblfi_test_testprog, liblfi_test_testprog_len, NULL, 0, &info);
    if (!b) {
        fprintf(stderr, "error: %s\n", lfi_strerror());
        return 1;
    }

    b = lfi_proc_init(proc, info.elfentry, (uintptr_t) info.stack + info.stacksize - 16);
    if (!b) {
        fprintf(stderr, "error: %s\n", lfi_strerror());
        return 1;
    }

    uint64_t ret = lfi_proc_start(proc);
    assert(ret == 10);

    lfi_rmproc(lfi, proc);

    lfi_delete(lfi);

    return 0;
}
