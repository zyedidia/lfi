module mem;

import core.lib;

import proc;

struct MemRegion {
    void* base;
    usize len;
    int prot;

    enum MMAP_FLAGS = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS;

    static MemRegion map(uintptr base, usize len, int prot) {
        return map(base, len, prot, MMAP_FLAGS, -1, 0);
    }

    static MemRegion map(uintptr base, usize len, int prot, int flags, int fd, ssize offset) {
        // TODO: disallow PROT_EXEC?
        void* p = mmap(cast(void*) base, len, prot, flags, fd, offset);
        return MemRegion(p, len, prot);
    }

    MemRegion copy_to(Proc* p) {
        int prot = this.prot;
        if (read(this.prot)) {
            // Force writable so that we can copy into it.
            prot |= PROT_WRITE;
            prot &= ~PROT_EXEC;
        }
        MemRegion m = MemRegion.map(p.addr(cast(uintptr) this.base), this.len, prot);
        if (!m.valid())
            return m;
        if (read(this.prot)) {
            // Copy and reset permissions.
            memcpy(m.base, this.base, this.len);
            if (this.prot != prot) {
                // No verification necessary since we are copying from an
                // existing region (already verified).
                ensure(m.protect_noverify(this.prot) == 0);
            }
        }
        return m;
    }

    int unmap() {
        int ret = munmap(base, len);
        base = cast(void*) -1;
        return ret;
    }

    private int protect_noverify(int prot) {
        assert(!exec(prot) || (exec(prot) && !write(prot)));
        this.prot = prot;
        return mprotect(base, len, prot);
    }

    int protect(int prot) {
        if (exec(prot)) {
            if (write(prot)) {
                return -1;
            }
            // TODO: verify
        }
        this.prot = prot;
        return mprotect(base, len, prot);
    }

    bool valid() {
        return base != cast(void*) -1 && cast(uintptr) base % PAGESIZE == 0;
    }
}

private bool exec(int prot) {
    return (prot & PROT_EXEC) != 0;
}
private bool write(int prot) {
    return (prot & PROT_WRITE) != 0;
}
private bool read(int prot) {
    return (prot & PROT_READ) != 0;
}
