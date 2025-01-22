#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "types.h"

struct TuxThread;

struct HostFile;

struct Stat;

struct HostFile* host_openat(struct HostFile* dir, const char* filename, int flags, int mode);

static inline struct HostFile*
host_open(const char* filename, int flags, int mode)
{
    return host_openat(NULL, filename, flags, mode);
}

struct HostFile* host_fdopen(int fd);

ssize_t host_read(struct HostFile* file, uint8_t* buffer, size_t size);

ssize_t host_write(struct HostFile* file, uint8_t* buffer, size_t size);

ssize_t host_seek(struct HostFile* file, size_t loc, int whence);

int host_fstatat(struct HostFile* file, const char* path, struct Stat* stat, int flags);

static inline int
host_fstat(struct HostFile* file, struct Stat* stat)
{
    return host_fstatat(file, "", stat, TUX_AT_EMPTY_PATH);
}

int host_fchmodat(struct HostFile* dir, const char* path, tux_mode_t mode, int flags);
int host_fchmod(struct HostFile* file, tux_mode_t mode);

int host_ftruncate(struct HostFile* file, off_t length);
int host_truncate(const char* path, off_t length);

int host_fchownat(struct HostFile* file, const char* path, tux_uid_t owner, tux_gid_t group, int flags);

static inline int
host_fchown(struct HostFile* file, tux_uid_t owner, tux_gid_t group)
{
    return host_fchownat(file, "", owner, group, TUX_AT_EMPTY_PATH);
}

ssize_t host_getdents64(struct HostFile* file, void* dirp, size_t count);

int host_close(struct HostFile* file);

struct HostFile* host_stdin(void);

struct HostFile* host_stdout(void);

struct HostFile* host_stderr(void);

ssize_t host_getrandom(void* buf, size_t size, unsigned int flags);

void* host_mmap(void* addr, size_t length, int prot, int flags, struct HostFile* file, off_t offset);

int host_munmap(void* addr, size_t length);

int host_mprotect(void* addr, size_t length, int prot);

int host_sched_yield(void);

tux_time_t host_time(void);

int host_fsync(struct HostFile* file);

int host_unlinkat(struct HostFile* file, const char* path, int flags);

ssize_t host_readlinkat(struct HostFile* file, const char* path, char* buf, size_t size);

int host_renameat2(struct HostFile* olddir, const char* oldpath,
        struct HostFile* newdir, const char* newpath, int flags);

int host_faccessat2(struct HostFile* dir, const char* path, int mode, int flags);

int host_getpath(struct HostFile* dir, char* buf, size_t size);

bool host_isdir(struct HostFile* file);

int host_mkdirat(struct HostFile* dir, const char* path, tux_mode_t mode);

int host_sysinfo(struct SysInfo* info);

long host_futexwait(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val, struct TimeSpec* timeout);

long host_futexwake(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val);

long host_futexrequeue(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val);

unsigned host_cpucount(void);

int host_prctl_set_name(char* name);
