module core.lib;

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

noreturn exit(int status);

__gshared {
    extern void* stdout;
    extern void* stderr;
    extern void* stdin;
    extern int errno;
}
