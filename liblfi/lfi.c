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
        total += lfi->vaspaces[i].size / LFI_PROC_SIZE;
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

int lfi_add_vaspace(struct lfi* lfi, void* base, size_t size) {
    if (lfi->n_vaspaces >= LFI_VASPACE_MAX) {
        return LFI_ERR_MAX_VASPACE;
    }

    struct buddy* alloc = buddy_new(base, size, LFI_PROC_SIZE);
    if (!alloc) {
        return LFI_ERR_NOMEM;
    }

    void* region = mmap(base, size, PROT_NONE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0);
    if (region == (void*) -1) {
        free(alloc);
        return LFI_ERR_CANNOT_MAP;
    }
    lfi->vaspaces[lfi->n_vaspaces++] = (struct lfi_vaspace) {
        .base = base,
        .size = size,
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
        }
    }
}

void lfi_delete(struct lfi* lfi) {
    for (uint8_t i = 0; i < lfi->n_vaspaces; i++) {
        munmap(lfi->vaspaces[i].base, lfi->vaspaces[i].size);
    }
    free(lfi);
}

struct lfi_proc* lfi_add_proc(struct lfi* lfi, uint8_t* prog, size_t size, void* ctxp, struct lfi_proc_info* info, int* err) {
    if (lfi_is_full(lfi)) {
        if (err) *err = LFI_ERR_NOSLOT;
        return NULL;
    }

    struct lfi_proc* proc = malloc(sizeof(struct lfi_proc));
    if (!proc) {
        if (err) *err = LFI_ERR_NOMEM;
        return NULL;
    }

    *proc = (struct lfi_proc) {
        .base = lfi_alloc_slot(lfi),
        .lfi = lfi,
        .ctxp = ctxp,
    };

    int err_exec = lfi_proc_exec(proc, prog, size, info);
    if (err_exec < 0) {
        if (err) *err = err_exec;
        return NULL;
    }

    return proc;
}

void lfi_remove_proc(struct lfi* lfi, struct lfi_proc* proc) {
    lfi_delete_slot(lfi, proc->base);
    lfi_proc_free(proc);
}
