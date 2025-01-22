#include <errno.h>
#include <sys/random.h>

#include "host/error.h"
#include "host.h"

static unsigned int
linuxflags(unsigned int flags)
{
    unsigned int f = 0;
    if ((flags & TUX_GRND_RANDOM) != 0)
        f |= GRND_RANDOM;
    if ((flags & TUX_GRND_NONBLOCK) != 0)
        f |= GRND_NONBLOCK;
    return f;
}

ssize_t
host_getrandom(void* buf, size_t size, unsigned int flags)
{
    ssize_t r = getrandom(buf, size, linuxflags(flags));
    if (r < 0)
        return tuxerr(errno);
    return r;
}
