#pragma once

#include <stddef.h>
#include <stdint.h>
#include <errno.h>

#include "lfix.h"

enum {
    SYS_max = 500,
};

typedef uintptr_t (*SyscallFn)(LFIXProc* p, uintptr_t a0, uintptr_t a1,
        uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5);

extern SyscallFn syscalls[];

static inline size_t
mb(size_t n)
{
    return n * 1024 * 1024;
}

static inline size_t
gb(size_t n)
{
    return n * 1024 * 1024 * 1024;
}

static inline int
syserr(int val)
{
    if (val == -1)
        return -errno;
    return val;
}
