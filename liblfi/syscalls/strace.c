#include "syscalls/strace.h"

const char*
sysname(uint64_t sysno)
{
    switch (sysno) {
    STRACE_CASE(gettid)
    STRACE_CASE(getpid)
    STRACE_CASE(write)
    STRACE_CASE(read)
    STRACE_CASE(lseek)
    STRACE_CASE(exit)
    STRACE_CASE(exit_group)
    STRACE_CASE(brk)
    STRACE_CASE(openat)
    STRACE_CASE(close)
    STRACE_CASE(writev)
    STRACE_CASE(readv)
    STRACE_CASE(pread64)
    STRACE_CASE(mmap)
    STRACE_CASE(mprotect)
    STRACE_CASE(munmap)
    STRACE_CASE(getdents64)
    STRACE_CASE(newfstatat)
    STRACE_CASE(getrandom)
    STRACE_CASE(clock_gettime)
    STRACE_CASE(ioctl)
    STRACE_CASE(set_tid_address)
    STRACE_CASE(set_robust_list)
    STRACE_CASE(uname)
    STRACE_CASE(statx)
    STRACE_CASE(rseq)
    STRACE_CASE(prlimit64)
    STRACE_CASE(statfs)
    STRACE_CASE(rt_sigprocmask)
    STRACE_CASE(getxattr)
    STRACE_CASE(lgetxattr)
    STRACE_CASE(socket)
    }
    return NULL;
}
