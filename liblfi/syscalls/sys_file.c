#include <stdalign.h>
#include <errno.h>

#include "cwalk.h"

#include "syscalls/syscalls.h"

#include "file.h"
#include "fd.h"
#include "host.h"

static struct HostFile*
getfdir(struct TuxProc* p, int dirfd)
{
    if (dirfd == TUX_AT_FDCWD)
        return p->cwd.file;
    struct FDFile* f = fdget(&p->fdtable, dirfd);
    if (!f || !f->file)
        return NULL;
    struct HostFile* dir = f->file(f->dev);
    if (!host_isdir(dir))
        return NULL;
    return dir;
}

ssize_t
sys_write(struct TuxProc* p, int fd, lfiptr_t bufp, size_t size)
{
    if (size == 0)
        return 0;
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->write)
        return -TUX_EPERM;
    uint8_t* buf = procbuf(p, bufp, size);
    if (!buf)
        return -TUX_EFAULT;
    return f->write(f->dev, buf, size);
}

ssize_t
sys_read(struct TuxProc* p, int fd, lfiptr_t bufp, size_t size)
{
    if (size == 0)
        return 0;
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->read)
        return -TUX_EPERM;
    uint8_t* buf = procbuf(p, bufp, size);
    if (!buf)
        return -TUX_EFAULT;
    return f->read(f->dev, buf, size);
}

struct IOVec {
    uintptr_t base;
    size_t len;
};

