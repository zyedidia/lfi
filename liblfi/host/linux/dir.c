#define _GNU_SOURCE
#include <dirent.h>
#include <stdio.h>

#include "types.h"
#include "host/posix/file.h"
#include "host/error.h"

#ifndef HAVE_GETDENTS64
#include <limits.h>
#include <unistd.h>
#include <sys/syscall.h>
static int
getdents64(int fd, struct dirent *buf, size_t len)
{
    if (len>INT_MAX) len = INT_MAX;
    return syscall(SYS_getdents64, fd, buf, len);
}
#endif

ssize_t
host_getdents64(struct HostFile* file, void* dirp, size_t count)
{
    ssize_t r = getdents64(file->fd, dirp, count);
    if (r < 0)
        return tuxerr(errno);
    return r;
}
