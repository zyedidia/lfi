#include <stdio.h>

#include "host.h"
#include "print.h"

int
host_prctl_set_name(char* name)
{
    fprintf(stderr, "warning: PR_SET_NAME is unsupported on this platform");
    return 0;
}
