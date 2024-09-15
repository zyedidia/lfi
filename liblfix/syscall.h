#include <stddef.h>
#include <stdio.h>
#include <stdalign.h>

#include "sys.h"
#include "lfix.h"
#include "proc.h"
#include "fd.h"

#include "syswrap.h"

static uintptr_t
truncp(uintptr_t addr, size_t align)
{
    size_t align_mask = align - 1;
    return addr & ~align_mask;
}

static bool
procinbrk(LFIXProc* p, uintptr_t addr, size_t size)
{
    return addr >= p->brkbase && addr + size <= p->brkbase + p->brksize;
}

static uint8_t*
procbufalign(LFIXProc* p, uintptr_t buf, size_t size, size_t align)
{
    buf = procaddr(p, buf);
    if (buf % align != 0)
        return NULL;
    if (size >= p->size || buf + size >= p->base + p->size)
        return NULL;
    return (uint8_t*) buf;
}

static uint8_t*
procbuf(LFIXProc* p, uintptr_t buf, size_t size)
{
    buf = procaddr(p, buf);
    if (size >= p->size || buf + size >= p->base + p->size)
        return NULL;
    return (uint8_t*) buf;
}

static ssize_t
sysread(LFIXProc* p, int fd, uintptr_t bufp, size_t size)
{
    if (size == 0)
        return 0;
    FDFile* f = lfix_fdget(&p->fdtable, fd);
    if (!f)
        return -EBADF;
    if (!f->read)
        return -EPERM;
    uint8_t* buf = procbuf(p, bufp, size);
    if (!buf)
        return -EFAULT;
    return f->read(f->dev, p, buf, size);
}
SYSWRAP_3(sysread, int, uintptr_t, size_t)

static ssize_t
syswrite(LFIXProc* p, int fd, uintptr_t bufp, size_t size)
{
    if (size == 0)
        return 0;
    FDFile* f = lfix_fdget(&p->fdtable, fd);
    if (!f)
        return -EBADF;
    if (!f->write)
        return -EPERM;
    uint8_t* buf = procbuf(p, bufp, size);
    if (!buf)
        return -EFAULT;
    return f->write(f->dev, p, buf, size);
}
SYSWRAP_3(syswrite, int, uintptr_t, size_t)

typedef struct {
    uintptr_t base;
    size_t len;
} Iovec;

static ssize_t
sysreadv(LFIXProc* p, int fd, uintptr_t iovp, size_t iovcnt)
{
    uint8_t* iovb = procbufalign(p, iovp, iovcnt * sizeof(Iovec), alignof(Iovec));
    if (!iovb)
        return -EFAULT;
    Iovec* iov = (Iovec*) iovb;
    ssize_t total = 0;

    for (size_t i = 0; i < iovcnt; i++) {
        ssize_t n = sysread(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}
SYSWRAP_3(sysreadv, int, uintptr_t, size_t)

static ssize_t
syswritev(LFIXProc* p, int fd, uintptr_t iovp, ssize_t iovcnt)
{
    uint8_t* iovb = procbufalign(p, iovp, iovcnt * sizeof(Iovec), alignof(Iovec));
    if (!iovb)
        return -EFAULT;
    Iovec* iov = (Iovec*) iovb;
    ssize_t total = 0;

    for (int i = 0; i < iovcnt; i++) {
        ssize_t n = syswrite(p, fd, iov[i].base, iov[i].len);
        if (n < 0) {
            return n;
        }
        total += n;
    }

    return total;
}
SYSWRAP_3(syswritev, int, uintptr_t, ssize_t)
