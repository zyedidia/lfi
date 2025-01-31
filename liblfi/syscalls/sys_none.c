#include "print.h"
#include "syscalls/syscalls.h"

uintptr_t
sys_ignore(struct TuxProc* p, const char* name)
{
    WARN(p->tux, "%s: ignored", name);
    return 0;
}

uintptr_t
sys_nosys(struct TuxProc* p, const char* name)
{
    WARN(p->tux, "%s: unsupported (ENOSYS)", name);
    return -TUX_ENOSYS;
}
