#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    // small allocations
    for (int i = 0; i < 10; i++) {
        size_t size = 1024;
        int* p = malloc(size);
        assert(p);
        printf("allocated: %ld\n", size);
    }

    // large allocations
    for (int i = 0; i < 10; i++) {
        size_t size = 1024 * 1024;
        volatile int* p = malloc(size);
        assert(p);
        for (int j = 0; j < 8192; j++) {
            p[j] = j;
        }
        printf("allocated: %ld\n", size);
    }
    return 0;
}
