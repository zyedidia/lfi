module syscall;

import core.lib;
import core.math;
import core.alloc;

import sysno;
import proc;
import file;
import schedule;
import pipe;

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
        ret = p.pid();
        break;
    case Sys.GETTID:
        ret = 0;
        break;
    case Sys.CLOCK_GETTIME:
        ret = sys_clock_gettime(p, cast(uint) a0, a1);
        break;
    case Sys.PIPE2:
        ret = sys_pipe2(p, a0, cast(int) a1);
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
    case Sys.READV:
        ret = sys_readv(p, cast(int) a0, a1, a2);
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
    case Sys.RENAMEAT:
        ret = sys_renameat2(p, cast(int) a0, a1, cast(int) a2, a3, 0);
        break;
    case Sys.UNLINKAT:
        ret = sys_unlinkat(p, cast(int) a0, a1, cast(int) a2);
        break;
    case Sys.READLINKAT:
        ret = sys_readlinkat(p, cast(int) a0, a1, a2, a3);
        break;
    case Sys.FACCESSAT:
        ret = sys_faccessat(p, cast(int) a0, a1, cast(int) a2, cast(int) a3);
        break;
    case Sys.GETCWD:
        ret = sys_getcwd(p, a0, a1);
        break;
    case Sys.CHDIR:
        ret = sys_chdir(p, a0);
        break;
    case Sys.SYSINFO:
        ret = sys_sysinfo(p, a0);
        break;
    case Sys.CLONE:
        ret = sys_fork(p);
        break;
    case Sys.EXECVE:
        ret = sys_execve(p, a0, a1, a2);
        break;
    case Sys.IOCTL, Sys.FCNTL, Sys.PRLIMIT64, Sys.RT_SIGPROCMASK:
        ret = 0;
        break;
    default:
        fprintf(stderr, "unknown syscall: %ld\n", sysno);
        exit(1);
    }

    p.regs.x0 = ret;

    // printf("syscall %ld = %lx\n", sysno, ret);
}

int sys_openat(Proc* p, int dirfd, uintptr pathname, int flags, int mode) {
    if (dirfd != AT_FDCWD) {
        return Err.BADF;
    }
    pathname = p.addr(pathname);
    if (!p.checkpath(pathname)) {
        return Err.FAULT;
    }
    VFile* vf;
    int err = file_new(vf, p.cwd.fd, cast(char*) pathname, flags, mode);
    if (err < 0)
        return err;
    if (!vf)
        return Err.NOMEM;
    int fd = p.fdtable.alloc(vf);
    if (fd < 0) {
        kfree(vf);
        return Err.NFILE;
    }
    return fd;
}

int sys_close(Proc* p, int fd) {
    if (!p.fdtable.remove(fd)) {
        return Err.BADF;
    }
    return 0;
}

ssize sys_lseek(Proc* p, int fd, ssize off, int whence) {
    VFile* file;
    if (!p.fdtable.get(fd, file))
        return Err.BADF;
    if (!file.lseek)
        return Err.PERM;
    return file.lseek(file.dev, p, off, whence);
}

struct Iovec {
    uintptr base;
    usize len;
}

