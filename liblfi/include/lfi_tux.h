#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "lfi.h"

struct TuxFS {
    struct HostFile* (*open)(const char* filename, int flags, int mode);
};

struct TuxOptions {
    size_t pagesize;
    size_t stacksize;
    bool pause_on_exit;
    bool verbose;
    bool strace;
    bool perf;
    struct TuxFS fs;
};

struct LFIPlatform;

struct Tux;

struct TuxThread;

struct Tux* lfi_tux_new(struct LFIPlatform* plat, struct TuxOptions opts);

struct TuxThread* lfi_tux_proc_new(struct Tux* tux, uint8_t* prog, size_t progsize, int argc, char** argv);

uint64_t lfi_tux_proc_run(struct TuxThread* p);

void lfi_tux_syscall(struct LFIContext* ctx);

struct LFIContext* lfi_tux_ctx(struct TuxThread* p);