ssize_t
sys_writev(struct TuxProc* p, int fd, lfiptr_t iovp, size_t iovcnt)
{
    uint8_t* iovb = procbufalign(p, iovp, iovcnt * sizeof(struct IOVec), alignof(struct IOVec));
    if (!iovb)
        return -TUX_EFAULT;
    struct IOVec* iov = (struct IOVec*) iovb;
    ssize_t total = 0;

    for (size_t i = 0; i < iovcnt; i++) {
        ssize_t n = sys_write(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}

ssize_t
sys_readv(struct TuxProc* p, int fd, lfiptr_t iovp, size_t iovcnt)
{
    uint8_t* iovb = procbufalign(p, iovp, iovcnt * sizeof(struct IOVec), alignof(struct IOVec));
    if (!iovb)
        return -TUX_EFAULT;
    struct IOVec* iov = (struct IOVec*) iovb;
    ssize_t total = 0;

    for (size_t i = 0; i < iovcnt; i++) {
        ssize_t n = sys_read(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}

int
sys_openat(struct TuxProc* p, int dirfd, lfiptr_t pathp, int flags, int mode)
{
    struct HostFile* dir = getfdir(p, dirfd);
    if (dirfd != TUX_AT_FDCWD && !dir)
        return -TUX_EBADF;
    // TODO: copy from user to avoid TOCTOU
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    struct FDFile* f = filenew(p->tux, dir, path, flags, mode);
    if (!f) {
        VERBOSE(p->tux, "sys_open(\"%s\") = %d", path, -TUX_ENOENT);
        return -TUX_ENOENT;
    }
    int fd = fdalloc(&p->fdtable);
    if (fd < 0) {
        fdrelease(f, p);
        VERBOSE(p->tux, "sys_open(\"%s\") = %d", path, -TUX_EMFILE);
        return -TUX_EMFILE;
    }
    VERBOSE(p->tux, "sys_open(\"%s\") = %d", path, fd);
    fdassign(&p->fdtable, fd, f);
    return fd;
}

int
sys_open(struct TuxProc* p, lfiptr_t pathp, int flags, int mode)
{
    return sys_openat(p, TUX_AT_FDCWD, pathp, flags, mode);
}

int
sys_close(struct TuxProc* p, int fd)
{
    bool ok = fdremove(&p->fdtable, fd, p);
    if (!ok)
        return -TUX_EBADF;
    return 0;
}

ssize_t
sys_readlinkat(struct TuxProc* p, int dirfd, lfiptr_t pathp, lfiptr_t bufp, size_t size)
{
    struct HostFile* dir = getfdir(p, dirfd);
    if (dirfd != TUX_AT_FDCWD && !dir)
        return -TUX_EBADF;
    const char* path = procpath(p, pathp);
    uint8_t* buf = procbuf(p, bufp, size);
    if (!path || !buf)
        return -TUX_EFAULT;
    int r = host_readlinkat(dir, path, (char*) buf, size);
    if (r < 0)
        return -errno;
    return r;
}

ssize_t
sys_readlink(struct TuxProc* p, lfiptr_t pathp, lfiptr_t bufp, size_t size)
{
    return sys_readlinkat(p, TUX_AT_FDCWD, pathp, bufp, size);
}

ssize_t
sys_pread64(struct TuxProc* p, int fd, lfiptr_t bufp, size_t size, ssize_t offset)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->read || !f->lseek)
        return -TUX_EPERM;
    uint8_t* buf = procbuf(p, bufp, size);
    if (!buf)
        return -TUX_EFAULT;
    ssize_t orig = f->lseek(f->dev, 0, TUX_SEEK_CUR);
    f->lseek(f->dev, offset, TUX_SEEK_SET);
    ssize_t n = f->read(f->dev, buf, size);
    f->lseek(f->dev, orig, TUX_SEEK_SET);
    return n;
}

int
sys_newfstatat(struct TuxProc* p, int dirfd, lfiptr_t pathp, lfiptr_t statbufp, int flags)
{
    uint8_t* statb = procbufalign(p, statbufp, sizeof(struct Stat), alignof(struct Stat));
    if (!statb)
        return -TUX_EFAULT;
    struct Stat* stat = (struct Stat*) statb;
    if ((flags & TUX_AT_EMPTY_PATH) == 0) {
        const char* path = procpath(p, pathp);
        if (!path)
            return -TUX_EFAULT;
        struct HostFile* dir = getfdir(p, dirfd);
        if (dirfd != TUX_AT_FDCWD && !dir)
            return -TUX_EBADF;
        return host_fstatat(dir, path, stat, 0);
    }
    struct FDFile* f = fdget(&p->fdtable, dirfd);
    if (!f)
        return -TUX_EBADF;
    if (!f->stat_)
        return -TUX_EACCES;
    return f->stat_(f->dev, stat);
}

int
sys_fstat(struct TuxProc* p, int fd, lfiptr_t statbufp)
{
    return sys_newfstatat(p, fd, 0, statbufp, TUX_AT_EMPTY_PATH);
}


int
sys_stat(struct TuxProc* p, lfiptr_t pathp, lfiptr_t statbufp)
{
    return sys_newfstatat(p, TUX_AT_FDCWD, pathp, statbufp, 0);
}

int
sys_lstat(struct TuxProc* p, lfiptr_t pathp, lfiptr_t statbufp)
{
    // TODO: lstat: handle links properly
    return sys_stat(p, pathp, statbufp);
}

ssize_t
sys_getdents64(struct TuxProc* p, int fd, lfiptr_t dirp, size_t count)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->getdents)
        return -TUX_EPERM;
    uint8_t* buf = procbufalign(p, dirp, count, alignof(struct Dirent));
    if (!buf)
        return -TUX_EFAULT;
    return f->getdents(f->dev, buf, count);
}

off_t
sys_lseek(struct TuxProc* p, int fd, off_t offset, int whence)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->lseek)
        return -TUX_EPERM;
    return f->lseek(f->dev, offset, whence);
}

int
sys_truncate(struct TuxProc* p, uintptr_t pathp, off_t length)
{
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    char buffer[TUX_PATH_MAX];
    if (!cwk_path_is_absolute(path)) {
        char cwd[TUX_PATH_MAX];
        int r;
        if ((r = host_getpath(p->cwd.file, cwd, sizeof(cwd))) < 0)
            return r;
        cwk_path_join(cwd, path, buffer, sizeof(buffer));
        path = buffer;
    }
    return host_truncate(path, length);
}

