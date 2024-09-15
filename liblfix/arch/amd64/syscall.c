#include "sys.h"
#include "syscall.h"

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
};

SyscallFn syscalls[] = {
    [SYS_read]   = sysread_,
    [SYS_write]  = syswrite_,
    [SYS_readv]  = sysreadv_,
    [SYS_writev] = syswritev_,
};

_Static_assert(sizeof(syscalls) / sizeof(SyscallFn) < SYS_max);
