#include <stdio.h>
#include <stdlib.h>

#include "fd.h"
#include "file.h"
#include "syscalls/syscalls.h"

void
fdassign(struct FDTable* t, int fd, struct FDFile* ff)
{
    LOCK_WITH_DEFER(&t->lk, t_lk);
    LOCK_WITH_DEFER(&ff->lk_refs, lk_refs);
    ff->refs++;
    t->files[fd] = ff;
}

int
fdalloc(struct FDTable* t)
{
    LOCK_WITH_DEFER(&t->lk, lk);
    int i;
    for (i = 0; i < TUX_NOFILE; i++) {
        if (t->files[i] == NULL)
            break;
    }
    if (i >= TUX_NOFILE)
        return -1;
    return i;
}

static bool
fdhas_x(struct FDTable* t, int fd)
{
    return fd >= 0 && fd < TUX_NOFILE && t->files[fd] != NULL;
}

static bool
fdremove_x(struct FDTable* t, int fd)
{
    if (fdhas_x(t, fd)) {
        fdrelease(t->files[fd]);
        t->files[fd] = NULL;
        return true;
    }
    return false;
}

struct FDFile*
fdget(struct FDTable* t, int fd)
{
    LOCK_WITH_DEFER(&t->lk, lk);
    if (fdhas_x(t, fd)) {
        LOCK_WITH_DEFER(&t->files[fd]->lk_refs, lk_refs);
        t->files[fd]->refs++;
        return t->files[fd];
    }
    return NULL;
}

void
fdrelease(struct FDFile* f)
{
    if (!f)
        return;
    lock(&f->lk_refs);
    f->refs--;
    if (f->refs == 0) {
        unlock(&f->lk_refs);
        if (f->close)
            f->close(f->dev);
        free(f);
    } else {
        unlock(&f->lk_refs);
    }
}

bool
fdremove(struct FDTable* t, int fd)
{
    LOCK_WITH_DEFER(&t->lk, lk);
    return fdremove_x(t, fd);
}

bool
fdhas(struct FDTable* t, int fd)
{
    LOCK_WITH_DEFER(&t->lk, lk);
    return fdhas_x(t, fd);
}

void
fdclear(struct FDTable* t)
{
    LOCK_WITH_DEFER(&t->lk, lk);
    for (int fd = 0; fd < TUX_NOFILE; fd++) {
        fdremove_x(t, fd);
    }
}

void
fdinit(struct Tux* tux, struct FDTable* t)
{
    pthread_mutex_init(&t->lk, NULL);

    fdassign(t, 0, tux->fstdin);
    fdassign(t, 1, tux->fstdout);
    fdassign(t, 2, tux->fstderr);
}
