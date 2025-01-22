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
    SYS(getpid,            0)
    SYS(write,             sys_write(proc, a0, a1, a2))
    SYS(read,              sys_read(proc, a0, a1, a2))
    SYS(lseek,             sys_lseek(proc, a0, a1, a2))
    SYS(exit,              sys_exit(p, a0))
    SYS(exit_group,        sys_exit_group(p, a0))
    SYS(brk,               sys_brk(proc, a0))
    SYS(openat,            sys_openat(proc, a0, a1, a2, a3))
    SYS(close,             sys_close(proc, a0))
    SYS(writev,            sys_writev(proc, a0, a1, a2))
    SYS(readv,             sys_readv(proc, a0, a1, a2))
    SYS(pread64,           sys_pread64(proc, a0, a1, a2, a3))
    SYS(mmap,              sys_mmap(proc, a0, a1, a2, a3, a4, a5))
    SYS(mprotect,          sys_mprotect(proc, a0, a1, a2))
    SYS(munmap,            sys_munmap(proc, a0, a1))
    SYS(getdents64,        sys_getdents64(proc, a0, a1, a2))
    SYS(newfstatat,        sys_newfstatat(proc, a0, a1, a2, a3))
    SYS(fstat,             sys_newfstatat(proc, a0, 0, a1, TUX_AT_EMPTY_PATH))
    SYS(fchmod,            sys_fchmod(proc, a0, a1))
    SYS(truncate,          sys_truncate(proc, a0, a1))
    SYS(ftruncate,         sys_ftruncate(proc, a0, a1))
    SYS(fchown,            sys_fchown(proc, a0, a1, a2))
    SYS(fsync,             sys_fsync(proc, a0))
    SYS(chdir,             sys_chdir(proc, a0))
    SYS(fchdir,            sys_fchdir(proc, a0))
    SYS(mkdirat,           sys_mkdirat(proc, a0, a1, a2))
    SYS(getrandom,         sys_getrandom(proc, a0, a1, a2))
    SYS(getcwd,            sys_getcwd(proc, a0, a1))
    SYS(clock_gettime,     sys_clock_gettime(proc, a0, a1))
    SYS(unlinkat,          sys_unlinkat(proc, a0, a1, a2))
    SYS(renameat,          sys_renameat(proc, a0, a1, a2, a3))
    SYS(faccessat,         sys_faccessat(proc, a0, a1, a2))
    SYS(readlinkat,        sys_readlinkat(proc, a0, a1, a2, a3))
    SYS(ioctl,             sys_ioctl(proc, a0, a1, a2, a3, a4, a5))
    SYS(fcntl,             sys_fcntl(proc, a0, a1, a2, a3, a4, a5))
#ifdef CONFIG_THREADS
    SYS(gettid,            sys_gettid(p))
    SYS(futex,             sys_futex(p, a0, a1, a2, a3, a4, a5))
# if defined(__x86_64__) || defined(_M_X64)
    // syscall: clone(flags, stack, ptid, ctid, tls, func)
    SYS(clone,             sys_clone(p, a0, a1, a2, a3, a4, a5))
# elif defined(__aarch64__) || defined(_M_ARM64)
    // syscall: clone(flags, stack, ptid, tls, ctid, func)
    // clone signature is different on aarch64 and x86-64
    SYS(clone,             sys_clone(p, a0, a1, a2, a4, a3, a5))
# endif
    SYS(set_tid_address,   sys_set_tid_address(p, a0))
    SYS(sched_getaffinity, sys_sched_getaffinity(proc, a0, a1, a2))
    SYS(sched_setaffinity, sys_sched_setaffinity(proc, a0, a1, a2))
    SYS(sched_yield,       sys_sched_yield(proc))
#else
    SYS(gettid,            0)
    SYS(set_tid_address,   0)
#endif
    SYS(rt_sigaction,      sys_rt_sigaction(proc, a0, a1, a2, a3))
    SYS(rt_sigprocmask,    sys_rt_sigprocmask(proc, a0, a1, a2, a3))
    SYS(rt_sigreturn,      sys_rt_sigreturn(proc))
    SYS(uname,             sys_uname(proc, a0))
    SYS(sysinfo,           sys_sysinfo(proc, a0))
    SYS(getrlimit,         sys_getrlimit(proc, a0, a1))
    SYS(prctl,             sys_prctl(proc, a0, a1, a2, a3, a4))
    SYS(set_robust_list,   0)
    SYS(membarrier,        0)
    SYS(statx,             -TUX_ENOSYS)
    SYS(rseq,              -TUX_ENOSYS)
    SYS(prlimit64,         -TUX_ENOSYS)
    SYS(statfs,            -TUX_ENOSYS)
    SYS(getxattr,          -TUX_ENOSYS)
    SYS(lgetxattr,         -TUX_ENOSYS)
    SYS(socket,            -TUX_ENOSYS)
    SYS(mremap,            -TUX_ENOSYS)
    SYS(utimensat,         -TUX_ENOSYS)
    default:
        fprintf(stderr, "unknown syscall: %ld (%s)\n", sysno, sysname(sysno));
        assert(!"unhandled syscall");
    }

    return r;
}
