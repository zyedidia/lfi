#ifndef LFI_ARM64_H
#define LFI_ARM64_H

#include <stdint.h>

static inline uint64_t rd_tpidr() {
    uintptr_t val;
    asm volatile ("mrs %0, tpidr_el0" : "=r"(val));
    return val;
}

#endif
