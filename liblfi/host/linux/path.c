#include <assert.h>
#include <unistd.h>

#include "host/posix/file.h"
#include "host/error.h"

ssize_t
host_getpath(struct HostFile* dir, char* buf, size_t size)
{
    if (!dir) {
        // Get path of current working directory.
        char* d = getcwd(buf, size);
        if (!d)
            return tuxerr(errno);
        return strnlen(d, size) + 1;
    }

    char procfd[32];
    snprintf(procfd, sizeof(procfd), "/proc/self/fd/%d", dir->fd);
    ssize_t r = readlink(procfd, buf, size - 1);
    if (r < 0)
        return tuxerr(errno);
    buf[r + 1] = 0;
    return r + 1;
}
