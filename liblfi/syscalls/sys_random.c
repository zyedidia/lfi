#include "host.h"
#include "syscalls/syscalls.h"

ssize_t
sys_getrandom(struct TuxProc* p, lfiptr_t bufp, size_t buflen, unsigned int flags)
{
    uint8_t* buf = procbuf(p, bufp, buflen);
    if (!buf)
        return -TUX_EINVAL;
    if ((flags & (~TUX_GRND_RANDOM & ~TUX_GRND_NONBLOCK)) != 0)
        return -TUX_EINVAL;
    return host_getrandom(buf, buflen, flags);
}
