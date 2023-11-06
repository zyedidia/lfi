#include <stdio.h>
int main() {

    int* p = malloc(10);
    printf("%p\n", p);

    /* asm volatile ("mov x8, %0" :: "r"((unsigned long) 172) : "x8"); */
    /*  */
    /* for (int i = 0; i < 10; i++) { */
    /*     asm volatile ("svc #0"); */
    /* } */

    return 0;
}
