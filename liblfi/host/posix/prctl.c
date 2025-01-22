#include "host.h"
#include "print.h"

int
host_prctl_set_name(char* name)
{
    WARN("PR_SET_NAME is unsupported on this platform");
    return 0;
}
