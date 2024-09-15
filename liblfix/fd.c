#include <stdio.h>
#include <stdlib.h>

#include "fd.h"
#include "file.h"

void
lfix_fdassign(FDTable* t, int fd, FDFile* ff)
{
    ff->refs++;
    t->files[fd] = ff;
}

int
lfix_fdalloc(FDTable* t)
{
    int i;
    for (i = 0; i < NOFILE; i++) {
        if (t->files[i] == NULL)
            break;
    }
    if (i >= NOFILE)
        return -1;
    return i;
}

FDFile*
lfix_fdget(FDTable* t, int fd)
{
    if (lfix_fdhas(t, fd))
        return t->files[fd];
    return NULL;
}

void
lfix_fdrelease(FDFile* f, struct LFIXProc* p)
{
    f->refs--;
    if (f->refs == 0) {
        if (f->close)
            f->close(f->dev, p);
        free(f);
    }
}

bool
lfix_fdremove(FDTable* t, int fd, struct LFIXProc* p)
{
    if (lfix_fdhas(t, fd)) {
        lfix_fdrelease(t->files[fd], p);
        t->files[fd] = NULL;
        return true;
    }
    return false;
}

bool
lfix_fdhas(FDTable* t, int fd)
{
    return fd >= 0 && fd < NOFILE && t->files[fd] != NULL;
}

void
lfix_fdclear(FDTable* t, struct LFIXProc* p)
{
    for (int fd = 0; fd < NOFILE; fd++) {
        lfix_fdremove(t, fd, p);
    }
}

void
lfix_fdinit(FDTable* t)
{
    lfix_fdassign(t, 0, lfix_filefdnew(fileno(stdin)));
    lfix_fdassign(t, 1, lfix_filefdnew(fileno(stdout)));
    lfix_fdassign(t, 2, lfix_filefdnew(fileno(stderr)));
}
