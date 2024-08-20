#include <assert.h>
#include <stdio.h>

#include "sys.h"
#include "lib.h"

enum {
    SYS_ioctl = 16,
    SYS_archprctl = 158,
    SYS_fcntl = 72,
    SYS_openat = 257,
    SYS_munmap = 11,
    SYS_mremap = 25,
    SYS_set_tid_address = 218,
};

enum {
    ARCH_SET_FS = 0x1002,
};

static int
sysarchprctl(SoboxLib* lib, int code, uintptr_t addr)
{
    switch (code) {
    case ARCH_SET_FS:
        addr = libaddr(lib, addr);
        lfi_proc_get_regs(lib->proc)->fs = addr;
        return 0;
    default:
        return -EINVAL;
    }
}

uint64_t
syshandler(void* ctxp, uint64_t sysno,
        uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5)
{
    SoboxLib* l = (SoboxLib*) ctxp;
    uint64_t ret;
    switch (sysno) {
    case SYS_archprctl:
        ret = sysarchprctl(l, (int) a0, a1);
        break;
    case SYS_set_tid_address:
        ret = 0;
        break;
    default:
        printf("unknown syscall: %ld\n", sysno);
        assert(!"NOSYS");
        return -ENOSYS;
    }
    return ret;
}

int
syserr(int val)
{
    if (val == -1)
        return -errno;
    return val;
}
