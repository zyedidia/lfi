// For mremap
#define _GNU_SOURCE

#include "syscall.h"
#include "sys.h"

enum {
    SYS_getcwd          = 17,
    SYS_fcntl           = 25,
    SYS_ioctl           = 29,
    SYS_unlinkat        = 35,
    SYS_renameat        = 38,
    SYS_faccessat       = 48,
    SYS_chdir           = 49,
    SYS_openat          = 56,
    SYS_close           = 57,
    SYS_pipe2           = 59,
    SYS_getdents64      = 61,
    SYS_lseek           = 62,
    SYS_read            = 63,
    SYS_write           = 64,
    SYS_readv           = 65,
    SYS_writev          = 66,
    SYS_readlinkat      = 78,
    SYS_newfstatat      = 79,
    SYS_fstat           = 80,
    SYS_exit            = 93,
    SYS_exit_group      = 94,
    SYS_set_tid_address = 96,
    SYS_clock_gettime   = 113,
    SYS_rt_sigprocmask  = 135,
    SYS_getpid          = 172,
    SYS_gettid          = 178,
    SYS_sysinfo         = 179,
    SYS_brk             = 214,
    SYS_munmap          = 215,
    SYS_mremap          = 216,
    SYS_clone           = 220,
    SYS_execve          = 221,
    SYS_mmap            = 222,
    SYS_wait4           = 260,
    SYS_prlimit64       = 261,
    SYS_getrandom       = 278,
    SYS_rt_sigaction    = 134,
    SYS_prctl           = 167,
    SYS_madvise         = 233,
    SYS_mprotect        = 226,
};

SyscallFn syscalls[] = {
    [SYS_read]            = sysread_,
    [SYS_write]           = syswrite_,
    [SYS_readv]           = sysreadv_,
    [SYS_writev]          = syswritev_,
    [SYS_set_tid_address] = sysignore_,
    [SYS_brk]             = sysbrk_,
    [SYS_ioctl]           = sysignore_,
    [SYS_exit_group]      = sysexit_,
    [SYS_exit]            = sysexit_,
    [SYS_openat]          = sysopenat_,
    [SYS_close]           = sysclose_,
    [SYS_newfstatat]      = sysfstatat_,
    [SYS_mmap]            = sysmmap_,
    [SYS_munmap]          = sysmunmap_,
    [SYS_mprotect]        = sysmprotect_,
};

_Static_assert(sizeof(syscalls) / sizeof(SyscallFn) < SYS_max, "syscalls exceed SYS_max");
