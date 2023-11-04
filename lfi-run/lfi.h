#pragma once

#include <stdint.h>
#include <stddef.h>

struct mem_region {
    char* base;
    size_t len;
};

struct proc {
    uintptr_t entry;
    struct mem_region sys;
    struct mem_region mem;
    struct mem_region guard;
};

struct manager {
    struct proc proc;
};
