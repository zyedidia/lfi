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
    case Sys.EXIT_GROUP, Sys.EXIT:
        exit(1);
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
