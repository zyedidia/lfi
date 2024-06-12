module arch.amd64.sys;

import core.lib;

import proc;
import sys;
import lfi;

// System call numbers to match Linux.
enum Sys {
    GETCWD          = 79,
    FCNTL           = 72,
    IOCTL           = 16,
    UNLINKAT        = 263,
    RENAMEAT        = 264,
    FACCESSAT       = 269,
    CHDIR           = 80,
    OPENAT          = 257,
    CLOSE           = 3,
    PIPE2           = 293,
    GETDENTS64      = 217,
    LSEEK           = 8,
    READ            = 0,
    WRITE           = 1,
    READV           = 19,
    WRITEV          = 20,
    READLINKAT      = 267,
    NEWFSTATAT      = 262,
    FSTAT           = 5,
    EXIT            = 60,
    EXIT_GROUP      = 231,
    SET_TID_ADDRESS = 218,
    CLOCK_GETTIME   = 228,
    RT_SIGPROCMASK  = 14,
    GETPID          = 39,
    GETTID          = 186,
    SYSINFO         = 99,
    BRK             = 12,
    MUNMAP          = 11,
    MREMAP          = 25,
    CLONE           = 56,
    EXECVE          = 59,
    MMAP            = 9,
    WAIT4           = 61,
    PRLIMIT64       = 302,
    FORK            = 57,
    ARCH_PRCTL      = 158,
    OPEN            = 2,
    STAT            = 4,
    READLINK        = 89,
    ACCESS          = 21,
    UNLINK          = 87,
    RENAME          = 82,
    GETRANDOM       = 318,
    RT_SIGACTION    = 13,
}

enum {
    ARCH_SET_FS = 0x1002,
}

uintptr sysarchprctl_(Proc* p, ulong[6] args) {
    return sysarchprctl(p, cast(int) args[0], args[1]);
}

uintptr sysarchprctl(Proc* p, int code, ulong addr) {
    switch (code) {
    case ARCH_SET_FS:
        addr = procaddr(p, addr);
        lfi_proc_get_regs(p.lp).fs = addr;
        return 0;
    default:
        return Err.INVAL;
    }
}

uintptr sysopen_(Proc* p, ulong[6] args) {
    return sysopenat(p, AT_FDCWD, args[0], cast(int) args[1], cast(int) args[2]);
}

uintptr sysstat_(Proc* p, ulong[6] args) {
    return sysfstatat(p, AT_FDCWD, args[0], args[1], 0);
}

uintptr sysreadlink_(Proc* p, ulong[6] args) {
    return sysreadlinkat(p, AT_FDCWD, args[0], args[1], args[2]);
}

uintptr sysaccess_(Proc* p, ulong[6] args) {
    return sysfaccessat(p, AT_FDCWD, args[0], cast(int) args[1], 0);
}

uintptr sysunlink_(Proc* p, ulong[6] args) {
    return sysunlinkat(p, AT_FDCWD, args[0], 0);
}

uintptr sysrename_(Proc* p, ulong[6] args) {
    return sysrenameat(p, AT_FDCWD, args[0], AT_FDCWD, args[1], 0);
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
    Sys.ARCH_PRCTL:      &sysarchprctl_,
    Sys.OPEN:            &sysopen_,
    Sys.STAT:            &sysstat_,
    Sys.READLINK:        &sysreadlink_,
    Sys.ACCESS:          &sysaccess_,
    Sys.UNLINK:          &sysunlink_,
    Sys.RENAME:          &sysrename_,
    Sys.GETRANDOM:       &sysgetrandom_,
    Sys.RT_SIGACTION:    &ignore,
];
