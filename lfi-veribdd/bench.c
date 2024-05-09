#include <stdbool.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

bool lfi_verify_insn(uint32_t insn);

int main() {
    size_t n_test = 1024 * 1024 * 128;

    uint32_t* testvec = malloc(n_test * sizeof(uint32_t));

    srand(42);

    printf("generating test set...\n");

    for (size_t i = 0; i < n_test; i++) {
        unsigned int x = ((rand() & 0x7fffu)<<17 | (rand() & 0x7fffu)<<2 ) | (rand() & 0x7fffu)>>13;
        testvec[i] = x;
    }

    printf("benchmarking...\n");

    clock_t begin = clock();

    size_t total = 0;
    for (size_t i = 0; i < n_test; i++) {
        if (lfi_verify_insn(testvec[i])) {
            total++;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("total: %ld\n", total);
    printf("time: %.3f, %.3f MiB/s\n", time_spent, ((sizeof(uint32_t) * n_test) / 1024 / 1024) / time_spent);
}
