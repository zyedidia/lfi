// For mremap
#define _GNU_SOURCE

#include "syscall.h"
#include "sys.h"

enum {
    LSYS_getcwd            = 79,
    LSYS_fcntl             = 72,
    LSYS_ioctl             = 16,
    LSYS_unlinkat          = 263,
    LSYS_renameat          = 264,
    LSYS_faccessat         = 269,
    LSYS_chdir             = 80,
    LSYS_openat            = 257,
    LSYS_close             = 3,
    LSYS_pipe2             = 293,
    LSYS_getdents64        = 217,
    LSYS_lseek             = 8,
    LSYS_read              = 0,
    LSYS_write             = 1,
    LSYS_readv             = 19,
    LSYS_writev            = 20,
    LSYS_readlinkat        = 267,
    LSYS_newfstatat        = 262,
    LSYS_fstat             = 5,
    LSYS_exit              = 60,
    LSYS_exit_group        = 231,
    LSYS_set_tid_address   = 218,
    LSYS_clock_gettime     = 228,
    LSYS_rt_sigprocmask    = 14,
    LSYS_getpid            = 39,
    LSYS_gettid            = 186,
    LSYS_sysinfo           = 99,
    LSYS_brk               = 12,
    LSYS_munmap            = 11,
    LSYS_mremap            = 25,
    LSYS_clone             = 56,
    LSYS_execve            = 59,
    LSYS_mmap              = 9,
    LSYS_wait4             = 61,
    LSYS_prlimit64         = 302,
    LSYS_fork              = 57,
    LSYS_archprctl         = 158,
    LSYS_open              = 2,
    LSYS_stat              = 4,
    LSYS_readlink          = 89,
    LSYS_access            = 21,
    LSYS_unlink            = 87,
    LSYS_rename            = 82,
    LSYS_getrandom         = 318,
    LSYS_rt_sigaction      = 13,
    LSYS_dup               = 32,
    LSYS_pipe              = 22,
    LSYS_madvise           = 28,
    LSYS_mprotect          = 10,
    LSYS_poll              = 7,
    LSYS_membarrier        = 324,
    LSYS_sched_getaffinity = 204,
    LSYS_getrusage         = 98,
    LSYS_prctl             = 157,
    LSYS_futex             = 202,
    LSYS_sigaltstack       = 131,
};

enum {
    ARCH_SET_FS = 0x1002,
};

static int
sysarchprctl(LFIXProc* p, int code, uintptr_t addr)
{
    switch (code) {
    case ARCH_SET_FS:
        addr = procuseraddr(p, addr);
        lfi_proc_tpset(p->l_proc, addr);
        return 0;
    default:
        return -EINVAL;
    }
}
SYSWRAP_2(sysarchprctl, int, uintptr_t);

static int
sysrename(LFIXProc* p, uintptr_t oldp, uintptr_t newp)
{
    return sysrenameat2(p, AT_FDCWD, oldp, AT_FDCWD, newp, 0);
}
SYSWRAP_2(sysrename, uintptr_t, uintptr_t);

static int
sysrenameat(LFIXProc* p, int oldfd, uintptr_t oldp, int newfd, uintptr_t newp)
{
    return sysrenameat2(p, oldfd, oldp, newfd, newp, 0);
}
SYSWRAP_4(sysrenameat, int, uintptr_t, int, uintptr_t);

static int
sysstat(LFIXProc* p, uintptr_t pathp, uintptr_t statbufp)
{
    return sysfstatat(p, AT_FDCWD, pathp, statbufp, 0);
}
SYSWRAP_2(sysstat, uintptr_t, uintptr_t);

static ssize_t
sysreadlink(LFIXProc* p, uintptr_t pathp, uintptr_t bufp, size_t bufsiz)
{
    return sysreadlinkat(p, AT_FDCWD, pathp, bufp, bufsiz);
}
SYSWRAP_3(sysreadlink, uintptr_t, uintptr_t, size_t);

static int
sysaccess(LFIXProc* p, uintptr_t pathp, int mode)
{
    return sysfaccessat(p, AT_FDCWD, pathp, mode, 0);
}
SYSWRAP_2(sysaccess, uintptr_t, int);

static int
sysunlink(LFIXProc* p, uintptr_t pathp)
{
    return sysunlinkat(p, AT_FDCWD, pathp, 0);
}
SYSWRAP_1(sysunlink, uintptr_t);

SyscallFn syscalls[] = {
    [LSYS_read]              = sysread_,
    [LSYS_write]             = syswrite_,
    [LSYS_readv]             = sysreadv_,
    [LSYS_writev]            = syswritev_,
    [LSYS_archprctl]         = sysarchprctl_,
    [LSYS_set_tid_address]   = sysignore_,
    [LSYS_brk]               = sysbrk_,
    [LSYS_ioctl]             = sysignore_,
    [LSYS_exit_group]        = sysexit_,
    [LSYS_exit]              = sysexit_,
    [LSYS_close]             = sysclose_,
    [LSYS_open]              = sysopen_,
    [LSYS_fstat]             = sysfstat_,
    [LSYS_newfstatat]        = sysfstatat_,
    [LSYS_openat]            = sysopenat_,
    [LSYS_mmap]              = sysmmap_,
    [LSYS_munmap]            = sysmunmap_,
    [LSYS_mprotect]          = sysmprotect_,
    [LSYS_fcntl]             = sysignore_,
    [LSYS_clock_gettime]     = sysclock_gettime_,
    [LSYS_rt_sigprocmask]    = sysignore_,
    [LSYS_membarrier]        = sysignore_,
    [LSYS_getrandom]         = sysgetrandom_,
    [LSYS_sched_getaffinity] = syssched_getaffinity_,
    [LSYS_getpid]            = sysgetpid_,
    [LSYS_mremap]            = syserror_,
    [LSYS_madvise]           = sysignore_,
    [LSYS_getrusage]         = sysignore_,
    [LSYS_getcwd]            = sysgetcwd_,
    [LSYS_lseek]             = syslseek_,
    [LSYS_prctl]             = sysignore_,
    [LSYS_readlinkat]        = sysreadlinkat_,
    [LSYS_faccessat]         = sysfaccessat_,
    [LSYS_renameat]          = sysrenameat_,
    [LSYS_sysinfo]           = syssysinfo_,
    [LSYS_dup]               = sysdup_,
    [LSYS_rename]            = sysrename_,
    [LSYS_getdents64]        = sysgetdents64_,
    [LSYS_prlimit64]         = sysignore_,
    [LSYS_chdir]             = syschdir_,
    [LSYS_unlinkat]          = sysunlinkat_,
    [LSYS_futex]             = sysfutex_,
    [LSYS_stat]              = sysstat_,
    [LSYS_readlink]          = sysreadlink_,
    [LSYS_access]            = sysaccess_,
    [LSYS_unlink]            = sysunlink_,
    [LSYS_gettid]            = sysignore_,
    [LSYS_poll]              = sysignore_,
    [LSYS_rt_sigaction]      = sysignore_,
    [LSYS_sigaltstack]       = sysignore_,
};

_Static_assert(sizeof(syscalls) / sizeof(SyscallFn) < SYS_max, "syscalls exceed SYS_max");
