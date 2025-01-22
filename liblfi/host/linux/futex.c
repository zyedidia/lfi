#include <assert.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "proc.h"

long
host_futexwait(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val, struct TimeSpec* timeout)
{
    long r;
    if (!timeout) {
        r = syscall(SYS_futex, uaddr, op, val, NULL);
    } else {
        struct timespec k_timeout = {0};
        k_timeout.tv_sec = timeout->sec;
        k_timeout.tv_nsec = timeout->nsec;
        r = syscall(SYS_futex, uaddr, op, val, &k_timeout);
    }
    return r;
}

long
host_futexwake(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val)
{
    return syscall(SYS_futex, uaddr, op, val);
}

long
host_futexrequeue(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val)
{
    return syscall(SYS_futex, uaddr, op, val);
}
