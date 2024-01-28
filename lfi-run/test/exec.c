#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv, char** envp) {
    if (argc <= 1) {
        fprintf(stderr, "no file given\n");
        return 1;
    }

    argv[0] = argv[1];
    execve(argv[1], argv, envp);
    fprintf(stderr, "error: execve failed\n");
}
