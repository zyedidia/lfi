#pragma once

#include <stdlib.h>

typedef struct {
    char* (*readfile)(const char* filename, size_t* size);
} Sobox;

void sbx_init(Sobox* sbx);

void* sbx_dlopen(Sobox* sbx, const char* filename, int flags);

int sbx_dlclose(Sobox* sbx, void* handle);

void* sbx_dlsym(Sobox* sbx, void* handle, const char* symbol, const char* ty);

void* sbx_malloc(Sobox* sbx, size_t size);

void sbx_free(Sobox* sbx, void* ptr);

void sbx_delete(Sobox* sbx);
