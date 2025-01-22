#pragma once

#include <stdint.h>

typedef uint64_t tux_dev_t;
typedef uint64_t tux_ino_t;
typedef uint32_t tux_nlink_t;
typedef uint32_t tux_mode_t;
typedef uint32_t tux_uid_t;
typedef uint32_t tux_gid_t;
typedef uint64_t tux_off_t;
typedef uint32_t tux_blksize_t;
typedef uint64_t tux_blkcnt_t;

struct TimeSpec {
    uint64_t sec;
    uint64_t nsec;
};

struct Stat {
    tux_dev_t st_dev;
    tux_ino_t st_ino;
    tux_mode_t st_mode;
    tux_nlink_t st_nlink;
    tux_uid_t st_uid;
    tux_gid_t st_gid;
    tux_dev_t st_rdev;
    uint64_t _pad0;
    tux_off_t st_size;
    tux_blksize_t st_blksize;
    uint32_t _pad2;
    tux_blkcnt_t st_blocks;

    struct TimeSpec st_atim;
    struct TimeSpec st_mtim;
    struct TimeSpec st_ctim;
    uint32_t _unused[2];
};
