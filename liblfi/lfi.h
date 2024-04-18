#ifndef LFI_H
#define LFI_H

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

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

struct lfi_regs;

typedef uint64_t (*lfi_syshandler)(void* ctxp, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

struct lfi_options {
    int noverify;
    int fastyield;
    size_t pagesize;
    size_t stacksize;
    lfi_syshandler syshandler;
    uint64_t gas;
    int poc;
};

struct lfi_proc_info {
    void* stack;
    size_t stacksize;
    uint64_t lastva;
    uint64_t elfentry;
    uint64_t elfbase;
    uint64_t elfphoff;
    uint16_t elfphnum;
    uint16_t elfphentsize;
};

// Create a new LFI engine with the following options. Returns the new object
// or NULL if there was an error allocating.
struct lfi* lfi_new(struct lfi_options options);

// Automatically try to 'size' bytes of virtual address space from the OS. If
// 'size' is 0, this will reserve as much space as possible.
int lfi_auto_add_vaspaces(struct lfi* lfi, size_t size);

// Add a new region of virtual address space for allocating sandboxes. It must
// be possible to mmap the given region. The number of VA regions cannot exceed
// LFI_VASPACE_MAX. It is recommended to use `lfi_auto_add_vaspaces` unless you
// want direct control over what virtual address regions are reserved.
int lfi_add_vaspace(struct lfi* lfi, void* base, size_t size);

// Return the maximum number of processes that can be allocated.
uint64_t lfi_max_procs(struct lfi* lfi);

// Return the current number of processes that are currently allocated.
uint64_t lfi_num_procs(struct lfi* lfi);

// Create a new LFI process in `proc`. The process is also associated with a
// context pointer `ctxp` that is passed to the user callback when a runtime
// call happens. The process will be runnable after calling lfi_proc_exec and
// initializing the registers.
int lfi_add_proc(struct lfi* lfi, struct lfi_proc** proc, void* ctxp);

// Remove a process from the LFI engine. This frees the sandbox slot used by
// the given process and frees the process as well.
void lfi_remove_proc(struct lfi* lfi, struct lfi_proc* proc);

// Delete the LFI engine and free all its resources.
void lfi_delete(struct lfi* lfi);

// Initialize the process's registers.
void lfi_proc_init_regs(struct lfi_proc* proc, uintptr_t entry, uintptr_t sp);

// Start running a given process.
int lfi_proc_start(struct lfi_proc* proc);

// Exit a process. This causes execution to redirect to where lfi_proc_start
// was called, as if that function has now returned. The error code is returned
// from lfi_proc_start.
void lfi_proc_exit(struct lfi_proc* proc, int code);

// Fetch the register file for the given process and put it in `regs`. The regs can then be
// edited by modifying the returned pointer.
struct lfi_regs* lfi_proc_get_regs(struct lfi_proc* proc);

// Copy an LFI process. This function creates a new process initialized with
// the current state of `proc` in the `childp` pointer. It will be given a new
// sandbox slot. This function can be used to implement a "fork" operation.
int lfi_proc_copy(struct lfi* lfi, struct lfi_proc** childp, struct lfi_proc* proc, void* new_ctxp);

// Reset a process's address space and load the given ELF file into its
// address space. This can be used to implement an "execve" operation.
int lfi_proc_exec(struct lfi_proc* proc, uint8_t* prog, size_t size, struct lfi_proc_info* info);

// Return the base address of the process.
uintptr_t lfi_proc_base(struct lfi_proc* proc);

uint64_t lfi_signal_start(uint64_t syspage);

void lfi_signal_end(uint64_t saved);

struct lfi_proc* lfi_sys_proc(uint64_t syspage);

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

#endif
