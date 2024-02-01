module mem;

import core.lib;

import proc;

struct MemRegion {
    void* base;
    usize len;
    int prot;

    int fd;

    enum MMAP_PRIVATE = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS;
    enum MMAP_SHARED = MAP_FIXED | MAP_SHARED;

    static MemRegion map(uintptr base, usize len, int prot, bool share = false) {
        int fd = -1;
        int flags = MMAP_PRIVATE;
        if (share) {
            fd = memfd_create("", 0);
            if (fd < 0)
                return MemRegion(cast(void*) -1, 0, 0, 0);
            ensure(ftruncate(fd, len) == 0);
            flags = MMAP_SHARED;
        }
        return map(base, len, prot, flags, fd, 0);
    }

    static MemRegion map(uintptr base, usize len, int prot, int flags, int fd, ssize offset) {
        // TODO: disallow PROT_EXEC?
        void* p = mmap(cast(void*) base, len, prot, flags, fd, offset);
        return MemRegion(p, len, prot, fd);
    }

    MemRegion copy_to_shared(Proc* p) {
        MemRegion m = MemRegion.map(p.addr(cast(uintptr) this.base), this.len, this.prot, MMAP_SHARED, this.fd, 0L);
        return m;
    }

    MemRegion copy_to_unshared(Proc* p) {
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

    MemRegion copy_to(Proc* p) {
        if (this.fd >= 0 && !write(this.prot)) {
            return copy_to_shared(p);
        }
        return copy_to_unshared(p);
    }

    void remap(usize new_len) {
        ensure(mremap(base, len, new_len, 0) == base);
        this.len = new_len;
    }

    int unmap() {
        int ret = munmap(base, len);
        // if (fd >= 0)
        //     close(fd);
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
