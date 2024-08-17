module lfi.env;

import cwalk;

import core.lib;

ubyte[] lfireadfile(const(char)* name) {
    char* sysroot = getenv("LFISYSROOT");
    if (!sysroot) {
        fprintf(stderr, "warning: no LFI sysroot\n");
        return null;
    }
    int dirfd = open(sysroot, O_DIRECTORY | O_PATH, 0);
    if (dirfd < 0)
        return null;
    scope(exit) close(dirfd);
    if (name[0] == '/')
        name++;
    int fd = openat(dirfd, name, O_RDONLY, 0);
    if (fd < 0)
        return null;
    void* f = fdopen(fd, "rb");
    if (!f)
        return null;
    scope(exit) fclose(f);
    ubyte[] buf = readfile(f);
    return buf;
}
