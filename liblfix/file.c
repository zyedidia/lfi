#define _GNU_SOURCE

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "file.h"
#include "sys.h"

FDFile*
lfix_filenew(int dirfd, const char* name, int flags, int mode)
{
    int kfd = openat(dirfd, name, flags, mode);
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
fileread(void* dev, LFIXProc* p, uint8_t* buf, size_t buflen)
{
    (void) p;
    return syserr(read(filefd(dev), buf, buflen));
}

static ssize_t
filewrite(void* dev, LFIXProc* p, uint8_t* buf, size_t buflen)
{
    (void) p;
    return syserr(write(filefd(dev), buf, buflen));
}

static ssize_t
filelseek(void* dev, LFIXProc* p, off_t off, int whence)
{
    (void) p;
    return syserr(lseek(filefd(dev), off, whence));
}

static int
fileclose(void* dev, LFIXProc* p)
{
    (void) p;
    return syserr(close(filefd(dev)));
}

static int
filestat(void* dev, LFIXProc* p, struct stat* statbuf)
{
    (void) p;
    return syserr(fstatat(filefd(dev), "", statbuf, AT_EMPTY_PATH));
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
        .mapfd = filemapfd,
    };
    return ff;
}
