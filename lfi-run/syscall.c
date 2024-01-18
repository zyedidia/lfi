#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <assert.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/syscall.h>
#include <sys/uio.h>

#include "lfi.h"
#include "mem.h"
#include "queue.h"
#include "pipe.h"
#include "file.h"

enum {
    SYS_GETCWD = 17,
    SYS_FCNTL = 25,
    SYS_IOCTL = 29,
    SYS_UNLINKAT = 35,
    SYS_RENAMEAT = 38,
    SYS_FACCESSAT = 48,
    SYS_CHDIR = 49,
    SYS_OPENAT = 56,
    SYS_CLOSE = 57,
    SYS_PIPE2 = 59,
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
    SYS_CLONE = 220,
    SYS_MMAP = 222,
    SYS_WAIT4 = 260,
    SYS_PRLIMIT64 = 261,
};

enum {
    MAX_PATH = 1024,
};

static struct file* fdalloc(struct proc* p, int* fd) {
    struct file* f = NULL;
    for (int i = 0; i < NFD; i++) {
        if (!p->fdtable[i].allocated) {
            p->fdtable[i].allocated = true;
            f = &p->fdtable[i];
            *fd = i;
            break;
        }
    }
    return f;
}

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
    uint64_t base = (uint64_t) proc->sys.base;
    uint64_t end = (uint64_t) proc->stack.base + proc->stack.len;
    return addr >= base && addr < end;
}

static bool proc_inbrk(struct proc* proc, uint64_t addr) {
    uint64_t base = (uint64_t) proc->brk_heap.base;
    uint64_t end = (uint64_t) proc->brk_heap.base + proc->brk_heap.len;
    return addr >= base && addr < end;
}

static bool proc_inmmap(struct proc* proc, uint64_t addr) {
    uint64_t base = (uint64_t) proc->mmap_heap.base;
    uint64_t end = (uint64_t) proc->mmap_heap.base + proc->mmap_heap.len;
    return addr >= base && addr < end;
}

static void sys_unlinkat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    if (dirfd != AT_FDCWD) {
        proc->regs.x0 = -1;
        return;
    }
    char* pathname = (char*) proc_addr(proc, proc->regs.x1);
    int flags = proc->regs.x2;
    check(proc, unlinkat(dirfd, pathname, flags));
}

static void sys_getdents64(struct proc* proc) {
    // TODO: use readdir instead
    int fd = proc->regs.x0;
    void* dirp = (void*) proc_addr(proc, proc->regs.x1);
    size_t count = proc->regs.x2;
    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated || !proc->fdtable[fd].is_file) {
        proc->regs.x0 = -1;
        return;
    }
    struct filedev* fdev = (struct filedev*) proc->fdtable[fd].device;
    check(proc, syscall(SYS_getdents64, fdev->fd, dirp, count));
}

static void sys_readlinkat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    if (dirfd != AT_FDCWD) {
        proc->regs.x0 = -1;
        return;
    }
    // TODO
    char* pathname = (char*) proc_addr(proc, proc->regs.x1);
    char* buf = (char*) proc_addr(proc, proc->regs.x2);
    size_t bufsiz = proc->regs.x3;
    check(proc, readlinkat(dirfd, pathname, buf, bufsiz));
}

static void sys_renameat(struct proc* proc) {
    int olddirfd = proc->regs.x0;
    if (olddirfd != AT_FDCWD) {
        proc->regs.x0 = -1;
        return;
    }
    int newdirfd = proc->regs.x2;
    if (newdirfd != AT_FDCWD) {
        proc->regs.x0 = -1;
        return;
    }
    // TODO
    char* oldpath = (char*) proc_addr(proc, proc->regs.x1);
    char* newpath = (char*) proc_addr(proc, proc->regs.x3);
    check(proc, renameat(olddirfd, oldpath, newdirfd, newpath));
}

static void sys_faccessat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    if (dirfd != AT_FDCWD) {
        proc->regs.x0 = -1;
        return;
    }
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
    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated || !proc->fdtable[fd].read) {
        proc->regs.x0 = -1;
        return;
    }
    check(proc, proc->fdtable[fd].read(proc, proc->fdtable[fd].device, buf, size));
}

