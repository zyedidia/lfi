#ifndef LFI_H
#define LFI_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

struct lfi_regs {
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

enum {
    LFI_VASPACE_MAX = 16,
};

enum {
    LFI_ERR_NOMEM         = -1,
    LFI_ERR_NOSLOT        = -2,
    LFI_ERR_CANNOT_MAP    = -3,
    LFI_ERR_MAX_VASPACE   = -4,
    LFI_ERR_INVALID_ELF   = -5,
    LFI_ERR_VERIFY        = -6,
    LFI_ERR_PROTECTION    = -7,
    LFI_ERR_INVALID_STACK = -8,
};

enum {
    LFI_PROT_NONE  = 0,
    LFI_PROT_READ  = 1,
    LFI_PROT_WRITE = 2,
    LFI_PROT_EXEC  = 4,
};

struct lfi;

struct lfi_proc;

typedef uint64_t (*rtcall_handler_f)(void* ctxp, uint64_t, uint64_t[6]);

struct lfi_options {
    int noverify;
    int fast_yield;
    size_t page_size;
    size_t stack_size;
    rtcall_handler_f syscall_handler;
};

struct lfi_proc_info {
    void* stack;
    size_t stack_size;
    uint64_t last_va;
    uint64_t elf_entry;
    uint64_t elf_base;
    uint64_t elf_phoff;
    uint16_t elf_phnum;
    uint16_t elf_phentsize;
};

// Create a new LFI engine with the following options. Returns the new object
// or NULL if there was an error allocating.
struct lfi* lfi_new(struct lfi_options options);

// Automatically reserves as much virtual address space from the OS as possible
// for sandbox slots.
int lfi_auto_add_vaspaces(struct lfi* lfi);

// Add a new region of virtual address space for allocating sandboxes. It must
// be possible to mmap the given region. The number of VA regions cannot exceed
// LFI_VASPACE_MAX. It is recommended to use `lfi_auto_add_vaspaces` unless you
// want direct control over what virtual address regions are reserved.
int lfi_add_vaspace(struct lfi* lfi, void* base, size_t size);

// Return the maximum number of processes that can be allocated.
uint64_t lfi_max_procs(struct lfi* lfi);

// Return the current number of processes that are currently allocated.
uint64_t lfi_num_procs(struct lfi* lfi);

// Create a new LFI process from the given ELF file. The process is also
// associated with a context pointer `ctxp` that is passed to the user callback
// when a runtime call happens. Additional info about the ELF file is placed in
// `info`. If an error occurs, the function returns null and places the error
// code in `err` (if it is non-null).
struct lfi_proc* lfi_add_proc(struct lfi* lfi, uint8_t* prog, size_t size, void* ctxp, struct lfi_proc_info* info, int* err);

// Remove a process from the LFI engine. This frees the sandbox slot used by
// the given process and frees the process as well.
void lfi_remove_proc(struct lfi* lfi, struct lfi_proc* proc);

// Delete the LFI engine and free all its resources.
void lfi_delete(struct lfi* lfi);

// Start running a given process.
void lfi_proc_start(struct lfi_proc* proc, uintptr_t entry, void* stack, size_t stack_size);

// Fetch the register file for the given process and put it in `regs`.
void lfi_proc_get_regs(struct lfi_proc* proc, struct lfi_regs* regs);

// Copy the contents of `regs` into the process's register file.
void lfi_proc_set_regs(struct lfi_proc* proc, struct lfi_regs* regs);

// Copy an LFI process. This function returns a new process initialized with
// the current state of `proc`. It will be given a new sandbox slot. This
// function can be used to implement a "fork" operation.
struct lfi_proc* lfi_proc_copy(struct lfi_proc* proc, void* new_ctxp);

// Reset a process's address space and load the given ELF file into its
// address space. This can be used to implement an "execve" operation.
int lfi_proc_exec(struct lfi_proc* proc, uint8_t* prog, size_t size, struct lfi_proc_info* info);

#endif
