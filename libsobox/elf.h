#pragma once

#include <stdint.h>
#include <stdlib.h>

enum {
    PT_NULL    = 0,
    PT_LOAD    = 1,
    PT_DYNAMIC = 2,
    PT_INTERP  = 3,
    PT_NOTE    = 4,
    PT_SHLIB   = 5,
    PT_PHDR    = 6,
    PT_TLS     = 7,
    PT_NUM     = 8,
    AT_NULL   = 0,

    AT_IGNORE = 1,
    AT_EXECFD = 2,
    AT_PHDR   = 3,
    AT_PHENT  = 4,
    AT_PHNUM  = 5,
    AT_PAGESZ = 6,
    AT_BASE   = 7,
    AT_FLAGS  = 8,
    AT_ENTRY  = 9,
    AT_NOTELF = 10,
    AT_UID    = 11,
    AT_EUID   = 12,
    AT_GID    = 13,
    AT_EGID   = 14,
    AT_CLKTCK = 17,
    AT_HWCAP  = 16,
    AT_SECURE = 23,
    AT_RANDOM = 25,
    AT_HWCAP2 = 17,
    AT_EXECFN = 31,
};

typedef struct {
    uint32_t magic;
    uint8_t width;
    uint8_t _elf[11];
    uint16_t type;
    uint16_t machine;
    uint32_t version_;
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
} FileHeader;

typedef struct {
    uint32_t type;
    uint32_t flags;
    uint64_t offset;
    uint64_t vaddr;
    uint64_t paddr;
    uint64_t filesz;
    uint64_t memsz;
    uint64_t align_;
} ProgHeader;

typedef struct {
    uint64_t a_type;
    uint64_t a_val;
} Auxv;

static char*
elfinterp(uint8_t* buf)
{
    FileHeader* hdr = (FileHeader*) buf;
    ProgHeader* phdr = (ProgHeader*) (buf + hdr->phoff);

    for (int x = 0; x < hdr->phnum; x++) {
        if (phdr[x].type == PT_INTERP) {
            return (char*) buf + phdr[x].offset;
        }
    }
    return NULL;
}