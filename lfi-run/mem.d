module mem;

import core.lib;

import verify;

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
    }

    int protect(int prot) {
        if (exec(prot)) {
            if (!lfi_verify_bytes(base, len)) {
                return -1;
            }
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
