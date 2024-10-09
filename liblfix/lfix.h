#pragma once

#include "lfi.h"
#include "fd.h"

enum {
    LFI_PATH_MAX = 4096,
};

typedef struct {
    LFIEngine* l_engine;
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
