#include "lfi.h"

struct memmap {
    uint64_t base;
    size_t size;
    int prot;

    struct memmap* next;
};

void proc_mmap_init(struct proc* proc, uint64_t base, size_t size);
uint64_t proc_mmap(struct proc* proc, uint64_t base, size_t size, int prot, int flags);
