#pragma once

#include <sys/stat.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "lfix.h"

void lfix_fdassign(FDTable* t, int fd, FDFile* ff);

int lfix_fdalloc(FDTable* t);

FDFile* lfix_fdget(FDTable* t, int fd);

void lfix_fdrelease(FDFile* f, struct LFIXProc* p);

bool lfix_fdremove(FDTable* t, int fd, struct LFIXProc* p);

bool lfix_fdhas(FDTable* t, int fd);

void lfix_fdclear(FDTable* t, struct LFIXProc* p);

void lfix_fdinit(FDTable* t);