ssize sys_readv(Proc* p, int fd, uintptr iovp, usize iovcnt) {
    iovp = p.addr(iovp);
    if (!p.checkptr(iovp, iovcnt * Iovec.sizeof)) {
        return Err.FAULT;
    }

    Iovec[] iov = (cast(Iovec*) iovp)[0 .. iovcnt];
    ssize total = 0;

    for (int i = 0; i < iov.length; i++) {
        ssize n = sys_read(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}

ssize sys_read(Proc* p, int fd, uintptr buf, usize size) {
    VFile* file;
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
    VFile* file;
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
    if (p.brkp >= cast(uintptr) p.brk.base + BRK_SIZE)
        p.brkp = cast(uintptr) p.brk.base + BRK_SIZE;
    if (p.brkp >= cast(uintptr) p.brk.base + p.brk.len) {
        usize new_len = p.brkp - cast(uintptr) p.brk.base + BRK_EXPAND;
        p.brk.remap(new_len);
    }
    return p.brkp;
}

noreturn sys_exit(Proc* p, int status) {
    if (mainp != p) {
        // Exiting process's children all get reparented to mainp.
        foreach (ref child; p.children) {
            child.parent = mainp;
            ensure(mainp.children.append(child));
        }
        p.children.clear();

        // Alert parent of exiting process.
        if (p.parent && p.parent.state == Proc.State.BLOCKED && p.parent.wq == &waitq) {
            waitq.wake(p.parent);
        }
    }

    // Enter the exit queue.
    p.block(&exitq, Proc.State.EXITED);

    // should not return
    assert(0, "exited");
}

uintptr sys_mmap(Proc* p, uintptr addr, usize length, int prot, int flags, int fd, long offset) {
    if (fd >= 0) {
        return Err.BADF;
    }

    if (length == 0) {
        return Err.INVAL;
    }

    if ((prot & PROT_EXEC) != 0) {
        return Err.PERM;
    }

    enum illegal_mask = ~MAP_ANONYMOUS &
        ~MAP_PRIVATE &
        ~MAP_HUGETLB &
        ~MAP_FIXED &
        ~MAP_DENYWRITE;

    if ((flags & illegal_mask) != 0) {
        return Err.PERM;
    }

    if (addr == 0) {
        if (!p.map_any(length, prot, flags, fd, offset, addr)) {
            return Err.NOMEM;
        }
    } else {
        addr = p.addr(truncpg(addr));

        // TODO: mprotect the brk page
        if (p.inbrk(addr, length)) {
            return addr;
        }

        if (!p.checkmap(addr, length)) {
            return Err.INVAL;
        }

        if (!p.map_fixed(addr, length, prot, flags, fd, offset)) {
            return Err.NOMEM;
        }
    }

    return addr;
}

int sys_munmap(Proc* p, uintptr addr, usize length) {
    addr = p.addr(truncpg(addr));
    if (!p.checkmap(addr, length)) {
        return Err.PERM;
    }
    return p.unmap(addr, length);
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
    return syserr(clock_gettime(clockid, t));
}

int sys_fstatat(Proc* p, int dirfd, uintptr pathname, uintptr statbuf, int flags) {
    pathname = p.addr(pathname);
    statbuf = p.addr(statbuf);
    if (!p.checkptr(statbuf, Stat.sizeof))
        return Err.FAULT;
    Stat* stat = cast(Stat*) statbuf;
    if ((flags & AT_EMPTY_PATH) == 0) {
        if (!p.checkpath(pathname))
            return Err.FAULT;
        if (dirfd != AT_FDCWD)
            return Err.BADF;
        return syserr(fstatat(p.cwd.fd, cast(const(char)*) pathname, stat, flags));
    }
    VFile* file;
    if (!p.fdtable.get(dirfd, file))
        return Err.BADF;
    if (!file.stat)
        return Err.PERM;
    if (file.stat(file.dev, p, stat) < 0)
        return Err.INVAL;
    return 0;
}

int sys_fork(Proc* p) {
    Proc* child = Proc.make_from_parent(p);
    if (!child) {
        return Err.NOMEM;
    }
    child.regs.x0 = 0;
    if (!p.children.append(child)) {
        kfree(child);
        return Err.NOMEM;
    }

    int pid = child.pid;
    runq.push_front(child);
    return pid;
}

int sys_wait4(Proc* p, int pid, uintptr wstatus) {
    if (pid != -1 || wstatus != 0)
        return Err.INVAL;
    if (p.children.length == 0)
        return Err.CHILD;

    while (1) {
        foreach (ref zombie; exitq) {
            if (zombie.parent == p) {
                int zpid = zombie.pid();
                for (usize i = 0; i < p.children.length; i++) {
                    if (p.children[i] == zombie) {
                        p.children.unordered_remove(i);
                        break;
                    }
                }

                exitq.remove(zombie);
                kfree(zombie);
                return zpid;
            }
        }

        p.block(&waitq, Proc.State.BLOCKED);
    }
}

ssize sys_getdents64(Proc* p, int fd, uintptr dirp, usize count) {
    VFile* file;
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

int sys_renameat2(Proc* p, int oldfd, uintptr oldpath, int newfd, uintptr newpath, int flags) {
    if (oldfd != AT_FDCWD || newfd != AT_FDCWD) {
        return Err.BADF;
    }
    oldpath = p.addr(oldpath);
    newpath = p.addr(newpath);
    if (!p.checkpath(oldpath) || !p.checkpath(newpath)) {
        return Err.FAULT;
    }
    return renameat2(p.cwd.fd, cast(const(char)*) oldpath,
                     p.cwd.fd, cast(const(char)*) newpath, flags);
}

int sys_unlinkat(Proc* p, int dirfd, uintptr path, int flags) {
    if (dirfd != AT_FDCWD) {
        return Err.BADF;
    }
    path = p.addr(path);
    if (!p.checkpath(path)) {
        return Err.FAULT;
    }
    return syserr(unlinkat(p.cwd.fd, cast(const(char)*) path, flags));
}

int sys_readlinkat(Proc* p, int dirfd, uintptr path, uintptr buf, usize size) {
    if (dirfd != AT_FDCWD) {
        return Err.BADF;
    }
    path = p.addr(path);
    buf = p.addr(buf);
    if (!p.checkpath(path) || !p.checkptr(buf, size)) {
        return Err.FAULT;
    }
    return syserr(readlinkat(p.cwd.fd, cast(const(char)*) path, cast(char*) buf, size));
}

int sys_faccessat(Proc* p, int dirfd, uintptr path, int mode, int flags) {
    if (dirfd != AT_FDCWD) {
        return Err.BADF;
    }
    path = p.addr(path);
    if (!p.checkpath(path)) {
        return Err.FAULT;
    }
    return syserr(faccessat(p.cwd.fd, cast(const(char)*) path, mode, flags));
}

ssize sys_getcwd(Proc* p, uintptr buf, usize size) {
    buf = p.addr(buf);
    if (!p.checkptr(buf, size)) {
        return Err.FAULT;
    }
    ubyte[] pathbuf = (cast(ubyte*) buf)[0 .. min(size, p.cwd.name.length + 1)];
    memcpy(pathbuf.ptr, p.cwd.name.ptr, pathbuf.length - 1);
    pathbuf[$ - 1] = 0;
    return pathbuf.length - 1;
}

int sys_sysinfo(Proc* p, uintptr info) {
    info = p.addr(info);
    if (!p.checkptr(info, SysInfo.sizeof)) {
        return Err.FAULT;
    }
    return syserr(sysinfo(cast(SysInfo*) info));
}

int sys_chdir(Proc* p, uintptr path) {
    path = p.addr(path);
    if (!p.checkpath(path)) {
        return Err.FAULT;
    }
    return p.chdir(cast(const(char)*) path);
}

int sys_pipe2(Proc* p, uintptr pipefd, int flags) {
    pipefd = p.addr(pipefd);
    if (!p.checkptr(pipefd, int[2].sizeof)) {
        return Err.FAULT;
    }
    int[] pipes = (cast(int*) pipefd)[0 .. 2];
    int fd0, fd1;
    VFile* f0, f1;

    if (!pipe_new(f0, f1)) {
        goto err1;
    }

    fd0 = p.fdtable.alloc(f0);
    if (!f0)
        goto err2;
    fd1 = p.fdtable.alloc(f1);
    if (!f1)
        goto err3;

    pipes[0] = fd0;
    pipes[1] = fd1;

    return 0;

err3:
    p.fdtable.remove(fd0);
err2:
    kfree(f0);
    kfree(f1);
err1:
    return -1;
}

const(char)*[] copy_args(Proc* p, const(char)** args) {
    int n;
    for (n = 0; args[n] != null; n++) {
        args[n] = cast(const(char)*) p.addr(cast(uintptr) args[n]);
    }

    auto new_args = kallocarray!(const(char)*)(n);
    if (!new_args)
        return null;
    for (int i = 0; i < n; i++) {
        usize len = strnlen(args[i], ARGV_MAX);
        char[] new_arg = kallocarray!(char)(len + 1);
        if (!new_arg)
            goto err;
        memcpy(new_arg.ptr, args[i], len);
        new_arg[len] = 0;
        new_args[i] = new_arg.ptr;
    }
    return new_args;

err:
    kfree_all(new_args);
    return null;
}

const(char)* copy_path(const(char)* path) {
    usize len = strnlen(path, PATH_MAX);
    char[] new_path = kallocarray!(char)(len + 1);
    if (!new_path)
        return null;
    memcpy(new_path.ptr, path, len);
    new_path[len] = 0;
    return new_path.ptr;
}

int sys_execve(Proc* p, uintptr path, uintptr argv, uintptr envp) {
    path = p.addr(path);
    argv = p.addr(argv);
    envp = p.addr(envp);

    if (!p.checkpath(path))
        return Err.FAULT;

    int fd = openat(p.cwd.fd, cast(const(char)*) path, O_RDONLY, 0);
    if (fd < 0)
        return Err.NOENT;
    close(fd);

    const(char)* newpath = copy_path(cast(const(char)*) path);
    if (!newpath)
        return Err.NOMEM;

    // TODO: check argv and envp
    const(char)*[] k_argv = copy_args(p, cast(const(char)**) argv);
    if (!k_argv) {
        kfree(newpath);
        return Err.NOMEM;
    }
    const(char)*[] k_envp = copy_args(p, cast(const(char)**) envp);
    if (!k_envp) {
        kfree(newpath);
        kfree_all(k_argv);
        return Err.NOMEM;
    }

    // Free old segments.
    p.free_regions();

    if (!p.init_from_file(newpath, cast(int) k_argv.length, k_argv.ptr, k_envp.ptr)) {
        printf("failed\n");
        return -1;
    }

    p.exec();
    // should not return
    assert(0, "execve");
}
