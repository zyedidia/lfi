#ifndef LFI_INTERNAL_H
#define LFI_INTERNAL_H

#include "lfi.h"

enum {
    LFI_PROC_SIZE  = 4ULL * 1024 * 1024 * 1024,
};

uintptr_t lfi_is_full(struct lfi* lfi);

uintptr_t lfi_alloc_slot(struct lfi* lfi);

void lfi_delete_slot(struct lfi* lfi, uintptr_t base);

void lfi_proc_free(struct lfi_proc* proc);

int lfi_verify_bytes(void* b, size_t size, void* fn);

static inline uintptr_t trunc_p(uintptr_t addr, size_t align) {
    size_t align_mask = align - 1;
    return addr & ~align_mask;
}

static inline uintptr_t ceil_p(uintptr_t addr, size_t align) {
    size_t align_mask = align - 1;
    return (addr + align_mask) & ~align_mask;
}

#endif
