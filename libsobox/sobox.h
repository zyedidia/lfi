#pragma once

#include <stdlib.h>

#include "lfi.h"

typedef struct {
    LFIEngine* lfimgr;
} Sobox;

// sbx_init initializes the Sobox library manager.
//
// Multiple libraries can be loaded with this manager, and they will each be
// placed into a separate sandbox. Returns false if an error occurred (out of
// memory).
bool sbx_init(Sobox* sbx);

// sbx_dlopen opens and loads a new sandboxed shared library.
void* sbx_dlopen(Sobox* sbx, const char* filename, int flags);

// sbx_dlclose closes a sandboxed library.
int sbx_dlclose(void* lib);

// sbx_dlsym looks up a symbol in a sandboxed library.
//
// This should only be used to look up non-function symbols. To look up a
// function, use sbx_dlsymfn.
void* sbx_dlsym(void* lib, const char* symbol);

// sbx_dlsymfn looks up a function symbol in a sandboxed library.
//
// The type signature must be provided in the 'ty' parameter. This type
// information is used to generate a trampoline that properly copies arguments
// into the sandbox according to the calling convention.
void* sbx_dlsymfn(void* lib, const char* symbol, const char* ty);

// sbx_dlsymfnstk looks up a function symbol in a sandboxed library.
//
// The amount of data to copy from the stack is passed in 'stkamt'. This amount
// can be derived from the type signature of the function and the calling
// convention. The sbx_dlsymfn derives this automatically from a 'ty' string
// but this function allows you to provide the information manually.
void* sbx_dlsymfnstk(void* lib, const char* symbol, size_t stkamt);

// sbx_malloc allocates memory inside the sandbox.
void* sbx_malloc(void* lib, size_t size);

// sbx_free frees memory that was allocated inside the sandbox.
void sbx_free(void* lib, void* ptr);

// sbx_deinit deletes the Sobox sandbox manager.
void sbx_deinit(Sobox* sbx);

// this function is temporary and will be removed in a future version
uint64_t sbx_dlinvoke(void* handle, void* symbol, uint64_t a0, uint64_t a1);
