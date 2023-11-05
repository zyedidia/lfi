#include <stdio.h>
int main() {

    asm volatile ("mov x8, %0" :: "r"((unsigned long) 172) : "x8");

    for (int i = 0; i < 100000000; i++) {
        asm volatile ("svc #0");
    }

    return 0;
}
