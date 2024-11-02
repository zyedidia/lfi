#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

static inline size_t
pagesize()
{
    return 4 * 1024;
}

bool runprog(void* buf, size_t sz);
