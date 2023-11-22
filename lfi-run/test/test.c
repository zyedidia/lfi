#include <stdlib.h>
#include <stdio.h>

void delay() {
    for (long i = 0; i < 1000000000; i++) {
        asm volatile ("nop");
    }
}

int main() {
    while (1) {
        printf("Hello world\n");
        delay();
    }

    /* int* p = malloc(10); */
    /* int* p; */
    /* if (!p) { */
    /*     printf("no alloc\n"); */
    /*     return 0; */
    /* } */
    /* p[1024 * 1024] = 10; */
    /* printf("%p\n", p); */
    /* free(p); */

    return 0;
}
