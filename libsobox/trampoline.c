// Generate trampolines at runtime for sandboxed functions

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/mman.h>

#include "proc.h"

#define N_INSN 19

/*
pushq %r15
pushq %r14
pushq %r13
pushq %r12
pushq %rbx
pushq %rbp

mov proc(%rip), %r12
subq $16, %rsp
mov %rsp, 0(%r12) // kstackp

mov 16+0(%r12), %rsp // stack pointer
mov 16+14*8(%r12), %r14 // base pointer

pushq retfn(%rip)

mov fn(%rip), %r12
jmpq *%r12
int3

proc:
.quad 0
retfn:
.quad 0
fn:
.quad 0
*/
static const uint8_t insns[N_INSN][10] = {
    {0x41, 0x57},                                     // push %r15
    {0x41, 0x56},                                     // push %r14
    {0x41, 0x55},                                     // push %r13
    {0x41, 0x54},                                     // push %r12
    {0x53},                                           // push %rbx
    {0x55},                                           // push %rbp
    {0x4c, 0x8b, 0x25, 0x27, 0x00, 0x00, 0x00},
    {0x48, 0x83, 0xec, 0x10},                         // sub $0x10, %rsp
    {0x49, 0x89, 0x24, 0x24},                         // mov %rsp, 0x0(%r12)
    {0x49, 0x8b, 0x64, 0x24, 0x10},                   // mov 0x10(%r12), %rsp
    {0x4d, 0x8b, 0xb4, 0x24, 0x80, 0x00, 0x00, 0x00}, // mov 0x80(%r12), %r14
    {0xff, 0x35, 0x14, 0x00, 0x00, 0x00},
    {0x4c, 0x8b, 0x25, 0x15, 0x00, 0x00, 0x00},
    {0x41, 0xff, 0xe4},                               // jmp *%r12
    {0xcc},                                           // int3
    {0xcc},                                           // int3
    {0, 0, 0, 0, 0, 0, 0, 0}, // proc
    {0, 0, 0, 0, 0, 0, 0, 0}, // retfn
    {0, 0, 0, 0, 0, 0, 0, 0}, // fn
};

static const size_t insn_sizes[N_INSN] = {
    2, 2, 2, 2, 1, 1, 7, 4, 4, 5, 8, 6, 7, 3, 1, 1, 8, 8, 8
};

static const size_t proc_idx  = 2+2+2+2+1+1+7+4+4+5+8+6+7+3+1+1;
static const size_t retfn_idx = proc_idx + 8;
static const size_t fn_idx    = retfn_idx + 8;

static size_t
trampoline_size()
{
    size_t size = 0;
    for (size_t i = 0; i < N_INSN; i++) {
        size += insn_sizes[i];
    }
    return size;
}

uint8_t*
sbx_trampoline_gen(SoboxProc* proc, void* fn)
{
    fprintf(stderr, "libsobox: generating trampoline for %p\n", fn);
    size_t size = trampoline_size();
    uint8_t* buf = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (buf == (uint8_t*) -1)
        return NULL;
    size_t count = 0;
    for (size_t i = 0; i < N_INSN; i++) {
        assert(count + insn_sizes[i] <= size);
        memcpy(&buf[count], insns[i], insn_sizes[i]);
        count += insn_sizes[i];
    }
    *((uint64_t*) &buf[proc_idx]) = (uint64_t) proc->proc;
    *((uint64_t*) &buf[retfn_idx]) = (uint64_t) proc->fns->ret;
    *((uint64_t*) &buf[fn_idx]) = (uint64_t) fn;
    mprotect(buf, size, PROT_READ | PROT_EXEC);
    return buf;
}
