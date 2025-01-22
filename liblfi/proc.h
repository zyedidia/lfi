#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>

#include "lfi_tux.h"

#include "config.h"
#include "lfi.h"
#include "types.h"
#include "futex.h"

enum {
    TUX_PATH_MAX   = 4096,
    TUX_NOFILE     = 128,
    TUX_BRKMAXSIZE = 512ULL * 1024 * 1024,
};

struct TuxProc;

struct FDFile {
    void* dev;
    size_t refs;
    pthread_mutex_t lk_refs;

    ssize_t (*read)(void*, uint8_t*, size_t);
    ssize_t (*write)(void*, uint8_t*, size_t);
    ssize_t (*lseek)(void*, off_t, int);
    int     (*close)(void*);
    int     (*stat_)(void*, struct Stat*);
    ssize_t (*getdents)(void*, void*, size_t);
    int     (*chown)(void*, tux_uid_t, tux_gid_t);
    int     (*chmod)(void*, tux_mode_t);
    int     (*truncate)(void*, off_t);
    int     (*sync)(void*);

    struct HostFile* (*file)(void*);
};

struct FDTable {
    struct FDFile* files[TUX_NOFILE];
    pthread_mutex_t lk;
};

struct Dir {
    struct HostFile* file;
    struct FDFile* fd;
    pthread_mutex_t lk;
};

struct TuxProc {
    struct LFIAddrSpace* p_as;
    lfiptr_t brkbase;
    size_t brksize;
    pthread_mutex_t lk_as;
    pthread_mutex_t lk_brk;

    struct FDTable fdtable;
    struct Dir cwd;

#ifdef CONFIG_THREADS
    struct Futexes futexes;
#endif

    struct Tux* tux;
    struct LFIAddrSpaceInfo p_info;
};

struct TuxThread {
    struct LFIContext* p_ctx;
    lfiptr_t stack;

    uintptr_t ctid;
    int tid;

    struct TuxProc* proc;
};

int procmapat(struct TuxProc* p, lfiptr_t start, size_t size, int prot, int flags, int fd, off_t offset);

int procmapany(struct TuxProc* p, size_t size, int prot, int flags, int fd, off_t offset, lfiptr_t* o_mapstart);

int procunmap(struct TuxProc* p, lfiptr_t start, size_t size);

struct TuxThread* procnewthread(struct TuxThread* p);
