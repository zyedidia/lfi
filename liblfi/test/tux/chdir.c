#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char** argv) {
    if (argc <= 2) {
        fprintf(stderr, "no file given\n");
        return 1;
    }

    if (chdir(argv[1]) != 0) {
        fprintf(stderr, "could not chdir to %s\n", argv[1]);
        return 1;
    }

    FILE* f = fopen(argv[2], "r");
    if (!f) {
        fprintf(stderr, "%s does not exist\n", argv[2]);
        return 1;
    }
    char buf[1024];
    int n;
    while ((n = fread(buf, 1, sizeof(buf), f)) != 0) {
        fwrite(buf, 1, n, stdout);
    }
    return 0;
}
