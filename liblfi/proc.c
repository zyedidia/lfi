#if __linux__
// for memfd_create
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "align.h"
#include "lfi.h"
#include "lfiv.h"
#include "engine.h"
#include "proc.h"
#include "err.h"
#include "elf.h"
#include "stack.h"

#if defined(__aarch64__) || defined(_M_ARM64)
#include "arch/arm64/arm64.h"
#elif defined(__x86_64__) || defined(_M_X64)
#include "arch/amd64/amd64.h"
#endif

extern uint64_t lfi_proc_entry(LFIProc* proc, void** kstackp) asm ("lfi_proc_entry");
extern uint64_t lfi_asm_invoke(LFIProc* proc, void* fn, void** kstackp) asm ("lfi_asm_invoke");
extern void lfi_asm_proc_exit(void* kstackp, uint64_t code) asm ("lfi_asm_proc_exit");
extern void lfi_syscall_entry() asm ("lfi_syscall_entry");
extern void lfi_get_tp() asm ("lfi_get_tp");
extern void lfi_set_tp() asm ("lfi_set_tp");
extern void lfi_ret() asm ("lfi_ret");

static LFISys* sysalloc(uintptr_t base, int sysexternal, size_t pagesize);
static void syssetup(LFISys* table, LFIProc* proc);

enum {
    MAPANON = MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS,
    MAPFILE = MAP_PRIVATE | MAP_FIXED,
};

static uintptr_t
procaddr(uintptr_t base, uintptr_t addr)
{
    return base | ((uint32_t) addr);
}

static uint64_t
mask(int size)
{
    return (~0ULL) >> (64 - size);
}

static void
proc_validate(LFIProc* proc)
{
    uint64_t* r;

    // base
    wr_regs_base(&proc->regs, proc->base);

    // address registers
    int n = 0;
    while ((r = regs_addr(&proc->regs, n++)))
        *r = procaddr(proc->base, *r);

    // sys register (if used for this arch)
    if ((r = regs_sys(&proc->regs)))
        *r = (uintptr_t) proc->sys;

    if (proc->lfi->opts.p2size != 32 && proc->lfi->opts.p2size != 0)
        *lfi_regs_mask(&proc->regs) = mask(proc->lfi->opts.p2size);
}

bool
lfi_uproc_init(LFIProc* proc, uintptr_t codebase, size_t codesize, size_t datasize)
{
    uintptr_t guard1 = proc->base + proc->lfi->opts.pagesize;
    uintptr_t guard2 = proc->base + proc->size - GUARD2SZ;

    proc->g1start = proc->base; // includes first page, which may be the syspage
    proc->g1end = guard1 + GUARD1SZ;
    proc->g2start = guard2;
    proc->g2end = guard2 + GUARD2SZ;

    if (proc->base + codebase < proc->g1end) {
        lfi_errno = LFI_ERR_INVALID_UPROC;
        return false;
    }

#if __linux__
    int fd = memfd_create("", 0);
    if (fd < 0)
        goto err1;
#else
    char name[32];
    snprintf(name, 32, "lfi_uproc_%lx", proc->base);
    int fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0600);
    if (fd < 0)
        goto err1;
    shm_unlink(name);
#endif

    int r = ftruncate(fd, codesize + datasize);
    if (r < 0)
        goto err2;
    void* alias = mmap(NULL, codesize + datasize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (alias == (void*) -1)
        goto err2;

    proc->ucode = codesize;
    proc->udata = datasize;
    proc->ucodebase = proc->base + codebase;
    proc->ucodealias = alias;

    void* codemap = mmap((void*) (proc->base + codebase), codesize, PROT_READ | PROT_EXEC, MAP_SHARED | MAP_FIXED, fd, 0);
    if (codemap == (void*) -1)
        goto err3;
    void* datamap = mmap((void*) (proc->base + codebase + codesize), datasize, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_FIXED, fd, codesize);
    if (datamap == (void*) -1)
        goto err3;
    size_t stacksize = proc->lfi->opts.stacksize;
    void* stack = mmap((void*) (guard2 - stacksize), stacksize, PROT_READ | PROT_WRITE, MAPANON, -1, 0);
    if (stack == (void*) -1)
        goto err3;
    proc->stack = stack;

    // Close the file descriptor now so that it is automatically deleted when
    // its last mapping is unmapped.
    close(fd);

    proc->sys = sysalloc(proc->base, proc->lfi->opts.sysexternal, proc->lfi->opts.pagesize);
    if (!proc->sys)
        goto err3;
    syssetup(proc->sys, proc);

    return true;

err3:
    lfi_errno = LFI_ERR_CANNOT_MAP;
    munmap(alias, codesize + datasize);
err2:
    close(fd);
err1:
    return false;
}

