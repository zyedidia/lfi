module sys;

import core.lib;
import core.math;
import core.alloc;

import proc;
import lfi;
import file;
import fd;
import pipe;
import sched;
import queue;

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
}

enum Err {
    PERM  = -1,
    NOENT = -2,
    BADF  = -9,
    CHILD = -10,
    NOMEM = -12,
    FAULT = -14,
    INVAL = -22,
    MFILE = -24,
    NPIPE = -25,
    NOSYS = -38,
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
];

uintptr syscall(void* p, ulong num,
        ulong a0, ulong a1, ulong a2, ulong a3, ulong a4, ulong a5) {
    if (num >= systbl.length) {
        fprintf(stderr, "unknown system call: %ld\n", num);
        assert(0, "NOSYS");
        return Err.NOSYS;
    }
    SyscallFn fn = systbl[num];
    if (fn == null) {
        fprintf(stderr, "unknown system call: %ld\n", num);
        assert(0, "NOSYS");
        return Err.NOSYS;
    }
    uintptr ret = fn(cast(Proc*) p, [a0, a1, a2, a3, a4, a5]);
    // fprintf(stderr, "syscall %ld = %lx\n", num, ret);
    return ret;
}

uintptr ignore(Proc* p, ulong[6] args) {
    return 0;
}

uintptr sysexit_(Proc* p, ulong[6] args) {
    return sysexit(p, cast(int) args[0]);
}
uintptr sysexit(Proc* p, int status) {
    if (initp != p) {
        // Exiting process's children all get reparented to initp.
        foreach (ref child; p.children) {
            child.parent = initp;
            ensure(initp.children.append(child));
        }
        p.children.clear();

        // Alert parent of exiting process.
        if (p.parent && p.parent.state == PState.BLOCKED && p.parent.wq == &waitq)
            qwake(&waitq, p.parent);
    }
    procblock(p, &exitq, PState.EXITED);

    // should not return
    assert(0, "exited");
}

uintptr sysopenat_(Proc* p, ulong[6] args) {
    return sysopenat(p, cast(int) args[0], args[1], cast(int) args[2], cast(int) args[3]);
}
uintptr sysopenat(Proc* p, int dirfd, uintptr pathp, int flags, int mode) {
    if (dirfd != AT_FDCWD)
        return Err.BADF;
    const(char)* path = procpath(p, pathp);
    if (!path)
        return Err.FAULT;
    FDFile* f = filenew(p.cwd.fd, path, flags, mode);
    if (!f)
        return Err.INVAL;
    int fd = fdalloc(&p.fdtable);
    if (fd < 0) {
        fdrelease(f);
        return Err.MFILE;
    }
    fdassign(&p.fdtable, fd, f);
    return fd;
}

uintptr sysclose_(Proc* p, ulong[6] args) {
    return sysclose(p, cast(int) args[0]);
}
uintptr sysclose(Proc* p, int fd) {
    bool ok = fdremove(&p.fdtable, fd);
    if (!ok)
        return Err.BADF;
    return 0;
}

uintptr sysread_(Proc* p, ulong[6] args) {
    return sysread(p, cast(int) args[0], args[1], args[2]);
}
uintptr sysread(Proc* p, int fd, uintptr bufp, usize size) {
    FDFile* f = fdget(&p.fdtable, fd);
    if (!f)
        return Err.BADF;
    if (f.read == null)
        return Err.PERM;
    ubyte[] buf = procbuf(p, bufp, size);
    if (!buf)
        return Err.FAULT;
    return f.read(f.dev, p, buf);
}

uintptr syswrite_(Proc* p, ulong[6] args) {
    return syswrite(p, cast(int) args[0], args[1], args[2]);
}
uintptr syswrite(Proc* p, int fd, uintptr bufp, usize size) {
    FDFile* f = fdget(&p.fdtable, fd);
    if (!f)
        return Err.BADF;
    if (f.write == null)
        return Err.PERM;
    ubyte[] buf = procbuf(p, bufp, size);
    if (!buf)
        return Err.FAULT;
    return f.write(f.dev, p, buf);
}

