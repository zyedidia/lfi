#include <assert.h>
#include <stdlib.h>

#include <sys/mman.h>

#include "lfi.h"
#include "mem.h"

#define BUDDY_ALLOC_ALIGN (PAGE_SIZE)
#define BUDDY_ALLOC_IMPLEMENTATION
#include "buddy.h"
#undef BUDDY_ALLOC_IMPLEMENTATION

bool proc_mmap_init(struct proc* proc, uint64_t base, size_t size) {
    void* meta = malloc(buddy_sizeof(size));
    if (!meta)
        return false;
    proc->mmap = buddy_init(meta, (void*) base, size);
    if (!proc->mmap)
        return false;
    return true;
}

uint64_t proc_mmap(struct proc* proc, uint64_t base, size_t size, int prot, int flags) {
    void* alloc = NULL;
    if (base == 0) {
        alloc = buddy_malloc(proc->mmap, size);
        if (!alloc)
            goto err;
        base = (uint64_t) alloc;
    }

    void* p = mmap((void*) base, size, prot, flags, -1, 0);
    if (p == (void*) -1) {
        if (alloc)
            buddy_free(proc->mmap, alloc);
        goto err;
    }
    return (uint64_t) p;

err:
    return (uint64_t) -1;
}

bool proc_unmap(struct proc* proc, uint64_t base, size_t size) {
    return buddy_safe_free(proc->mmap, (void*) base, size);
}
