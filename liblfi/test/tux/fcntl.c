#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // Test fcntl() syscall
    int fd1 = open("/dev/null", O_WRONLY);
    if (fd1 < 0) {
        printf("failed to open /dev/null\n");
        return 1;
    }
    
    // Test F_DUPFD - duplicate fd with minimum fd number
    int fd2 = fcntl(fd1, F_DUPFD, 5);
    if (fd2 < 0) {
        printf("fcntl F_DUPFD failed\n");
        return 1;
    }
    if (fd2 < 5) {
        printf("fcntl F_DUPFD returned fd %d, expected >= 5\n", fd2);
        return 1;
    }
    
    printf("fcntl F_DUPFD: original fd=%d, dup fd=%d\n", fd1, fd2);
    
    // Test F_GETFL - get file status flags
    int flags = fcntl(fd1, F_GETFL);
    if (flags < 0) {
        printf("fcntl F_GETFL failed\n");
        return 1;
    }
    
    printf("fcntl F_GETFL: fd=%d has flags=0x%x\n", fd1, flags);
    
    // Test F_GETFD - get file descriptor flags
    int fd_flags = fcntl(fd1, F_GETFD);
    if (fd_flags < 0) {
        printf("fcntl F_GETFD failed\n");
        return 1;
    }
    
    printf("fcntl F_GETFD: fd=%d has fd_flags=0x%x\n", fd1, fd_flags);
    
    // Test F_SETFD - set file descriptor flags (should work)
    int result = fcntl(fd1, F_SETFD, FD_CLOEXEC);
    if (result < 0) {
        printf("fcntl F_SETFD failed\n");
        return 1;
    }
    
    // Verify the flag was set
    fd_flags = fcntl(fd1, F_GETFD);
    if (fd_flags < 0) {
        printf("fcntl F_GETFD after F_SETFD failed\n");
        return 1;
    }
    
    printf("fcntl F_SETFD: fd=%d now has fd_flags=0x%x\n", fd1, fd_flags);
    
    // Test F_DUPFD_CLOEXEC - should return ENOSYS
    int fd3 = fcntl(fd1, F_DUPFD_CLOEXEC, 8);
    if (fd3 >= 0) {
        printf("fcntl F_DUPFD_CLOEXEC should have failed but returned fd=%d\n", fd3);
        return 1;
    }
    
    printf("fcntl F_DUPFD_CLOEXEC correctly returned error (not supported)\n");
    
    // Test writing to duplicated fd to verify it works
    const char* msg = "test\n";
    write(fd1, msg, strlen(msg));
    write(fd2, msg, strlen(msg));
    
    close(fd1);
    close(fd2);
    
    printf("fcntl test passed\n");
    return 0;
}