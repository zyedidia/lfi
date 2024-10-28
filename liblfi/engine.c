#include <assert.h>
#include <stdlib.h>
#include <sys/mman.h>

#include "align.h"
#include "lfi.h"
#include "engine.h"
#include "err.h"
#include "proc.h"

static size_t
gb(size_t x)
{
    return x * 1024 * 1024 * 1024;
}

static size_t
tb(size_t x)
{
    return x * 1024 * 1024 * 1024 * 1024;
}

static size_t
procsize(LFIEngine* engine)
{
    return 1ULL << engine->opts.p2size;
}

LFIEngine*
lfi_new(LFIOptions options)
{
    if ((!options.verifier || !options.verifier->verify) && !options.noverify) {
        lfi_errno = LFI_ERR_NOVERIFIER;
        return NULL;
    }
    if (!options.syshandler) {
        lfi_errno = LFI_ERR_NOSYSHANDLER;
        return NULL;
    }
    LFIEngine* engine = malloc(sizeof(LFIEngine));
    if (!engine) {
        lfi_errno = LFI_ERR_NOMEM;
        return NULL;
    }
    if (options.p2size == 0)
        options.p2size = 32;
    if (options.noverify)
        options.verifier = NULL;

#if __APPLE
    // sysexternal is required on macOS
    options.sysexternal = 1;
#endif

    assert(!options.verifier || options.verifier->verify);

    *engine = (LFIEngine) {
        .opts = options,
    };
    return engine;
}

uint64_t
lfi_maxprocs(LFIEngine* lfi)
{
    size_t total = 0;
    for (size_t i = 0; i < lfi->nspaces; i++) {
        // Subtract 2 for guard slots reserved on either end of a space.
        total += lfi->spaces[i].size / procsize(lfi) - 2;
    }
    return total;
}

uint64_t
lfi_numprocs(LFIEngine* lfi)
{
    size_t total = 0;
    for (size_t i = 0; i < lfi->nspaces; i++) {
        total += lfi->spaces[i].active;
    }
    return total;
}

// Attempt to reserve as much virtual address space as possible, starting with
// 'size'. Returns 0 if it is not able to reserve at least 'threshold'.
static size_t
reserve(size_t size, size_t threshold, void** base)
{
    void* p;
    do {
        p = mmap(NULL, size, PROT_NONE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        if (p == (void*) -1) {
            size /= 2;
        } else {
            munmap(p, size);
        }
        if (size < threshold)
            return 0;
    } while (p == (void*) -1);
    *base = p;
    return size;
}

static struct buddy*
buddynew(void* base, size_t size, size_t align)
{
    unsigned char* at = malloc(buddy_sizeof_alignment(size, align));
    if (!at) {
        lfi_errno = LFI_ERR_NOMEM;
        return NULL;
    }
    return buddy_init_alignment(at, base, size, align);
}

static bool
addspace(LFIEngine* lfi, void* base, size_t size)
{
    if (lfi->nspaces >= LFI_ADDR_SPACE_MAX) {
        lfi_errno = LFI_ERR_MAX_SPACE;
        return false;
    }

    uintptr_t alignbase = ceilp((uintptr_t) base, procsize(lfi));
    size_t alignsize = truncp(alignbase + (size - (alignbase - (uintptr_t) base)), procsize(lfi)) - alignbase;

    struct buddy* alloc = buddynew((void*) alignbase, alignsize, procsize(lfi));
    if (!alloc)
        return false;

    void* region = mmap((void*) alignbase, alignsize, PROT_NONE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0);
    if (region != (void*) alignbase) {
        free(alloc);
        lfi_errno = LFI_ERR_CANNOT_MAP;
        return false;
    }

    // To be safe we will reserve the start and end sandboxes of the region, in
    // case the region is directly adjacent to some sensitive data.
    buddy_reserve_range(alloc, (void*) alignbase, procsize(lfi));
    buddy_reserve_range(alloc, (void*) (alignbase + alignsize - procsize(lfi)), procsize(lfi));

    lfi->spaces[lfi->nspaces++] = (LFIAddrSpace) {
        .base = (void*) alignbase,
        .size = alignsize,
        .alloc = alloc,
    };

    return true;
}

bool
lfi_reserve(LFIEngine* lfi, size_t size)
{
    size_t total = size;
    size_t min = size;
    size_t totalgot = 0;
    size_t i_size = size;

    if (size == 0) {
        total = tb(256);
        size = tb(255);
        min = gb(32);
    }
    int i;
    for (i = 0; i < LFI_ADDR_SPACE_MAX; i++) {
        void* base;
        size_t got = reserve(size, min, &base);
        if (!got)
            break;
        totalgot += got;
        total = total - got;
        size = total;
        if (!addspace(lfi, base, got))
            return false;
        if (totalgot >= i_size)
            break;
    }
    if (totalgot < i_size) {
        lfi_errno = LFI_ERR_CANNOT_MAP;
        return false;
    }
    return true;
}

static bool
isfull(LFIEngine* lfi)
{
    for (size_t i = 0; i < lfi->nspaces; i++) {
        if (!buddy_is_full(lfi->spaces[i].alloc))
            return false;
    }
    return true;
}

// This function can only be called if the engine is not full.
static uintptr_t
allocslot(LFIEngine* lfi)
{
    for (size_t i = 0; i < lfi->nspaces; i++) {
        if (!buddy_is_full(lfi->spaces[i].alloc)) {
            lfi->spaces[i].active++;
            return (uintptr_t) buddy_malloc(lfi->spaces[i].alloc, procsize(lfi));
        }
    }
    assert(0);
}

static void
deleteslot(LFIEngine* lfi, uintptr_t base)
{
    for (size_t i = 0; i < lfi->nspaces; i++) {
        uintptr_t vabase = (uintptr_t) lfi->spaces[i].base;
        if (base >= vabase && base < vabase + lfi->spaces[i].size) {
            int b = buddy_safe_free(lfi->spaces[i].alloc, (void*) base, procsize(lfi));
            assert(b);
            lfi->spaces[i].active--;
        }
    }
}

void
lfi_delete(LFIEngine* lfi)
{
    for (size_t i = 0; i < lfi->nspaces; i++) {
        munmap(lfi->spaces[i].base, lfi->spaces[i].size);
    }
    free(lfi);
}

bool
lfi_addproc(LFIEngine* lfi, LFIProc** proc, void* ctxp)
{
    if (isfull(lfi)) {
        lfi_errno = LFI_ERR_NOSLOT;
        return false;
    }

    LFIProc* p = malloc(sizeof(LFIProc));
    if (!p) {
        lfi_errno = LFI_ERR_NOMEM;
        return false;
    }
    *p = (LFIProc) {
        .base = allocslot(lfi),
        .size = procsize(lfi),
        .lfi = lfi,
        .ctxp = ctxp,
    };
    if (!lfi_proc_meminit(p)) {
        free(p);
        return false;
    }

    *proc = p;

    return true;
}

bool
lfi_adduproc(LFIEngine* lfi, LFIProc** proc, void* ctxp, uintptr_t codebase,
        size_t codesize, size_t datasize)
{
    if (!lfi_addproc(lfi, proc, ctxp))
        return false;

    if (!lfi_uproc_init(*proc, codebase, codesize, datasize)) {
        lfi_rmproc(lfi, *proc);
        return false;
    }

    return true;
}

void
lfi_rmproc(LFIEngine* lfi, LFIProc* proc)
{
    deleteslot(lfi, proc->base);
    lfi_proc_free(proc);
}
