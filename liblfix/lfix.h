#pragma once

#include <sys/stat.h>

#include "lfi.h"

enum {
    LFI_PATH_MAX = 4096,
    NOFILE = 128,
};

struct LFIXProc;

typedef struct {
    void* dev;
    size_t refs;
    ssize_t (*read)(void*, struct LFIXProc*, uint8_t*, size_t);
    ssize_t (*write)(void*, struct LFIXProc*, uint8_t*, size_t);
    ssize_t (*lseek)(void*, struct LFIXProc*, off_t, int);
    int (*close)(void*, struct LFIXProc*);
    int (*stat)(void*, struct LFIXProc*, struct stat*);
    ssize_t (*getdents)(void*, struct LFIXProc*, void*, size_t);
    int (*mapfd)(void*);
} FDFile;

typedef struct {
    FDFile* files[NOFILE];
} FDTable;

typedef struct {
    LFIEngine* l_engine;
    bool pause;
    bool (*readfile)(const char* filename, uint8_t** buf, size_t* size);
    bool poc;
} LFIXEngine;

typedef struct {
    char name[LFI_PATH_MAX];
    int fd;
} Cwd;

typedef struct LFIXProc {
    LFIProc* l_proc;
    uintptr_t base;
    size_t size;
    LFIXEngine* lfix;

    FDTable fdtable;
    Cwd cwd;

    uintptr_t brkbase;
    size_t brksize;
} LFIXProc;

bool lfix_init(LFIXEngine* lfi);

LFIXProc* lfix_proc_newfile(LFIXEngine* lfix, uint8_t* prog, size_t progsz, int argc, char** argv);

void lfix_schedule(LFIXEngine* engine);
