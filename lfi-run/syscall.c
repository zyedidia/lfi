#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/syscall.h>

#include <sys/uio.h>

#include "lfi.h"
#include "heap.h"

enum {
    SYS_GETCWD = 17,
    SYS_FCNTL = 25,
    SYS_IOCTL = 29,
    SYS_UNLINKAT = 35,
    SYS_FACCESSAT = 48,
    SYS_CHDIR = 49,
    SYS_OPENAT = 56,
    SYS_CLOSE = 57,
    SYS_GETDENTS64 = 61,
    SYS_LSEEK = 62,
    SYS_READ = 63,
    SYS_WRITE = 64,
    SYS_READV = 65,
    SYS_WRITEV = 66,
    SYS_READLINKAT = 78,
    SYS_NEWFSTATAT = 79,
    SYS_FSTAT = 80,
    SYS_EXIT = 93,
    SYS_EXIT_GROUP = 94,
    SYS_SET_TID_ADDRESS = 96,
    SYS_CLOCK_GETTIME = 113,
    SYS_GETPID = 172,
    SYS_GETTID = 178,
    SYS_SYSINFO = 179,
    SYS_BRK = 214,
    SYS_MUNMAP = 215,
    SYS_MREMAP = 216,
    SYS_MMAP = 222,
    SYS_PRLIMIT64 = 261,
};

enum {
    MAX_PATH = 1024,
};

static void check(struct proc* proc, int val) {
    if (val == -1) {
        proc->regs.x0 = -errno;
    } else {
        proc->regs.x0 = val;
    }
}

static uint64_t proc_addr(struct proc* proc, uint64_t addr) {
    return (uint32_t) (addr) | (uint64_t) proc->sys.base;
}

static bool proc_inbounds(struct proc* proc, uint64_t addr) {
    uint64_t base = (uint64_t) proc->mem.base;
    return addr >= base && addr < base + proc->mem.len;
}

static void sys_unlinkat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    char* pathname = (char*) proc_addr(proc, proc->regs.x1);
    int flags = proc->regs.x2;
    check(proc, unlinkat(dirfd, pathname, flags));
}

static void sys_getdents64(struct proc* proc) {
    // TODO: use readdir instead
    int fd = proc->regs.x0;
    void* dirp = (void*) proc_addr(proc, proc->regs.x1);
    size_t count = proc->regs.x2;
    check(proc, syscall(SYS_getdents64, fd, dirp, count));
}

static void sys_readlinkat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    // TODO
    char* pathname = (char*) proc_addr(proc, proc->regs.x1);
    char* buf = (char*) proc_addr(proc, proc->regs.x2);
    size_t bufsiz = proc->regs.x3;
    check(proc, readlinkat(dirfd, pathname, buf, bufsiz));
}

static void sys_faccessat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    // TODO
    char* pathname = (char*) proc_addr(proc, proc->regs.x1);
    int mode = proc->regs.x2;
    check(proc, faccessat(dirfd, pathname, mode, AT_EACCESS));
}

static void sys_chdir(struct proc* proc) {
    check(proc, chdir((char*) proc_addr(proc, proc->regs.x0)));
}

static void sys_sysinfo(struct proc* proc) {
    check(proc, sysinfo((struct sysinfo*) proc_addr(proc, proc->regs.x0)));
}

static void sys_getcwd(struct proc* proc) {
    char* buf = (char*) proc_addr(proc, proc->regs.x0);
    size_t size = proc->regs.x1;
    proc->regs.x0 = (uint64_t) getcwd(buf, size);
}

static void sys_clock_gettime(struct proc* proc) {
    clockid_t which_clock = (clockid_t) proc->regs.x0;
    struct timespec* tp = (struct timespec*) proc_addr(proc, proc->regs.x1);
    check(proc, clock_gettime(which_clock, tp));
}

static void sys_read(struct proc* proc) {
    int fd = proc->regs.x0;
    void* buf = (void*) proc_addr(proc, proc->regs.x1);
    size_t size = proc->regs.x2;
    check(proc, read(fd, buf, size));
}

static void sys_readv(struct proc* proc) {
    int fd = proc->regs.x0;
    struct iovec* iov = (struct iovec*) proc_addr(proc, proc->regs.x1);
    int iovcnt = proc->regs.x2;

    // TODO: copy to prevent TOCTOU

    for (int i = 0; i < iovcnt; i++) {
        if (iov[i].iov_base == NULL && iov[i].iov_len == 0) {
            continue;
        }

        if (!proc_inbounds(proc, (uint64_t) &iov[i])) {
            proc->regs.x0 = -1;
            return;
        }
        struct iovec* v = &iov[i];
        v->iov_base = (void*) proc_addr(proc, (uint64_t) v->iov_base);
        if (!proc_inbounds(proc, (uint64_t) v->iov_base) || !proc_inbounds(proc, (uint64_t) v->iov_base + v->iov_len)) {
            proc->regs.x0 = -1;
            return;
        }
    }

    check(proc, readv(fd, iov, iovcnt));
}

static void sys_write(struct proc* proc) {
    int fd = proc->regs.x0;
    void* buf = (void*) proc_addr(proc, proc->regs.x1);
    size_t size = proc->regs.x2;
    check(proc, write(fd, buf, size));
}

