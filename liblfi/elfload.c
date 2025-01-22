#include <assert.h>

#include "engine.h"
#include "print.h"
#include "align.h"
#include "buf.h"
#include "elfload.h"
#include "syscalls/syscalls.h"

enum {
    MAPANON = LFI_MAP_PRIVATE | LFI_MAP_ANONYMOUS,
    MAPFILE = LFI_MAP_PRIVATE,
};

enum {
    STACKSIZE = 2ULL * 1024 * 1024,
    CODEMAX   = 1ULL * 1024 * 1024 * 1024,
};

static bool
elfcheck(struct FileHeader* ehdr)
{
    return ehdr->magic == ELF_MAGIC &&
        ehdr->width == ELFCLASS64 &&
        ehdr->version == EV_CURRENT &&
        (ehdr->type == ET_DYN || ehdr->type == ET_EXEC);
}

static int
pflags(int prot)
{
    return ((prot & PF_R) ? LFI_PROT_READ : 0) |
        ((prot & PF_W) ? LFI_PROT_WRITE : 0) |
        ((prot & PF_X) ? LFI_PROT_EXEC : 0);
}

static void
sanitize(void* p, size_t sz, int prot)
{
    if ((prot & LFI_PROT_EXEC) == 0)
        return;
#if (defined(__x86_64__) || defined(_M_X64)) && TUX_SANITIZE_CODE
    const uint8_t SAFE_BYTE = 0xcc;
    memset(p, SAFE_BYTE, sz);
#endif
}

static bool
bufreadelfseg(struct LFIAddrSpace* as, lfiptr_t start, lfiptr_t offset, lfiptr_t end,
        size_t p_offset, size_t filesz, int prot, buf_t buf, size_t pagesize)
{
    lfiptr_t p = lfi_as_mapat(as, start, end - start, LFI_PROT_READ | LFI_PROT_WRITE, MAPANON, NULL, 0);
    if (p == (lfiptr_t) -1) {
        return false;
    }
    // If we have any subsequent errors, it is expected that the caller will
    // unmap all mapped regions.

    sanitize((void*) p, pagesize, prot);
    sanitize((void*) (end - pagesize), pagesize, prot);
    // Converting start to actual pointer requires no TUX_EXTERNAL_ADDR_SPACE.
    ssize_t n = bufread(buf, (void*) (start + offset), filesz, p_offset);
    if (n != (ssize_t) filesz) {
        return false;
    }
    if (lfi_as_mprotect(as, start, end - start, prot) < 0) {
        return false;
    }
    return true;
}

static bool
load(struct LFIAddrSpace* as, buf_t buf, uintptr_t base, uintptr_t* pfirst, uintptr_t* plast, uintptr_t* pentry, size_t pagesize)
{
    struct LFIAddrSpaceInfo info = lfi_as_info(as);

    uintptr_t last = 0;

    struct FileHeader ehdr;
    size_t n = bufread(buf, &ehdr, sizeof(ehdr), 0);
    if (n != sizeof(ehdr)) {
        return false;
    }

    if (!elfcheck(&ehdr)) {
        WARN("elfcheck failed");
        return false;
    }

    struct ProgHeader* phdr = malloc(sizeof(struct ProgHeader) * ehdr.phnum);
    if (!phdr) {
        return false;
    }

    n = bufread(buf, phdr, sizeof(struct ProgHeader) * ehdr.phnum, ehdr.phoff);
    if (n != sizeof(struct ProgHeader) * ehdr.phnum) {
        goto err1;
    }

    if (ehdr.entry >= CODEMAX) {
        goto err1;
    }

    uintptr_t first = 0;

    uintptr_t elfbase = ehdr.type == ET_DYN ? base : info.base;

    // TODO: enforce filesz/memsz limit?

    uintptr_t laststart = -1;
    for (int i = 0; i < ehdr.phnum; i++) {
        struct ProgHeader* p = &phdr[i];
        if (p->type != PT_LOAD)
            continue;
        if (p->memsz == 0)
            continue;

        if (p->align % pagesize != 0) {
            goto err1;
        }

        uintptr_t start = truncp(p->vaddr, p->align);
        uintptr_t end = ceilp(p->vaddr + p->memsz, p->align);
        uintptr_t offset = p->vaddr - start;

        if (first == 0 || elfbase + start < first)
            first = elfbase + start;

        if (start == laststart)
            fprintf(stderr, "warning: current segment will overwrite previous segment\n");

        laststart = start;

        if (ehdr.type == ET_EXEC) {
            if (start < base - info.base) {
                goto err1;
            }
            start = start - (base - info.base);
            end = end - (base - info.base);
        }

        if (p->memsz < p->filesz) {
            goto err1;
        }
        if (end <= start || start >= CODEMAX || end >= CODEMAX) {
            goto err1;
        }

        /* VERBOSE(proc->tux, "load %lx %lx (P: %d)", base + start, base + end, pflags(p->flags)); */

        if (!bufreadelfseg(as, base + start, offset, base + end, p->offset, p->filesz, pflags(p->flags), buf, pagesize))
            goto err1;

        if (base == 0) {
            base = base + start;
        }
        if (base + end > last) {
            last = base + end;
        }
    }

    *plast = last;
    *pentry = ehdr.type == ET_DYN ? base + ehdr.entry : info.base + ehdr.entry;
    *pfirst = first;

    free(phdr);

    return true;
err1:
    free(phdr);
    return false;
}

