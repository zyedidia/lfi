#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool lfi_verify_insn(uint32_t insn);
bool lfiveribdd_verify_insn(uint32_t insn);

int main() {
    size_t n_verify = 0x0ffffffffULL + 1;

    for (size_t i = 0; i < n_verify; i++) {
        if (i % 10000000 == 0) {
            printf("%.1f\n", (float) i / (float) n_verify * 100.0);
        }
        uint32_t insn = (uint32_t) i;
        if (lfiveribdd_verify_insn(insn) != lfi_verify_insn(insn)) {
            printf("mismatch: %lx\n", i);
        }
    }

	/* uint32_t insn = (uint32_t) 0x2f9ae; // 0x30000; // 0x2f9ae;
        if (lfiveribdd_verify_insn(insn) != lfi_verify_insn(insn)) {
            printf("mismatch: %x\n", insn);
        } */

    return 0;
}
