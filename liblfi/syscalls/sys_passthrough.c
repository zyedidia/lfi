#include <unistd.h>

#include "syscalls/syscalls.h"
#include "host/error.h"

// Pass system calls through unmodified (UNSAFE). This should only be used for
// testing/benchmarking.
uintptr_t
sys_passthrough(struct TuxThread *t, uintptr_t sysno, uintptr_t a0,
    uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5)
{
#ifdef __linux__
    long r = syscall(sysno, a0, a1, a2, a3, a4, a5);
    if (r == -1)
        return tuxerr(r);
    VERBOSE(t->proc->tux,
        "passthrough: syscall %ld (%lx, %lx, %lx, %lx, %lx, %lx) = %ld", sysno,
        a0, a1, a2, a3, a4, a5, (long) r);
    return r;
#else
    WARN(t->proc->tux, "passthrough requires linux");
    return -LINUX_ENOSYS;
#endif
}
