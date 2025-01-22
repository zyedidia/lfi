#include <assert.h>

#include "syscalls/syscalls.h"

int
sys_fcntl(struct TuxProc* p, int fd, int cmd, uintptr_t va0, uintptr_t va1,
        uintptr_t va2, uintptr_t va3)
{
    WARN("fcntl ignored");
    return 0;
}