static void sys_readv(struct proc* proc) {
    int fd = proc->regs.x0;
    struct iovec* iov = (struct iovec*) proc_addr(proc, proc->regs.x1);
    int iovcnt = proc->regs.x2;

    // TODO: copy to prevent TOCTOU

    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated || !proc->fdtable[fd].read) {
        proc->regs.x0 = -1;
        return;
    }

    int total = 0;
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
        int n = proc->fdtable[fd].read(proc, proc->fdtable[fd].device, v->iov_base, v->iov_len);
        if (n < 0) {
            proc->regs.x0 = n;
            return;
        }
        total += n;
    }
    proc->regs.x0 = total;
}

static void sys_write(struct proc* proc) {
    int fd = proc->regs.x0;
    void* buf = (void*) proc_addr(proc, proc->regs.x1);
    size_t size = proc->regs.x2;
    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated || !proc->fdtable[fd].write) {
        goto err;
    }
    check(proc, proc->fdtable[fd].write(proc, proc->fdtable[fd].device, buf, size));

    return;
err:
    proc->regs.x0 = -1;
    return;
}

static void sys_writev(struct proc* proc) {
    int fd = proc->regs.x0;
    struct iovec* iov = (struct iovec*) proc_addr(proc, proc->regs.x1);
    int iovcnt = proc->regs.x2;

    // TODO: copy to prevent TOCTOU

    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated || !proc->fdtable[fd].write) {
        proc->regs.x0 = -1;
        return;
    }

    int total = 0;
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
        int n = proc->fdtable[fd].write(proc, proc->fdtable[fd].device, v->iov_base, v->iov_len);
        if (n < 0) {
            proc->regs.x0 = n;
            return;
        }
        total += n;
    }
    proc->regs.x0 = total;
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

    int linuxfd = openat(dirfd, safepath, flags, mode);
    if (linuxfd < 0) {
        proc->regs.x0 = linuxfd;
        return;
    }
    int fd;
    struct file* f = fdalloc(proc, &fd);
    assert(f);
    filedev_init(f, linuxfd);
    proc->regs.x0 = fd;
}

static void sys_brk(struct proc* proc) {
    if (proc->regs.x0 != 0) {
        proc->brk = proc_addr(proc, proc->regs.x0);
    }
    proc->regs.x0 = proc->brk;
}

static void sys_mmap(struct proc* proc) {
    if (proc->regs.x1 == 0) {
        proc->regs.x0 = -1;
        return;
    }

    uint64_t base = proc->regs.x0;
    if (base) {
        base = truncpg(proc_addr(proc, proc->regs.x0));
    }
    size_t size = ceilpg(proc->regs.x1);
    int prot = proc->regs.x2;

    if ((prot & PROT_EXEC) != 0) {
        proc->regs.x0 = -1;
        return;
    }

    int flags = proc->regs.x3;

    if (base != 0 && proc_inbrk(proc, base) && proc_inbrk(proc, base + size)) {
        /* mprotect((void*) base, size, prot); */
        proc->regs.x0 = base;
        return;
    }

    if (base != 0 && (!proc_inmmap(proc, base) || !proc_inmmap(proc, base + size))) {
        proc->regs.x0 = -1;
        return;
    }

    proc->regs.x0 = proc_mmap(proc, base, size, prot, flags | MAP_FIXED);
    return;
}

static void sys_munmap(struct proc* proc) {
    uint64_t addr = proc_addr(proc, proc->regs.x0);
    size_t size = proc->regs.x1;
    if (!proc_unmap(proc, addr, size)) {
        proc->regs.x0 = -1;
    } else {
        proc->regs.x0 = 0;
    }
}

static void sys_lseek(struct proc* proc) {
    int fd = proc->regs.x0;
    off_t off = proc->regs.x1;
    unsigned int whence = proc->regs.x2;

    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated || !proc->fdtable[fd].lseek) {
        proc->regs.x0 = -1;
        return;
    }

    check(proc, proc->fdtable[fd].lseek(proc, proc->fdtable[fd].device, off, whence));
}

static void sys_close(struct proc* proc) {
    int fd = proc->regs.x0;

    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated) {
        proc->regs.x0 = -1;
        return;
    }

    if (!proc->fdtable[fd].close) {
        proc->regs.x0 = 0;
        return;
    }

    check(proc, proc->fdtable[fd].close(proc, proc->fdtable[fd].device));
}

