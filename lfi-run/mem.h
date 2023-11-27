#include <stdbool.h>

#include "lfi.h"

bool proc_mmap_init(struct proc* proc, uint64_t base, size_t size);
uint64_t proc_mmap(struct proc* proc, uint64_t base, size_t size, int prot, int flags);
bool proc_unmap(struct proc* proc, uint64_t base, size_t size);
void mmap_push_back(struct proc* p, struct mem_region* n);
