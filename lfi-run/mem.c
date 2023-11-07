#include <stdlib.h>
#include <assert.h>
#include <sys/mman.h>

#include "lfi.h"
#include "mem.h"

void proc_mmap_init(struct proc* proc, uint64_t base, size_t size) {
    proc->mmap_heap = (struct mem_region){
        .base = base,
        .len = size,
    };
}

static struct memmap* proc_mmap_nobase(struct proc* proc, size_t size, int prot) {
    uint64_t next_mmap = proc->mmap_heap.base;

    struct memmap** m = &proc->memmaps;
    struct memmap* prev = NULL;
    while (*m) {
        prev = *m;
        m = &((*m)->next);
    }
    if (prev)
        next_mmap = prev->base + size;

    struct memmap* newm = malloc(sizeof(struct memmap));
    if (!newm) {
        return NULL;
    }
    *newm = (struct memmap){
        .base = next_mmap,
        .size = size,
        .prot = prot,
        .next = NULL,
    };
    *m = newm;
    return newm;
}

uint64_t proc_mmap(struct proc* proc, uint64_t base, size_t size, int prot, int flags) {
    struct memmap* newm;
    if (base == 0) {
        newm = proc_mmap_nobase(proc, size, prot);
    } else {
        assert(!"unimplemented");
    }

    if (!newm)
        return (uint64_t) -1;

    void* p = mmap((void*) newm->base, newm->size, newm->prot, flags, -1, 0);
    if (p == (void*) -1) {
        free(newm);
        return (uint64_t) -1;
    }
    return (uint64_t) p;
}
