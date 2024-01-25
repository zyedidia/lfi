module syscall;

import core.lib;

import sysno;
import proc;
import file;

extern (C) void syscall_handler(Proc* p) {
    ulong sysno = p.regs.x8;
    uintptr ret;

    ulong a0 = p.regs.x0;
    ulong a1 = p.regs.x1;
    ulong a2 = p.regs.x2;
    ulong a3 = p.regs.x3;
    ulong a4 = p.regs.x4;
    ulong a5 = p.regs.x5;

    switch (sysno) {
    case Sys.GETPID:
        ret = p.getpid();
        break;
    case Sys.GETTID:
        ret = 0;
        break;
    case Sys.BRK:
        ret = sys_brk(p, a0);
        break;
    case Sys.MMAP:
        ret = sys_mmap(p, a0, a1, cast(int) a2, cast(int) a3, cast(int) a4, cast(long) a5);
        break;
    case Sys.MUNMAP:
        ret = sys_munmap(p, a0, a1);
        break;
    case Sys.MREMAP:
        ret = -1;
        break;
    case Sys.WAIT4:
        ret = sys_wait4(p, cast(int) a0, a1);
        break;
    case Sys.EXIT_GROUP, Sys.EXIT:
        sys_exit(p, cast(int) a0);
    case Sys.OPENAT:
        ret = sys_openat(p, cast(int) a0, a1, cast(int) a2, cast(int) a3);
        break;
    case Sys.CLOSE:
        ret = sys_close(p, cast(int) a0);
        break;
    case Sys.FSTAT:
        ret = sys_fstatat(p, cast(int) a0, 0, a1, AT_EMPTY_PATH);
        break;
    case Sys.NEWFSTATAT:
        ret = sys_fstatat(p, cast(int) a0, a1, a2, cast(int) a3);
        break;
    case Sys.READ:
        ret = sys_read(p, cast(int) a0, a1, a2);
        break;
    case Sys.GETDENTS64:
        ret = sys_getdents64(p, cast(int) a0, a1, a2);
        break;
    case Sys.LSEEK:
        ret = sys_lseek(p, cast(int) a0, a1, cast(int) a2);
        break;
    case Sys.SET_TID_ADDRESS:
        ret = 0;
        break;
    case Sys.WRITE:
        ret = sys_write(p, cast(int) a0, a1, a2);
        break;
    case Sys.WRITEV:
        ret = sys_writev(p, cast(int) a0, a1, a2);
        break;
    case Sys.IOCTL, Sys.FCNTL:
        ret = 0;
        break;
    default:
        fprintf(stderr, "unknown syscall: %ld\n", sysno);
        exit(1);
    }

    p.regs.x0 = ret;
}

int sys_openat(Proc* p, int dirfd, uintptr pathname, int flags, int mode) {
    if (dirfd != AT_FDCWD) {
        return Err.BADF;
    }
    pathname = p.addr(pathname);
    if (!p.checkptr(pathname, PATH_MAX)) {
        return Err.FAULT;
    }
    int fd;
    VFile* vf = p.fdtable.alloc(fd);
    if (!vf) {
        return Err.NFILE;
    }
    int err = file_new(vf, cast(char*) pathname, flags, mode);
    if (err < 0) {
        p.fdtable.remove(fd);
        return err;
    }
    return fd;
}

int sys_close(Proc* p, int fd) {
    // TODO: file refcount
    if (!p.fdtable.remove(fd)) {
        return Err.BADF;
    }
    return 0;
}

ssize sys_lseek(Proc* p, int fd, ssize off, int whence) {
    VFile file;
    if (!p.fdtable.get(fd, file))
        return Err.BADF;
    if (!file.lseek)
        return Err.PERM;
    return file.lseek(file.dev, p, off, whence);
}

ssize sys_read(Proc* p, int fd, uintptr buf, usize size) {
    VFile file;
    if (!p.fdtable.get(fd, file)) {
        return Err.BADF;
    }
    if (file.read == null) {
        return Err.PERM;
    }
    buf = p.addr(buf);
    if (!p.checkptr(buf, size)) {
        return Err.FAULT;
    }
    ssize i = 0;
    while (size > 0) {
        ssize n = file.read(file.dev, p, cast(ubyte*) buf, size);
        i += n;
        if (n < size) {
            break;
        }
        size -= n;
    }
    return i;
}

