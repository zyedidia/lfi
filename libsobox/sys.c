#include <assert.h>
#include <stdio.h>

#include "sys.h"

uint64_t
syshandler(void* ctxp, uint64_t sysno,
        uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
    printf("received syscall %ld\n", sysno);
    assert(0);
}

int
syserr(int val)
{
    if (val == -1)
        return -errno;
    return val;
}
