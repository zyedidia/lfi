#pragma once

#include "lfi.h"
#include "fd.h"
#include "mmap.h"

typedef struct {
    LFIEngine* l_engine;
} LFIXEngine;

typedef struct LFIXProc {
    LFIProc* l_proc;
    uintptr_t base;
    size_t size;
    LFIXEngine* lfix;

    FDTable fdtable;

    uintptr_t brkbase;
    size_t brksize;
    MMAddrSpace mm;
} LFIXProc;

bool lfix_init(LFIXEngine* lfi);

LFIXProc* lfix_proc_newfile(LFIXEngine* lfix, int fd, int argc, char** argv);

void lfix_schedule(LFIXEngine* engine);
