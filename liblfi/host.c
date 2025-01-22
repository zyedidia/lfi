#include "host.h"

EXPORT struct HostFile*
lfi_host_open(const char* filename, int flags, int mode)
{
    return host_open(filename, flags, mode);
}

EXPORT struct HostFile*
lfi_host_fdopen(int fd)
{
    return host_fdopen(fd);
}

EXPORT int
lfi_host_close(struct HostFile* file)
{
    return host_close(file);
}
