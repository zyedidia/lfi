#include <assert.h>
#include <stdlib.h>

#include <sys/mman.h>

#include "lfi.h"
#include "mem.h"

#include "buddy.h"

struct mem_region mem_map(uintptr_t base,
                          size_t len,
                          int prot,
                          int flags) {
    void* m = mmap((void*) base, len, prot, flags, -1, 0);
    return (struct mem_region){
        .base = (uint64_t) m,
        .len = len,
        .prot = prot,
    };
}

void mem_unmap(struct mem_region* mem) {
    munmap((void*) mem->base, mem->len);
}

void mmap_push_back(struct proc* p, struct mem_region* n) {
    n->next = NULL;
    n->prev = p->mmap_back;
    if (p->mmap_back)
        p->mmap_back->next = n;
    else
        p->mmap_front = n;
    p->mmap_back = n;
}

static void mmap_remove(struct proc* p, struct mem_region* n) {
    if (n->next)
        n->next->prev = n->prev;
    else
        p->mmap_back = n->prev;
    if (n->prev)
        n->prev->next = n->next;
    else
        p->mmap_front = n->next;
}

bool proc_mmap_init(struct proc* proc, uint64_t base, size_t size) {
    void* meta = malloc(buddy_sizeof_alignment(size, PAGE_SIZE));
    if (!meta)
        return false;
    proc->mmap = buddy_init_alignment(meta, (void*) base, size, PAGE_SIZE);
    if (!proc->mmap)
        return false;
    proc->mmap_heap = (struct mem_region){
        .base = base,
        .len = size,
    };
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

    struct mem_region* region = malloc(sizeof(struct mem_region));
    assert(region);
    *region = (struct mem_region){
        .base = base,
        .len = size,
        .prot = prot,
        .allocated = alloc != NULL,
    };
    if (!alloc)
        buddy_reserve_range(proc->mmap, (void*) base, size);
    mmap_push_back(p, region);

    return (uint64_t) p;

err:
    return (uint64_t) -1;
}

bool proc_unmap(struct proc* proc, uint64_t base, size_t size) {
    struct mem_region* m = proc->mmap_front;
    while (m) {
        if (m->base == base && m->len == size) {
            mmap_remove(proc, m);
            if (m->allocated) {
                /* free(m); */
                return buddy_safe_free(proc->mmap, (void*) base, size);
            } else {
                buddy_unsafe_release_range(proc->mmap, (void*) base, size);
                munmap((void*) base, size);
                /* free(m); */
                return true;
            }
        }
        m = m->next;
    }
    return false;
}
