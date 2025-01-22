#pragma once

#include "lfi_small.h"

typedef struct {
    LFIProc** elements;
    size_t size;
    size_t cap;
} Stack;

bool stackpush(Stack* s, LFIProc* p);
LFIProc* stackpop(Stack* s);
