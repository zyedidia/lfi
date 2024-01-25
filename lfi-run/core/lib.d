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
    O_RDONLY = 0,
    O_WRONLY = 1,
    O_RDWR   = 2,
    O_APPEND = 0x0400,
    O_TRUNC  = 0x0200,
    O_CREAT  = 0x0040,
}
