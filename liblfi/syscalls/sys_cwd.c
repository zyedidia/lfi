#include <assert.h>

#include "syscalls/syscalls.h"
#include "fd.h"
#include "host.h"

ssize_t
sys_getcwd(struct TuxProc* p, uintptr_t bufp, size_t size)
{
    if (size == 0)
        return 0;
    uint8_t* buf = procbuf(p, bufp, size);
    if (!buf)
        return -TUX_EFAULT;
    LOCK_WITH_DEFER(&p->cwd.lk, lk_cwd);
    size = size < TUX_PATH_MAX ? size : TUX_PATH_MAX;
    ssize_t r_size = host_getpath(p->cwd.file, (char*) buf, size);
    if (r_size < 0)
        return -TUX_EINVAL;
    assert(r_size <= size);
    buf[r_size - 1] = 0;
    VERBOSE(p->tux, "sys_getcwd(\"%s\", %ld) = %ld", buf, size, r_size);
    return r_size;
}

int
sys_chdir(struct TuxProc* p, uintptr_t pathp)
{
    const char* path = procpath(p, pathp);
    if (!path)
        return -TUX_EFAULT;
    LOCK_WITH_DEFER(&p->cwd.lk, lk_cwd);
    struct HostFile* file = host_openat(p->cwd.file, path, TUX_O_DIRECTORY | TUX_O_PATH, 0);
    if (p->cwd.fd) {
        fdrelease(p->cwd.fd);
        p->cwd.fd = NULL;
    } else if (p->cwd.file) {
        host_close(p->cwd.file);
    }
    p->cwd.file = file;
    return 0;
}

int
sys_fchdir(struct TuxProc* p, int fd)
{
    struct FDFile* f = fdget(&p->fdtable, fd);
    if (!f)
        return -TUX_EBADF;
    if (!f->file)
        return -TUX_EACCES;
    struct HostFile* file = f->file(f->dev);
    if (!host_isdir(file))
        return -TUX_ENOTDIR;
    LOCK_WITH_DEFER(&p->cwd.lk, lk_cwd);
    if (p->cwd.fd) {
        fdrelease(p->cwd.fd);
        p->cwd.fd = NULL;
    } else if (p->cwd.file) {
        host_close(p->cwd.file);
    }

    p->cwd.fd = f;
    p->cwd.file = file;
    return 0;
}
