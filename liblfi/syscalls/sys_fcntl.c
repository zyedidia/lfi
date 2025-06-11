#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "syscalls/syscalls.h"
#include "fd.h"
#include "file.h"
#include "host.h"
#include "host/posix/file.h"

int
sys_fcntl(struct TuxProc* p, int fd, int cmd, uintptr_t va0, uintptr_t va1,
        uintptr_t va2, uintptr_t va3)
{
    switch (cmd) {
    case F_DUPFD: {
        int minfd = va0;
        struct FDFile* FD_DEFER(f) = fdget(&p->fdtable, fd);
        if (!f)
            return -TUX_EBADF;
        
        // Find the lowest available fd >= minfd
        for (int newfd = minfd; newfd < TUX_NOFILE; newfd++) {
            if (!fdhas(&p->fdtable, newfd)) {
                fdassign(&p->fdtable, newfd, f);
                return newfd;
            }
        }
        return -TUX_EMFILE;
    }
    
    case F_DUPFD_CLOEXEC:
        // Close-on-exec not supported yet
        return -TUX_ENOSYS;
    
    case F_GETFD:
    case F_SETFD:
    case F_GETFL:
    case F_SETFL: {
        struct FDFile* FD_DEFER(f) = fdget(&p->fdtable, fd);
        if (!f)
            return -TUX_EBADF;
        
        // Get the underlying host file descriptor
        struct HostFile* hf = f->file ? f->file(f->dev) : NULL;
        if (!hf)
            return -TUX_EBADF;
        
        // Pass through to system fcntl
        int result = fcntl(hf->fd, cmd, va0);
        if (result < 0)
            return -errno;
        return result;
    }
    
    default:
        WARN(p->tux, "fcntl command %d not implemented", cmd);
        return -TUX_ENOSYS;
    }
}
