module arch.arm64.sys;

import proc;
import sys;

// System call numbers to match Linux.
enum Sys {
    GETCWD          = 17,
    FCNTL           = 25,
    IOCTL           = 29,
    UNLINKAT        = 35,
    RENAMEAT        = 38,
    FACCESSAT       = 48,
    CHDIR           = 49,
    OPENAT          = 56,
    CLOSE           = 57,
    PIPE2           = 59,
    GETDENTS64      = 61,
    LSEEK           = 62,
    READ            = 63,
    WRITE           = 64,
    READV           = 65,
    WRITEV          = 66,
    READLINKAT      = 78,
    NEWFSTATAT      = 79,
    FSTAT           = 80,
    EXIT            = 93,
    EXIT_GROUP      = 94,
    SET_TID_ADDRESS = 96,
    CLOCK_GETTIME   = 113,
    RT_SIGPROCMASK  = 135,
    GETPID          = 172,
    GETTID          = 178,
    SYSINFO         = 179,
    BRK             = 214,
    MUNMAP          = 215,
    MREMAP          = 216,
    CLONE           = 220,
    EXECVE          = 221,
    MMAP            = 222,
    WAIT4           = 260,
    PRLIMIT64       = 261,
    GETRANDOM       = 278,
    RT_SIGACTION    = 134,
    PRCTL           = 167,
    MADVISE         = 233,
    MPROTECT        = 226,
}

alias SyscallFn = uintptr function(Proc* p, ulong[6] args);

SyscallFn[] systbl = [
    Sys.GETCWD:          &sysgetcwd_,
    Sys.FCNTL:           &ignore,
    Sys.IOCTL:           &ignore,
    Sys.UNLINKAT:        &sysunlinkat_,
    Sys.RENAMEAT:        &sysrenameat_,
    Sys.FACCESSAT:       &sysfaccessat_,
    Sys.CHDIR:           &syschdir_,
    Sys.OPENAT:          &sysopenat_,
    Sys.CLOSE:           &sysclose_,
    Sys.PIPE2:           &syspipe_,
    Sys.GETDENTS64:      &sysgetdents_,
    Sys.LSEEK:           &syslseek_,
    Sys.READ:            &sysread_,
    Sys.WRITE:           &syswrite_,
    Sys.READV:           &sysreadv_,
    Sys.WRITEV:          &syswritev_,
    Sys.READLINKAT:      &sysreadlinkat_,
    Sys.NEWFSTATAT:      &sysnewfstatat_,
    Sys.FSTAT:           &sysfstatat_,
    Sys.EXIT:            &sysexit_,
    Sys.EXIT_GROUP:      &sysexit_,
    Sys.SET_TID_ADDRESS: &ignore,
    Sys.CLOCK_GETTIME:   &systime_,
    Sys.RT_SIGPROCMASK:  &ignore,
    Sys.GETPID:          &sysgetpid_,
    Sys.GETTID:          &ignore,
    Sys.SYSINFO:         &syssysinfo_,
    Sys.BRK:             &sysbrk_,
    Sys.MUNMAP:          &sysmunmap_,
    Sys.MREMAP:          &sysmremap_,
    Sys.CLONE:           &sysfork_,
    Sys.EXECVE:          &sysexecv_,
    Sys.MMAP:            &sysmmap_,
    Sys.WAIT4:           &syswait_,
    Sys.PRLIMIT64:       &ignore,
    Sys.GETRANDOM:       &sysgetrandom_,
    Sys.RT_SIGACTION:    &ignore,
    Sys.PRCTL:           &ignore,
    Sys.MADVISE:         &ignore,
    Sys.MPROTECT:        &sysmprotect_,
];
