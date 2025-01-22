#pragma once

#include <sys/stat.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "proc.h"

void fdassign(struct FDTable* t, int fd, struct FDFile* ff);

int fdalloc(struct FDTable* t);

struct FDFile* fdget(struct FDTable* t, int fd);

void fdrelease(struct FDFile* f, struct TuxProc* p);

bool fdremove(struct FDTable* t, int fd, struct TuxProc* p);

bool fdhas(struct FDTable* t, int fd);

void fdclear(struct FDTable* t, struct TuxProc* p);

void fdinit(struct Tux* tux, struct FDTable* t);
