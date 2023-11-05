#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>

#include <sys/uio.h>

#include "lfi.h"

enum {
    SYS_IOCTL = 29,
    SYS_OPENAT = 56,
    SYS_WRITEV = 66,
    SYS_EXIT = 93,
    SYS_EXIT_GROUP = 94,
    SYS_SET_TID_ADDRESS = 96,
    SYS_GETPID = 172,
    SYS_BRK = 214,
};

enum {
    MAX_PATH = 1024,
};

static uint64_t proc_addr(struct proc* proc, uint64_t addr) {
    return (uint32_t) (addr) | (uint64_t) proc->sys.base;
}

static bool proc_inbounds(struct proc* proc, uint64_t addr) {
    uint64_t base = (uint64_t) proc->mem.base;
    return addr >= base && addr < base + proc->mem.len;
}

static void sys_writev(struct proc* proc) {
    int fd = proc->regs.x0;
    struct iovec* iov = (struct iovec*) proc_addr(proc, proc->regs.x1);
    int iovcnt = proc->regs.x2;

    // TODO: copy to prevent TOCTOU

    for (int i = 0; i < iovcnt; i++) {
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

    proc->regs.x0 = writev(fd, iov, iovcnt);
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
        printf("set brk:%lx\n", proc->brk);
    }
    proc->regs.x0 = proc->brk;
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
        printf("[warning]: ioctl ignored\n");
        proc->regs.x0 = 0;
        break;
    case SYS_GETPID:
        proc->regs.x0 = 0;
        break;
    case SYS_WRITEV:
        sys_writev(proc);
        break;
    case SYS_OPENAT:
        sys_openat(proc);
        break;
    case SYS_BRK:
        sys_brk(proc);
        break;
    default:
        printf("unhandled syscall: %ld\n", sysno);
        exit(1);
        break;
    }
}
