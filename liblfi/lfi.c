#include <assert.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "buddy.h"
#include "lfi_internal.h"

struct lfi* lfi_new(struct lfi_options options) {
    struct lfi* lfi = malloc(sizeof(struct lfi));
    if (!lfi) {
        return NULL;
    }
    *lfi = (struct lfi) {
        .opts = options,
    };
    return lfi;
}

uint64_t lfi_max_procs(struct lfi* lfi) {
    uint64_t total = 0;
    for (uint8_t i = 0; i < lfi->n_vaspaces; i++) {
        // Subtract 2 because of the guard slots that are reserved on either
        // end of a vaspace.
        total += lfi->vaspaces[i].size / LFI_PROC_SIZE - 2;
    }
    return total;
}

uint64_t lfi_num_procs(struct lfi* lfi) {
    uint64_t total = 0;
    for (uint8_t i = 0; i < lfi->n_vaspaces; i++) {
        total += lfi->vaspaces[i].active;
    }
    return total;
}

static struct buddy* buddy_new(void* base, size_t size, size_t align) {
    unsigned char* at = malloc(buddy_sizeof_alignment(size, align));
    if (!at) {
        return NULL;
    }
    return buddy_init_alignment(at, base, size, align);
}

static uint64_t gb(uint64_t n) {
    return n * 1024 * 1024 * 1024;
}

static uint64_t tb(uint64_t n) {
    return n * 1024 * 1024 * 1024 * 1024;
}

// Attempt to reserve as much virtual address space as possible, starting with
// `size`. Returns 0 if it is not able to reserve at least `threshold`.
static uint64_t reserve(uint64_t size, uint64_t threshold, void** base) {
    void* p;
    do {
        p = mmap(NULL, size, PROT_NONE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        if (p == (void*) -1) {
            size /= 2;
        } else {
            munmap(p, size);
        }
        if (size < threshold) {
            return 0;
        }
    } while (p == (void*) -1);
    *base = p;
    return size;
}

int lfi_auto_add_vaspaces(struct lfi* lfi, size_t size) {
    // Start by trying to reserve nearly all of the arm64 virtual address space
    // and then work down from there with exponential backoff.
    uint64_t total = size;
    uint64_t min = size;
    if (size == 0) {
        total = tb(256);
        size = tb(255);
        min = gb(32);
    }
    int i;
    for (i = 0; i < LFI_VASPACE_MAX; i++) {
        void* base;
        uint64_t got = reserve(size, min, &base);
        if (!got) {
            break;
        }
        total = total - got;
        size = total;
        int err = lfi_add_vaspace(lfi, base, got);
        if (err < 0) {
            return err;
        }
    }
    if (i == 0) {
        return LFI_ERR_CANNOT_MAP;
    }
    return 0;
}

int lfi_add_vaspace(struct lfi* lfi, void* base, size_t size) {
    if (lfi->n_vaspaces >= LFI_VASPACE_MAX) {
        return LFI_ERR_MAX_VASPACE;
    }

    uintptr_t align_base = ceil_p((uintptr_t) base, LFI_PROC_SIZE);
    size_t align_size = trunc_p(align_base + (size - (align_base - (uintptr_t) base)), LFI_PROC_SIZE) - align_base;

    struct buddy* alloc = buddy_new((void*) align_base, align_size, LFI_PROC_SIZE);
    if (!alloc) {
        return LFI_ERR_NOMEM;
    }

    void* region = mmap((void*) align_base, align_size, PROT_NONE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0);
    if (region != (void*) align_base) {
        free(alloc);
        return LFI_ERR_CANNOT_MAP;
    }

    // To be safe we will reserve the start and end sandboxes of the region, in
    // case the region is directly adjacent to some sensitive data.
    buddy_reserve_range(alloc, (void*) align_base, LFI_PROC_SIZE);
    buddy_reserve_range(alloc, (void*) (align_base + align_size - LFI_PROC_SIZE), LFI_PROC_SIZE);

    lfi->vaspaces[lfi->n_vaspaces++] = (struct lfi_vaspace) {
        .base = (void*) align_base,
        .size = align_size,
        .alloc = alloc,
    };
    return 0;
}

uintptr_t lfi_is_full(struct lfi* lfi) {
    for (uint8_t i = 0; i < lfi->n_vaspaces; i++) {
        if (!buddy_is_full(lfi->vaspaces[i].alloc)) {
            return false;
        }
    }
    return true;
}

// This function should only be called if `lfi_is_full` returns false.
uintptr_t lfi_alloc_slot(struct lfi* lfi) {
    for (uint8_t i = 0; i < lfi->n_vaspaces; i++) {
        if (!buddy_is_full(lfi->vaspaces[i].alloc)) {
            lfi->vaspaces[i].active++;
            return (uintptr_t) buddy_malloc(lfi->vaspaces[i].alloc, LFI_PROC_SIZE);
        }
    }
    assert(0);
    return 0;
}

void lfi_delete_slot(struct lfi* lfi, uintptr_t base) {
    for (uint8_t i = 0; i < lfi->n_vaspaces; i++) {
        uintptr_t va_base = (uintptr_t) lfi->vaspaces[i].base;
        if (base >= va_base && base < va_base + lfi->vaspaces[i].size) {
            int b = buddy_safe_free(lfi->vaspaces[i].alloc, (void*) base, LFI_PROC_SIZE);
            assert(b);
            lfi->vaspaces[i].active--;
        }
    }
}

void lfi_delete(struct lfi* lfi) {
    for (uint8_t i = 0; i < lfi->n_vaspaces; i++) {
        munmap(lfi->vaspaces[i].base, lfi->vaspaces[i].size);
    }
    free(lfi);
}

struct lfi_proc* lfi_new_proc(void) {
    return malloc(sizeof(struct lfi_proc));
}

int lfi_add_proc(struct lfi* lfi, struct lfi_proc** proc, void* ctxp) {
    if (lfi_is_full(lfi)) {
        return LFI_ERR_NOSLOT;
    }

    struct lfi_proc* p = lfi_new_proc();
    if (!p) {
        return LFI_ERR_NOMEM;
    }
    *p = (struct lfi_proc) {
        .base = lfi_alloc_slot(lfi),
        .lfi = lfi,
        .ctxp = ctxp,
    };
    *proc = p;

    return 0;
}

void lfi_remove_proc(struct lfi* lfi, struct lfi_proc* proc) {
    lfi_delete_slot(lfi, proc->base);
    lfi_proc_free(proc);
}
