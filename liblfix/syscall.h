#pragma once

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdalign.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/random.h>
#include <sched.h>

#include "sys.h"
#include "lfix.h"
#include "proc.h"
#include "fd.h"
#include "file.h"

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

enum {
    PATH_MAX = 4096,
};

static const char*
procpath(LFIXProc* p, uintptr_t path)
{
    path = procaddr(p, path);
    const char* str = (const char*) path;
    size_t len = strnlen(str, PATH_MAX);
    if (path + len >= p->base + p->size)
        return NULL;
    if (str[len] != 0)
        return NULL;
    return str;
}

static off_t
syslseek(LFIXProc* p, int fd, off_t offset, int whence)
{
    FDFile* f = lfix_fdget(&p->fdtable, fd);
    if (!f)
        return -EBADF;
    if (!f->lseek)
        return -EPERM;
    return f->lseek(f->dev, p, offset, whence);
}
SYSWRAP_3(syslseek, int, off_t, int);

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
SYSWRAP_3(sysread, int, uintptr_t, size_t);

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
SYSWRAP_3(syswrite, int, uintptr_t, size_t);

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
SYSWRAP_3(sysreadv, int, uintptr_t, size_t);

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
SYSWRAP_3(syswritev, int, uintptr_t, ssize_t);

static uintptr_t
sysbrk(LFIXProc* p, uintptr_t addr)
{
    uintptr_t brkp = p->brkbase + p->brksize;
    if (addr != 0)
        brkp = procaddr(p, addr);
    if (brkp < p->brkbase)
        brkp = p->brkbase;
    if (brkp >= p->brkbase + BRKMAXSIZE)
        brkp = p->brkbase + BRKMAXSIZE;

    size_t newsize = brkp - p->brkbase;
    assert(newsize <= BRKMAXSIZE);

    if (newsize == p->brksize)
        return procuseraddr(p, brkp);

    const int mapflags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED;
    const int mapprot = PROT_READ | PROT_WRITE;

    if (brkp >= p->brkbase + p->brksize) {
        void* map;
        if (p->brksize == 0) {
            map = mmap((void*) p->brkbase, newsize, mapprot, mapflags, -1, 0);
        } else {
            // Since liblfi reserves all sandboxes in one big mmap region, we
            // first need to unmap the piece that we want to expand into,
            // otherwise Linux will decide there is no space for mremap.
            int r = munmap((void*) p->brkbase + p->brksize, newsize - p->brksize);
            assert(r == 0);
            map = mremap((void*) p->brkbase, p->brksize, newsize, 0);
        }
        if (map == (void*) -1)
            return -1;
    }
    p->brksize = newsize;
    return procuseraddr(p, p->brkbase + p->brksize);
}
SYSWRAP_1(sysbrk, uintptr_t);

static int
sysexit(LFIXProc* p, int code)
{
    lfi_proc_exit(code);
    assert(!"unreachable");
}
SYSWRAP_1(sysexit, int);

static int
sysopenat(LFIXProc* p, int dirfd, uintptr_t pathp, int flags, int mode)
{
    if (dirfd != AT_FDCWD)
        return -EBADF;
    const char* path = procpath(p, pathp);
    if (!path)
        return -EFAULT;
    // printf("openat %s\n", path);
    FDFile* f = lfix_filenew(AT_FDCWD, path, flags, mode);
    if (!f)
        return -ENOENT;
    int fd = lfix_fdalloc(&p->fdtable);
    if (fd < 0) {
        lfix_fdrelease(f, p);
        return -EMFILE;
    }
    lfix_fdassign(&p->fdtable, fd, f);
    return fd;
}
SYSWRAP_4(sysopenat, int, uintptr_t, int, int);

static int
sysopen(LFIXProc* p, uintptr_t pathp, int flags, int mode)
{
    return sysopenat(p, AT_FDCWD, pathp, flags, mode);
}
SYSWRAP_3(sysopen, uintptr_t, int, int);

static uintptr_t
sysclose(LFIXProc* p, int fd)
{
    bool ok = lfix_fdremove(&p->fdtable, fd, p);
    if (!ok)
        return -EBADF;
    return 0;
}
SYSWRAP_1(sysclose, int);

static int
sysfstatat(LFIXProc* p, int dirfd, uintptr_t pathp, uintptr_t statbuf, int flags)
{
    uint8_t* statb = procbufalign(p, statbuf, sizeof(struct stat), alignof(struct stat));
    if (!statb)
        return -EFAULT;
    struct stat* stat = (struct stat*) statb;
    if ((flags & AT_EMPTY_PATH) == 0) {
        const char* path = procpath(p, pathp);
        if (!path)
            return -EFAULT;
        if (dirfd != AT_FDCWD)
            return -EBADF;
        return syserr(fstatat(AT_FDCWD, path, stat, flags));
    }
    FDFile* f = lfix_fdget(&p->fdtable, dirfd);
    if (!f)
        return -EBADF;
    if (!f->stat)
        return -EACCES;
    return f->stat(f->dev, p, stat);
}
SYSWRAP_4(sysfstatat, int, uintptr_t, uintptr_t, int);

