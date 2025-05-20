#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef __linux__

bool
perf_output_jit_interface_file(uint8_t *elf_data, size_t size, uintptr_t offset)
{
    (void) elf_data, (void) size, (void) offset;
    fprintf(stderr, "perf is not supported on non-linux platforms\n");
    return false;
}

#else

#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <dirent.h>

static bool
direxists(const char* dirname)
{
    DIR* dir = opendir(dirname);
    if (dir) {
        closedir(dir);
        return true;
    }
    return false;
}

bool
perf_output_jit_interface_file(uint8_t *elf_data, size_t size, uintptr_t offset)
{
    char* tmpdir = "/data/local/tmp";
    if (!direxists(tmpdir))
        tmpdir = "/tmp";
    if (!direxists(tmpdir))
        tmpdir = ".";

    char output_file[256];
    snprintf(output_file, sizeof(output_file), "%s/perf-%d.map", tmpdir, getpid());
    FILE *out = fopen(output_file, "w");
    if (!out) {
        perror("fopen");
        goto err;
    }

    // Ensure the buffer is large enough for an ELF header
    if (size < sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Buffer too small for ELF header.\n");
        goto err;
    }

    // Read ELF header
    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)elf_data;

    // Verify ELF magic number
    if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file.\n");
        goto err;
    }

    // Ensure section headers fit within the buffer
    if (ehdr->e_shoff + (ehdr->e_shnum * sizeof(Elf64_Shdr)) > size) {
        fprintf(stderr, "Invalid ELF section headers.\n");
        goto err;
    }

    // Read section headers
    Elf64_Shdr *shdr = (Elf64_Shdr *)(elf_data + ehdr->e_shoff);

    // Find symbol table and string table
    Elf64_Shdr *symtab = NULL, *strtab = NULL;
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            symtab = &shdr[i];
            strtab = &shdr[shdr[i].sh_link]; // Linked string table
            break;
        }
    }

    if (!symtab || !strtab) {
        fprintf(stderr, "No symbol table found.\n");
        goto err;
    }

    // Ensure symbol and string tables fit within the buffer
    if (symtab->sh_offset + symtab->sh_size > size || strtab->sh_offset + strtab->sh_size > size) {
        fprintf(stderr, "Invalid symbol or string table offsets.\n");
        goto err;
    }

    // Read symbol table and string table
    Elf64_Sym *symbols = (Elf64_Sym *)(elf_data + symtab->sh_offset);
    char *strtab_data = (char *)(elf_data + strtab->sh_offset);

    // Calculate number of symbols
    int num_symbols = symtab->sh_size / sizeof(Elf64_Sym);

    // Print symbols
    for (int i = 0; i < num_symbols; i++) {
        if (symbols[i].st_size == 0)
            continue;
        if (symbols[i].st_name != 0) {
            fprintf(out, "0x%016lx 0x%08lx %s\n",
                    (unsigned long)symbols[i].st_value + offset,
                    (unsigned long)symbols[i].st_size,
                    &strtab_data[symbols[i].st_name]);
        }
    }

    fclose(out);
    printf("Perf map written to: %s\n", output_file);
    return true;
err:
    if (out) fclose(out);
    return false;
}

#endif
