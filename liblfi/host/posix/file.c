#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "host/error.h"
#include "syscalls/syscalls.h"
#include "file.h"

static int
openflags(int flags)
{
    return ((flags & TUX_O_RDONLY) ? O_RDONLY : 0) |
        ((flags & TUX_O_WRONLY) ? O_WRONLY : 0) |
        ((flags & TUX_O_RDWR) ? O_RDWR : 0) |
        ((flags & TUX_O_CREAT) ? O_CREAT : 0) |
        ((flags & TUX_O_APPEND) ? O_APPEND : 0) |
        ((flags & TUX_O_NONBLOCK) ? O_NONBLOCK : 0) |
        ((flags & TUX_O_DIRECTORY) ? O_DIRECTORY : 0);
}

struct HostFile*
host_openat(struct HostFile* dir, const char* path, int flags, int mode)
{
    struct HostFile* hf = malloc(sizeof(struct HostFile));
    if (!hf)
        return NULL;
    int fd = openat(dir ? dir->fd : AT_FDCWD, path, openflags(flags), mode);
    if (fd < 0)
        goto err;
    *hf = (struct HostFile) {
        .fd = fd,
    };
    return hf;
err:
    free(hf);
    return NULL;
}

struct HostFile*
host_fdopen(int fd)
{
    struct HostFile* hf = malloc(sizeof(struct HostFile));
    *hf = (struct HostFile) {
        .fd = fd,
    };
    return hf;
}

ssize_t
host_read(struct HostFile* file, uint8_t* buf, size_t size)
{
    ssize_t r = read(file->fd, buf, size);
    if (r < 0)
        return tuxerr(errno);
    return r;
}

ssize_t
host_write(struct HostFile* file, uint8_t* buf, size_t size)
{
    ssize_t r = write(file->fd, buf, size);
    if (r < 0)
        return tuxerr(errno);
    return r;
}

static int
seekwhence(int whence)
{
    switch (whence) {
    case TUX_SEEK_SET:
        return SEEK_SET;
    case TUX_SEEK_CUR:
        return SEEK_CUR;
    case TUX_SEEK_END:
        return SEEK_END;
    }
    assert(!"unreachable");
}

ssize_t
host_seek(struct HostFile* file, size_t loc, int whence)
{
    ssize_t r = lseek(file->fd, loc, seekwhence(whence));
    if (r < 0)
        return tuxerr(errno);
    return r;
}

int
host_close(struct HostFile* file)
{
    int r = close(file->fd);
    if (r < 0)
        return tuxerr(errno);
    file->fd = -1;
    free(file);
    return r;
}

static void
copystat(struct Stat* stat_, struct stat* kstat)
{
    stat_->st_dev = kstat->st_dev;
    stat_->st_ino = kstat->st_ino;
    stat_->st_nlink = kstat->st_nlink;
    stat_->st_mode = kstat->st_mode;
    stat_->st_uid = kstat->st_uid;
    stat_->st_gid = kstat->st_gid;
    stat_->st_rdev = kstat->st_rdev;
    stat_->st_size = kstat->st_size;
    stat_->st_blksize = kstat->st_blksize;
    stat_->st_blocks = kstat->st_blocks;
#ifdef __APPLE__
    stat_->st_atim.sec  = kstat->st_atimespec.tv_sec;
    stat_->st_atim.nsec = kstat->st_atimespec.tv_nsec;
    stat_->st_mtim.sec  = kstat->st_mtimespec.tv_sec;
    stat_->st_mtim.nsec = kstat->st_mtimespec.tv_nsec;
    stat_->st_ctim.sec  = kstat->st_ctimespec.tv_sec;
    stat_->st_ctim.nsec = kstat->st_ctimespec.tv_nsec;
#else
    stat_->st_atim.sec  = kstat->st_atim.tv_sec;
    stat_->st_atim.nsec = kstat->st_atim.tv_nsec;
    stat_->st_mtim.sec  = kstat->st_mtim.tv_sec;
    stat_->st_mtim.nsec = kstat->st_mtim.tv_nsec;
    stat_->st_ctim.sec  = kstat->st_ctim.tv_sec;
    stat_->st_ctim.nsec = kstat->st_ctim.tv_nsec;
#endif
}

int
host_stat(const char* path, struct Stat* stat_)
{
    struct stat kstat;
    int r = stat(path, &kstat);
    if (r < 0)
        return tuxerr(errno);
    copystat(stat_, &kstat);
    return 0;
}

