#include <stdalign.h>
#include <errno.h>
#include <sys/ioctl.h>

#include "syscalls/syscalls.h"

enum {
    // TODO: check if TIOCGWINSZ constant might vary across arches?
    TUX_TIOCGWINSZ = 0x5413,
};

struct WinSize {
    unsigned short ws_row, ws_col, ws_xpixel, ws_ypixel;
};

int
sys_ioctl(struct TuxProc* p, int fd, unsigned long request, uintptr_t va0,
        uintptr_t va1, uintptr_t va2, uintptr_t va3)
{
    if (fd != 0 && fd != 1 && fd != 2)
        return -TUX_EINVAL;
    if (request != TUX_TIOCGWINSZ) {
        WARN("unknown ioctl request: %ld", request);
        return -TUX_EINVAL;
    }
    uint8_t* wsb = procbufalign(p, va0, sizeof(struct WinSize), alignof(struct WinSize));
    if (!wsb)
        return -TUX_EFAULT;
    struct WinSize* tux_ws = (struct WinSize*) wsb;
    struct winsize ws;
    // TODO: use host call for this
    int kfd = fd == 0 ? fileno(stdin) : fd == 1 ? fileno(stdout) : fileno(stderr);
    int err = ioctl(kfd, TIOCGWINSZ, &ws);
    if (err != 0) {
        return -errno;
    }
    tux_ws->ws_row = ws.ws_row;
    tux_ws->ws_col = ws.ws_col;
    tux_ws->ws_xpixel = ws.ws_xpixel;
    tux_ws->ws_ypixel = ws.ws_ypixel;
    return 0;
}
