#include <unistd.h>
#include <sys/random.h>

#include "host/error.h"

ssize_t
host_getrandom(void* buf, size_t size, unsigned int flags)
{
    if (size > 256)
        size = 256;
    int r = getentropy(buf, size);
    if (r < 0)
        return tuxerr(errno);
    return size;
}
