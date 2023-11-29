#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <signal.h>

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif
#define ALIGN (PAGE_SIZE - 1)

enum {
    GB = (uint64_t) 1024 * 1024 * 1024,
    MB = (uint64_t) 1024 * 1024,
    BOX_SIZE = (uint64_t) 4 * GB,
    GUARD_SIZE = (uint64_t) 4 * GB,
    BRK_SIZE = (uint64_t) 512 * MB,
    STACK_SIZE = (uint64_t) 2 * MB,

    NUM_BOXES = (uint64_t) 1024 * 16,
    BOXES_START = (uint64_t) 8ULL * GB,
};

static inline uintptr_t truncpg(uintptr_t addr) {
    return addr & ~ALIGN;
}

static inline uintptr_t ceilpg(uintptr_t addr) {
    return (addr + ALIGN) & ~ALIGN;
}

struct regs {
    uint64_t x0;
    uint64_t x1;
    uint64_t x2;
    uint64_t x3;
    uint64_t x4;
    uint64_t x5;
    uint64_t x6;
    uint64_t x7;
    uint64_t x8;
    uint64_t x9;
    uint64_t x10;
    uint64_t x11;
    uint64_t x12;
    uint64_t x13;
    uint64_t x14;
    uint64_t x15;
    uint64_t x16;
    uint64_t x17;
    uint64_t x18;
    uint64_t x19;
    uint64_t x20;
    uint64_t x21;
    uint64_t x22;
    uint64_t x23;
    uint64_t x24;
    uint64_t x25;
    uint64_t x26;
    uint64_t x27;
    uint64_t x28;
    uint64_t x29;
    uint64_t x30;
    uint64_t sp;
    uint64_t nzcv;
    uint64_t fpsr;
    uint64_t tpidr;
    uint64_t vector[64];
};

struct context {
    uint64_t x30;
    uint64_t sp;
    uint64_t x19;
    uint64_t x20;
    uint64_t x21;
    uint64_t x22;
    uint64_t x23;
    uint64_t x24;
    uint64_t x25;
    uint64_t x26;
    uint64_t x27;
    uint64_t x28;
    uint64_t nzcv;
    uint64_t fpsr;
    uint64_t d8;
    uint64_t d9;
    uint64_t d10;
    uint64_t d11;
    uint64_t d12;
    uint64_t d13;
    uint64_t d14;
    uint64_t d15;
    void* sp_base;
};

struct mem_region {
    uint64_t base;
    size_t len;
    int prot;

    bool allocated;

    struct mem_region* next;
    struct mem_region* prev;
};

enum {
    KSTACK_SIZE = 8192 * 16, // includes guard page
    KSTACK_CANARY = 0xdeadbeef,
};

struct __attribute__((aligned(16))) stack {
    uint8_t data[KSTACK_SIZE];
};

struct buddy;

enum procstate {
    STATE_RUNNABLE,
    STATE_BLOCKED,
    STATE_EXITED,
};

struct proc {
    uintptr_t kstack_ptr;
    struct regs regs;
    struct context context;
    struct mem_region sys;
    struct mem_region bin;
    struct mem_region brk_heap;
    struct mem_region mmap_heap;
    struct mem_region stack;
    struct mem_region guard;

    enum procstate state;

    struct buddy* mmap;
    uint64_t brk;

    struct mem_region* mmap_front;
    struct mem_region* mmap_back;

    struct proc* parent;
    size_t children;
    void* wq;

    struct proc* next;
    struct proc* prev;
};

struct queue {
    struct proc* front;
    struct proc* back;
    size_t size;
};

static inline int proc_getpid(struct proc* p) {
    return p->sys.base >> 32;
}

struct manager {
    struct proc* running;

    struct queue runq;
    struct queue waitq;
    struct queue exitq;

    struct buddy* proc_allocator;
};

uintptr_t proc_newbase(struct manager* m);

void timer_setup(long us);
void signal_enable();
void signal_disable();
void signal_setstack(void* stack, size_t size);
void signal_setup();

void schedule(struct manager* m);
void proc_yield();
void proc_wait(struct proc* p, struct queue* q, enum procstate state);

struct mem_region mem_map(uintptr_t base, size_t len, int prot, int flags);
void mem_unmap(struct mem_region* mem);

void sys_fork(struct proc* p);

extern struct manager manager;
