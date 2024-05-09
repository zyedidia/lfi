#pragma once

#include <stdint.h>

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
};

struct elf_file_header {
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

struct elf_prog_header {
    uint32_t type;
    uint32_t flags;
    uint64_t offset;
    uint64_t vaddr;
    uint64_t paddr;
    uint64_t filesz;
    uint64_t memsz;
    uint64_t align;
};
