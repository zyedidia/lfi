#pragma once

#include <stdint.h>
#include <errno.h>

enum {
    MB = 1ULL * 1024 * 1024,
    GB = 1ULL * 1024 * 1024 * 1024,
};

int syserr(int val);

uint64_t
syshandler(void* ctxp, uint64_t sysno,
        uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5);
