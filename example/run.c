#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "lfi.h"

static size_t gb(size_t n) {
    return n * 1024 * 1024 * 1024;
}

enum {
    STACK_SIZE = 2UL * 1024 * 1024,
};

static void readfile(FILE* f, void** buf, size_t* size) {
    if (fseek(f, 0, SEEK_END) != 0) {
        perror("fseek");
        exit(1);
    }
    long sz = ftell(f);
    if (fseek(f, 0, SEEK_SET) != 0) {
        perror("fseek");
        exit(1);
    }
    void* b = malloc(sz);
    assert(b);
    size_t n = fread(b, sz, 1, f);
    assert(n == 1);

    *buf = b;
    *size = sz;
}

uint64_t syscall_handler(void* ctxp, uint64_t sysno, uint64_t args[6]) {
    printf("received syscall %ld: %s\n", sysno, (char*) args[0]);
    exit(1);
}

int main(int argc, char** argv) {
    struct lfi* lfi = lfi_new((struct lfi_options) {
        .page_size = getpagesize(),
        .stack_size = STACK_SIZE,
        .syscall_handler = &syscall_handler,
    });

    int err;
    if ((err = lfi_add_vaspace(lfi, (void*) gb(8), gb(128))) < 0) {
        fprintf(stderr, "error adding address space %d\n", err);
        exit(1);
    }

    printf("max procs: %ld\n", lfi_max_procs(lfi));

    if (argc <= 1) {
        fprintf(stderr, "no input binary\n");
        exit(1);
    }

    FILE* f = fopen(argv[1], "r");
    if (!f) {
        fprintf(stderr, "error opening %s: %s\n", argv[1], strerror(errno));
    }

    void* buf;
    size_t size;
    readfile(f, &buf, &size);

    struct lfi_proc_info info;
    struct lfi_proc* proc = lfi_add_proc(lfi, buf, size, NULL, &info, &err);
    if (!proc) {
        fprintf(stderr, "error loading: %d\n", err);
        exit(1);
    }

    printf("loaded %s, entry: %lx, stack: %p\n", argv[1], info.elf_entry, info.stack);

    lfi_proc_start(proc, info.elf_entry, info.stack, info.stack_size);

    return 0;
}
