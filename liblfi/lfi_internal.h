#ifndef LFI_INTERNAL_H
#define LFI_INTERNAL_H

#include "lfi.h"

enum {
    LFI_PROC_SIZE  = 4ULL * 1024 * 1024 * 1024,
};

struct lfi_vaspace {
    void* base;
    size_t size;
    uint64_t active;
    struct buddy* alloc;
};

struct lfi {
    struct lfi_vaspace vaspaces[LFI_VASPACE_MAX];
    uint8_t n_vaspaces;

    struct lfi_options opts;
};

struct lfi_mem {
    uintptr_t base;
    size_t size;
    int prot;
};

struct lfi_proc {
    struct lfi_regs regs;

    uintptr_t base;

    struct lfi_mem guards[2];
    struct lfi* lfi;
    void* ctxp;
};

uintptr_t lfi_is_full(struct lfi* lfi);

uintptr_t lfi_alloc_slot(struct lfi* lfi);

void lfi_delete_slot(struct lfi* lfi, uintptr_t base);

void lfi_proc_free(struct lfi_proc* proc);

#endif
