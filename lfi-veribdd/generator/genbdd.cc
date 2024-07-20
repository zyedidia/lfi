#include <bdd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <fcntl.h>

#include "lfi.h"

bdd
add_value(uint32_t val)
{
    bdd total = bddtrue;
    for (size_t i = 0; i < 32; i++) {
        uint32_t bit = (val >> i) & 1;
        bdd var = bdd_ithvar(i);
        if (!bit) {
            var = bdd_not(var);
        }
        total &= var;
    }
    return total;
}

int
main(int argc, char* argv[])
{
    if (argc <= 3) {
        printf("usage: %s out.bdd startHex endHex\n", argv[0]);
        return 1;
    }

    char * end_ptr;
    size_t start = std::strtol(argv[2], &end_ptr, 16);
    size_t end = std::strtol(argv[3], &end_ptr, 16);


    fprintf(stderr, "Beginning BDD generation on instruction range \u001b[46m [0x%016lx, 0x%016lx) \u001b[0m\n", start, end);


    bdd_init(10000000, 10000);
    bdd_setvarnum(32);

    int order[] = {
        31,
        25, 26, 27, 28,
        29, 30,
        24, 23, 22, 21, 20, 19, 18, 17, 16,
        15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };
    bdd_setvarorder(order);

    bdd full = bddfalse;
    for (size_t i = start; i < end; i++) {
        if (i % 5000000 == 0) {
            fprintf(stderr, "%.1f\n", (float) (i - start) / (float) (end - start) * 100);
        }
        if (lfi_verify_insn((uint32_t) i)) {
            full |= add_value(i);
        }
    }

    FILE* f = fopen(argv[1], "w");
    if (!f) {
        fprintf(stderr, "could not open %s\n", argv[1]);
        perror("open");
        return 1;
    }
    bdd_save(f, full);
    fclose(f);

    return 0;
}