ssize sys_writev(Proc* p, int fd, uintptr iovp, usize iovcnt) {
    struct Iovec {
        uintptr base;
        usize len;
    }

    iovp = p.addr(iovp);
    if (!p.checkptr(iovp, iovcnt * Iovec.sizeof)) {
        return Err.FAULT;
    }

    Iovec[] iov = (cast(Iovec*) iovp)[0 .. iovcnt];
    ssize total = 0;

    for (int i = 0; i < iov.length; i++) {
        ssize n = sys_write(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}

ssize sys_write(Proc* p, int fd, uintptr buf, usize size) {
    VFile file;
    if (!p.fdtable.get(fd, file)) {
        return Err.BADF;
    }
    if (file.write == null) {
        return Err.PERM;
    }
    buf = p.addr(buf);
    if (!p.checkptr(buf, size)) {
        return Err.FAULT;
    }
    ssize i = 0;
    while (size > 0) {
        ssize n = file.write(file.dev, p, cast(ubyte*) buf, size);
        i += n;
        if (n < size) {
            break;
        }
        size -= n;
    }
    return i;
}

uintptr sys_brk(Proc* p, uintptr addr) {
    if (addr != 0) {
        p.brkp = p.addr(addr);
    }
    if (p.brkp < cast(uintptr) p.brk.base)
        p.brkp = cast(uintptr) p.brk.base;
    if (p.brkp >= cast(uintptr) p.brk.base + p.brk.len)
        p.brkp = cast(uintptr) p.brk.base + p.brk.len - 1;
    return p.brkp;
}

noreturn sys_exit(Proc* p, int status) {
    assert(0, "exit");
}

uintptr sys_mmap(Proc* p, uintptr addr, usize length, int prot, int flags, int fd, long offset) {
    return -1;
}

int sys_munmap(Proc* p, uintptr addr, usize length) {
    return -1;
}

enum {
    CLOCK_REALTIME  = 0,
    CLOCK_MONOTONIC = 1,
}

int sys_clock_gettime(Proc* p, uint clockid, uintptr tp) {
    tp = p.addr(tp);
    if (!p.checkptr(tp, TimeSpec.sizeof)) {
        return Err.FAULT;
    }
    if (clockid != CLOCK_REALTIME && clockid != CLOCK_MONOTONIC) {
        return Err.INVAL;
    }
    TimeSpec* t = cast(TimeSpec*) tp;
    int ret = clock_gettime(clockid, t);
    return ret;
}

int sys_fstatat(Proc* p, int dirfd, uintptr pathname, uintptr statbuf, int flags) {
    pathname = p.addr(pathname);
    statbuf = p.addr(statbuf);
    if ((flags & AT_EMPTY_PATH) == 0) {
        if (!p.checkptr(pathname, PATH_MAX))
            return Err.FAULT;
        // TODO: only supports AT_EMPTY_PATH
        return Err.INVAL;
    }
    if (!p.checkptr(statbuf, Stat.sizeof))
        return Err.FAULT;
    VFile file;
    if (!p.fdtable.get(dirfd, file))
        return Err.BADF;
    if (!file.stat)
        return Err.BADF;
    Stat* stat = cast(Stat*) statbuf;
    if (file.stat(file.dev, p, stat) < 0)
        return Err.INVAL;
    return 0;
}

int sys_fork(Proc* p) {
    return -1;
}

int sys_wait4(Proc* p, int pid, uintptr wstatus) {
    return -1;
}

ssize sys_getdents64(Proc* p, int fd, uintptr dirp, usize count) {
    VFile file;
    if (!p.fdtable.get(fd, file)) {
        return Err.BADF;
    }
    if (file.getdents64 == null) {
        return Err.PERM;
    }
    dirp = p.addr(dirp);
    if (!p.checkptr(dirp, count)) {
        return Err.FAULT;
    }
    ssize n = file.getdents64(file.dev, p, cast(void*) dirp, count);
    return n;
}