int
host_fstatat(struct HostFile* file, const char* path, struct Stat* stat_, int flags)
{
    struct stat kstat;
    int r;
    if (flags == TUX_AT_EMPTY_PATH) {
        r = fstat(file->fd, &kstat);
    } else {
        assert(flags == 0);
        r = fstatat(file ? file->fd : AT_FDCWD, path, &kstat, 0);
    }
    if (r < 0)
        return tuxerr(errno);
    copystat(stat_, &kstat);
    return 0;
}

int
host_truncate(const char* path, off_t length)
{
    int r = truncate(path, length);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

int
host_ftruncate(struct HostFile* file, off_t length)
{
    int r = ftruncate(file->fd, length);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

int
host_fchownat(struct HostFile* dir, const char* path, tux_uid_t owner, tux_gid_t group, int flags)
{
    int r;
    if (flags == TUX_AT_EMPTY_PATH) {
        assert(dir);
        r = fchown(dir->fd, owner, group);
    } else {
        r = fchownat(dir ? dir->fd : AT_FDCWD, path, owner, group, 0);
    }
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

int
host_fchmodat(struct HostFile* dir, const char* path, tux_mode_t mode, int flags)
{
    assert(flags == 0);
    int r = fchmodat(dir ? dir->fd : AT_FDCWD, path, mode, 0);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

int
host_fchmod(struct HostFile* file, tux_mode_t mode)
{
    int r = fchmod(file->fd, mode);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

static int
mmapprot(int prot)
{
    return ((prot & LFI_PROT_READ) ? PROT_READ : 0) |
        ((prot & LFI_PROT_WRITE) ? PROT_WRITE : 0) |
        ((prot & LFI_PROT_EXEC) ? PROT_EXEC : 0);
}

static int
mmapflags(int flags)
{
    return ((flags & LFI_MAP_PRIVATE) ? MAP_PRIVATE : 0) |
        ((flags & LFI_MAP_ANONYMOUS) ? MAP_ANONYMOUS : 0) |
        ((flags & LFI_MAP_FIXED) ? MAP_FIXED : 0) |
        ((flags & LFI_MAP_SHARED) ? MAP_SHARED : 0);
}

void*
host_mmap(void* addr, size_t length, int prot, int flags, struct HostFile* file, off_t offset)
{
    int fd = file ? file->fd : -1;
    return mmap(addr, length, mmapprot(prot), mmapflags(flags), fd, offset);
}

int
host_munmap(void* addr, size_t length)
{
    int r = munmap(addr, length);
    if (r < 0)
        return tuxerr(errno);
    return r;
}

int
host_mprotect(void* addr, size_t length, int prot)
{
    int r = mprotect(addr, length, mmapprot(prot));
    if (r < 0)
        return tuxerr(errno);
    return r;
}

int
host_fsync(struct HostFile* file)
{
    int r = fsync(file->fd);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

static int
unlinkflags(int flags)
{
    return ((flags & TUX_AT_REMOVEDIR) ? AT_REMOVEDIR : 0);
}

int
host_unlinkat(struct HostFile* file, const char* path, int flags)
{
    int r = unlinkat(file ? file->fd : AT_FDCWD, path, unlinkflags(flags));
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

ssize_t
host_readlinkat(struct HostFile* file, const char* path, char* buf, size_t size)
{
    ssize_t r = readlinkat(file ? file->fd : AT_FDCWD, path, buf, size);
    if (r < 0)
        return tuxerr(errno);
    return r;
}

int
host_renameat2(struct HostFile* olddir, const char* oldpath,
        struct HostFile* newdir, const char* newpath, int flags)
{
    assert(flags == 0);
    int r = renameat(olddir ? olddir->fd : AT_FDCWD, oldpath, newdir ? newdir->fd : AT_FDCWD, newpath);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

int
host_faccessat2(struct HostFile* dir, const char* path, int mode, int flags)
{
    assert(flags == 0);
    int r = faccessat(dir ? dir->fd : AT_FDCWD, path, mode, 0);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

bool
host_isdir(struct HostFile* file)
{
    struct stat stat;
    if (fstat(file->fd, &stat) == 0) {
        if (S_ISDIR(stat.st_mode)) {
            return true;
        }
    }
    return false;
}

int
host_mkdirat(struct HostFile* dir, const char* path, tux_mode_t mode)
{
    int r = mkdirat(dir ? dir->fd : AT_FDCWD, path, mode);
    if (r < 0)
        return tuxerr(errno);
    return 0;
}

static struct HostFile fstdin  = { .fd = STDIN_FILENO };
static struct HostFile fstdout = { .fd = STDOUT_FILENO };
static struct HostFile fstderr = { .fd = STDERR_FILENO };

struct HostFile*
host_stdin(void)
{
    return &fstdin;
}
struct HostFile*
host_stdout(void)
{
    return &fstdout;
}
struct HostFile*
host_stderr(void)
{
    return &fstderr;
}
