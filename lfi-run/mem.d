module mem;

import core.lib;

struct MemRegion {
    void* base;
    usize len;
    int prot;

    enum MMAP_FLAGS = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS;

    static MemRegion map(uintptr base, usize len, int prot) {
        // TODO: disallow PROT_EXEC?
        void* p = mmap(cast(void*) base, len, prot, MMAP_FLAGS, -1, 0);
        return MemRegion(p, len, prot);
    }

    void unmap() {
        munmap(base, len);
        base = cast(void*) -1;
    }

    int protect(int prot) {
        if (exec(prot)) {
            // TODO: verify
        }
        return mprotect(base, len, prot);
    }

    bool valid() {
        return base != cast(void*) -1 && cast(uintptr) base % PAGESIZE == 0;
    }
}

private bool exec(int prot) {
    return (prot & PROT_EXEC) != 0;
}
