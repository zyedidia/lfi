#include <stdint.h>

#include "lfix.h"

enum {
    BRKMAXSIZE = 512ULL * 1024 * 1024,
};

uintptr_t procaddr(LFIXProc* proc, uintptr_t addr);

uintptr_t procuseraddr(LFIXProc* proc, uintptr_t addr);

int procmapat(LFIXProc* p, uintptr_t start, size_t size, int prot, int flags, int fd, off_t offset);

int procunmap(LFIXProc* p, uintptr_t start, size_t size);

int procmapany(LFIXProc* p, size_t size, int prot, int flags, int fd, off_t offset, uintptr_t* o_mapstart);

int procchdir(LFIXProc* p, const char* path);
