#pragma once

#include "lfi.h"

typedef struct {
    LFIProc** elements;
    size_t size;
    size_t cap;
} Stack;

bool stackpush(Stack* s, LFIProc* p);
LFIProc* stackpop(Stack* s);
