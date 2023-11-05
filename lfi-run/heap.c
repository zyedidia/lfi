#include <stdlib.h>
#include <assert.h>

#include "lfi.h"

#define BUDDY_ALLOC_ALIGN (PAGE_SIZE)
#define BUDDY_ALLOC_IMPLEMENTATION
#include "buddy.h"
#undef BUDDY_ALLOC_IMPLEMENTATION

void proc_heap_init(struct proc* proc, void* base, size_t size) {
    void* meta = malloc(buddy_sizeof(size));
    assert(meta);
    proc->heap = buddy_init(meta, base, size);
    assert(proc->heap);
}

void* proc_alloc(struct proc* proc, size_t size) {
    return buddy_malloc(proc->heap, size);
}

void proc_free(struct proc* proc, void* ptr) {
    buddy_free(proc->heap, ptr);
}
