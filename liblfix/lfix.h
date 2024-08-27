#pragma once

#include "lfi.h"

typedef struct {
    LFIEngine* l_engine;
} LFIXEngine;

typedef struct {
    LFIProc* l_proc;
    uintptr_t base;
} LFIXProc;

bool lfix_init(LFIXEngine* lfi);

LFIXProc* lfix_proc_newfile(LFIXEngine* lfix, const char* filename, int argc, const char** argv, const char** env);

void lfix_schedule(LFIXEngine* engine);
