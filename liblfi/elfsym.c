#include <elf.h>
#include <stdlib.h>

#include "pal/platform.h"

EXPORT bool
lfi_proc_loadsyms(struct LFIContext* ctx, uint8_t* elfdat, size_t elfsize)
{
    Elf64_Ehdr* ehdr = (Elf64_Ehdr*) elfdat;

    if (elfsize < sizeof(Elf64_Ehdr) || memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0) {
        return false;
    }

    Elf64_Shdr *shdrs = (Elf64_Shdr *)((uint8_t*) elfdat + ehdr->e_shoff);

    Elf64_Shdr *symtab_hdr = NULL;
    Elf64_Shdr *strtab_hdr = NULL;

    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (shdrs[i].sh_type == SHT_SYMTAB) {
            symtab_hdr = &shdrs[i];
            strtab_hdr = &shdrs[symtab_hdr->sh_link];
            break;
        }
    }

    if (!symtab_hdr || !strtab_hdr)
        return false;

    ctx->symtab.size = symtab_hdr->sh_size;
    ctx->symtab.tab = malloc(ctx->symtab.size);
    if (!ctx->symtab.tab)
        return false;
    memcpy(ctx->symtab.tab, &elfdat[symtab_hdr->sh_offset], ctx->symtab.size);

    ctx->strtab.size = strtab_hdr->sh_size;
    ctx->strtab.tab = malloc(ctx->strtab.size);
    if (!ctx->strtab.tab)
        goto err;
    memcpy(ctx->strtab.tab, &elfdat[strtab_hdr->sh_offset], ctx->strtab.size);

    return true;

err:
    free(ctx->symtab.tab);
    return false;
}

EXPORT uint64_t
lfi_proc_sym(struct LFIContext* ctx, char* sym)
{
    char* strtab = ctx->strtab.tab;
    Elf64_Sym* syms = (Elf64_Sym*) ctx->symtab.tab;
    int num_syms = ctx->symtab.size / sizeof(Elf64_Sym);

    for (int i = 0; i < num_syms; i++) {
        if (syms[i].st_name >= ctx->strtab.size)
            continue;
        const char* name = &strtab[syms[i].st_name];
        if (strcmp(name, sym) == 0) {
            return ctx->elfbase + syms[i].st_value;
        }
    }

    return 0;
}
