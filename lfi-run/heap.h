#include "lfi.h"

void proc_heap_init(struct proc* proc, void* base, size_t size);
void* proc_alloc(struct proc* proc, size_t size);
void proc_free(struct proc* proc, void* ptr);
