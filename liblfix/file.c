#define _GNU_SOURCE

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

#include "file.h"
#include "sys.h"
#include "io.h"

FDFile*
lfix_filenew(LFIXEngine* lfix, int dirfd, const char* name, int flags, int mode)
{
    Buf file;
    int kfd;
    // TODO: handle dirfd properly for readfile?
    if (lfix->readfile && lfix->readfile(name, &file.data, &file.size)) {
        kfd = memfd_create("", 0);
        if (kfd < 0)
            return NULL;
        ssize_t n = write(kfd, file.data, file.size);
        if (n == -1 || (size_t) n != file.size) {
            close(kfd);
            return NULL;
        }
        lseek(kfd, 0, SEEK_SET);
    } else {
        kfd = openat(dirfd, name, flags, mode);
    }
    if (kfd < 0)
        return NULL;
    return lfix_filefdnew(kfd);
}

static int
filefd(void* dev)
{
    return (int) ((intptr_t) dev);
}

static ssize_t
fileread(void* dev, struct LFIXProc* p, uint8_t* buf, size_t buflen)
{
    (void) p;
    return syserr(read(filefd(dev), buf, buflen));
}

static ssize_t
filewrite(void* dev, struct LFIXProc* p, uint8_t* buf, size_t buflen)
{
    (void) p;
    return syserr(write(filefd(dev), buf, buflen));
}

static ssize_t
filelseek(void* dev, struct LFIXProc* p, off_t off, int whence)
{
    (void) p;
    return syserr(lseek(filefd(dev), off, whence));
}

static int
fileclose(void* dev, struct LFIXProc* p)
{
    (void) p;
    return syserr(close(filefd(dev)));
}

static int
filestat(void* dev, struct LFIXProc* p, struct stat* statbuf)
{
    (void) p;
    int err = syserr(fstatat(filefd(dev), "", statbuf, AT_EMPTY_PATH));
    return err;
}

static ssize_t
filegetdents(void* dev, struct LFIXProc* p, void* dirp, size_t count)
{
    return syserr(getdents64(filefd(dev), dirp, count));
}

static int
filemapfd(void* dev)
{
    return filefd(dev);
}

FDFile*
lfix_filefdnew(int kfd)
{
    FDFile* ff = malloc(sizeof(FDFile));
    if (!ff)
        return NULL;
    *ff = (FDFile) {
        .dev = (void*) (uint64_t) kfd,
        .refs = 0,
        .read = fileread,
        .write = filewrite,
        .lseek = filelseek,
        .close = fileclose,
        .stat = filestat,
        .getdents = filegetdents,
        .mapfd = filemapfd,
    };
    return ff;
}
