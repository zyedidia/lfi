#include <stdalign.h>

#include "version.h"
#include "host.h"
#include "syscalls/syscalls.h"

enum {
    UTSNAME_LENGTH = 65,
};

struct UTSName {
    char sysname[UTSNAME_LENGTH];
    char nodename[UTSNAME_LENGTH];
    char release[UTSNAME_LENGTH];
    char version[UTSNAME_LENGTH];
    char machine[UTSNAME_LENGTH];
};

int
sys_uname(struct TuxProc* p, lfiptr_t bufp)
{
    uint8_t* utsb = procbufalign(p, bufp, sizeof(struct UTSName), alignof(struct UTSName));
    if (!utsb)
        return -TUX_EFAULT;
    struct UTSName* uts = (struct UTSName*) utsb;
    strcpy(uts->sysname, "Linux");
    strcpy(uts->release, LINUX_VERSION "-libtux");
    strcpy(uts->version, "0.0.0-unknown");
    strcpy(uts->machine, "x86_64");
    return 0;
}

int
sys_sysinfo(struct TuxProc* p, lfiptr_t infop)
{
    uint8_t* infob = procbufalign(p, infop, sizeof(struct SysInfo), alignof(struct SysInfo));
    if (!infob)
        return -TUX_EFAULT;
    struct SysInfo* info = (struct SysInfo*) infob;
    return host_sysinfo(info);
}

int
sys_getrlimit(struct TuxProc* p, int resource, uintptr_t rlimp)
{
    WARN("getrlimit ignored");
    return 0;
}