struct Iovec {
    uintptr base;
    usize len;
}

uintptr sysreadv_(Proc* p, ulong[6] args) {
    return sysreadv(p, cast(int) args[0], args[1], args[2]);
}
uintptr sysreadv(Proc* p, int fd, uintptr iovp, usize iovcnt) {
    Iovec[] iov = procarr!(Iovec)(p, iovp, iovcnt);
    if (!iov)
        return Err.FAULT;
    ssize total = 0;

    for (int i = 0; i < iov.length; i++) {
        ssize n = sysread(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}

uintptr syswritev_(Proc* p, ulong[6] args) {
    return syswritev(p, cast(int) args[0], args[1], args[2]);
}
uintptr syswritev(Proc* p, int fd, uintptr iovp, usize iovcnt) {
    Iovec[] iov = procarr!(Iovec)(p, iovp, iovcnt);
    if (!iov)
        return Err.FAULT;
    ssize total = 0;

    for (int i = 0; i < iov.length; i++) {
        ssize n = syswrite(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}

uintptr sysrenameat_(Proc* p, ulong[6] args) {
    return sysrenameat(p, cast(int) args[0], args[1], cast(int) args[2], args[3], cast(int) args[4]);
}
uintptr sysrenameat(Proc* p, int oldfd, uintptr oldpathp, int newfd, uintptr newpathp, int flags) {
    if (oldfd != AT_FDCWD || newfd != AT_FDCWD)
        return Err.BADF;
    const(char)* oldpath = procpath(p, oldpathp);
    const(char)* newpath = procpath(p, newpathp);
    if (!oldpath || !newpath)
        return Err.FAULT;
    return syserr(renameat2(p.cwd.fd, oldpath, p.cwd.fd, newpath, flags));
}

uintptr sysfaccessat_(Proc* p, ulong[6] args) {
    return sysfaccessat(p, cast(int) args[0], args[1], cast(int) args[2], cast(int) args[3]);
}
uintptr sysfaccessat(Proc* p, int dirfd, uintptr pathp, int mode, int flags) {
    if (dirfd != AT_FDCWD)
        return Err.BADF;
    const(char)* path = procpath(p, pathp);
    if (!path)
        return Err.FAULT;
    return syserr(faccessat(p.cwd.fd, path, mode, flags));
}

uintptr sysreadlinkat_(Proc* p, ulong[6] args) {
    return sysreadlinkat(p, cast(int) args[0], args[1], args[2], args[3]);
}
uintptr sysreadlinkat(Proc* p, int dirfd, uintptr pathp, uintptr bufp, usize size) {
    if (dirfd != AT_FDCWD)
        return Err.BADF;
    const(char)* path = procpath(p, pathp);
    ubyte[] buf = procbuf(p, bufp, size);
    if (!path || !buf)
        return Err.FAULT;
    return syserr(readlinkat(p.cwd.fd, path, cast(char*) buf.ptr, buf.length));
}

uintptr sysgetdents_(Proc* p, ulong[6] args) {
    return sysgetdents(p, cast(int) args[0], args[1], args[2]);
}
uintptr sysgetdents(Proc* p, int fd, uintptr dirp, usize count) {
    FDFile* f = fdget(&p.fdtable, fd);
    if (!f)
        return Err.BADF;
    if (f.getdents == null)
        return Err.PERM;
    ubyte[] buf = procbuf(p, dirp, count);
    if (!buf)
        return Err.FAULT;
    return f.getdents(f.dev, p, buf.ptr, buf.length);
}

uintptr sysnewfstatat_(Proc* p, ulong[6] args) {
    return sysfstatat(p, cast(int) args[0], args[1], args[2], cast(int) args[3]);
}
uintptr sysfstatat_(Proc* p, ulong[6] args) {
    return sysfstatat(p, cast(int) args[0], 0, args[1], AT_EMPTY_PATH);
}
uintptr sysfstatat(Proc* p, int dirfd, uintptr pathp, uintptr statbuf, int flags) {
    Stat* stat = procobj!(Stat)(p, statbuf);
    if (!stat)
        return Err.FAULT;
    if ((flags & AT_EMPTY_PATH) == 0) {
        const(char)* path = procpath(p, pathp);
        if (!path)
            return Err.FAULT;
        if (dirfd != AT_FDCWD)
            return Err.BADF;
        return syserr(fstatat(p.cwd.fd, path, stat, flags));
    }
    FDFile* f = fdget(&p.fdtable, dirfd);
    if (!f)
        return Err.BADF;
    if (f.stat == null)
        return Err.PERM;
    if (f.stat(f.dev, p, stat) < 0)
        return Err.INVAL;
    return 0;
}

uintptr syschdir_(Proc* p, ulong[6] args) {
    return syschdir(p, args[0]);
}
uintptr syschdir(Proc* p, uintptr pathp) {
    const(char)* path = procpath(p, pathp);
    if (!path)
        return Err.FAULT;
    return procchdir(p, path);
}

uintptr sysdup_(Proc* p, ulong[6] args) {
    return sysdup(p, cast(int) args[0]);
}
uintptr sysdup(Proc* p, int oldfd) {
    FDFile* f = fdget(&p.fdtable, oldfd);
    if (!f)
        return Err.BADF;
    int newfd = fdalloc(&p.fdtable);
    if (newfd < 0)
        return Err.MFILE;
    return newfd;
}

uintptr sysgetpid_(Proc* p, ulong[6] args) {
    return procpid(p);
}

uintptr sysunlinkat_(Proc* p, ulong[6] args) {
    return sysunlinkat(p, cast(int) args[0], args[1], cast(int) args[2]);
}
uintptr sysunlinkat(Proc* p, int dirfd, uintptr pathp, int flags) {
    if (dirfd != AT_FDCWD)
        return Err.BADF;
    const(char)* path = procpath(p, pathp);
    if (!path)
        return Err.FAULT;
    return syserr(unlinkat(p.cwd.fd, path, 0));
}

uintptr sysmkdir_(Proc* p, ulong[6] args) {
    return sysmkdir(p, args[0], cast(int) args[1]);
}
uintptr sysmkdir(Proc* p, uintptr pathp, int mode) {
    const(char)* path = procpath(p, pathp);
    if (!path)
        return Err.FAULT;
    return syserr(mkdirat(p.cwd.fd, path, mode));
}

uintptr sysfork_(Proc* p, ulong[6] args) {
    return sysfork(p);
}
uintptr sysfork(Proc* p) {
    Proc* child = procnewchild(p);
    if (!child)
        return Err.NOMEM;
    lfi_proc_get_regs(child.lp).x0 = 0;
    if (!p.children.append(child)) {
        procfree(child);
        return Err.NOMEM;
    }

    int pid = procpid(child);
    qpushf(&runq, child);
    return pid;
}

uintptr syswait_(Proc* p, ulong[6] args) {
    return syswait(p, cast(int) args[0], args[1]);
}
uintptr syswait(Proc* p, int pid, uintptr wstatus) {
    if (pid != -1 || wstatus != 0)
        return Err.INVAL;
    if (p.children.length == 0)
        return Err.CHILD;

    while (1) {
        foreach (ref zombie; exitq) {
            if (zombie.parent == p) {
                int zpid = procpid(zombie);
                for (usize i = 0; i < p.children.length; i++) {
                    if (p.children[i] == zombie) {
                        p.children.unordered_remove(i);
                        break;
                    }
                }

                qremove(&exitq, zombie);
                procfree(zombie);
                return zpid;
            }
        }
        procblock(p, &waitq, PState.BLOCKED);
    }
}

uintptr syspipe_(Proc* p, ulong[6] args) {
    return syspipe(p, args[0], cast(int) args[1]);
}
uintptr syspipe(Proc* p, uintptr pipefdp, int flags) {
    struct Pipefd {
        int[2] fd;
    }

    bool success;
    Pipefd* pipefd = procobj!(Pipefd)(p, pipefdp);
    if (pipefd == null)
        return Err.FAULT;

    int fd0, fd1;
    FDFile* f0, f1;
    if (!pipenew(f0, f1))
        return Err.NPIPE;
    scope(exit) if (!success) {
        fdrelease(f0);
        fdrelease(f1);
    }

    fd0 = fdalloc(&p.fdtable);
    if (fd0 < 0)
        return Err.MFILE;
    scope(exit) if (!success) fdremove(&p.fdtable, fd0);

    fd1 = fdalloc(&p.fdtable);
    if (fd1 < 0)
        return Err.MFILE;
    pipefd.fd[0] = fd0;
    pipefd.fd[1] = fd1;
    success = true;
    return 0;
}

const(char)* copypath(const(char)* path) {
    usize len = strnlen(path, PATH_MAX);
    char[] newpath = kallocarray!(char)(len + 1);
    if (!newpath)
        return null;
    memcpy(newpath.ptr, path, len);
    newpath[len] = 0;
    return newpath.ptr;
}

const(char)*[] copyargs(Proc* p, const(char)** args) {
    int n;
    for (n = 0; args[n] != null && n < ARGC_MAX; n++) {
        const(char)* arg = procarg(p, cast(uintptr) args[n]);
        if (!arg)
            return null;
        args[n] = arg;
    }

    bool success;

    const(char)*[] newargs = kallocarray!(const(char)*)(n);
    if (!newargs)
        return null;
    scope(exit) if (!success) kfreearray(newargs);

    for (int i = 0; i < n; i++) {
        usize len = strnlen(args[i], ARGV_MAX);
        char[] newarg = kallocarray!(char)(len + 1);
        if (!newarg)
            return null;
        memcpy(newarg.ptr, args[i], len);
        newarg[len] = 0;
        newargs[i] = newarg.ptr;
    }
    success = true;
    return newargs;
}

uintptr sysexecv_(Proc* p, ulong[6] args) {
    return sysexecv(p, args[0], args[1], args[2]);
}
uintptr sysexecv(Proc* p, uintptr pathp, uintptr argvp, uintptr envp) {
    const(char)* path = procpath(p, pathp);
    if (!path)
        return Err.FAULT;
    uintptr argv = procaddr(p, argvp);

    // Make sure file exists.
    int fd = openat(p.cwd.fd, path, O_RDONLY, 0);
    if (fd < 0)
        return Err.NOENT;
    close(fd);

    const(char)* newpath = copypath(path);
    if (!newpath)
        return Err.NOMEM;
    scope(exit) kfree(newpath);

    const(char)*[] kargv = copyargs(p, cast(const(char)**) argv);
    if (!kargv)
        return Err.NOMEM;
    scope(exit) kfreearray(kargv);

    // Free old segments.
    procfreemaps(p);

    if (!procfile(p, newpath, cast(int) kargv.length, kargv.ptr))
        return -1;

    procexec(p);
    // should not return
    assert(0, "execv");
}

uintptr syslseek_(Proc* p, ulong[6] args) {
    return syslseek(p, cast(int) args[0], args[1], cast(int) args[2]);
}
uintptr syslseek(Proc* p, int fd, ssize off, int whence) {
    FDFile* f = fdget(&p.fdtable, fd);
    if (!f)
        return Err.BADF;
    if (f.lseek == null)
        return Err.PERM;
    return f.lseek(f.dev, p, off, whence);
}

uintptr sysgetcwd_(Proc* p, ulong[6] args) {
    return sysgetcwd(p, args[0], args[1]);
}
uintptr sysgetcwd(Proc* p, uintptr bufp, usize size) {
    if (size == 0)
        return 0;
    ubyte[] buf = procbuf(p, bufp, size);
    if (!buf)
        return Err.FAULT;
    memcpy(buf.ptr, p.cwd.name.ptr, min(buf.length, p.cwd.name.length));
    buf[$-1] = 0;
    return buf.length - 1;
}

uintptr syssysinfo_(Proc* p, ulong[6] args) {
    return syssysinfo(p, args[0]);
}
uintptr syssysinfo(Proc* p, uintptr infop) {
    SysInfo* info = procobj!(SysInfo)(p, infop);
    if (!info)
        return Err.FAULT;
    return syserr(sysinfo(info));
}

enum {
    CLOCK_REALTIME  = 0,
    CLOCK_MONOTONIC = 1,
}

uintptr systime_(Proc* p, ulong[6] args) {
    return systime(p, cast(uint) args[0], args[1]);
}
uintptr systime(Proc* p, uint clockid, uintptr tp) {
    if (clockid != CLOCK_REALTIME && clockid != CLOCK_MONOTONIC)
        return Err.INVAL;
    TimeSpec* t = procobj!(TimeSpec)(p, tp);
    if (!t)
        return Err.FAULT;
    return syserr(clock_gettime(clockid, t));
}

uintptr sysbrk_(Proc* p, ulong[6] args) {
    return sysbrk(p, args[0]);
}
uintptr sysbrk(Proc* p, uintptr addr) {
    uintptr brkp = p.brkbase + p.brksize;
    if (addr != 0)
        brkp = procaddr(p, addr);
    if (brkp < p.brkbase)
        brkp = p.brkbase;
    if (brkp >= p.brkbase + BRKMAXSIZE)
        brkp = p.brkbase + BRKMAXSIZE;

    usize newsize = brkp - p.brkbase;
    assert(newsize <= BRKMAXSIZE);

    if (newsize == p.brksize)
        return procuseraddr(p, brkp);

    enum {
        mapflags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
        mapprot  = PROT_READ | PROT_WRITE,
    }
    if (brkp >= p.brkbase + p.brksize) {
        void* map;
        if (p.brksize == 0) {
            map = mmap(cast(void*) p.brkbase, newsize, mapprot, mapflags, -1, 0);
        } else {
            // Since liblfi reserves all sandboxes in one big mmap region, we
            // first need to unmap the piece that we want to expand into,
            // otherwise Linux will decide there is no space for mremap.
            ensure(munmap(cast(void*) p.brkbase + p.brksize, newsize - p.brksize) == 0);
            ensure(mremap(cast(void*) p.brkbase, p.brksize, newsize, 0) == cast(void*) p.brkbase);
        }
        if (map == cast(void*) -1)
            return -1;
    }

    p.brksize = newsize;
    return procuseraddr(p, p.brkbase + p.brksize);
}

uintptr sysmremap_(Proc* p, ulong[6] args) {
    return -1;
}

uintptr sysmmap_(Proc* p, ulong[6] args) {
    return sysmmap(p, args[0], args[1], cast(int) args[2], cast(int) args[3], cast(int) args[4], cast(long) args[5]);
}
uintptr sysmmap(Proc* p, uintptr addrp, usize length, int prot, int flags, int fd, long offset) {
    if (length == 0)
        return Err.INVAL;
    if ((prot & PROT_EXEC) != 0)
        return Err.PERM;
    length = ceilpg(length);

    // The flags listed are the only allowed flags.
    enum illegal_mask = ~MAP_ANONYMOUS &
        ~MAP_PRIVATE &
        ~MAP_HUGETLB &
        ~MAP_FIXED &
        ~MAP_DENYWRITE;
    if ((flags & illegal_mask) != 0)
        return Err.PERM;

    if (addrp == 0) {
        if (!procmapany(p, length, prot, flags, fd, offset, addrp)) {
            return Err.NOMEM;
        }
    } else {
        addrp = procaddr(p, truncpg(addrp));

        // TODO: if it's in the brk region, there is already a mapping, so just mprotect the requested range
        if (procinbrk(p, addrp, length)) {
            return procuseraddr(p, addrp);
        }

        if (!procinmap(p, addrp, length)) {
            return Err.INVAL;
        }

        if (!procmapfixed(p, addrp, length, prot, flags, fd, offset)) {
            return Err.NOMEM;
        }
    }
    return procuseraddr(p, addrp);
}

uintptr sysmunmap_(Proc* p, ulong[6] args) {
    return sysmunmap(p, args[0], args[1]);
}
uintptr sysmunmap(Proc* p, uintptr addrp, usize length) {
    return procunmap(p, procaddr(p, truncpg(addrp)), ceilpg(length));
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
