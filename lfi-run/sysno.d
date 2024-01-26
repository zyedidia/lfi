module sysno;

import core.lib;

enum Sys {
    GETCWD = 17,
    FCNTL = 25,
    IOCTL = 29,
    UNLINKAT = 35,
    RENAMEAT = 38,
    FACCESSAT = 48,
    CHDIR = 49,
    OPENAT = 56,
    CLOSE = 57,
    PIPE2 = 59,
    GETDENTS64 = 61,
    LSEEK = 62,
    READ = 63,
    WRITE = 64,
    READV = 65,
    WRITEV = 66,
    READLINKAT = 78,
    NEWFSTATAT = 79,
    FSTAT = 80,
    EXIT = 93,
    EXIT_GROUP = 94,
    SET_TID_ADDRESS = 96,
    CLOCK_GETTIME = 113,
    GETPID = 172,
    GETTID = 178,
    SYSINFO = 179,
    BRK = 214,
    MUNMAP = 215,
    MREMAP = 216,
    CLONE = 220,
    MMAP = 222,
    WAIT4 = 260,
    PRLIMIT64 = 261,
}

enum Err {
    AGAIN       = -11,       // Try again
    BADF        = -9,        // Bad file number
    CHILD       = -10,       // No child processes
    FAULT       = -14,       // Bad address
    FBIG        = -27,       // File too large
    INTR        = -4,        // Interrupted system call
    INVAL       = -22,       // Invalid argument
    IO          = -5,        // I/O error
    MFILE       = -24,       // Too many open files
    NAMETOOLONG = -36,       // File name too long
    NFILE       = -23,       // File table overflow
    NOENT       = -2,        // No such file or directory
    NOEXEC      = -8,        // Exec format error
    NOMEM       = -12,       // Out of memory
    NOSPC       = -28,       // No space left on device
    NOSYS       = -38,       // Invalid system call number
    NXIO        = -6,        // No such device or address
    PERM        = -1,        // Operation not permitted
    PIPE        = -32,       // Broken pipe
    RANGE       = -34,       // Out of range
    SPIPE       = -29,       // Illegal seek
    SRCH        = -3,        // No such process
    TXTBSY      = -26,       // Text file busy
    TOOBIG      = -7,        // Argument list too long
}

int syserr(int val) {
    if (val == -1) {
        return -errno;
    }
    return val;
}

ssize syserr(ssize val) {
    if (val == -1) {
        return -errno;
    }
    return val;
}

