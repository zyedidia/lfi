#include "types.h"
#include "host/error.h"

int
host_sysinfo(struct SysInfo* info)
{
    // TODO: emulate sysinfo on posix
    *info = (struct SysInfo){0};
    return 0;
}
