#include <stdalign.h>
#include <time.h>
#include <errno.h>

#include "host.h"

#include "syscalls/syscalls.h"

enum {
    TUX_CLOCK_REALTIME  = 0,
    TUX_CLOCK_MONOTONIC = 1,
};

int
sys_clock_gettime(struct TuxProc* p, tux_clockid_t clockid, uintptr_t tp) {
    if (clockid != TUX_CLOCK_REALTIME && clockid != TUX_CLOCK_MONOTONIC)
        return -TUX_EINVAL;
    uint8_t* tb = procbufalign(p, tp, sizeof(struct TimeSpec), alignof(struct TimeSpec));
    if (!tb)
        return -TUX_EFAULT;
    struct TimeSpec* tux_t = (struct TimeSpec*) tb;
    // TODO: host wrapper for clock_gettime
    struct timespec t;
    int err = clock_gettime(clockid, &t);
    if (err < 0)
        return -errno;
    tux_t->sec = t.tv_sec;
    tux_t->nsec = t.tv_nsec;
    return 0;
}

tux_time_t
sys_time(struct TuxProc* p, uintptr_t tlocp)
{
    // TODO: sys_time: currently we require tlocp to be NULL
    if (tlocp != 0)
        return -TUX_EINVAL;
    return host_time();
}