int
sys_ftruncate(struct TuxProc* p, int fd, off_t length)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->truncate)
        return -TUX_EPERM;
    return f->truncate(f->dev, length);
}

int
sys_chown(struct TuxProc* p, uintptr_t pathp, tux_uid_t owner, tux_gid_t group)
{
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    return host_fchownat(p->cwd.file, path, owner, group, 0);
}

int
sys_fchown(struct TuxProc* p, int fd, tux_uid_t owner, tux_gid_t group)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->chown)
        return -TUX_EPERM;
    return f->chown(f->dev, owner, group);
}

int
sys_chmod(struct TuxProc* p, uintptr_t pathp, tux_mode_t mode)
{
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    return host_fchmodat(p->cwd.file, path, mode, 0);
}

int
sys_fchmod(struct TuxProc* p, int fd, tux_mode_t mode)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->chmod)
        return -TUX_EPERM;
    return f->chmod(f->dev, mode);
}

int
sys_fsync(struct TuxProc* p, int fd)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->sync)
        return -TUX_EPERM;
    return f->sync(f->dev);
}

int
sys_unlinkat(struct TuxProc* p, int dirfd, lfiptr_t pathp, int flags)
{
    struct HostFile* dir = getfdir(p, dirfd);
    if (dirfd != TUX_AT_FDCWD && !dir)
        return -TUX_EBADF;
    if (flags != 0 && flags != TUX_AT_REMOVEDIR)
        return -TUX_EINVAL;
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    int r = host_unlinkat(dir, path, flags);
    if (r < 0)
        return -errno;
    return r;
}

int
sys_unlink(struct TuxProc* p, lfiptr_t pathp)
{
    return sys_unlinkat(p, TUX_AT_FDCWD, pathp, 0);
}

int
sys_renameat(struct TuxProc* p, int olddir, uintptr_t oldpathp, int newdir, uintptr_t newpathp)
{
    struct HostFile* oldf = getfdir(p, olddir);
    struct HostFile* newf = getfdir(p, newdir);
    if ((olddir != TUX_AT_FDCWD && !oldf) || (newdir != TUX_AT_FDCWD && !newf))
        return -TUX_EBADF;
    const char* oldpath = procpath(p, oldpathp);
    const char* newpath = procpath(p, newpathp);
    if (!oldpath || !newpath)
        return -TUX_EFAULT;
    return host_renameat2(oldf, oldpath, newf, newpath, 0);
}

int
sys_rename(struct TuxProc* p, uintptr_t oldpathp, uintptr_t newpathp)
{
    return sys_renameat(p, TUX_AT_FDCWD, oldpathp, TUX_AT_FDCWD, newpathp);
}

int
sys_faccessat2(struct TuxProc* p, int dirfd, uintptr_t pathp, int mode, int flags)
{
    struct HostFile* dir = getfdir(p, dirfd);
    if (dirfd != TUX_AT_FDCWD && !dir)
        return -TUX_EBADF;
    if (flags != 0) {
        WARN("faccessat2 used with non-zero flags");
        return -TUX_EINVAL;
    }
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    return host_faccessat2(dir, path, mode, 0);
}

int
sys_faccessat(struct TuxProc* p, int dirfd, uintptr_t pathp, int mode)
{
    return sys_faccessat2(p, dirfd, pathp, mode, 0);
}

int
sys_access(struct TuxProc* p, uintptr_t pathp, int mode)
{
    return sys_faccessat2(p, TUX_AT_FDCWD, pathp, mode, 0);
}

int
sys_mkdirat(struct TuxProc* p, int dirfd, uintptr_t pathp, tux_mode_t mode)
{
    struct HostFile* dir = getfdir(p, dirfd);
    if (dirfd != TUX_AT_FDCWD && !dir)
        return -TUX_EBADF;
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    return host_mkdirat(dir, path, mode);
}

int
sys_mkdir(struct TuxProc* p, uintptr_t pathp, tux_mode_t mode)
{
    return sys_mkdirat(p, TUX_AT_FDCWD, pathp, mode);
}
