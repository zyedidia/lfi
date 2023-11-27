#include <unistd.h>
#include <stdio.h>

int main() {
    printf("fork test beginning\n");

    int pid = fork();
    printf("forked: %d\n", pid);
}
