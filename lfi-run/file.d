module file;

import core.lib;
import core.alloc;

import fd;
import proc;
import sys;

FDFile* filenew(int dirfd, const(char)* name, int flags, int mode) {
    int kfd = syserr(openat(dirfd, name, flags, mode));
    if (kfd < 0)
        return null;
    return filefdnew(kfd);
}

FDFile* filefdnew(int kfd) {
    FDFile* ff = knew!(FDFile)();
    if (!ff)
        return null;
    ff.dev = cast(void*) kfd;
    ff.read = &fileread;
    ff.write = &filewrite;
    ff.lseek = &filelseek;
    ff.stat = &filestat;
    ff.close = &fileclose;
    ff.getdents = &filegetdents;
    ff.mapfd = &filemapfd;
    return ff;
}

private int filefd(void* dev) {
    return cast(int) dev;
}

ssize fileread(void* dev, Proc* p, ubyte[] buf) {
    return syserr(read(filefd(dev), buf.ptr, buf.length));
}

ssize filewrite(void* dev, Proc* p, ubyte[] buf) {
    return syserr(write(filefd(dev), buf.ptr, buf.length));
}

ssize filelseek(void* dev, Proc* p, ssize off, uint whence) {
    return syserr(lseek(filefd(dev), off, whence));
}

int filestat(void* dev, Proc* p, Stat* st) {
    return syserr(fstatat(filefd(dev), "".ptr, st, AT_EMPTY_PATH));
}

int fileclose(void* dev, Proc* p) {
    return syserr(close(filefd(dev)));
}

ssize filegetdents(void* dev, Proc* p, void* dirp, usize count) {
    return syserr(getdents64(filefd(dev), dirp, count));
}

int filemapfd(void* dev) {
    return filefd(dev);
}
