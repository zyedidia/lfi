#include <stdlib.h>
#include <stdio.h>
int main(int argc, char** argv) {
    printf("hello world %s\n", argv[1]);
    int* p = malloc(sizeof(int));
    printf("%p\n", p);
    *p = 10;
    return 0;
}
