#include <assert.h>

#include "align.h"
#include "syscalls/syscalls.h"

uintptr_t
sys_brk(struct TuxProc* p, lfiptr_t addr)
{
    LOCK_WITH_DEFER(&p->lk_brk, lk_brk);

    lfiptr_t brkp = p->brkbase + p->brksize;
    if (addr != 0) {
        if (!procvalid(p, addr))
            return -1;
        brkp = addr;
    }
    if (brkp < p->brkbase)
        brkp = p->brkbase;
    if (brkp >= p->brkbase + TUX_BRKMAXSIZE)
        brkp = p->brkbase + TUX_BRKMAXSIZE;

    size_t newsize = brkp - p->brkbase;
    assert(newsize < TUX_BRKMAXSIZE);

    if (newsize == p->brksize)
        return brkp;

    const int mapflags = LFI_MAP_PRIVATE | LFI_MAP_ANONYMOUS;
    const int mapprot = LFI_PROT_READ | LFI_PROT_WRITE;

    if (brkp >= p->brkbase + p->brksize) {
        LOCK_WITH_DEFER(&p->lk_as, lk_as);
        lfiptr_t map;
        if (p->brksize == 0) {
            map = lfi_as_mapat(p->p_as, p->brkbase, newsize, mapprot, mapflags, NULL, 0);
        } else {
            lfiptr_t next = ceilp(p->brkbase + p->brksize, p->tux->opts.pagesize);
            map = lfi_as_mapat(p->p_as, next, newsize - p->brksize, mapprot, mapflags, NULL, 0);
        }
        if (map == (lfiptr_t) -1)
            return -1;
    }
    p->brksize = newsize;
    return p->brkbase + p->brksize;
}

uintptr_t
sys_mmap(struct TuxProc* p, lfiptr_t addrp, size_t length, int prot, int flags, int fd, off_t off)
{
    if (length == 0)
        return -TUX_EINVAL;
    length = ceilp(length, p->tux->opts.pagesize);

    const int illegal_mask = ~LFI_MAP_ANONYMOUS &
        ~LFI_MAP_PRIVATE &
        ~LFI_MAP_NORESERVE &
        ~LFI_MAP_DENYWRITE &
        ~LFI_MAP_FIXED;
    if ((flags & illegal_mask) != 0) {
        VERBOSE(p->tux, "invalid mmap flag: not one of MAP_ANONYMOUS, MAP_PRIVATE, MAP_FIXED");
        return -TUX_EINVAL;
    }

    lfiptr_t i_addrp = addrp;

    int r;
    if ((flags & LFI_MAP_FIXED) != 0) {
        addrp = truncp(addrp, p->tux->opts.pagesize);
        if (!procvalid(p, addrp))
            return -1;
        r = procmapat(p, addrp, length, prot, flags, fd, off);
    } else {
        r = procmapany(p, length, prot, flags, fd, off, &addrp);
    }
    if (r < 0) {
        VERBOSE(p->tux, "sys_mmap((%lx), %ld, %d, %d, %d, %ld) = %d", i_addrp, length, prot, flags, fd, (long) off, r);
        return r;
    }
    lfiptr_t ret = addrp;
    VERBOSE(p->tux, "sys_mmap(%lx (%lx), %ld, %d, %d, %d, %ld) = %lx", addrp, i_addrp, length, prot, flags, fd, (long) off, ret);
    return ret;
}

int
sys_mprotect(struct TuxProc* p, lfiptr_t addrp, size_t length, int prot)
{
    if (!procvalid(p, addrp))
        return -1;
    LOCK_WITH_DEFER(&p->lk_as, lk_as);
    return lfi_as_mprotect(p->p_as, addrp, length, prot);
}

int
sys_munmap(struct TuxProc* p, lfiptr_t addrp, size_t length)
{
    if (!procvalid(p, addrp))
        return -1;
    return procunmap(p, addrp, length);
}
