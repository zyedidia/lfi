// For mremap
#define _GNU_SOURCE

#include "syscall.h"
#include "sys.h"

enum {
    SYS_getcwd            = 79,
    SYS_fcntl             = 72,
    SYS_ioctl             = 16,
    SYS_unlinkat          = 263,
    SYS_renameat          = 264,
    SYS_faccessat         = 269,
    SYS_chdir             = 80,
    SYS_openat            = 257,
    SYS_close             = 3,
    SYS_pipe2             = 293,
    SYS_getdents64        = 217,
    SYS_lseek             = 8,
    SYS_read              = 0,
    SYS_write             = 1,
    SYS_readv             = 19,
    SYS_writev            = 20,
    SYS_readlinkat        = 267,
    SYS_newfstatat        = 262,
    SYS_fstat             = 5,
    SYS_exit              = 60,
    SYS_exit_group        = 231,
    SYS_set_tid_address   = 218,
    SYS_clock_gettime     = 228,
    SYS_rt_sigprocmask    = 14,
    SYS_getpid            = 39,
    SYS_gettid            = 186,
    SYS_sysinfo           = 99,
    SYS_brk               = 12,
    SYS_munmap            = 11,
    SYS_mremap            = 25,
    SYS_clone             = 56,
    SYS_execve            = 59,
    SYS_mmap              = 9,
    SYS_wait4             = 61,
    SYS_prlimit64         = 302,
    SYS_fork              = 57,
    SYS_archprctl         = 158,
    SYS_open              = 2,
    SYS_stat              = 4,
    SYS_readlink          = 89,
    SYS_access            = 21,
    SYS_unlink            = 87,
    SYS_rename            = 82,
    SYS_getrandom         = 318,
    SYS_rt_sigaction      = 13,
    SYS_dup               = 32,
    SYS_pipe              = 22,
    SYS_madvise           = 28,
    SYS_mprotect          = 10,
    SYS_poll              = 7,
    SYS_membarrier        = 324,
    SYS_sched_getaffinity = 204,
    SYS_getrusage         = 98,
    SYS_prctl             = 157,
};

enum {
    ARCH_SET_FS = 0x1002,
};

static int
sysarchprctl(LFIXProc* p, int code, uintptr_t addr)
{
    switch (code) {
    case ARCH_SET_FS:
        addr = procaddr(p, addr);
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

SyscallFn syscalls[] = {
    [SYS_read]              = sysread_,
    [SYS_write]             = syswrite_,
    [SYS_readv]             = sysreadv_,
    [SYS_writev]            = syswritev_,
    [SYS_archprctl]         = sysarchprctl_,
    [SYS_set_tid_address]   = sysignore_,
    [SYS_brk]               = sysbrk_,
    [SYS_ioctl]             = syserror_,
    [SYS_exit_group]        = sysexit_,
    [SYS_exit]              = sysexit_,
    [SYS_close]             = sysclose_,
    [SYS_open]              = sysopen_,
    [SYS_fstat]             = sysfstat_,
    [SYS_newfstatat]        = sysfstatat_,
    [SYS_openat]            = sysopenat_,
    [SYS_mmap]              = sysmmap_,
    [SYS_munmap]            = sysmunmap_,
    [SYS_mprotect]          = sysmprotect_,
    [SYS_fcntl]             = sysignore_,
    [SYS_clock_gettime]     = sysclock_gettime_,
    [SYS_rt_sigprocmask]    = sysignore_,
    [SYS_membarrier]        = sysignore_,
    [SYS_getrandom]         = sysgetrandom_,
    [SYS_sched_getaffinity] = syssched_getaffinity_,
    [SYS_getpid]            = sysgetpid_,
    [SYS_mremap]            = syserror_,
    [SYS_madvise]           = sysignore_,
    [SYS_getrusage]         = sysignore_,
    [SYS_getcwd]            = sysgetcwd_,
    [SYS_lseek]             = syslseek_,
    [SYS_prctl]             = sysignore_,
    [SYS_readlinkat]        = sysreadlinkat_,
    [SYS_faccessat]         = sysfaccessat_,
    [SYS_renameat]          = sysrenameat_,
    [SYS_sysinfo]           = syssysinfo_,
    [SYS_dup]               = sysdup_,
    [SYS_rename]            = sysrename_,
    [SYS_getdents64]        = sysgetdents64_,
    [SYS_prlimit64]         = sysignore_,
    [SYS_chdir]             = syschdir_,
};

_Static_assert(sizeof(syscalls) / sizeof(SyscallFn) < SYS_max, "syscalls exceed SYS_max");