bool
lfi_proc_meminit(LFIProc* proc)
{
    uintptr_t guard1 = proc->base + proc->lfi->opts.pagesize;

    if (!mm_init(&proc->mm, guard1 + GUARD1SZ, proc->size - GUARD2SZ, proc->lfi->opts.pagesize)) {
        lfi_errno = LFI_ERR_NOMEM;
        return false;
    }
    return true;
}

bool
lfi_proc_init(LFIProc* proc, uintptr_t entry, uintptr_t sp)
{
    regs_init(&proc->regs, entry, sp);
    proc_validate(proc);
    if (proc->lfi->opts.gas) {
        uint64_t* r;
        if ((r = lfi_regs_gas(&proc->regs))) {
            *r = proc->lfi->opts.gas;
        } else {
            lfi_errno = LFI_ERR_INVALID_GAS;
            return false;
        }
    }
    return true;
}

// The procstack is only used for programs that call proc_start while a proc
// is already running (from a runtime call).
static _Thread_local Stack procstack;

__attribute__((visibility("hidden"))) _Thread_local LFIProc* lfi_myproc;

LFIProc*
lfi_proc()
{
    return lfi_myproc;
}

void
lfi_proc_settp(LFIProc* p, void* tp)
{
    p->tp = tp;
}

uint64_t
lfi_proc_start(LFIProc* proc)
{
    if (lfi_myproc != NULL)
        stackpush(&procstack, lfi_myproc);
    lfi_myproc = proc;
    return lfi_proc_entry(proc, &proc->kstackp);
}

uint64_t
lfi_proc_invoke(LFIProc* proc, void* fn, void* ret)
{
    lfi_myproc = proc;
    // TODO: set return point to retfn in a cross-architecture way
#if defined(__aarch64__) || defined(_M_ARM64)
    proc->regs.x30 = (uintptr_t) ret;
#elif defined(__x86_64__) || defined(_M_X64)
    proc->regs.rsp -= 8;
    *((void**) proc->regs.rsp) = ret;
#endif
    return lfi_asm_invoke(proc, fn, &proc->kstackp);
}

void
lfi_proc_pause(uint64_t code)
{
    LFIProc* p = lfi_myproc;
    lfi_asm_proc_exit(p->kstackp, code);
}

void
lfi_proc_exit(uint64_t code)
{
    LFIProc* p = lfi_myproc;
    lfi_myproc = stackpop(&procstack);
    lfi_asm_proc_exit(p->kstackp, code);
}

static bool
elfcheck(ElfFileHeader* ehdr)
{
    return ehdr->magic == ELF_MAGIC &&
        ehdr->width == ELFCLASS64 &&
        ehdr->version == EV_CURRENT &&
        (ehdr->type == ET_DYN || ehdr->type == ET_EXEC);
}

static int
pflags(int prot)
{
    return ((prot & PF_R) ? PROT_READ : 0) |
        ((prot & PF_W) ? PROT_WRITE : 0) |
        ((prot & PF_X) ? PROT_EXEC : 0);
}

static int
mprotectverify(void* base, size_t size, int prot, LFIVerifier* verifier)
{
    if ((prot & PROT_EXEC) == 0 || !verifier)
        return mprotect(base, size, prot);
    if (!lfiv_verify(verifier, base, size, (uintptr_t) base)) {
        lfi_errno = LFI_ERR_VERIFY;
        return -1;
    }
    return mprotect(base, size, prot);
}

