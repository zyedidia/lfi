#pragma once

#include "syscalls/syscalls.h"

static inline int
tuxerr(int err)
{
    if (err >= 0)
        return err;
    switch (err) {
    case -ENOSYS:
        return -TUX_ENOSYS;
    case -EINVAL:
        return -TUX_EINVAL;
    default:
        return -TUX_EINVAL;
    }
}
