#ifndef LFI_INTERNAL_H
#define LFI_INTERNAL_H

#include "lfi.h"

#if defined(ARCH_arm64)
#include "arch/arm64/regs.h"
#elif defined(ARCH_amd64)
#include "arch/amd64/regs.h"
#endif

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

    struct lfi_mem* next;
    struct lfi_mem* prev;
};

struct lfi_sys {
    uintptr_t rtcalls[256];
    struct lfi_proc* proc;
    uintptr_t k_tpidr;
    uintptr_t base;
};

struct lfi_proc {
    void* kstackp;
    struct lfi_regs regs;

    uintptr_t base;

    struct lfi_sys* sys;
    struct lfi_mem code;
    struct lfi_mem guards[2];
    struct lfi_mem* segments;
    struct lfi_mem stack;
    int codefd;
    void* codealias;

    struct lfi* lfi;
    void* ctxp;
};

enum {
    LFI_PROC_SIZE  = 4ULL * 1024 * 1024 * 1024,
};

struct lfi_proc* lfi_new_proc();

uintptr_t lfi_is_full(struct lfi* lfi);

uintptr_t lfi_alloc_slot(struct lfi* lfi);

void lfi_delete_slot(struct lfi* lfi, uintptr_t base);

void lfi_proc_free(struct lfi_proc* proc);

static inline uintptr_t trunc_p(uintptr_t addr, size_t align) {
    size_t align_mask = align - 1;
    return addr & ~align_mask;
}

static inline uintptr_t ceil_p(uintptr_t addr, size_t align) {
    size_t align_mask = align - 1;
    return (addr + align_mask) & ~align_mask;
}

void lfi_proc_init(struct lfi_proc* p);

#endif
