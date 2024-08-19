#include <fcntl.h>
#include <unistd.h>

#include "file.h"
#include "sys.h"

FDFile*
filenew(int dirfd, const char* name, int flags, int mode)
{
    int kfd = openat(dirfd, name, flags, mode);
    if (kfd < 0)
        return NULL;
    return filefdnew(kfd);
}

static int
filefd(void* dev)
{
    return (int) ((intptr_t) dev);
}

static ssize_t
fileread(void* dev, SoboxLib* l, uint8_t* buf, size_t buflen)
{
    (void) l;
    return syserr(read(filefd(dev), buf, buflen));
}

static ssize_t
filewrite(void* dev, SoboxLib* l, uint8_t* buf, size_t buflen)
{
    (void) l;
    return syserr(write(filefd(dev), buf, buflen));
}

static ssize_t
filelseek(void* dev, SoboxLib* l, off_t off, int whence)
{
    (void) l;
    return syserr(lseek(filefd(dev), off, whence));
}

static int
fileclose(void* dev, SoboxLib* l)
{
    (void) l;
    return syserr(close(filefd(dev)));
}

static int
filemapfd(void* dev)
{
    return filefd(dev);
}

FDFile*
filefdnew(int kfd)
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
        .mapfd = filemapfd,
    };
    return ff;
}
