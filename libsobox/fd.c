#include <stdio.h>

#include "fd.h"
#include "file.h"

void
fdassign(FDTable* t, int fd, FDFile* ff)
{
    ff->refs++;
    t->files[fd] = ff;
}

int
fdalloc(FDTable* t)
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
fdget(FDTable* t, int fd)
{
    if (fdhas(t, fd))
        return t->files[fd];
    return NULL;
}

void
fdrelease(FDFile* f, SoboxProc* p)
{
    f->refs--;
    if (f->refs == 0) {
        if (f->close)
            f->close(f->dev, p);
        free(f);
    }
}

bool
fdremove(FDTable* t, int fd, SoboxProc* p)
{
    if (fdhas(t, fd)) {
        fdrelease(t->files[fd], p);
        t->files[fd] = NULL;
        return true;
    }
    return false;
}

bool
fdhas(FDTable* t, int fd)
{
    return fd >= 0 && fd < NOFILE && t->files[fd] != NULL;
}

void
fdclear(FDTable* t, SoboxProc* p)
{
    for (int fd = 0; fd < NOFILE; fd++) {
        fdremove(t, fd, p);
    }
}

void
fdinit(FDTable* t)
{
    fdassign(t, 0, filefdnew(fileno(stdin)));
    fdassign(t, 1, filefdnew(fileno(stdout)));
    fdassign(t, 2, filefdnew(fileno(stderr)));
}
