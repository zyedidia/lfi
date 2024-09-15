// For mremap
#define _GNU_SOURCE

#include "syscall.h"
#include "sys.h"

enum {
    SYS_ioctl           = 16,
    SYS_archprctl       = 158,
    SYS_fcntl           = 72,
    SYS_openat          = 257,
    SYS_mmap            = 9,
    SYS_munmap          = 11,
    SYS_mremap          = 25,
    SYS_mprotect        = 10,
    SYS_set_tid_address = 218,
    SYS_brk             = 12,
    SYS_read            = 0,
    SYS_write           = 1,
    SYS_readv           = 19,
    SYS_writev          = 20,
    SYS_open            = 2,
    SYS_close           = 3,
    SYS_fstat           = 5,
    SYS_exit_group      = 231,
    SYS_exit            = 60,
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

SyscallFn syscalls[] = {
    [SYS_read]            = sysread_,
    [SYS_write]           = syswrite_,
    [SYS_readv]           = sysreadv_,
    [SYS_writev]          = syswritev_,
    [SYS_archprctl]       = sysarchprctl_,
    [SYS_set_tid_address] = sysignore_,
    [SYS_brk]             = sysbrk_,
    [SYS_ioctl]           = sysignore_,
    [SYS_exit_group]      = sysexit_,
    [SYS_exit]            = sysexit_,
};

_Static_assert(sizeof(syscalls) / sizeof(SyscallFn) < SYS_max);
