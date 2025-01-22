#define _GNU_SOURCE
#include <sys/sysinfo.h>

#include "types.h"
#include "host/error.h"

int
host_sysinfo(struct SysInfo* info)
{
    struct sysinfo kinfo;
    int r = sysinfo(&kinfo);
    if (r < 0)
        return tuxerr(errno);

    *info = (struct SysInfo) {
        .uptime = kinfo.uptime,
        .totalram = kinfo.totalram,
        .freeram = kinfo.freeram,
        .sharedram = kinfo.sharedram,
        .bufferram = kinfo.bufferram,
        .totalswap = kinfo.totalswap,
        .freeswap = kinfo.freeswap,
        .procs = kinfo.procs,
        .totalhigh = kinfo.totalhigh,
        .freehigh = kinfo.freehigh,
        .mem_unit = kinfo.mem_unit,
    };
    info->loads[0] = kinfo.loads[0];
    info->loads[1] = kinfo.loads[1];
    info->loads[2] = kinfo.loads[2];

    return 0;
}