static void*
mmapverify(void* base, size_t size, int prot, int flags, int fd, off_t offset, LFIVerifier* verifier)
{
    if ((prot & PROT_EXEC) == 0)
        return mmap(base, size, prot, flags, fd, offset);
    void* p = mmap(base, size, PROT_READ, flags, fd, offset);
    if (p == (void*) -1) {
        lfi_errno = LFI_ERR_CANNOT_MAP;
        return p;
    }
    if (mprotectverify(base, size, prot, verifier) < 0) {
        munmap(base, size);
        return (void*) -1;
    }
    return p;
}

static void
sanitize(void* p, size_t sz, int prot)
{
    if ((prot & PROT_EXEC) == 0)
        return;
#if defined(__x86_64__) || defined(_M_X64)
    const uint8_t SAFE_BYTE = 0xcc;
    memset(p, SAFE_BYTE, sz);
#endif
}

typedef struct {
    uint8_t* data;
    size_t size;
} FileBuf;

// read 'count' bytes from 'buf' into 'to', starting at 'offset'.
static size_t
bufread(FileBuf buf, void* to, size_t count, off_t offset)
{
    if (offset + count > buf.size)
        count = buf.size - offset;
    memcpy(to, &buf.data[offset], count);
    return count;
}

static bool
bufreadelfseg(LFIProc* proc, uintptr_t start, uintptr_t offset, uintptr_t end,
        size_t p_offset, size_t filesz, int prot, FileBuf buf, size_t pagesize)
{
    void* p = lfi_proc_mapat(proc, start, end - start, PROT_READ | PROT_WRITE, MAPANON, -1, 0);
    if (p == (void*) -1) {
        lfi_errno = LFI_ERR_CANNOT_MAP;
        return false;
    }
    // If we have any subsequent errors, it is expected that the caller will
    // unmap all mapped regions.

    sanitize(p, pagesize, prot);
    sanitize((void*) (end - pagesize), pagesize, prot);
    ssize_t n = bufread(buf, (void*) (start + offset), filesz, p_offset);
    if (n != (ssize_t) filesz) {
        lfi_errno = LFI_ERR_INVALID_ELF;
        return false;
    }
    if (lfi_proc_mprotect(proc, start, end - start, prot) < 0)
        return false;
    return true;
}

static bool
ureadelfseg(LFIProc* proc, uintptr_t start, uintptr_t offset, uintptr_t end,
        size_t p_offset, size_t filesz, int prot, FileBuf buf, size_t pagesize)
{
    void* target;
    if (prot == (PROT_READ | PROT_EXEC)) {
        // code region segment
        if (start < proc->ucodebase || start + (end - start) > proc->ucodebase + proc->ucode) {
            lfi_errno = LFI_ERR_UPROC_SEG;
            return false;
        }

        LFIVerifier* verifier = proc->lfi->opts.verifier;
        if (verifier) {
            if (!lfiv_verify(verifier, &buf.data[p_offset], filesz, start + offset)) {
                lfi_errno = LFI_ERR_VERIFY;
                return false;
            }
        }
        target = proc->ucodealias + (start - proc->ucodebase) + offset;
    } else if (prot == (PROT_READ | PROT_WRITE) || prot == PROT_READ) {
        // Note: for micro processes, read-only segments are mapped read-write.
        // data region segment
        uintptr_t database = proc->ucodebase + proc->udata;
        if (start < database || start + (end - start) > database + proc->udata) {
            lfi_errno = LFI_ERR_UPROC_SEG;
            return false;
        }
        target = (void*) start + offset;
    } else {
        // All segments in a micro process are either RX or RW.
        lfi_errno = LFI_ERR_UPROC_SEG;
        return false;
    }
    // If we want to support memory mapping for micro processes we have to
    // update proc->mm here. Currentl memory mappings are not supported for
    // micro processes.
    ssize_t n = bufread(buf, target, filesz, p_offset);
    if (n != (ssize_t) filesz) {
        lfi_errno = LFI_ERR_INVALID_ELF;
        return false;
    }
    return true;
}

