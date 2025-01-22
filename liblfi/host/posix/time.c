#include <time.h>

#include "types.h"
#include "host/error.h"

tux_time_t
host_time(void)
{
    time_t r = time(NULL);
    if (r < 0)
        return tuxerr(errno);
    return r;
}
