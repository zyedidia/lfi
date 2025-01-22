#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>

#include "lfi.h"
#include "boxmap.h"
#include "pal/platform.h"
#include "host.h"

static size_t
guardsize(void)
{
    return 80 * 1024;
}

EXPORT struct LFIAddrSpace*
lfi_as_new(struct LFIPlatform* plat)
{
    struct LFIAddrSpace* as = malloc(sizeof(struct LFIAddrSpace));
    if (!as)
        return NULL;
    size_t size = plat->opts.vmsize;
    uintptr_t base = boxmap_addspace(plat->bm, size);
    if (base == 0)
        goto err1;

    *as = (struct LFIAddrSpace) {
        .base = base,
        .size = size,
        .minaddr = base + guardsize() + plat->opts.pagesize, // for sys page
        .maxaddr = base + size - guardsize(),
        .plat = plat,
    };
    bool ok = mm_init(&as->mm, as->minaddr, as->maxaddr - as->minaddr, plat->opts.pagesize);
    if (!ok)
        goto err2;

    return as;

err2:
    boxmap_rmspace(plat->bm, base, size);
err1:
    free(as);
    return NULL;
}

EXPORT struct LFIAddrSpaceInfo
lfi_as_info(struct LFIAddrSpace* as)
{
    return (struct LFIAddrSpaceInfo) {
        .base = as->base,
        .size = as->size,
        .minaddr = as->minaddr,
        .maxaddr = as->maxaddr,
    };
}

static int
asmap(struct LFIAddrSpace* as, uintptr_t start, size_t size, int prot,
        int flags, struct HostFile* hf, off_t off)
{
    // TODO: verify
    void* mem = host_mmap((void*) start, size, prot, flags | MAP_FIXED, hf, off);
    if (mem == (void*) -1)
        return -errno;
    return 0;
}

EXPORT lfiptr_t
lfi_as_mapany(struct LFIAddrSpace* as, size_t size, int prot, int flags,
        struct HostFile* hf, off_t off)
{
    lfiptr_t addr = mm_mapany(&as->mm, size, prot, flags, hf, off);
    if (addr == (lfiptr_t) -1)
        return 0;
    int r = asmap(as, addr, size, prot, flags, hf, off);
    if (r < 0) {
        mm_unmap(&as->mm, addr, size);
        return (lfiptr_t) -1;
    }
    return addr;
}

static void
cbunmap(uint64_t start, size_t len, MMInfo info, void* udata)
{
    (void) udata, (void) info;
    void* p = host_mmap((void*) start, len, LFI_PROT_NONE, LFI_MAP_ANONYMOUS |
            LFI_MAP_PRIVATE | LFI_MAP_FIXED, NULL, 0);
    assert(p == (void*) start);
}

EXPORT lfiptr_t
lfi_as_mapat(struct LFIAddrSpace* as, lfiptr_t addr, size_t size, int prot,
        int flags, struct HostFile* hf, off_t off)
{
    assert(addr >= as->minaddr && addr + size <= as->maxaddr);

    addr = (lfiptr_t) mm_mapat_cb(&as->mm, addr, size, prot, flags, hf, off, cbunmap, NULL);
    if (addr == (lfiptr_t) -1)
        return (lfiptr_t) -1; 
    int r = asmap(as, addr, size, prot, flags, hf, off);
    if (r < 0) {
        mm_unmap(&as->mm, addr, size);
        return (lfiptr_t) -1;
    }
    return addr;
}

EXPORT int
lfi_as_mprotect(struct LFIAddrSpace* as, lfiptr_t addr, size_t size, int prot)
{
    assert(addr >= as->minaddr && addr + size <= as->maxaddr);

    // TODO: verify

    // TODO: mark the mapping with libmmap?

    return host_mprotect((void*) addr, size, prot);
}

EXPORT int
lfi_as_munmap(struct LFIAddrSpace* as, lfiptr_t addr, size_t size)
{
    if (addr >= as->minaddr && addr + size < as->maxaddr)
        return mm_unmap_cb(&as->mm, addr, size, cbunmap, NULL);
    return -1;
}

EXPORT void
lfi_as_free(struct LFIAddrSpace* as)
{
    assert(!"unimplemented");
}

// TODO: lfi_as_toptr
EXPORT lfiptr_t
lfi_as_toptr(struct LFIAddrSpace* as, void* p)
{
    lfiptr_t userp = (lfiptr_t) p;
    assert(userp >= as->minaddr && userp < as->maxaddr);
    return userp;
}

// TODO: lfi_as_fmptr
EXPORT void*
lfi_as_fmptr(struct LFIAddrSpace* as, lfiptr_t userp)
{
    if (userp >= as->minaddr && userp < as->maxaddr)
        return (void*) userp;
    return NULL;
}

// TODO: lfi_as_validptr
EXPORT lfiptr_t
lfi_as_validptr(struct LFIAddrSpace* as, lfiptr_t asp)
{
    return (lfiptr_t) asp;
}
