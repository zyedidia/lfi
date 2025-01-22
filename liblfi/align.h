#pragma once

#include <stdint.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static inline uintptr_t
truncp(uintptr_t addr, size_t align)
{
    size_t align_mask = align - 1;
    return addr & ~align_mask;
}

static inline uintptr_t
ceilp(uintptr_t addr, size_t align)
{
    size_t align_mask = align - 1;
    return (addr + align_mask) & ~align_mask;
}
