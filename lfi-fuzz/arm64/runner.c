#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>

#include "runner.h"
#include "generator.h"

enum {
    CODE_BASE = 128ULL * 1024 * 1024 * 1024,
    DATA_BASE = 256ULL * 1024 * 1024 * 1024,
    DATA_SIZE = 4ULL * 1024 * 1024 * 1024,

    GUARD_SIZE = 48 * 1024,

    STACK_SIZE = SIGSTKSZ + 1024 * 1024,
};

struct Regs {
    uint64_t gpr[31];
    uint64_t sp;
    uint64_t pad;
    uint64_t simd[64];
};

struct Mem {
    void* p;
    size_t sz;

    struct Mem* next;
};

static int illegal;

static uint64_t
hash(uint64_t u)
{
    uint64_t v = u * 3935559000370003845 + 2691343689449507681;
    v ^= v >> 21;
    v ^= v << 37;
    v ^= v >>  4;
    v *= 4768777513237032717;
    v ^= v << 20;
    v ^= v >> 41;
    v ^= v <<  5;
    return v;
}

static uint64_t
hashregs(struct Regs* r)
{
    uint64_t u = 0;
    for (int i = 0; i < 31; i++) {
        u += hash(r->gpr[i]);
    }
    u += hash(r->sp);
    for (int i = 0; i < 64; i++) {
        u += hash(r->simd[i]);
    }
    return u;
}

static uint64_t
hashmem(void* p, size_t sz)
{
    assert(sz % sizeof(uint64_t) == 0);
    uint64_t* data = (uint64_t*) p;
    uint64_t u = 0;
    for (size_t i = 0; i < sz / sizeof(uint64_t); i++) {
        u += hash(data[i]);
    }
    return u;
}

#define IMAX_BITS(m) ((m)/((m)%255+1) / 255%255*8 + 7-86/((m)%255+12))
#define RAND_MAX_WIDTH IMAX_BITS(RAND_MAX)

static uint64_t
rand64()
{
    uint64_t r = 0;
    for (int i = 0; i < 64; i += RAND_MAX_WIDTH) {
        r <<= RAND_MAX_WIDTH;
        r ^= (unsigned) rand();
    }
    return r;
}

static uint64_t
mask(uint64_t base, uint64_t addr)
{
    return base + (uint32_t) addr;
}

static struct Mem* memfirst;
static struct Mem* memlast;

static void
end(struct Regs r)
{
    struct Mem* m = memfirst;
    uint64_t u = hashregs(&r);
    while (m) {
        u += hashmem(m->p, m->sz);
        m = m->next;
    }

    printf("ended: %lx\n", u);
    printf("illegal: %d\n", illegal);
    exit(1);
}

static void
check(struct Regs r, uintptr_t pc)
{
    if (r.gpr[21] != DATA_BASE) {
        fprintf(stderr, "%lx: x21 modified: %lx\n", pc, r.gpr[21]);
        end(r);
    }
}

static char*
strsigno(int signo)
{
    switch (signo) {
    case SIGBUS:
        return "SIGBUS";
    case SIGILL:
        return "SIGILL";
    case SIGSEGV:
        return "SIGSEGV";
    case SIGFPE:
        return "SIGFPE";
    case SIGTRAP:
        return "SIGTRAP";
    default:
        return "SIGOTHER";
    }
}

static size_t codesize;

static void
sighandler(int signo, siginfo_t* si, void* data)
{
    ucontext_t* uc = (ucontext_t*) data;
    size_t pgsz = pagesize();
    void* p;
    uintptr_t addr = (uintptr_t) si->si_addr;

    printf("%llx: %s\n", uc->uc_mcontext.pc, strsigno(signo));

    struct Regs r;
    memset(&r, 0, sizeof(r));

    for (int i = 0; i < 31; i++) {
        r.gpr[i] = uc->uc_mcontext.regs[i];
    }
    r.sp = uc->uc_mcontext.sp;

    check(r, uc->uc_mcontext.pc);
    uc->uc_mcontext.regs[18] = mask(r.gpr[21], r.gpr[18]);
    uc->uc_mcontext.regs[30] = mask(r.gpr[21], r.gpr[30]);
    uc->uc_mcontext.sp = mask(r.gpr[21], r.sp);

    uint32_t* insn = (uint32_t*) uc->uc_mcontext.pc;

    switch (signo) {
    case SIGILL:
        printf("illegal: %x\n", *insn);
        illegal++;
        uc->uc_mcontext.pc += 4;
        break;
    case SIGSEGV:
        if (addr < DATA_BASE - GUARD_SIZE || addr > DATA_BASE + DATA_SIZE + GUARD_SIZE) {
            fprintf(stderr, "%llx: out of bounds access %lx (outside %lx-%lx)\n", uc->uc_mcontext.pc, addr, DATA_BASE, DATA_BASE + DATA_SIZE);
            if (uc->uc_mcontext.pc > CODE_BASE && uc->uc_mcontext.pc < CODE_BASE + codesize)
                fprintf(stderr, "insn: %x\n", *insn);
            end(r);
        }
        addr = addr & ~(pgsz - 1);
        p = mmap((void*) addr, pgsz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS, -1, 0);
        if (p == (void*) -1) {
            fprintf(stderr, "error mapping %lx\n", addr);
            end(r);
        }

        struct Mem* m = malloc(sizeof(struct Mem));
        assert(m);

        m->p = p;
        m->sz = pgsz;

        if (!memfirst)
            memfirst = m;
        if (!memlast) {
            memlast = m;
        } else {
            memlast->next = m;
            memlast = m;
        }

        break;
    case SIGBUS:
    case SIGFPE:
    case SIGTRAP:
        uc->uc_mcontext.pc += 4;
        break;
    }
}

extern void jumpto(struct Regs* regs);

bool
runprog(void* prog, size_t sz)
{
    void* buf = mmap((void*) CODE_BASE, sz, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (buf == (void*) -1) {
        perror("mmap");
        return false;
    }
    memcpy(buf, prog, sz);
    mprotect(buf, sz, PROT_EXEC);
    codesize = sz;

    stack_t ss;
    ss.ss_sp = malloc(STACK_SIZE);
    ss.ss_size = STACK_SIZE;
    ss.ss_flags = 0;
    sigaltstack(&ss, NULL);

    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
    sa.sa_sigaction = sighandler;
    sigaction(SIGBUS, &sa, 0);
    sigaction(SIGSEGV, &sa, 0);
    sigaction(SIGILL, &sa, 0);
    sigaction(SIGTRAP, &sa, 0);
    sigaction(SIGFPE, &sa, 0);

    struct Regs regs;

    for (int i = 0; i < 31; i++) {
        regs.gpr[i] = rand64();
    }
    for (int i = 0; i < 64; i++) {
        regs.simd[i] = rand64();
    }
    regs.sp = mask(DATA_BASE, rand64() & 0xfffffff0);
    regs.gpr[18] = mask(DATA_BASE, rand64());
    regs.gpr[30] = CODE_BASE;
    regs.gpr[21] = DATA_BASE;

    jumpto(&regs);

    return true;
}
