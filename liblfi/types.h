#pragma once

#include <stdint.h>

#define EXPORT __attribute__((visibility("default")))

typedef uint64_t  u64;
typedef uint32_t  u32;
typedef uint16_t  u16;
typedef uint8_t   u8;
typedef int64_t   i64;
typedef int32_t   i32;
typedef int16_t   i16;
typedef int8_t    i8;

#include "arch_types.h"

typedef int64_t tux_time_t;

struct Dirent {
    tux_ino_t d_ino;
    tux_off_t d_off;
    unsigned short d_reclen;
    unsigned char d_type;
    char d_name[256];
};

struct SysInfo {
    unsigned long uptime;
    unsigned long loads[3];
    unsigned long totalram;
    unsigned long freeram;
    unsigned long sharedram;
    unsigned long bufferram;
    unsigned long totalswap;
    unsigned long freeswap;
    unsigned short procs, pad;
    unsigned long totalhigh;
    unsigned long freehigh;
    unsigned mem_unit;
    char __reserved[256];
};

enum {
    TUX_EPERM   = 1,
    TUX_ENOENT  = 2,
    TUX_EBADF   = 9,
    TUX_EAGAIN  = 11,
    TUX_ENOMEM  = 12,
    TUX_EACCES  = 13,
    TUX_EFAULT  = 14,
    TUX_ENOTDIR = 20,
    TUX_EINVAL  = 22,
    TUX_EMFILE  = 24,
    TUX_ENOSYS  = 38,
};

enum {
    TUX_SEEK_SET  = 0,
    TUX_SEEK_CUR  = 1,
    TUX_SEEK_END  = 2,
};

enum {
    TUX_O_RDONLY    = 0x0,
    TUX_O_WRONLY    = 0x1,
    TUX_O_RDWR      = 0x2,
    TUX_O_CREAT     = 0x40,
    TUX_O_TRUNC     = 0x200,
    TUX_O_APPEND    = 0x400,
    TUX_O_NONBLOCK  = 0x800,
    TUX_O_DIRECTORY = 0x10000,
    TUX_O_CLOEXEC   = 0x80000,
    TUX_O_PATH      = 0x200000,
};

enum {
    TUX_AT_FDCWD      = -100,
    TUX_AT_REMOVEDIR  = 0x200,
    TUX_AT_EMPTY_PATH = 0x1000,
};

enum {
    TUX_GRND_NONBLOCK = 1,
    TUX_GRND_RANDOM   = 2,
};

enum {
    TUX_FUTEX_WAIT           = 0,
    TUX_FUTEX_WAKE           = 1,
    TUX_FUTEX_REQUEUE        = 3,
    TUX_FUTEX_WAIT_BITSET    = 9,
    TUX_FUTEX_PRIVATE_FLAG   = 128,
    TUX_FUTEX_CLOCK_REALTIME = 256,
};

enum {
    TUX_CLONE_VM             = 0x100,
    TUX_CLONE_FS             = 0x200,
    TUX_CLONE_FILES          = 0x400,
    TUX_CLONE_SIGHAND        = 0x800,
    TUX_CLONE_VFORK          = 0x4000,
    TUX_CLONE_THREAD         = 0x10000,
    TUX_CLONE_SYSVSEM        = 0x40000,
    TUX_CLONE_SETTLS         = 0x80000,
    TUX_CLONE_PARENT_SETTID  = 0x100000,
    TUX_CLONE_CHILD_CLEARTID = 0x200000,
    TUX_CLONE_DETACHED       = 0x400000,
    TUX_CLONE_CHILD_SETTID   = 0x1000000,
};

#define TUX_CLONE_IO           0x80000000UL

enum {
    TUX_SIGCHLD = 0x11,
};

enum {
    TUX_PR_SET_NAME = 15,
};