int perf_output_jit_interface_file(uint8_t*, size_t, uintptr_t);

EXPORT bool
lfi_proc_loadelf(struct LFIAddrSpace* as, uint8_t* progdat, size_t progsz, uint8_t* interpdat, size_t interpsz, struct LFILoadInfo* o_info, struct LFILoadOpts opts)
{
    struct LFIAddrSpaceInfo info = lfi_as_info(as);

    buf_t prog = (buf_t) {
        .data = progdat,
        .size = progsz,
    };

    buf_t interp = (buf_t) {
        .data = interpdat,
        .size = interpsz,
    };

    size_t stacksize = opts.stacksize;

    lfiptr_t stack = lfi_as_mapat(as, info.maxaddr - stacksize, stacksize, LFI_PROT_READ | LFI_PROT_WRITE, MAPANON, NULL, 0);
    if (stack == (lfiptr_t) -1)
        goto err;

    lfiptr_t base = info.minaddr;
    lfiptr_t pfirst, plast, pentry, ifirst, ilast, ientry;
    bool hasinterp = interp.data != NULL;
    if (!load(as, prog, base, &pfirst, &plast, &pentry, opts.pagesize))
        goto err;
    if (hasinterp)
        if (!load(as, interp, plast, &ifirst, &ilast, &ientry, opts.pagesize))
            goto err;

    if (opts.perf) {
        if (perf_output_jit_interface_file(progdat, progsz, pfirst))
            goto err;
    }

    struct FileHeader ehdr;
    ssize_t n = bufread(prog, &ehdr, sizeof(ehdr), 0);
    assert(n == sizeof(ehdr));

    *o_info = (struct LFILoadInfo) {
        .stack = stack,
        .stacksize = stacksize,
        .lastva = hasinterp ? ilast : plast,
        .elfentry = pentry,
        .ldentry = hasinterp ? ientry : 0,
        .elfbase = pfirst,
        .ldbase = hasinterp ? ifirst : pfirst,
        .elfphoff = ehdr.phoff,
        .elfphnum = ehdr.phnum,
        .elfphentsize = ehdr.phentsize,
    };

    return true;
err:
    // TODO: procclear
    return false;
}

#define STACKSIZE (2 * 1024 * 1024)

bool
elfload(struct TuxThread* p, uint8_t* progdat, size_t progsz, uint8_t* interpdat, size_t interpsz, struct LFILoadInfo* o_info)
{
    return lfi_proc_loadelf(p->proc->p_as, progdat, progsz, interpdat, interpsz, o_info, (struct LFILoadOpts) {
        .stacksize = STACKSIZE,
        .pagesize = p->proc->tux->opts.pagesize,
        .perf = p->proc->tux->opts.perf,
    });
}
