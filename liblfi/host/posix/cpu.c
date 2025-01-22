#include <unistd.h>

unsigned
host_cpucount(void)
{
    return sysconf(_SC_NPROCESSORS_ONLN);
}
