#include <capstone/capstone.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "verify.h"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "usage: %s verified.dat\n", argv[0]);
        return 1;
    }

    size_t n_verify = 0x0ffffffffULL + 1;
    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (ftruncate(fd, n_verify) == -1) {
        printf("failed to ftruncate\n");
        return 1;
    }
    uint8_t* data = mmap(NULL, n_verify, PROT_WRITE, MAP_SHARED, fd, 0);
    if (data == (uint8_t*) -1) {
        printf("failed to mmap\n");
        return 1;
    }

    if (!verify_init()) {
        fprintf(stderr, "failed to initialize disassembler\n");
        return 1;
    }

    size_t total = 0;
    for (size_t i = 0; i < n_verify; i++) {
        if (i % 10000000 == 0) {
            printf("%lu\n", i);
        }
        int verified = (int) verify_insn((uint32_t) i);
        data[i] = verified;
        if (verified) {
            total++;
        }
    }
    printf("total allowed: %ld\n", total);

    close(fd);
    return 0;
}