static bool
load(LFIProc* proc, FileBuf buf, uintptr_t base, uintptr_t* pfirst, uintptr_t* plast, uintptr_t* pentry)
{
    uintptr_t last = 0;
    size_t pagesize = proc->lfi->opts.pagesize;

    ElfFileHeader ehdr;
    ssize_t n = bufread(buf, &ehdr, sizeof(ehdr), 0);
    if (n != sizeof(ehdr)) {
        lfi_errno = LFI_ERR_INVALID_ELF;
        return false;
    }

    if (!elfcheck(&ehdr)) {
        lfi_errno = LFI_ERR_INVALID_ELF;
        return false;
    }

    ElfProgHeader* phdr = malloc(sizeof(ElfProgHeader) * ehdr.phnum);
    if (!phdr) {
        lfi_errno = LFI_ERR_NOMEM;
        return false;
    }

    n = bufread(buf, phdr, sizeof(ElfProgHeader) * ehdr.phnum, ehdr.phoff);
    if (n != sizeof(ElfProgHeader) * ehdr.phnum) {
        lfi_errno = LFI_ERR_INVALID_ELF;
        goto err1;
    }

    if (ehdr.entry >= CODEMAX) {
        lfi_errno = LFI_ERR_INVALID_ELF;
        goto err1;
    }

    uintptr_t first = 0;

    uintptr_t elfbase = ehdr.type == ET_DYN ? base : proc->base;

    // TODO: enforce filesz/memsz limit?

    uintptr_t laststart = -1;
    for (int i = 0; i < ehdr.phnum; i++) {
        ElfProgHeader* p = &phdr[i];
        if (p->type != PT_LOAD)
            continue;
        if (p->memsz == 0)
            continue;

        if (p->align % pagesize != 0) {
            lfi_errno = LFI_ERR_INVALID_ELF;
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
            if (start < base - proc->base) {
                lfi_errno = LFI_ERR_INVALID_ELF;
                goto err1;
            }
            start = start - (base - proc->base);
            end = end - (base - proc->base);
        }

        if (p->memsz < p->filesz) {
            lfi_errno = LFI_ERR_INVALID_ELF;
            goto err1;
        }
        if (end <= start || start >= CODEMAX || end >= CODEMAX) {
            lfi_errno = LFI_ERR_INVALID_ELF;
            goto err1;
        }

        /* printf("load %lx %lx (P: %d)\n", base + start, base + end, pflags(p->flags)); */

        if (proc->ucodealias) {
            if (!ureadelfseg(proc, base + start, offset, base + end, p->offset, p->filesz, pflags(p->flags), buf, pagesize))
                goto err1;
        } else {
            if (!bufreadelfseg(proc, base + start, offset, base + end, p->offset, p->filesz, pflags(p->flags), buf, pagesize))
                goto err1;
        }

        if (base == 0) {
            base = base + start;
        }
        if (base + end > last) {
            last = base + end;
        }
    }

    if (proc->ucodealias) {
        __builtin___clear_cache((char*) proc->ucodebase, (char*) proc->ucodebase + proc->ucode);
    }

    *plast = last;
    *pentry = ehdr.type == ET_DYN ? base + ehdr.entry : proc->base + ehdr.entry;
    *pfirst = first;

    free(phdr);

    return true;
err1:
    free(phdr);
    return false;
}

