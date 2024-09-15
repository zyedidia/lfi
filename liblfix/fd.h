#pragma once

#include <sys/stat.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

struct LFIXProc;

enum {
    NOFILE = 128,
};

typedef struct {
    void* dev;
    size_t refs;
    ssize_t (*read)(void*, struct LFIXProc*, uint8_t*, size_t);
    ssize_t (*write)(void*, struct LFIXProc*, uint8_t*, size_t);
    ssize_t (*lseek)(void*, struct LFIXProc*, off_t, int);
    int (*close)(void*, struct LFIXProc*);
    int (*stat)(void*, struct LFIXProc*, struct stat*);
    int (*mapfd)(void*);
} FDFile;

typedef struct {
    FDFile* files[NOFILE];
} FDTable;

void lfix_fdassign(FDTable* t, int fd, FDFile* ff);

int lfix_fdalloc(FDTable* t);

FDFile* lfix_fdget(FDTable* t, int fd);

void lfix_fdrelease(FDFile* f, struct LFIXProc* p);

bool lfix_fdremove(FDTable* t, int fd, struct LFIXProc* p);

bool lfix_fdhas(FDTable* t, int fd);

void lfix_fdclear(FDTable* t, struct LFIXProc* p);

void lfix_fdinit(FDTable* t);
