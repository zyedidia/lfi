#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#include "lfi.h"
#include "mem.h"
#include "buddy.h"

static uint64_t proc_addr(struct proc* proc, uint64_t addr) {
    return (uint32_t) (addr) | (uint64_t) proc->sys.base;
}

void syscall_entry();
void yield_fast(int pid);
void enter_sandbox(struct proc* proc);

void sys_fork(struct proc* p) {
    struct proc* child = calloc(1, sizeof(struct proc));
    if (!child) {
        p->regs.x0 = -1;
    }
    // * find free base
    uintptr_t base = proc_newbase(&manager);
    if (!base)
        goto err;

    child->brk = p->brk;
    child->state = STATE_RUNNABLE;

    // * copy/share regions

    int flags = MAP_FIXED | MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
    child->sys = mem_map(base, PAGE_SIZE, PROT_READ | PROT_WRITE, flags);
    child->guard = mem_map(base + BOX_SIZE, GUARD_SIZE, PROT_NONE, flags);

    // TODO: unsafe, rewrite this to preserve correct protections
    child->bin = mem_map(proc_addr(child, p->bin.base), p->bin.len, PROT_READ | PROT_WRITE | PROT_EXEC, flags);
    memcpy((void*) child->bin.base, (void*) p->bin.base, p->bin.len);

    struct mem_region* m = p->mmap_front;
    while (m) {
        struct mem_region* region = malloc(sizeof(struct mem_region));
        assert(region);
        region->len = m->len;
        region->allocated = m->allocated;
        region->prot = m->prot;
        region->base = proc_addr(child, m->base);
        void* p = mmap((void*) region->base, region->len, PROT_READ | PROT_WRITE, flags, -1, 0);
        assert(p);
        mmap_push_back(child, region);
        memcpy((void*) region->base, (void*) m->base, m->len);
        mprotect((void*) region->base, region->len, region->prot);
        m = m->next;
    }

    child->brk_heap = mem_map(proc_addr(child, p->brk_heap.base), p->brk_heap.len, PROT_READ | PROT_WRITE, flags);
    memcpy((void*) child->brk_heap.base, (void*) p->brk_heap.base, p->brk - p->brk_heap.base);

    child->stack = mem_map(proc_addr(child, p->stack.base), p->stack.len, PROT_READ | PROT_WRITE, flags);
    memcpy((void*) child->stack.base, (void*) p->stack.base, p->stack.len);

    // copy mmap allocator
    uint64_t mmap_base = child->brk_heap.base + child->brk_heap.len;
    void* meta = malloc(buddy_sizeof_alignment(child->stack.base - mmap_base, PAGE_SIZE));
    assert(meta);
    child->mmap = buddy_copy(meta, (void*) mmap_base, p->mmap);
    assert(child->mmap);

    child->mmap_heap = (struct mem_region){
        .base = mmap_base,
        .len = p->mmap_heap.len,
    };

    // * initialize/protect sys page

    uintptr_t* ptrs = (uintptr_t*) child->sys.base;
    ptrs[0] = (uintptr_t) syscall_entry;
    ptrs[1] = (uintptr_t) yield_fast;
    ptrs[16+0] = (uintptr_t) child;
    uintptr_t tpidr;
    asm volatile ("mrs %0, tpidr_el0" : "=r"(tpidr));
    ptrs[16+1] = tpidr;
    mprotect((char*) child->sys.base, child->sys.len, PROT_READ);

    // * copy registers, change base

    memcpy(&child->regs, &p->regs, sizeof(struct regs));
    child->regs.x18 = proc_addr(child, child->regs.x18);
    child->regs.x30 = proc_addr(child, child->regs.x30);
    child->regs.x23 = proc_addr(child, child->regs.x23);
    child->regs.x24 = proc_addr(child, child->regs.x24);
    child->regs.x21 = base;
    child->regs.sp = proc_addr(child, child->regs.sp);

    char* kstack = aligned_alloc(PAGE_SIZE, KSTACK_SIZE);
    memset(kstack, 0, KSTACK_SIZE);
    mprotect(kstack, PAGE_SIZE, PROT_NONE); // guard page
    child->kstack_ptr = (uintptr_t) kstack + KSTACK_SIZE;

    child->context = (struct context){
        .sp = child->kstack_ptr,
        .x30 = (uintptr_t) enter_sandbox,
        .sp_base = kstack,
    };

    child->regs.x0 = 0;
    p->regs.x0 = proc_getpid(child);

    runq_push_front(&manager, child);
    return;
err:
    p->regs.x0 = -1;
}
