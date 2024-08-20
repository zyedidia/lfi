#pragma once

#include <sys/stat.h>

#include "sobox.h"

typedef struct SoboxProc SoboxProc;

enum {
    NOFILE = 128,
};

typedef struct {
    void* dev;
    size_t refs;
    ssize_t (*read)(void*, SoboxProc*, uint8_t*, size_t);
    ssize_t (*write)(void*, SoboxProc*, uint8_t*, size_t);
    ssize_t (*lseek)(void*, SoboxProc*, off_t, int);
    int (*close)(void*, SoboxProc*);
    int (*stat)(void*, SoboxProc*, struct stat*);
    int (*mapfd)(void*);
} FDFile;

typedef struct {
    FDFile* files[NOFILE];
} FDTable;

void fdassign(FDTable* t, int fd, FDFile* ff);

int fdalloc(FDTable* t);

FDFile* fdget(FDTable* t, int fd);

void fdrelease(FDFile* f, SoboxProc* p);

bool fdremove(FDTable* t, int fd, SoboxProc* p);

bool fdhas(FDTable* t, int fd);

void fdclear(FDTable* t, SoboxProc* p);

void fdinit(FDTable* t);
