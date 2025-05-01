#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "lfi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct TuxBinding {
    char* hostpath;
    char* tuxpath;
};

struct TuxFS {
    char* root;
    char* wd;
    struct TuxBinding* bindings;
    size_t nbindings;

    struct HostFile* (*open)(const char* filename, int flags, int mode);
};

struct TuxOptions {
    size_t pagesize;
    size_t stacksize;
    bool pause_on_exit;
    bool verbose;
    bool strace;
    bool perf;
    bool libinit;
    bool poc;
    struct TuxFS fs;
    char* gdbfile;
};

struct LFIPlatform;

struct Tux;

struct TuxThread;

struct Tux* lfi_tux_new(struct LFIPlatform* plat, struct TuxOptions opts);

struct TuxThread* lfi_tux_proc_new(struct Tux* tux, uint8_t* prog, size_t progsize, int argc, char** argv);

void lfi_tux_proc_free(struct TuxThread* p);

uint64_t lfi_tux_proc_run(struct TuxThread* p);

void lfi_tux_syscall(struct LFIContext* ctx);

struct LFIContext* lfi_tux_ctx(struct TuxThread* p);

void lfi_tux_libinit(struct Tux* tux, bool val);

struct LFILibCalls {
    // The lfi_ctx function has a non-standard calling convention, and should
    // only be called directly from assembly.
    void* lfi_ctx_fn;
    struct LFIPlatform*  (*lfi_new_plat)(struct LFIPlatOptions);
    struct Tux*          (*lfi_tux_new)(struct LFIPlatform*, struct TuxOptions);
    char*                (*lfi_strerror)(void);
    struct TuxThread*    (*lfi_tux_proc_new)(struct Tux*, uint8_t*, size_t, int, char**);
    struct LFIContext*   (*lfi_tux_ctx)(struct TuxThread*);
    void                 (*lfi_tux_libinit)(struct Tux*, bool);
    uint64_t             (*lfi_tux_proc_run)(struct TuxThread*);
    void                 (*lfi_thread_init)(void (*)(void*), void*);
    struct HostFile*     (*lfi_host_fdopen)(int);
    lfiptr_t             (*lfi_as_mapany)(struct LFIAddrSpace* as, size_t size, int prot, int flags, struct HostFile* f, off_t off);
    int                  (*lfi_as_mprotect)(struct LFIAddrSpace* as, lfiptr_t addr, size_t size, int prot);
    struct LFIAddrSpace* (*lfi_ctx_as)(struct LFIContext* ctx);
};

void* lfi_libcalls(void);

#ifdef __cplusplus
}
#endif
