#pragma once

#include "proc.h"

struct File {
    struct HostFile* file;
    int flags;
};

struct FDFile* filefnew(struct HostFile* file, int flags);

struct FDFile* filenew(struct Tux* tux, struct HostFile* dir, const char* name, int flags, int mode);

int filefstatat(const char* dir, const char* path, struct Stat* stat, int flags);
