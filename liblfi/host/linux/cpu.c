#define _GNU_SOURCE
#include <sched.h>

unsigned
host_cpucount(void)
{
    cpu_set_t cpuset;
    sched_getaffinity(0, sizeof(cpuset), &cpuset);
    return CPU_COUNT(&cpuset);
}
