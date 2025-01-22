#include <assert.h>

#include "syscalls/syscalls.h"

int
sys_rt_sigaction(struct TuxProc* p, int sig, int64_t act, int64_t old, uint64_t sigsetsize)
{
    WARN("unimplemented: rt_sigaction");
    return 0;
}

int
sys_rt_sigprocmask(struct TuxProc* p, int how, int64_t setaddr, int64_t oldsetaddr, uint64_t sigsetsize)
{
    WARN("unimplemented: rt_sigprocmask");
    return 0;
}

int
sys_rt_sigreturn(struct TuxProc* p)
{
    assert(!"unimplemented: rt_sigreturn");
}