static void sys_newfstatat(struct proc* proc) {
    int dirfd = proc->regs.x0;
    if (dirfd != AT_FDCWD) {
        proc->regs.x0 = -1;
        return;
    }
    char* filename = (char*) proc->regs.x1;
    struct stat* statbuf = (struct stat*) proc_addr(proc, proc->regs.x2);
    int flag = proc->regs.x3;
    check(proc, fstatat(dirfd, filename, statbuf, flag));
}

static void sys_fstat(struct proc* proc) {
    int fd = proc->regs.x0;
    if (fd < 0 || fd >= NFD || !proc->fdtable[fd].allocated || !proc->fdtable[fd].is_file) {
        proc->regs.x0 = -1;
        return;
    }
    struct filedev* fdev = (struct filedev*) proc->fdtable[fd].device;
    check(proc, fstat(fdev->fd, (struct stat*) proc_addr(proc, proc->regs.x1)));
}

static void sys_wait4(struct proc* proc) {
    int pid = proc->regs.x0;
    /* int* status = (int*) proc_addr(proc, proc->regs.x1); */
    assert(pid == -1);
    assert(proc->regs.x1 == 0);

    if (proc->nchildren == 0) {
        proc->regs.x0 = -1;
        return;
    }

    while (1) {
        struct proc* zombie = manager.exitq.front;
        while (zombie) {
            if (zombie->parent == proc) {
                int pid = proc_getpid(zombie);
                queue_remove(&manager.exitq, zombie);
                // TODO: free the zombie
                proc->regs.x0 = pid;
                proc->nchildren--;
                return;
            }
            zombie = zombie->next;
        }

        proc_wait(proc, &manager.waitq, STATE_BLOCKED);
    }
}

void sys_pipe2(struct proc* proc) {
    int* pipefd = (int*) proc_addr(proc, proc->regs.x0);
    // TODO: pipe flags
    int fd0, fd1;
    struct file* f0 = fdalloc(proc, &fd0);
    if (!f0)
        goto err;
    struct file* f1 = fdalloc(proc, &fd1);
    if (!f1)
        goto err;

    if (!pipe_new(f0, f1))
        goto err;

    pipefd[0] = fd0;
    pipefd[1] = fd1;

    proc->regs.x0 = 0;
    return;

err:
    proc->regs.x0 = -1;
    return;
}

void syscall_handler(struct proc* proc) {
    uint64_t sysno = proc->regs.x8;

    switch (sysno) {
    case SYS_EXIT_GROUP:
    case SYS_EXIT:
        if (manager.init != proc) {
            for (size_t i = 0; i < proc->nchildren; i++) {
                proc->children[i]->parent = manager.init;
                manager.init->nchildren++;
            }

            if (proc->parent && proc->parent->state == STATE_BLOCKED && proc->parent->wq == (void*) &manager.waitq) {
                queue_wake(&manager.waitq, proc->parent);
            }
        }

        proc_wait(proc, &manager.exitq, STATE_EXITED);
        break;
    case SYS_SET_TID_ADDRESS:
        proc->regs.x0 = 0;
        break;
    case SYS_IOCTL:
        /* fprintf(stderr, "[warning]: ioctl ignored\n"); */
        proc->regs.x0 = 0;
        break;
    case SYS_FCNTL:
        /* fprintf(stderr, "[warning]: fcntl ignored\n"); */
        proc->regs.x0 = 0;
        break;
    case SYS_GETPID:
        proc->regs.x0 = proc_getpid(proc);
        break;
    case SYS_GETTID:
        proc->regs.x0 = 42;
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
    case 135: // rt_sigprocmask
        proc->regs.x0 = 0;
        break;
    case SYS_CLONE:
        sys_fork(proc);
        break;
    case SYS_WAIT4:
        sys_wait4(proc);
        break;
    case SYS_PIPE2:
        sys_pipe2(proc);
        break;
    case SYS_RENAMEAT:
        sys_renameat(proc);
        break;
    default:
        fprintf(stderr, "unhandled syscall: %ld\n", sysno);
        exit(1);
        break;
    }
}
