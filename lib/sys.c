#include <stddef.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/times.h>

#include <sys/syscall.h>

static inline uintptr_t syscall_0(int sysno) {
    register uintptr_t a7 asm("x7") = sysno;
    register uintptr_t a0 asm("x0");
    asm volatile("svc #0" : "=r"(a0) : "r"(a7) : "memory");
    return a0;
}
static inline uintptr_t syscall_1(int sysno, uintptr_t arg0) {
    register uintptr_t a7 asm("x7") = sysno;
    register uintptr_t a0 asm("x0") = arg0;
    asm volatile("svc #0" : "+r"(a0) : "r"(a7) : "memory");
    return a0;
}
static inline uintptr_t syscall_2(int sysno, uintptr_t arg0, uintptr_t arg1) {
    register uintptr_t a7 asm("x7") = sysno;
    register uintptr_t a0 asm("x0") = arg0;
    register uintptr_t a1 asm("x1") = arg1;
    asm volatile("svc #0" : "+r"(a0) : "r"(a7), "r"(a1) : "memory");
    return a0;
}
static inline uintptr_t syscall_3(int sysno, uintptr_t arg0, uintptr_t arg1, uintptr_t arg2) {
    register uintptr_t a7 asm("x7") = sysno;
    register uintptr_t a0 asm("x0") = arg0;
    register uintptr_t a1 asm("x1") = arg1;
    register uintptr_t a2 asm("x2") = arg2;
    asm volatile("svc #0" : "+r"(a0) : "r"(a7), "r"(a1), "r"(a2) : "memory");
    return a0;
}

char *__env[1] = { 0 };
char **_environ = __env;

extern void exit(int code);
extern int main ();

void _start() {
    int ex = main();
    exit(ex);
}

int _execve(char* name, char** argv, char** env) {
    return syscall_3(SYS_execve, (uintptr_t) name, (uintptr_t) argv, (uintptr_t) env);
}

void* _sbrk(int incr) {
    return NULL;
}

int _close(int file) {
    return syscall_1(SYS_close, file);
}

int _fstat(int file, struct stat* st) {
    return syscall_2(SYS_fstat, file, (uintptr_t) st);
}

int _isatty(int file) {
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    return syscall_3(SYS_lseek, file, ptr, dir);
}

void _exit(int status) {
    syscall_1(SYS_exit, status);
    while (1) {}
}

void _kill(int pid, int sig) {
    syscall_2(SYS_kill, pid, sig);
}

int _getpid(void) {
    return syscall_0(SYS_getpid);
}

int _write(int file, char* ptr, int len) {
    return syscall_3(SYS_write, file, (uintptr_t) ptr, len);
}

int _read(int file, char* ptr, int len) {
    return syscall_3(SYS_read, file, (uintptr_t) ptr, len);
}

int _fork(void) {
    return 0;
    /* return syscall_0(SYS_fork); */
}

int _wait() {
    return -1;
    /* return syscall_0(SYS_wait); */
}

int _unlink(char* name) {
    return -1;
    /* return syscall_1(SYS_unlink, (uintptr_t) name); */
}

int _times(struct tms* buf) {
    return syscall_1(SYS_times, (uintptr_t) buf);
}