static int
sysfstat(LFIXProc* p, int fd, uintptr_t statbuf)
{
    return sysfstatat(p, fd, 0, statbuf, AT_EMPTY_PATH);
}
SYSWRAP_2(sysfstat, int, uintptr_t);

static uintptr_t
sysmmap(LFIXProc* p, uintptr_t addrp, size_t length, int prot, int flags, int fd, off_t offset)
{
    if (length == 0)
        return -EINVAL;

    // The flags listed are the only allowed flags.
    const int illegal_mask = ~MAP_ANONYMOUS &
        ~MAP_PRIVATE &
        ~MAP_HUGETLB &
        ~MAP_FIXED &
        ~MAP_NORESERVE &
        ~MAP_DENYWRITE;
    if ((flags & illegal_mask) != 0) {
        return -EPERM;
    }

    // uintptr_t i_addrp = addrp;

    int r;
    if ((flags & MAP_FIXED) != 0) {
        addrp = truncp(addrp, getpagesize());
        if (addrp != procaddr(p, addrp))
            return -EINVAL;
        addrp = procaddr(p, addrp);

        if (procinbrk(p, addrp, length)) {
            // TODO: handle brk region properly with mmap
            return procuseraddr(p, addrp);
        }
        r = procmapat(p, addrp, length, prot, flags, fd, offset);
    } else {
        // Runtime can pick any location (technically addrp is a hint that the
        // user wants it near that address but we don't care).
        r = procmapany(p, length, prot, flags, fd, offset, &addrp);
    }
    if (r < 0) {
        return r;
    }
    // fprintf(stderr, "sysmmap(%lx (%lx), %ld, %d, %d, %d, %ld) = %lx\n", addrp, i_addrp, length, prot, flags, fd, offset, addrp);
    return procuseraddr(p, addrp);
}
SYSWRAP_6(sysmmap, uintptr_t, size_t, int, int, int, off_t);

static int
sysmunmap(LFIXProc* p, uintptr_t addrp, size_t length)
{
    return procunmap(p, procaddr(p, addrp), length);
}
SYSWRAP_2(sysmunmap, uintptr_t, size_t);

static int
sysmprotect(LFIXProc* p, uintptr_t addrp, size_t length, int prot)
{
    addrp = procaddr(p, addrp);
    // int r = mm_protect(&p->mm, procaddr(p, addrp), length, prot);
    // printf("mprotect(%lx, %lx): %d\n", addrp, length, r);
    // if (r < 0)
    //     return r;
    // We are relying on Linux mmap behavior being the same as mm_protect with
    // respect to addrp and length, since we have not truncated/page-aligned
    // them here.
    // TODO: if this fails (verification), we should undo the mm_protect
    return lfi_proc_mprotect(p->l_proc, addrp, length, prot);
}
SYSWRAP_3(sysmprotect, uintptr_t, size_t, int);

static int
sysclock_gettime(LFIXProc* p, clockid_t clockid, uintptr_t tp) {
    if (clockid != CLOCK_REALTIME && clockid != CLOCK_MONOTONIC)
        return -EINVAL;
    uint8_t* tb = procbufalign(p, tp, sizeof(struct timespec), alignof(struct timespec));
    if (!tb)
        return -EFAULT;
    struct timespec* t = (struct timespec*) tb;
    return syserr(clock_gettime(clockid, t));
}
SYSWRAP_2(sysclock_gettime, clockid_t, uintptr_t);

static ssize_t
sysgetrandom(LFIXProc* p, uintptr_t bufp, size_t buflen, unsigned int flags)
{
    uint8_t* buf = procbuf(p, bufp, buflen);
    if (!buf)
        return -EINVAL;
    return getrandom(buf, buflen, flags);
}
SYSWRAP_3(sysgetrandom, uintptr_t, size_t, unsigned int);

static uintptr_t
sysgetcwd(LFIXProc* p, uintptr_t bufp, size_t size)
{
    uint8_t* buf = procbuf(p, bufp, size);
    if (!buf)
        return -EINVAL;
    return (uintptr_t) getcwd((char*) buf, size);
}
SYSWRAP_2(sysgetcwd, uintptr_t, size_t);

// Dummy syscalls below, not necessarily safe

static int
syssched_getaffinity(LFIXProc* p, pid_t pid, size_t cpusetsize, uintptr_t maskp)
{
    cpu_set_t* mask = (cpu_set_t*) procbufalign(p, maskp, sizeof(cpu_set_t), alignof(cpu_set_t));
    if (!mask)
        return -EINVAL;
    return sched_getaffinity(pid, cpusetsize, mask);
}
SYSWRAP_3(syssched_getaffinity, pid_t, size_t, uintptr_t);

static pid_t
sysgetpid(LFIXProc* p)
{
    (void) p;
    return getpid();
}
SYSWRAP_0(sysgetpid);

static int
sysignore(LFIXProc* p)
{
    return 0;
}
SYSWRAP_0(sysignore);

static int
syserror(LFIXProc* p)
{
    return -1;
}
SYSWRAP_0(syserror);
