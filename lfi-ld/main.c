#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <Zydis/Zydis.h>

#include "elf.h"

void rewrite(uint8_t* insns, size_t n, size_t addr);

int main(int argc, char** argv) {
    if (argc <= 1) {
        fprintf(stderr, "no input binary\n");
        exit(1);
    }

    char* filename = NULL;
    // search for the -o flag that the linker was invoked with so we can write
    // process that file
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            if (i == argc - 1) {
                fprintf(stderr, "no value provided for -o");
                exit(1);
            }
            filename = argv[i + 1];
            i++;
        }
    }

    if (!filename) {
        fprintf(stderr, "no file found");
        exit(1);
    }

    FILE* f = fopen(filename, "r+");
    if (!f) {
        fprintf(stderr, "error opening %s: %s\n", argv[1], strerror(errno));
        exit(1);
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

    uint8_t* buf = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(f), 0);
    if (buf == (uint8_t*) -1) {
        perror("mmap");
        exit(1);
    }
    fclose(f);

    struct elf_file_header* ehdr = (struct elf_file_header*) buf;
    struct elf_prog_header* phdr = (struct elf_prog_header*) &buf[ehdr->phoff];

    if (ehdr->magic != ELF_MAGIC)
        return 0;
    if (ehdr->type != ET_DYN && ehdr->type != ET_EXEC)
        return 0;
    printf("rewriting\n");
    
    size_t total = 0;
    for (int i = 0; i < ehdr->phnum; i++) {
        struct elf_prog_header* p = &phdr[i];
        if (p->type != PT_LOAD) {
            continue;
        }
        if ((p->flags & PF_X) == 0) {
            continue;
        }

        uint8_t* insns = (uint8_t*) (&buf[p->offset]);
        size_t n = p->filesz;

        rewrite(insns, n, p->vaddr);
        total += n;
    }

    munmap(buf, sz);

    return 0;
}
