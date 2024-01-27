#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    printf("fork test beginning\n");

    int pid = fork();
    if (pid == 0) {
        printf("in child\n");
        for (int i = 0; i < 1000000000; i++) {
            asm volatile ("nop");
        }
        exit(0);
    }
    printf("waiting for child %d\n", pid);
    int child = wait(NULL);
    printf("done waiting for %d\n", child);
}
