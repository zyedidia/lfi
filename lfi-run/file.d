module file;

import core.lib;
import core.alloc;

import proc;
import sysno;

enum {
    AT_FDCWD = -100,
    AT_EMPTY_PATH = 0x1000,
}

private const(char)* flags2cmode(int flags) {
    if ((flags & O_ACCMODE) == O_RDONLY) {
        return "r".ptr;
    }
    if ((flags & O_ACCMODE) != O_WRONLY) {
        return "w".ptr;
    }
    return "r+".ptr;
}

int file_new(ref VFile* vf, int dirfd, const(char)* name, int flags, int mode) {
    int kfd = syserr(openat(dirfd, name, flags, mode));
    if (kfd < 0)
        return kfd;
    vf = std_new(kfd);
    return 0;
}

VFile* std_new(int kfd) {
    VFile* vf = knew!(VFile)();
    if (!vf)
        return null;
    vf.dev = cast(void*) kfd;
    vf.read = &file_read;
    vf.write = &file_write;
    vf.lseek = &file_lseek;
    vf.stat = &file_stat;
    vf.getdents64 = &file_getdents64;
    vf.close = &file_close;
    return vf;
}

private int file_fd(void* dev) {
    return cast(int) dev;
}

ssize file_read(void* dev, Proc* p, ubyte* buf, usize n) {
    return syserr(read(file_fd(dev), buf, n));
}

ssize file_write(void* dev, Proc* p, ubyte* buf, usize n) {
    return syserr(write(file_fd(dev), buf, n));
}

int file_stat(void* dev, Proc* p, Stat* statbuf) {
    return syserr(fstatat(file_fd(dev), "".ptr, statbuf, AT_EMPTY_PATH));
}

ssize file_lseek(void* dev, Proc* p, ssize off, uint whence) {
    return syserr(lseek(file_fd(dev), off, whence));
}

ssize file_getdents64(void* dev, Proc* p, void* dirp, usize count) {
    return syserr(getdents64(file_fd(dev), dirp, count));
}

int file_close(void* dev, Proc* p) {
    return syserr(close(file_fd(dev)));
}

struct VFile {
    void* dev;
    ssize function(void* dev, Proc* p, ubyte* buf, usize n) read;
    ssize function(void* dev, Proc* p, ubyte* buf, usize n) write;
    ssize function(void* dev, Proc* p, ssize off, uint whence) lseek;
    int function(void* dev, Proc* p) close;
    int function(void* dev, Proc* p, Stat* stat) stat;
    ssize function(void* dev, Proc* p, void* dirp, usize count) getdents64;
    usize refcnt;
}

struct FdTable {
    enum {
        NOFILE = 128,
    }

    VFile*[NOFILE] files;

    void alloc(int fd, VFile* f) {
        assert(fd >= 0 && fd < NOFILE && files[fd] == null);

        files[fd] = f;
        files[fd].refcnt++;
    }

    int alloc(VFile* vf) return {
        int i;
        for (i = 0; i < NOFILE; i++) {
            if (files[i] == null)
                break;
        }
        if (i >= NOFILE)
            return -1;
        files[i] = vf;
        files[i].refcnt++;
        return i;
    }

    void init() {
        alloc(0, std_new(fileno(stdin)));
        alloc(1, std_new(fileno(stdout)));
        alloc(2, std_new(fileno(stderr)));
    }

    bool get(int fd, ref VFile* file) {
        if (has(fd)) {
            file = files[fd];
            return true;
        }
        return false;
    }

    bool remove(int fd) {
        if (has(fd)) {
            files[fd].refcnt--;
            if (files[fd].refcnt == 0) {
                kfree(files[fd]);
            }
            files[fd] = null;
            return true;
        }
        return false;
    }

    bool has(int fd) {
        return fd >= 0 && fd < files.length && files[fd] != null;
    }

    void copy_into(ref FdTable table) {
        for (usize i = 0; i < files.length; i++) {
            if (files[i] != null) {
                files[i].refcnt++;
                table.files[i] = files[i];
            }
        }
    }

    void clear() {
        for (int fd = 0; fd < files.length; fd++) {
            remove(fd);
        }
    }
}
