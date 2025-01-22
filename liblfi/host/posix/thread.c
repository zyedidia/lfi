#include <sched.h>

int
host_sched_yield(void)
{
    return sched_yield();
}
