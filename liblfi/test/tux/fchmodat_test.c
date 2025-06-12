#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main() {
    const char* testfile = "fchmodat_test_file.txt";
    const char* testdir = "fchmodat_test_dir";
    
    // Create a test directory
    if (mkdir(testdir, 0755) != 0 && errno != EEXIST) {
        fprintf(stderr, "Failed to create test directory: %s\n", strerror(errno));
        return 1;
    }
    
    // Create a test file in the directory
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "%s/%s", testdir, testfile);
    FILE* f = fopen(filepath, "w");
    if (!f) {
        fprintf(stderr, "Failed to create test file: %s\n", strerror(errno));
        rmdir(testdir);
        return 1;
    }
    fprintf(f, "test content\n");
    fclose(f);
    
    // Open the directory for fchmodat
    int dirfd = open(testdir, O_RDONLY);
    if (dirfd < 0) {
        fprintf(stderr, "Failed to open test directory: %s\n", strerror(errno));
        unlink(filepath);
        rmdir(testdir);
        return 1;
    }
    
    // Test fchmodat - make file read-only using directory fd
    printf("Testing fchmodat to make file read-only...\n");
    if (fchmodat(dirfd, testfile, 0444, 0) != 0) {
        fprintf(stderr, "fchmodat failed: %s\n", strerror(errno));
        close(dirfd);
        unlink(filepath);
        rmdir(testdir);
        return 1;
    }
    
    // Verify the permissions changed
    struct stat st;
    if (stat(filepath, &st) != 0) {
        fprintf(stderr, "stat failed: %s\n", strerror(errno));
        close(dirfd);
        unlink(filepath);
        rmdir(testdir);
        return 1;
    }
    
    if ((st.st_mode & 0777) == 0444) {
        printf("fchmodat test PASSED - file is now read-only\n");
    } else {
        printf("fchmodat test FAILED - expected mode 0444, got %o\n", st.st_mode & 0777);
        close(dirfd);
        unlink(filepath);
        rmdir(testdir);
        return 1;
    }
    
    // Test fchmodat with AT_FDCWD
    printf("Testing fchmodat with AT_FDCWD...\n");
    if (fchmodat(AT_FDCWD, filepath, 0644, 0) != 0) {
        fprintf(stderr, "fchmodat with AT_FDCWD failed: %s\n", strerror(errno));
        close(dirfd);
        unlink(filepath);
        rmdir(testdir);
        return 1;
    }
    
    // Verify the permissions changed back
    if (stat(filepath, &st) != 0) {
        fprintf(stderr, "stat failed: %s\n", strerror(errno));
        close(dirfd);
        unlink(filepath);
        rmdir(testdir);
        return 1;
    }
    
    if ((st.st_mode & 0777) == 0644) {
        printf("fchmodat with AT_FDCWD test PASSED - file is now writable\n");
    } else {
        printf("fchmodat with AT_FDCWD test FAILED - expected mode 0644, got %o\n", st.st_mode & 0777);
        close(dirfd);
        unlink(filepath);
        rmdir(testdir);
        return 1;
    }
    
    // Clean up
    close(dirfd);
    unlink(filepath);
    rmdir(testdir);
    printf("All fchmodat tests PASSED\n");
    return 0;
}