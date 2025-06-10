#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // Test dup() syscall
    int fd1 = open("/dev/null", O_WRONLY);
    if (fd1 < 0) {
        printf("failed to open /dev/null\n");
        return 1;
    }
    
    int fd2 = dup(fd1);
    if (fd2 < 0) {
        printf("dup() failed\n");
        return 1;
    }
    
    printf("dup: original fd=%d, dup fd=%d\n", fd1, fd2);
    
    // Test dup3() syscall
    int fd3 = 10; // arbitrary target fd
    int fd4 = dup3(fd1, fd3, 0);
    if (fd4 != fd3) {
        printf("dup3() failed: expected %d, got %d\n", fd3, fd4);
        return 1;
    }
    
    printf("dup3: original fd=%d, target fd=%d\n", fd1, fd3);
    
    // Test writing to all fds to verify they work
    const char* msg = "test\n";
    write(fd1, msg, strlen(msg));
    write(fd2, msg, strlen(msg));
    write(fd3, msg, strlen(msg));
    
    printf("dup test passed\n");
    return 0;
}