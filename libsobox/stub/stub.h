#pragma once

#include <stdlib.h>

enum {
    SOBOXDL = 0xffff,
};

typedef struct {
    void* (*dlopen)(const char*, int);
    int (*dlclose)(void*);
    void* (*dlsym)(void*, const char*);
    void* (*malloc)(size_t);
    void (*free)(void*);
} SoboxFns;
