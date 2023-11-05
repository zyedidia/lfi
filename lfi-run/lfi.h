#pragma once

#include <stdint.h>
#include <stddef.h>

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
    uint64_t vector[32];
};

struct mem_region {
    char* base;
    size_t len;
};

enum {
    KSTACK_SIZE = 8192,
    KSTACK_CANARY = 0xdeadbeef,
};

struct __attribute__((aligned(16))) stack {
    uint8_t data[KSTACK_SIZE];
};

struct proc {
    uintptr_t kstack_ptr;
    struct regs regs;
    struct mem_region sys;
    struct mem_region mem;
    struct mem_region guard;

    uint64_t brk;

    uint64_t kstack_canary;

    struct stack kstack;
};

struct manager {
    struct proc proc;
};
