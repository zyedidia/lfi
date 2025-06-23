#include <assert.h>

#include "config.h"
#include "sys.h"
#include "syscalls/strace.h"
#include "arch_sys.h"

#define SYS(SYSNO, expr)  \
    case TUX_SYS_##SYSNO: \
        r = expr;         \
        break;

uintptr_t
syshandle(struct TuxThread* p, uintptr_t sysno, uintptr_t a0, uintptr_t a1,
        uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5)
{
    struct TuxProc* proc = p->proc;

    uintptr_t r = -TUX_ENOSYS;
    switch (sysno) {
    SYS(exit,              sys_exit(p, a0))
    SYS(exit_group,        sys_exit_group(p, a0))
    SYS(brk,               sys_brk(proc, a0))
    /* SYS(mmap,              sys_mmap(proc, a0, a1, a2, a3, a4, a5)) */
    /* SYS(mprotect,          sys_mprotect(proc, a0, a1, a2)) */
    /* SYS(munmap,            sys_munmap(proc, a0, a1)) */
#ifdef CONFIG_THREADS
# if defined(__x86_64__) || defined(_M_X64)
    // syscall: clone(flags, stack, ptid, ctid, tls, func)
    SYS(clone,             sys_clone(p, a0, a1, a2, a3, a4, a5))
# elif defined(__aarch64__) || defined(_M_ARM64)
    // syscall: clone(flags, stack, ptid, tls, ctid, func)
    // clone signature is different on aarch64 and x86-64
    SYS(clone,             sys_clone(p, a0, a1, a2, a4, a3, a5))
# endif
#endif
    default:
        r = sys_passthrough(p, sysno, a0, a1, a2, a3, a4, a5);
    }

    return r;
}
