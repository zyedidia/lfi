#ifdef HAVE_LIBELF

#include <stdio.h>
#include <unistd.h>
#include <libelf.h>
#include <gelf.h>

int perf_output_jit_interface_file(uint8_t * buffer, size_t file_size, uintptr_t offset) {

    Elf *e = elf_memory((char *) buffer, file_size);
    if (!e) {
        fprintf(stderr, "elf_memory failed: %s\n", elf_errmsg(-1));
        return 1;
    }

    char output_file[256];
    snprintf(output_file, sizeof(output_file), "/tmp/perf-%d.map", getpid());
    FILE *out = fopen(output_file, "w");
    if (!out) {
        perror("fopen");
        goto err;
    }

    if (elf_version(EV_CURRENT) == EV_NONE) {
        fprintf(stderr, "ELF library initialization failed: %s\n", elf_errmsg(-1));
        goto err;
    }

    size_t shstrndx;
    if (elf_getshdrstrndx(e, &shstrndx) != 0) {
        fprintf(stderr, "elf_getshdrstrndx failed: %s\n", elf_errmsg(-1));
        goto err;
    }

    Elf_Scn *scn = NULL;
    while ((scn = elf_nextscn(e, scn)) != NULL) {
        GElf_Shdr shdr;
        if (!gelf_getshdr(scn, &shdr)) {
            fprintf(stderr, "gelf_getshdr failed: %s\n", elf_errmsg(-1));
	    goto err;
        }

        // Look for symbol table sections
        if (shdr.sh_type == SHT_SYMTAB) {
            Elf_Data *data = elf_getdata(scn, NULL);
            if (!data) {
                fprintf(stderr, "elf_getdata failed: %s\n", elf_errmsg(-1));
		goto err;
            }

            size_t num_symbols = shdr.sh_size / shdr.sh_entsize;
            for (size_t i = 0; i < num_symbols; ++i) {
                GElf_Sym sym;
                if (!gelf_getsym(data, i, &sym)) {
                    fprintf(stderr, "gelf_getsym failed: %s\n", elf_errmsg(-1));
                    continue;
                }

                // Get symbol name
                const char *name = elf_strptr(e, shdr.sh_link, sym.st_name);
                if (!name) {
                    name = "<no name>";
                }

                // Write to perf map file
                fprintf(out, "%016lx %08lx %s\n",
                        (unsigned long)sym.st_value + offset,
                        (unsigned long)sym.st_size,
                        name);
            }
        }
    }

    elf_end(e);
    fclose(out);
    printf("Perf map written to: %s\n", output_file);
    return 0;
err:
    if (e) elf_end(e);
    if (out) fclose(out);
    return 1;
}

#else

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "print.h"

int perf_output_jit_interface_file(uint8_t * buffer, size_t file_size, uintptr_t offset) {
    (void) buffer, (void) file_size, (void) offset;
    WARN("perf support is disabled because libtux was built without libelf");
    return 0;
}

#endif
