module core.lib;

import core.alloc;

ubyte[] readfile(void* f) {
    if (fseek(f, 0, SEEK_END) != 0)
        return null;
    ssize size = ftell(f);
    if (fseek(f, 0, SEEK_SET) != 0)
        return null;
    ubyte[] buf = kalloc(size);
    if (!buf)
        return null;
    if (fread(buf.ptr, size, 1, f) != 1) {
        kfree(buf);
        return null;
    }
    return buf;
}

extern (C):

void* memcpy(void* dst, const(void)* src, usize n);
void* memmove(void* dst, const(void)* src, usize n);
void* memset(void* v, int c, usize n);

void* malloc(usize size);
void* aligned_alloc(usize alignment, usize size);
void free(void* ptr);

usize strlen(const(char)* s);
usize strnlen(const(char)* s, usize len);
int strcmp(const(char)* s1, const(char)* s2);

int open(const char* name, int flags, int mode);
ssize read(int fd, void* buf, usize count);
ssize write(int fd, void* buf, usize count);
ssize lseek(int fd, ssize offset, int whence);
int close(int fd);

void* fopen(const(char)* path, const(char)* mode);
void* fdopen(int fd, const(char)* mode);
usize fread(const void* ptr, usize size, usize nmemb, void* stream);
usize fwrite(const void* ptr, usize size, usize nmemb, void* stream);
int fseek(void* stream, ssize off, uint whence);
int fclose(void* stream);
int fflush(void* stream);
int fileno(void* stream);
ssize ftell(void* stream);
ssize getdents64(int fd, void* dirp, usize count);
int fstat(int fd, Stat* statbuf);
int clock_gettime(uint clockid, TimeSpec* tp);
int unlinkat(int dirfd, const(char)* path, int flags);
int renameat2(int oldfd, const(char)* oldpath, int newfd, const(char)* newpath, int flags);
int faccessat(int dirfd, const(char)* path, int mode, int flags);

void* mmap(void* addr, usize length, int prot, int flags, int fd, long off);
int munmap(void* addr, usize length);
int mprotect(void* addr, usize len, int prot);

noreturn exit(int status);

__gshared {
    extern void* stdout;
    extern void* stderr;
    extern void* stdin;
    extern int errno;
}

enum {
    MAP_SHARED    = 0x001,
    MAP_PRIVATE   = 0x002,
    MAP_FIXED     = 0x010,
    MAP_FILE      = 0x000,
    MAP_ANONYMOUS = 0x020,
}

enum {
    PROT_NONE  = 0,
    PROT_READ  = 1,
    PROT_WRITE = 2,
    PROT_EXEC  = 4,
}

enum {
    SEEK_SET = 0,
    SEEK_CUR = 1,
    SEEK_END = 2,
}

enum {
    O_RDONLY    = 0,
    O_WRONLY    = 1,
    O_RDWR      = 2,
    O_APPEND    = 0x0400,
    O_TRUNC     = 0x0200,
    O_CREAT     = 0x0040,
    O_DIRECTORY = 0x4000,
    O_PATH      = 0x200000,
}

enum PATH_MAX = 4096;

struct TimeSpec {
    ulong sec;
    ulong nsec;
}

// AArch64 definitions
alias dev_t = ulong;
alias ino_t = ulong;
alias nlink_t = uint;
alias mode_t = uint;
alias uid_t = uint;
alias gid_t = uint;
alias off_t = ulong;
alias blksize_t = uint;
alias blkcnt_t = ulong;

struct Stat {
    dev_t st_dev;
    ino_t st_ino;
    mode_t st_mode;
    nlink_t st_nlink;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    ulong __pad;
    off_t st_size;
    blksize_t st_blksize;
    int __pad2;
    blkcnt_t st_blocks;
    TimeSpec st_atim;
    TimeSpec st_mtim;
    TimeSpec st_ctim;
    uint[2] __unused;
}

struct SysInfo {
	ulong uptime;
	ulong[3] loads;
	ulong totalram;
	ulong freeram;
	ulong sharedram;
	ulong bufferram;
	ulong totalswap;
	ulong freeswap;
	ushort procs, pad;
	ulong totalhigh;
	ulong freehigh;
	uint mem_unit;
	ubyte[256] __reserved;
}

int sysinfo(SysInfo* info);
