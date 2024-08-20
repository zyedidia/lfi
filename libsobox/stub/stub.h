#pragma once

#include <stdlib.h>
#include <stdint.h>

#include "stubasm.h"

typedef struct {
    void* (*dlopen)(const char*, int);
    int (*dlclose)(void*);
    void* (*dlsym)(void*, const char*);
    void* (*malloc)(size_t);
    void (*free)(void*);
    void (*dlret)(uint64_t ret);
    void (*hello)(void);
} SoboxFns;