static LFISys*
sysalloc(uintptr_t base, int sysexternal, size_t pagesize)
{
    LFISys* sys;
    if (sysexternal) {
        sys = malloc(sizeof(LFISys));
        if (!sys)
            return NULL;
    } else {
        sys = mmap((void*) base, pagesize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
        if (sys == (void*) -1)
            return NULL;
    }
    return sys;
}

static void
syssetup(LFISys* table, LFIProc* proc)
{
    table->rtcalls[0] = (uintptr_t) &lfi_syscall_entry;
    table->rtcalls[1] = (uintptr_t) &lfi_get_tp;
    table->rtcalls[2] = (uintptr_t) &lfi_set_tp;
    table->rtcalls[3] = (uintptr_t) &lfi_ret;
    table->base = proc->base;
    table->proc = proc;
    if (!proc->lfi->opts.sysexternal)
        mprotect(table, proc->lfi->opts.pagesize, PROT_READ);
}

static void
procclear(LFIProc* proc)
{
    if (proc->ucodealias) {
        // micro process just clears by zeroing/sanitizing
        memset(proc->stack, 0, proc->lfi->opts.stacksize);
#if defined(__x86_64__) || defined(_M_X64)
        // Why is 0 a valid instruction in x86.
        const uint8_t SAFE_BYTE = 0xcc;
#else
        const uint8_t SAFE_BYTE = 0;
#endif
        memset(proc->ucodealias, SAFE_BYTE, proc->ucode);
        memset(proc->ucodealias + proc->ucode, 0, proc->udata);
    } else {
        void* p = mmap((void*) proc->base, proc->size, PROT_NONE, MAPANON, -1, 0);
        assert(p != (void*) -1);
    }
}

bool
lfi_proc_loadelf(LFIProc* proc, uint8_t* progdat, size_t progsz, uint8_t* interpdat, size_t interpsz, LFIProcInfo* info)
{
    procclear(proc);

    FileBuf prog = (FileBuf) {
        .data = progdat,
        .size = progsz,
    };
    FileBuf interp = (FileBuf) {
        .data = interpdat,
        .size = interpsz,
    };

    uintptr_t guard1 = proc->base + proc->lfi->opts.pagesize;
    uintptr_t guard2 = proc->base + proc->size - GUARD2SZ;

    if (proc->ucodealias != NULL) {
        // This is a micro process.
        if (interpdat != NULL || interpsz != 0)
            return false;
    } else {
        proc->g1start = proc->base; // includes first page, which may be the syspage
        proc->g1end = guard1 + GUARD1SZ;
        proc->g2start = guard2;
        proc->g2end = guard2 + GUARD2SZ;

        size_t stacksize = proc->lfi->opts.stacksize;
        void* stack = mmap((void*) (guard2 - stacksize), stacksize, PROT_READ | PROT_WRITE, MAPANON, -1, 0);
        if (stack == (void*) -1)
            goto maperr;
        proc->stack = stack;

        proc->sys = sysalloc(proc->base, proc->lfi->opts.sysexternal, proc->lfi->opts.pagesize);
        if (!proc->sys)
            goto err;
        syssetup(proc->sys, proc);
    }

    // Now we are ready to load.
    uintptr_t base = guard1 + GUARD1SZ;
    uintptr_t pfirst, plast, pentry, ifirst, ilast, ientry;
    bool hasinterp = interp.data != NULL;
    if (!load(proc, prog, base, &pfirst, &plast, &pentry))
        goto err;
    if (hasinterp)
        if (!load(proc, interp, plast, &ifirst, &ilast, &ientry))
            goto err;

    ElfFileHeader ehdr;
    ssize_t n = bufread(prog, &ehdr, sizeof(ehdr), 0);
    assert(n == sizeof(ehdr)); // must succeed since we just read it to load

    *info = (LFIProcInfo) {
        .stack = proc->stack,
        .stacksize = proc->lfi->opts.stacksize,
        .lastva = hasinterp ? ilast : plast,
        .elfentry = pentry,
        .ldentry = hasinterp ? ientry : 0,
        .elfbase = pfirst,
        .ldbase = hasinterp ? ifirst : pfirst,
        .elfphoff = ehdr.phoff,
        .elfphnum = ehdr.phnum,
        .elfphentsize = ehdr.phentsize,
    };
    if (proc->ucodealias) {
        uintptr_t dataend = proc->base + proc->ucodebase + proc->ucode + proc->udata;
        info->extradata = dataend - info->lastva;
    }

    return true;

maperr:
    lfi_errno = LFI_ERR_CANNOT_MAP;
err:
    procclear(proc);
    return false;
}

LFIRegs*
lfi_proc_regs(LFIProc* proc)
{
    return &proc->regs;
}

// This function will be called from assembly.
void lfi_syscall_handler(LFIProc* proc) asm ("lfi_syscall_handler");

void
lfi_syscall_handler(LFIProc* proc)
{
    uint64_t sysno = *lfi_regs_sysno(&proc->regs);

    uint64_t a0 = *lfi_regs_sysarg(&proc->regs, 0);
    uint64_t a1 = *lfi_regs_sysarg(&proc->regs, 1);
    uint64_t a2 = *lfi_regs_sysarg(&proc->regs, 2);
    uint64_t a3 = *lfi_regs_sysarg(&proc->regs, 3);
    uint64_t a4 = *lfi_regs_sysarg(&proc->regs, 4);
    uint64_t a5 = *lfi_regs_sysarg(&proc->regs, 5);

    assert(proc->lfi->opts.syshandler);

    uint64_t ret = proc->lfi->opts.syshandler(proc->ctxp, sysno, a0, a1, a2, a3, a4, a5);

    *lfi_regs_sysret(&proc->regs) = ret;
}

static bool
overlaps(uintptr_t start1, uintptr_t end1, uintptr_t start2, uintptr_t end2)
{
    return start1 < end2 && end1 > start2;
}

static int
procmap(LFIProc* proc, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
{
    assert(!overlaps(start, start+size, proc->g1start, proc->g1end) &&
           !overlaps(start, start+size, proc->g2start, proc->g2end));

    assert(start >= proc->base && start < proc->base + proc->size);
    assert(start % proc->lfi->opts.pagesize == 0);
    assert(size % proc->lfi->opts.pagesize == 0);

    void* mem = mmapverify((void*) start, size, prot, flags | MAP_FIXED, fd, offset, proc->lfi->opts.verifier);
    if (mem == (void*) -1)
        return -errno;
    return 0;
}

void*
lfi_proc_mapany(LFIProc* proc, size_t size, int prot, int flags, int fd, off_t offset)
{
    assert(!proc->ucodealias);
    uintptr_t addr = mm_mapany(&proc->mm, size, prot, flags, fd, offset);
    if (addr == (uint64_t) -1)
        return NULL;
    int r = procmap(proc, addr, size, prot, flags, fd, offset);
    if (r < 0) {
        mm_unmap(&proc->mm, addr, size);
        return (void*) -1;
    }
    return (void*) addr;
}

static void
cbunmap(uint64_t start, size_t len, MMInfo info, void* udata)
{
    (void) udata, (void) info;
    void* p = mmap((void*) start, len, PROT_NONE, MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, -1, 0);
    assert(p == (void*) start);
}

void*
lfi_proc_mapat(LFIProc* proc, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset)
{
    uintptr_t addr = mm_mapat_cb(&proc->mm, start, size, prot, flags, fd, offset, cbunmap, NULL);
    if (addr == (uint64_t) -1)
        return (void*) -1;
    int r = procmap(proc, addr, size, prot, flags, fd, offset);
    if (r < 0) {
        mm_unmap(&proc->mm, addr, size);
        return (void*) -1;
    }
    return (void*) addr;
}

int
lfi_proc_mprotect(LFIProc* proc, uintptr_t addr, size_t size, int prot)
{
    assert(!proc->ucodealias);
    // Cannot overlap guard pages.
    if (overlaps(addr, size, proc->g1start, proc->g1end) ||
        overlaps(addr, size, proc->g2start, proc->g2end))
        return -1;

    assert(addr >= proc->base && addr < proc->base + proc->size);
    return mprotectverify((void*) addr, size, prot, proc->lfi->opts.verifier);
}

int
lfi_proc_munmap(LFIProc* proc, uintptr_t addr, size_t size)
{
    assert(!proc->ucodealias);
    // Cannot overlap guard pages.
    if (overlaps(addr, size, proc->g1start, proc->g1end) ||
        overlaps(addr, size, proc->g2start, proc->g2end))
        return -1;

    return mm_unmap_cb(&proc->mm, addr, size, cbunmap, NULL);
}

bool
lfi_proc_mquery(LFIProc* proc, uint64_t addr, LFIMapInfo* info)
{
    assert(!proc->ucodealias);
    MMInfo minfo;
    bool ok = mm_querypage(&proc->mm, addr, &minfo);
    if (ok) {
        *info = (LFIMapInfo) {
            .base = minfo.base,
            .len = minfo.len,
            .prot = minfo.prot,
            .flags = minfo.flags,
            .fd = minfo.fd,
            .offset = minfo.offset,
        };
    }
    return ok;
}

void
lfi_proc_free(LFIProc* p)
{
    procclear(p);
    if (p->lfi->opts.sysexternal)
        free(p->sys);
    free(p);
}

uintptr_t
lfi_proc_base(LFIProc* p)
{
    return p->base;
}

size_t
lfi_proc_size(LFIProc* p)
{
    return p->size;
}

void
lfi_proc_tpset(LFIProc* p, uintptr_t tp)
{
    p->tp = (void*) tp;
}
