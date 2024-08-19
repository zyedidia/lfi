#pragma once

#include "sobox.h"

enum {
    NOFILE = 128,
};

typedef struct {
    void* dev;
    size_t refs;
    ssize_t (*read)(void*, SoboxLib*, uint8_t*, size_t);
    ssize_t (*write)(void*, SoboxLib*, uint8_t*, size_t);
    ssize_t (*lseek)(void*, SoboxLib*, off_t, int);
    int (*close)(void*, SoboxLib*);
    int (*mapfd)(void*);
} FDFile;

typedef struct {
    FDFile* files[NOFILE];
} FDTable;

void fdassign(FDTable* t, int fd, FDFile* ff);

int fdalloc(FDTable* t);

FDFile* fdget(FDTable* t, int fd);

void fdrelease(FDFile* f, SoboxLib* l);

bool fdremove(FDTable* t, int fd, SoboxLib* l);

bool fdhas(FDTable* t, int fd);

void fdclear(FDTable* t, SoboxLib* l);

void fdinit(FDTable* t);
