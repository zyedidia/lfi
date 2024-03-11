#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool lfi_verify_insn(uint32_t insn);

bool verify_init();
bool verify_insn(uint32_t);

int main() {
    verify_init();

    size_t n_verify = 0x0ffffffffULL + 1;

    for (size_t i = 0; i < n_verify; i++) {
        if (i % 10000000 == 0) {
            printf("%.1f\n", (float) i / (float) n_verify * 100.0);
        }
        uint32_t insn = (uint32_t) i;
        if (verify_insn(insn) != lfi_verify_insn(insn)) {
            printf("mismatch: %lx\n", i);
        }
    }

    return 0;
}
