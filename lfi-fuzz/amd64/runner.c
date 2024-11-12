// for REG_RIP
#define _GNU_SOURCE
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>

#include "runner.h"
#include "generator.h"
#include "fadec.h"

enum {
    CODE_BASE = 128ULL * 1024 * 1024 * 1024,
    DATA_BASE = 256ULL * 1024 * 1024 * 1024,
    DATA_SIZE = 4ULL * 1024 * 1024 * 1024,

    GUARD_SIZE = 48 * 1024,
};

struct Regs {
    uint64_t rsp;
    uint64_t rax;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rbx;
    uint64_t rbp;
    uint64_t rsi;
    uint64_t rdi;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t r11;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;

    uint64_t xmm[32];
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

static inline void
dumpreginit(struct Regs* r)
{
    printf("movabs $0x%lx, %%rsp\n", r->rsp);
    printf("movabs $0x%lx, %%rax\n", r->rax);
    printf("movabs $0x%lx, %%rcx\n", r->rcx);
    printf("movabs $0x%lx, %%rdx\n", r->rdx);
    printf("movabs $0x%lx, %%rbx\n", r->rbx);
    printf("movabs $0x%lx, %%rbp\n", r->rbp);
    printf("movabs $0x%lx, %%rsi\n", r->rsi);
    printf("movabs $0x%lx, %%rdi\n", r->rdi);
    printf("movabs $0x%lx, %%r8\n", r->r8);
    printf("movabs $0x%lx, %%r9\n", r->r9);
    printf("movabs $0x%lx, %%r10\n", r->r10);
    printf("movabs $0x%lx, %%r11\n", r->r11);
    printf("movabs $0x%lx, %%r12\n", r->r12);
    printf("movabs $0x%lx, %%r13\n", r->r13);
    printf("movabs $0x%lx, %%r14\n", r->r14);
    printf("movabs $0x%lx, %%r15\n", r->r15);

    for (size_t i = 0; i < 16; i++) {
        printf("movaps xmm_%ld(%%rip), %%xmm%ld\n", i, i);
    }
    for (size_t i = 0; i < 16; i++) {
        printf(".p2align 4\n");
        printf("xmm_%ld:\n", i);
        printf(".quad 0x%lx\n", r->xmm[i*2]);
        printf(".quad 0x%lx\n", r->xmm[i*2+1]);
    }
}

static inline void
dumpregs(struct Regs* r)
{
    printf("%%rsp: %lx\n", r->rsp);
    printf("%%rax: %lx\n", r->rax);
    printf("%%rcx: %lx\n", r->rcx);
    printf("%%rdx: %lx\n", r->rdx);
    printf("%%rbx: %lx\n", r->rbx);
    printf("%%rbp: %lx\n", r->rbp);
    printf("%%rsi: %lx\n", r->rsi);
    printf("%%rdi: %lx\n", r->rdi);
    printf("%%r8: %lx\n", r->r8);
    printf("%%r9: %lx\n", r->r9);
    printf("%%r10: %lx\n", r->r10);
    printf("%%r11: %lx\n", r->r11);
    printf("%%r12: %lx\n", r->r12);
    printf("%%r13: %lx\n", r->r13);
    printf("%%r14: %lx\n", r->r14);
    printf("%%r15: %lx\n", r->r15);

    for (size_t i = 0; i < 32; i++) {
        printf("%%xmm_%ld: %lx\n", i, r->xmm[i]);
    }
}

static uint64_t
hashregs(struct Regs* r)
{
    uint64_t u = 0;
    u += hash(r->rsp);
    u += hash(r->rax);
    u += hash(r->rcx);
    u += hash(r->rdx);
    u += hash(r->rbx);
    u += hash(r->rbp);
    u += hash(r->rsi);
    u += hash(r->rdi);
    u += hash(r->r8);
    u += hash(r->r9);
    u += hash(r->r10);
    u += hash(r->r11);
    u += hash(r->r12);
    u += hash(r->r13);
    u += hash(r->r14);
    u += hash(r->r15);

    for (size_t i = 0; i < 32; i++) {
        u += hash(r->xmm[i]);
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

struct Regs regs;

void
end(struct Regs* r)
{
    struct Mem* m = memfirst;
    uint64_t u = hashregs(r);
    while (m) {
        u += hashmem(m->p, m->sz);
        m = m->next;
    }

    printf("ended: %lx\n", u);
    printf("illegal: %d\n", illegal);
    exit(0);
}

static void
check(struct Regs r, uintptr_t pc)
{
    if (r.r14 != DATA_BASE) {
        fprintf(stderr, "%lx: r14 modified: %lx\n", pc, r.r14);
        end(&r);
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
    uint8_t* pc = (uint8_t*) uc->uc_mcontext.gregs[REG_RIP];

    printf("%p: %s\n", pc, strsigno(signo));

    struct Regs regs;
    regs.rsp = uc->uc_mcontext.gregs[REG_RSP];
    regs.rax = uc->uc_mcontext.gregs[REG_RAX];
    regs.rcx = uc->uc_mcontext.gregs[REG_RCX];
    regs.rdx = uc->uc_mcontext.gregs[REG_RDX];
    regs.rbx = uc->uc_mcontext.gregs[REG_RBX];
    regs.rbp = uc->uc_mcontext.gregs[REG_RBP];
    regs.rsi = uc->uc_mcontext.gregs[REG_RSI];
    regs.rdi = uc->uc_mcontext.gregs[REG_RDI];
    regs.r8 = uc->uc_mcontext.gregs[REG_R8];
    regs.r9 = uc->uc_mcontext.gregs[REG_R9];
    regs.r10 = uc->uc_mcontext.gregs[REG_R10];
    regs.r11 = uc->uc_mcontext.gregs[REG_R11];
    regs.r12 = uc->uc_mcontext.gregs[REG_R12];
    regs.r13 = uc->uc_mcontext.gregs[REG_R13];
    regs.r14 = uc->uc_mcontext.gregs[REG_R14];
    regs.r15 = uc->uc_mcontext.gregs[REG_R15];

    switch (signo) {
    case SIGSEGV:
        if (addr == (uintptr_t) pc) {
            printf("YES ENDED\n");
            end(&regs);
        }
        break;
    }

    FdInstr instr;
    int r = fd_decode(pc, 15, 64, 0, &instr);
    if (r <= 0) {
        printf("unknown instruction\n");
        exit(1);
    }

    uc->uc_mcontext.gregs[REG_RIP] += r;
}

extern void jumpto(struct Regs* regs);
extern void finish();

static uint8_t endcode[16] = {
    0xff, 0x25, 0x02, 0x00, 0x00, 0x00, // jmp *0x2(%rip)
};

bool
runprog(void* prog, size_t sz)
{
    void* buf = mmap((void*) CODE_BASE, sz + sizeof(endcode), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (buf == (void*) -1) {
        perror("mmap");
        return false;
    }
    memcpy(buf, prog, sz);
    *((uint64_t*) &endcode[8]) = (uint64_t) &finish;
    memcpy(buf + sz, endcode, sizeof(endcode));
    mprotect(buf, sz, PROT_READ | PROT_EXEC);
    codesize = sz;

    stack_t ss;
    const size_t STACK_SIZE = SIGSTKSZ + 1024 * 1024;
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

    regs.rsp = rand64();
    regs.rax = rand64();
    regs.rcx = rand64();
    regs.rdx = rand64();
    regs.rbx = rand64();
    regs.rbp = rand64();
    regs.rsi = rand64();
    regs.rdi = rand64();
    regs.r8 = rand64();
    regs.r9 = rand64();
    regs.r10 = rand64();
    regs.r11 = rand64();
    regs.r12 = rand64();
    regs.r13 = rand64();
    regs.r14 = rand64();
    regs.r15 = rand64();

    for (size_t i = 0; i < 32; i++) {
        regs.xmm[i] = rand64();
    }

    regs.rsp = mask(DATA_BASE, rand64() & 0xfffffff0) + 8;
    regs.r11 = CODE_BASE;
    regs.r14 = DATA_BASE;

    jumpto(&regs);

    end(&regs);

    return true;
}
