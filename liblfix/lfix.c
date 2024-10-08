#include <assert.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#include "lfi.h"
#include "lfix.h"
#include "sys.h"

static uint64_t
lfix_syscall(void* ctxp, uint64_t sysno, uint64_t a0, uint64_t a1,
        uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
    if (sysno >= SYS_max)
        goto nosys;
    SyscallFn fn = syscalls[sysno];
    if (!fn)
        goto nosys;

    LFIXProc* p = (LFIXProc*) ctxp;
    uintptr_t ret = fn(p, a0, a1, a2, a3, a4, a5);

    /* printf("syscall: %ld = %lx\n", sysno, ret); */
    return ret;

nosys:
    fprintf(stderr, "unknown syscall: %ld\n", sysno);
    assert(!"ENOSYS");
    return -ENOSYS;
}

bool
lfix_init(LFIXEngine* lfix)
{
    *lfix = (LFIXEngine){0};

    LFIOptions options = (LFIOptions) {
        .pagesize = getpagesize(),
        .stacksize = mb(2),
        .syshandler = lfix_syscall,
        .noverify = true,
    };

    if (options.noverify) {
        fprintf(stderr, "warning: verification disabled\n");
    }

    LFIEngine* lfi = lfi_new(options);
    if (!lfi)
        return false;

    if (!lfi_reserve(lfi, gb(256))) {
        lfi_delete(lfi);
        return false;
    }

    lfix->l_engine = lfi;

    return true;
}
