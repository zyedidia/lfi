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
int strncmp(const(char)* s1, const(char)* s2, usize size);

int open(const char* name, int flags, int mode);
int openat(int dirfd, const char* name, int flags, int mode);
ssize read(int fd, void* buf, usize count);
ssize write(int fd, void* buf, usize count);
ssize lseek(int fd, ssize offset, int whence);
int close(int fd);
int mkdirat(int dirfd, const(char)* pathname, int mode);

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
int fstatat(int dirfd, const(char)* path, Stat* statbuf, int flags);
int clock_gettime(uint clockid, TimeSpec* tp);
int unlinkat(int dirfd, const(char)* path, int flags);
int renameat2(int oldfd, const(char)* oldpath, int newfd, const(char)* newpath, int flags);
int faccessat(int dirfd, const(char)* path, int mode, int flags);
int readlinkat(int dirfd, const(char)* path, char* buf, usize size);
char* getcwd(char* buf, usize size);
int memfd_create(const(char)* name, uint flags);
int ftruncate(int fd, long length);

void* mmap(void* addr, usize length, int prot, int flags, int fd, long off);
int munmap(void* addr, usize length);
int mprotect(void* addr, usize len, int prot);
void* mremap(void* old, usize old_size, usize new_size, int flags);

noreturn exit(int status);

__gshared {
    extern void* stdout;
    extern void* stderr;
    extern void* stdin;
}

extern int errno;

void perror(const(char)* s);

enum {
    MAP_SHARED    = 0x001,
    MAP_PRIVATE   = 0x002,
    MAP_FIXED     = 0x010,
    MAP_FILE      = 0x000,
    MAP_ANONYMOUS = 0x020,
    MAP_DENYWRITE = 0x800,
    MAP_HUGETLB   = 0x40000,
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
    AT_FDCWD = -100,
    AT_EMPTY_PATH = 0x1000,
}

enum {
    O_RDONLY    = 0,
    O_WRONLY    = 1,
    O_RDWR      = 2,
    O_ACCMODE   = 3,
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

enum {
    SIGHUP    = 1,
    SIGINT    = 2,
    SIGQUIT   = 3,
    SIGILL    = 4,
    SIGTRAP   = 5,
    SIGABRT   = 6,
    SIGIOT    = SIGABRT,
    SIGBUS    = 7,
    SIGFPE    = 8,
    SIGKILL   = 9,
    SIGUSR1   = 10,
    SIGSEGV   = 11,
    SIGUSR2   = 12,
    SIGPIPE   = 13,
    SIGALRM   = 14,
    SIGTERM   = 15,
    SIGSTKFLT = 16,
    SIGCHLD   = 17,
    SIGCONT   = 18,
    SIGSTOP   = 19,
    SIGTSTP   = 20,
    SIGTTIN   = 21,
    SIGTTOU   = 22,
    SIGURG    = 23,
    SIGXCPU   = 24,
    SIGXFSZ   = 25,
    SIGVTALRM = 26,
    SIGPROF   = 27,
    SIGWINCH  = 28,
    SIGIO     = 29,
    SIGPOLL   = 29,
    SIGPWR    = 30,
    SIGSYS    = 31,
    SIGUNUSED = SIGSYS,
}

enum {
    SA_NOCLDSTOP = 1,
    SA_NOCLDWAIT = 2,
    SA_SIGINFO   = 4,
    SA_ONSTACK   = 0x08000000,
    SA_RESTART   = 0x10000000,
    SA_NODEFER   = 0x40000000,
    SA_RESETHAND = 0x80000000,
    SA_RESTORER  = 0x04000000,
}

enum {
    SIG_BLOCK   = 0,
    SIG_UNBLOCK = 1,
    SIG_SETMASK = 2,
}

struct sigset_t {
    ulong[128 / long.sizeof] __bits;
}

struct SigAction {
    union {
        void function(int) sa_handler;
        void function(int, void*, void*) sa_sigaction;
    }
    sigset_t sa_mask;
    int sa_flags;
    void function() sa_restorer;
}

int sigemptyset(sigset_t* set);
int sigfillset(sigset_t* set);
int sigaddset(sigset_t* set, int signum);
int sigdelset(sigset_t* set, int signum);
int sigismember(const sigset_t* set, int signum);
int sigaction(int signum, const SigAction* act, SigAction* oldact);
int sigaltstack(const stack_t* ss, stack_t* old_ss);
int sigprocmask(int how, const sigset_t* set, sigset_t* oldset);

struct ucontext_t {
    ulong uc_flags;
    ucontext_t* uc_link;
    stack_t uc_stack;
    sigset_t uc_sigmask;
    mcontext_t uc_mcontext;
}

struct mcontext_t {
    ulong fault_address;
    ulong[31] regs;
    ulong sp, pc, pstate;
    ulong[256 * 2] __reserved;
}

struct stack_t {
    void* ss_sp;
    int ss_flags;
    usize ss_size;
}

struct ITimerval {
    Timeval it_interval;
    Timeval it_value;
}

struct Timeval {
    alias time_t = ulong;
    alias suseconds_t = ulong;
    time_t tv_sec;
    suseconds_t tv_usec;
}

int setitimer(int which, const ITimerval* new_value, ITimerval* old_value);

enum {
    ITIMER_REAL    = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF    = 2,
}

enum {
    RLIMIT_NOFILE = 7,
}

struct RLimit {
    ulong rlim_cur;
    ulong rlim_max;
}

int setrlimit(int resource, RLimit* rlim);
int getrlimit(int resource, RLimit* rlim);
