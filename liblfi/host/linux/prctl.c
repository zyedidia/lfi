#include <sys/prctl.h>

#include "host/error.h"
#include "host.h"

int
host_prctl_set_name(char* name)
{
    int r = prctl(PR_SET_NAME, name);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}
