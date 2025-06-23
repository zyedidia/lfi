#pragma once

#include "syscalls/syscalls.h"

static inline int
tuxerr(int err)
{
    switch (err) {
    case ENOSYS:
        return -TUX_ENOSYS;
    case EINVAL:
        return -TUX_EINVAL;
    case ENOENT:
        return -TUX_ENOENT;
    case EBADF:
        return -TUX_EBADF;
    case EAGAIN:
        return -TUX_EAGAIN;
    case EPERM:
        return -TUX_EPERM;
    case ENOMEM:
        return -TUX_ENOMEM;
    case EACCES:
        return -TUX_EACCES;
    case ENOTDIR:
        return -TUX_ENOTDIR;
    case EMFILE:
        return -TUX_EMFILE;
    case EFAULT:
        return -TUX_EFAULT;
    default:
        return -TUX_EINVAL;
    }
}
