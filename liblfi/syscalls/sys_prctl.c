#include "syscalls/syscalls.h"
#include "host.h"

static int
pr_set_name(struct TuxProc* p, lfiptr_t namep)
{
    char* name = (char*) procbuf(p, namep, 16);
    if (!name)
        return -TUX_EFAULT;
    return host_prctl_set_name(name);
}

int
sys_prctl(struct TuxProc* p, int op, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5)
{
    switch (op) {
    case TUX_PR_SET_NAME:
        return pr_set_name(p, arg2);
    default:
        WARN("unknown prctl op %d", op);
        return -TUX_EINVAL;
    }
}