static void sys_writev(struct proc* proc) {
    int fd = proc->regs.x0;
    struct iovec* iov = (struct iovec*) proc_addr(proc, proc->regs.x1);
    int iovcnt = proc->regs.x2;

    // TODO: copy to prevent TOCTOU

    for (int i = 0; i < iovcnt; i++) {
        if (iov[i].iov_base == NULL && iov[i].iov_len == 0) {
            continue;
        }

        if (!proc_inbounds(proc, (uint64_t) &iov[i])) {
            proc->regs.x0 = -1;
            return;
        }
        struct iovec* v = &iov[i];
        v->iov_base = (void*) proc_addr(proc, (uint64_t) v->iov_base);
        if (!proc_inbounds(proc, (uint64_t) v->iov_base) || !proc_inbounds(proc, (uint64_t) v->iov_base + v->iov_len)) {
            proc->regs.x0 = -1;
            return;
        }
    }

    check(proc, writev(fd, iov, iovcnt));
}

static void sys_openat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    if (dirfd != AT_FDCWD) {
        proc->regs.x0 = -1;
        return;
    }
    char* pathname = (char*) proc_addr(proc, proc->regs.x1);
    if (!proc_inbounds(proc, (uint64_t) pathname + MAX_PATH)) {
        proc->regs.x0 = -1;
        return;
    }

    char safepath[MAX_PATH];
    strncpy(safepath, pathname, MAX_PATH - 1);
    safepath[MAX_PATH - 1] = '\0';

    int flags = proc->regs.x2;
    mode_t mode = proc->regs.x3;

    int fd = openat(dirfd, safepath, flags, mode);
    proc->regs.x0 = fd;
}

static void sys_brk(struct proc* proc) {
    if (proc->regs.x0 != 0) {
        proc->brk = proc_addr(proc, proc->regs.x0);
    }
    proc->regs.x0 = proc->brk;
}

static void sys_mmap(struct proc* proc) {
    // TODO: mmap stuff
    if (proc->regs.x1 == 0) {
        proc->regs.x0 = -1;
        return;
    }
    if (proc->regs.x0 == 0) {
        size_t size = ceilpg(proc->regs.x1);
        void* p = proc_alloc(proc, size);
        if (!p) {
            proc->regs.x0 = -1;
            return;
        }
        proc->regs.x0 = (uint64_t) p;
        // TODO: protections and flags
    } else if (proc->regs.x0 + proc->regs.x1 <= proc->brk) {
        /* proc->regs.x0 = -1; */
        return;
    } else {
        fprintf(stderr, "[warning]: bad allocation\n");
        proc->regs.x0 = -1;
    }
}

static void sys_munmap(struct proc* proc) {
    // TODO
}

static void sys_lseek(struct proc* proc) {
    int fd = proc->regs.x0;
    off_t off = proc->regs.x1;
    unsigned int whence = proc->regs.x2;
    check(proc, lseek(fd, off, whence));
}

static void sys_close(struct proc* proc) {
    check(proc, close(proc->regs.x0));
}

static void sys_newfstatat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    char* filename = (char*) proc->regs.x1;
    struct stat* statbuf = (struct stat*) proc_addr(proc, proc->regs.x2);
    int flag = proc->regs.x3;
    check(proc, fstatat(dirfd, filename, statbuf, flag));
}

static void sys_fstat(struct proc* proc) {
    check(proc, fstat(proc->regs.x0, (struct stat*) proc_addr(proc, proc->regs.x1)));
}

void syscall_handler(struct proc* proc) {
    uint64_t sysno = proc->regs.x8;

    switch (sysno) {
    case SYS_EXIT_GROUP:
    case SYS_EXIT:
        exit(proc->regs.x0);
        break;
    case SYS_SET_TID_ADDRESS:
        proc->regs.x0 = 0;
        break;
    case SYS_IOCTL:
        fprintf(stderr, "[warning]: ioctl ignored\n");
        proc->regs.x0 = 0;
        break;
    case SYS_FCNTL:
        fprintf(stderr, "[warning]: fcntl ignored\n");
        proc->regs.x0 = 0;
        break;
    case SYS_GETPID:
        proc->regs.x0 = 0;
        break;
    case SYS_GETTID:
        proc->regs.x0 = 0;
        break;
    case SYS_GETCWD:
        sys_getcwd(proc);
        break;
    case SYS_READ:
        sys_read(proc);
        break;
    case SYS_READV:
        sys_readv(proc);
        break;
    case SYS_WRITE:
        sys_write(proc);
        break;
    case SYS_WRITEV:
        sys_writev(proc);
        break;
    case SYS_OPENAT:
        sys_openat(proc);
        break;
    case SYS_LSEEK:
        sys_lseek(proc);
        break;
    case SYS_CLOSE:
        sys_close(proc);
        break;
    case SYS_BRK:
        sys_brk(proc);
        break;
    case SYS_MMAP:
        sys_mmap(proc);
        break;
    case SYS_MUNMAP:
        sys_munmap(proc);
        break;
    case SYS_MREMAP:
        proc->regs.x0 = -1;
        break;
    case SYS_CHDIR:
        sys_chdir(proc);
        break;
    case SYS_NEWFSTATAT:
        sys_newfstatat(proc);
        break;
    case SYS_READLINKAT:
        sys_readlinkat(proc);
        break;
    case SYS_SYSINFO:
        sys_sysinfo(proc);
        break;
    case SYS_CLOCK_GETTIME:
        sys_clock_gettime(proc);
        break;
    case SYS_PRLIMIT64:
        proc->regs.x0 = 0;
        break;
    case SYS_FSTAT:
        sys_fstat(proc);
        break;
    case SYS_FACCESSAT:
        sys_faccessat(proc);
        break;
    case SYS_GETDENTS64:
        sys_getdents64(proc);
        break;
    case SYS_UNLINKAT:
        sys_unlinkat(proc);
        break;
    default:
        fprintf(stderr, "unhandled syscall: %ld\n", sysno);
        exit(1);
        break;
    }
}
