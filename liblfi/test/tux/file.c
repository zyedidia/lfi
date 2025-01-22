#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    if (argc <= 1) {
        fprintf(stderr, "no file given\n");
        return 1;
    }

    FILE* f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "%s does not exist\n", argv[1]);
        return 1;
    }
    char buf[1024];
    int n;
    while ((n = fread(buf, 1, sizeof(buf), f)) != 0) {
        fwrite(buf, 1, n, stdout);
    }
    return 0;
}
