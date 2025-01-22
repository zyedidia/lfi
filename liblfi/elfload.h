#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "buf.h"
#include "proc.h"
#include "lfi.h"

enum {
    ELF_MAGIC = 0x464C457FU, // "\x7ELF" in little endian

    PT_NULL    = 0,
    PT_LOAD    = 1,
    PT_DYNAMIC = 2,
    PT_INTERP  = 3,
    PT_NOTE    = 4,
    PT_SHLIB   = 5,
    PT_PHDR    = 6,
    PT_TLS     = 7,
    PT_NUM     = 8,

    ET_NONE   = 0,
    ET_REL    = 1,
    ET_EXEC   = 2,
    ET_DYN    = 3,
    ET_CORE   = 4,
    ET_NUM    = 5,
    ET_LOOS   = 0xfe00,
    ET_HIOS   = 0xfeff,
    ET_LOPROC = 0xff00,
    ET_HIPROC = 0xffff,

    PF_X = 1 << 0,
    PF_W = 1 << 1,
    PF_R = 1 << 2,

    ELFCLASS64 = 2,

    EV_CURRENT = 1,

    AT_NULL         = 0,
    AT_IGNORE       = 1,
    AT_EXECFD       = 2,
    AT_PHDR         = 3,
    AT_PHENT        = 4,
    AT_PHNUM        = 5,
    AT_PAGESZ       = 6,
    AT_BASE         = 7,
    AT_FLAGS        = 8,
    AT_ENTRY        = 9,
    AT_NOTELF       = 10,
    AT_UID          = 11,
    AT_EUID         = 12,
    AT_GID          = 13,
    AT_EGID         = 14,
    AT_CLKTCK       = 17,
    AT_HWCAP        = 16,
    AT_SECURE       = 23,
    AT_RANDOM       = 25,
    AT_HWCAP2       = 17,
    AT_EXECFN       = 31,
    AT_SYSINFO      = 32,
    AT_SYSINFO_EHDR = 33,
};

struct FileHeader {
    uint32_t magic;
    uint8_t width;
    uint8_t _elf[11];
    uint16_t type;
    uint16_t machine;
    uint32_t version;
    uint64_t entry;
    uint64_t phoff;
    uint64_t shoff;
    uint32_t flags;
    uint16_t ehsize;
    uint16_t phentsize;
    uint16_t phnum;
    uint16_t shentsize;
    uint16_t shnum;
    uint16_t shstrndx;
};

struct ProgHeader {
    uint32_t type;
    uint32_t flags;
    uint64_t offset;
    uint64_t vaddr;
    uint64_t paddr;
    uint64_t filesz;
    uint64_t memsz;
    uint64_t align;
};

struct Auxv {
    uint64_t a_type;
    uint64_t a_val;
};

enum {
    // Maximum size of interp string.
    INTERP_MAX = 1024,
    // Maximum phnum.
    PHNUM_MAX  = 64,
};

// The return value is dynamically allocated and must be freed by
// the caller.
static inline char*
elfinterp(uint8_t* progdat, size_t progsz)
{
    buf_t prog = (buf_t) {
        .data = progdat,
        .size = progsz,
    };

    struct FileHeader ehdr;
    size_t n = bufread(prog, &ehdr, sizeof(ehdr), 0);
    if (n != sizeof(ehdr))
        return NULL;

    if (ehdr.phnum >= PHNUM_MAX)
        return NULL;

    struct ProgHeader phdr[ehdr.phnum];
    n = bufread(prog, phdr, sizeof(struct ProgHeader) * ehdr.phnum, ehdr.phoff);
    if (n != sizeof(struct ProgHeader) * ehdr.phnum)
        return NULL;

    for (int x = 0; x < ehdr.phnum; x++) {
        if (phdr[x].type == PT_INTERP) {
            if (phdr[x].filesz >= INTERP_MAX)
                return NULL;
            char* interp = malloc(phdr[x].filesz);
            if (!interp)
                return NULL;
            size_t n = bufread(prog, interp, phdr[x].filesz, phdr[x].offset);
            if (n != phdr[x].filesz) {
                free(interp);
                return NULL;
            }
            return interp;
        }
    }
    return NULL;
}

bool elfload(struct TuxThread* p, uint8_t* prog, size_t progsz, uint8_t* interp, size_t interpsz, struct LFILoadInfo* o_info);
