#include <stdio.h>
#include <dirent.h>

#include "align.h"
#include "types.h"
#include "host/posix/file.h"
#include "host/error.h"

ssize_t
host_getdents64(struct HostFile* file, uint8_t* dirp, size_t count)
{
    DIR* dir = fdopendir(file->fd);
    if (!dir)
        return tuxerr(errno);
    size_t written = 0;
    while (written < count) {
        struct dirent* ent = readdir(dir);
        if (!ent)
            break;
        struct Dirent* tuxent = (struct Dirent*) &dirp[written];
        memset(tuxent, 0, sizeof(struct Dirent));
        tuxent->d_ino = ent->d_ino;
        tuxent->d_off = -1;
        // TODO: convert d_type properly
        size_t len = strlen(ent->d_name);
        len = len >= sizeof(tuxent->d_name) ? sizeof(tuxent->d_name) - 1 : len;
        tuxent->d_type = ent->d_type;
        tuxent->d_reclen = ceilp(8 + 8 + 2 + 1 + len + 1, 8);
        strncpy(tuxent->d_name, ent->d_name, len);
        written += tuxent->d_reclen;
    }
    if (errno < 0)
        return tuxerr(errno);
    return written;
}
