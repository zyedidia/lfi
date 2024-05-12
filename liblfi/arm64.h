#ifndef LFI_ARM64_H
#define LFI_ARM64_H

#include <stdint.h>

static uint64_t r_tpidr() {
    uint64_t val;
    asm volatile ("mrs %0, tpidr_el0" : "=r"(val));
    return val;
}

static void w_tpidr(uint64_t val) {
    asm volatile ("msr tpidr_el0, %0" :: "r"(val));
}

#endif
