#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main() {
    printf("fork test beginning\n");

    int pid = fork();
    printf("forked: %d\n", pid);
    wait(NULL);
}
