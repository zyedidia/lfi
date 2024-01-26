#include <stdio.h>
int main(int argc, char** argv) {
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %p, %s\n", i, argv[i], argv[i]);
    }
    printf("argv[%d]: %p\n", argc, argv[argc]);
    return 0;
}
