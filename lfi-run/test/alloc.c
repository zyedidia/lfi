#include <stdio.h>
#include <stdlib.h>
int main() {
    // small allocations
    for (int i = 0; i < 10; i++) {
        int* p = malloc(1024);
        printf("allocated: %p\n", p);
    }

    // large allocations
    for (int i = 0; i < 10; i++) {
        volatile int* p = malloc(1024 * 1024);
        for (int j = 0; j < 8192; j++) {
            p[j] = j;
        }
        printf("allocated: %p\n", p);
    }
    return 0;
}
