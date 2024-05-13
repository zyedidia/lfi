#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <time.h>

#include "elf.h"

bool lfi_verify_bytes(char* b, size_t size, void* error);

static inline long long unsigned time_ns() {
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts)) {
        exit(1);
    }
    return ((long long unsigned)ts.tv_sec) * 1000000000LLU +
        (long long unsigned)ts.tv_nsec;
}

static bool verify(const char* file) {
    FILE* f = fopen(file, "r+");
    if (!f) {
        fprintf(stderr, "error opening %s: %s\n", file, strerror(errno));
        return false;
    }

    if (fseek(f, 0, SEEK_END) != 0) {
        perror("fseek");
        exit(1);
    }
    long sz = ftell(f);
    if (fseek(f, 0, SEEK_SET) != 0) {
        perror("fseek");
        exit(1);
    }

    char* buf = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(f), 0);
    if (buf == (char*) -1) {
        perror("mmap");
        exit(1);
    }

    printf("verifying %s\n", file);

    struct elf_file_header* ehdr = (struct elf_file_header*) buf;
    struct elf_prog_header* phdr = (struct elf_prog_header*) &buf[ehdr->phoff];
    size_t total = 0;

    long long unsigned t1 = time_ns();
    /* const int times = 1000; */
    const int times = 1;
    for (int n = 0; n < times; n++) {
        for (int i = 0; i < ehdr->phnum; i++) {
            struct elf_prog_header* p = &phdr[i];
            if (p->type != PT_LOAD) {
                continue;
            }
            if ((p->flags & PF_X) == 0) {
                continue;
            }

            if (!lfi_verify_bytes(&buf[p->offset], p->filesz, NULL)) {
                printf("verification failed\n");
                return false;
            }
            total += p->filesz;
        }
    }
    const long long unsigned elapsed = time_ns() - t1;
    munmap(buf, sz);
    fclose(f);

    printf("verification passed (%.1f MiB/s)\n", ((float) total / ((float) elapsed / 1000 / 1000 / 1000)) / 1024 / 1024);
    return true;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        fprintf(stderr, "no input binary\n");
        exit(1);
    }

    bool failed = false;
    for (int i = 1; i < argc; i++) {
        if (!verify(argv[i]))
            failed = true;
    }
    if (failed)
        exit(1);
}
