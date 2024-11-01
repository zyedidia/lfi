#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include "lfiv.h"

enum {
    LFI_ERR_OK            = 0,
    LFI_ERR_NOMEM         = 1,
    LFI_ERR_NOSLOT        = 2,
    LFI_ERR_CANNOT_MAP    = 3,
    LFI_ERR_MAX_SPACE     = 4,
    LFI_ERR_INVALID_ELF   = 5,
    LFI_ERR_VERIFY        = 6,
    LFI_ERR_PROTECTION    = 7,
    LFI_ERR_INVALID_STACK = 8,
    LFI_ERR_SYSTEM        = 9,
    LFI_ERR_NOVERIFIER    = 10,
    LFI_ERR_INVALID_GAS   = 11,
    LFI_ERR_NOSYSHANDLER  = 12,
    LFI_ERR_INVALID_UPROC = 13,
    LFI_ERR_UPROC_SEG     = 14,
};

typedef uint64_t (*SysHandler)(void* ctxp, uint64_t sysno, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

typedef struct {
    // Do not run verification.
    bool noverify;
    // Enable position-oblivious code. Arm64 only.
    bool poc;
    // Store the runtime call page outside the sandbox. Arm64 only.
    bool sysexternal;
    // Set the power-of-2 size of the sandbox (0 is equivalent to 32, meaning
    // 4GiB sandboxes). x86-64 only.
    uint16_t p2size;
    // Set the pagesize.
    size_t pagesize;
    // Set the stack size.
    size_t stacksize;
    // Set the initial gas. Arm64 only.
    uint64_t gas;
    // User-provided verifier.
    LFIVerifier* verifier;
    // User-provided runtime call handler.
    SysHandler syshandler;
} LFIOptions;

typedef struct {
    void* stack;
    size_t stacksize;
    uint64_t lastva;
    uint64_t extradata;
    uint64_t elfentry;
    uint64_t ldentry;
    uint64_t elfbase;
    uint64_t ldbase;
    uint64_t elfphoff;
    uint16_t elfphnum;
    uint16_t elfphentsize;
} LFIProcInfo;

typedef struct LFIEngine LFIEngine;

typedef struct LFIProc LFIProc;

typedef struct LFIRegs LFIRegs;

#ifdef __cplusplus
extern "C" {
#endif

// lfi_new creates a new LFI engine with the provided options.
//
// Returns null if the engine could not be created.
LFIEngine* lfi_new(LFIOptions options);

// lfi_reserve attempts to reserve 'size' bytes from the address space, in
// possibly discontiguous regions.
//
// If size=0 then it tries to reserve as much space as possible.
bool lfi_reserve(LFIEngine* lfi, size_t size);

// lfi_maxprocs returns the maximum number of processes supported by the
// engine.
uint64_t lfi_maxprocs(LFIEngine* lfi);

// lfi_numprocs returns the number of currently active processes in the engine.
uint64_t lfi_numprocs(LFIEngine* lfi);

// lfi_addproc creates a new process in the engine.
//
// The allocated process is placed in 'proc' and associated with the given
// context pointer.
bool lfi_addproc(LFIEngine* lfi, LFIProc** proc, void* ctxp);

// lfi_adduproc creates a new micro process.
//
// A micro process can only load ELF images that split their code and data
// segments into to regions of size 'codesize' and 'datasize'. The sandbox
// memory for a micro process will be preallocated, and initialization will not
// involve any calls to mmap or mprotect. This means that micro processes can
// start up extremely quickly and scalably (no syscalls and no TLB shootdowns).
// Generally, you can expect a micro process to start in less than 10us for
// code/data sizes of 128KiB or less.
//
// 'codebase' is the base of the code/data regions relative to the sandbox
// base.
bool lfi_adduproc(LFIEngine* lfi, LFIProc** proc, void* ctxp, uintptr_t
        codebase, size_t codesize, size_t datasize);

// lfi_rmproc removes a process and frees all associated data.
void lfi_rmproc(LFIEngine* lfi, LFIProc* proc);

// lfi_copyproc creates a new process in 'childp' that is a duplicate of
// 'proc'. This is used for implementing fork.
bool lfi_copyproc(LFIEngine* lfi, LFIProc** childp, LFIProc* proc, void* childctxp);

// lfi_delete destroys the engine and frees all processes and associated data.
void lfi_delete(LFIEngine* lfi);

// lfi_proc_init initializes a process with the given entrypoint and stack
// pointer.
bool lfi_proc_init(LFIProc* proc, uintptr_t entry, uintptr_t sp);

// lfi_proc_base returns the base address of this process.
uintptr_t lfi_proc_base(LFIProc* proc);

// lfi_proc_size returns the size of this process's sandbox.
size_t lfi_proc_size(LFIProc* proc);

// lfi_proc_tpset sets this process's thread pointer.
void lfi_proc_tpset(LFIProc* proc, uintptr_t tp);

// lfi_proc_start starts running a process.
uint64_t lfi_proc_start(LFIProc* proc);

// lfi_proc returns this thread's currently active proc, started with either
// lfi_proc_start or lfi_proc_invoke.
//
// If no proc is currently active on this thread (e.g., after lfi_proc_exit),
// this function returns NULL.
LFIProc* lfi_proc();

// lfi_proc_exit causes the currently active process to exit.
//
// Control flow will return back to where lfi_proc_start was called, and the
// 'code' value will be returned there.
void lfi_proc_exit(uint64_t code);

// lfi_proc_pause causes the currently active process to pause.
//
// Control flow will return back to where lfi_proc_start was called, and the
// 'code' value will be returned there. However, the currently active LFI
// process (returned by lfi_proc) will not be reset. The user can use this
// value to resume the sandbox manually.
void lfi_proc_pause(uint64_t code);

// lfi_proc_load an ELF binary into the address space for 'proc'.
//
// 'prog/progsz' is the data of the ELF file to be loaded, and
// 'interp/interpsz' is the ELF image of the dynamic linker, or NULL if there
// is no dynamic linker. Output information will be placed in 'o_info'.
bool lfi_proc_loadelf(LFIProc* proc, uint8_t* prog, size_t progsz, uint8_t* interp, size_t interpsz, LFIProcInfo* o_info);

// Note: the following mmap functionality is not available for micro processes.
// Such processes should use an sbrk API written by the user, which allocates
// from the micro process's data region.

// lfi_proc_mapat maps a specific region of memory in a process's address space.
//
// If the mapping includes PROT_EXEC, it will be automatically verified. This
// will map at the given address 'addr' and fail otherwise (forced MAP_FIXED).
// The size and address must be a multiple of the pagesize as defined in the
// LFI options.
void* lfi_proc_mapat(LFIProc* proc, uintptr_t addr, size_t size, int prot, int flags, int fd, off_t offset);

// lfi_proc_mapany maps a new unmapped region of memory in a process's address
// space.
//
// This is similar to mmap without MAP_FIXED.
void* lfi_proc_mapany(LFIProc* proc, size_t size, int prot, int flags, int fd, off_t offset);

// lfi_proc_mprotect sets the protection for a region of a process's address space.
//
// If the protection includes PROT_EXEC, it will be automatically verified.
int lfi_proc_mprotect(LFIProc* proc, uintptr_t addr, size_t size, int prot);

// lfi_proc_munmap unmaps a region of a process's memory.
int lfi_proc_munmap(LFIProc* proc, uintptr_t addr, size_t size);

typedef struct {
    // base address of the mapping (not the region)
    uint64_t base;
    // length of the mapping
    size_t len;
    int prot;
    int flags;
    int fd;
    off_t offset;
} LFIMapInfo;

// lfi_proc_mquery queries the status of a mmap region within the sandbox.
// Returns false if there is no mapping at 'addr' and otherwise returns the
// info in 'info. 'addr' must be page-aligned.
bool lfi_proc_mquery(LFIProc* proc, uint64_t addr, LFIMapInfo* info);

// lfi_proc_invoke invokes 'fn' inside the given process.
//
// When the function returns it will call 'retfn', which must also be a
// function inside the process's address space. The code that the process
// exited with is returned.
uint64_t lfi_proc_invoke(LFIProc* proc, void* fn, void* retfn);

// lfi_err returns the LFI error code.
//
// This function should be used to retrieve error information when a function
// returns false or -1.
int lfi_err();

// lfi_strerror is similar to lfi_err but returns a string description instead
// of an error code.
char* lfi_strerror();

// lfi_proc_regs returns a pointer to the process's registers.
LFIRegs* lfi_proc_regs(LFIProc* proc);

// lfi_regs_arg returns a pointer to the register used for the nth argument
// (0-5) in the calling convention.
uint64_t* lfi_regs_arg(LFIRegs* regs, int n);

// lfi_regs_ret returns the register used for return values in the calling
// convention.
uint64_t* lfi_regs_ret(LFIRegs* regs);

// lfi_regs_sysno returns the register used for the system call number.
uint64_t* lfi_regs_sysno(LFIRegs* regs);

// lfi_regs_sysarg returns the nth system call argument (0-5).
uint64_t* lfi_regs_sysarg(LFIRegs* regs, int n);

// lfi_regs_sysret returns the register used for system call return values.
uint64_t* lfi_regs_sysret(LFIRegs* regs);

// lfi_regs_gas returns the register used to store gas.
uint64_t* lfi_regs_gas(LFIRegs* regs);

// lfi_regs_mask returns the register used to store the mask.
uint64_t* lfi_regs_mask(LFIRegs* regs);
#ifdef __cplusplus
}
#endif

#if defined(__aarch64__) || defined(_M_ARM64)
typedef struct LFIRegs {
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
    uint64_t _pad;
    uint64_t vector[64];
} LFIRegs;

#elif defined(__x86_64__) || defined(_M_X64)

typedef struct LFIRegs {
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
    uint64_t fs;
    uint64_t gs;
} LFIRegs;
#endif
