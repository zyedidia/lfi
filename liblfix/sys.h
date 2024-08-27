#pragma once

#include <stddef.h>
#include <stdint.h>
#include <errno.h>

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

uint64_t lfix_syscall(void* ctxp, uint64_t sysno, uint64_t a0, uint64_t a1,
        uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
