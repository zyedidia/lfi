module elf;

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
}

struct FileHeader {
    alias uword = ulong;

    uint magic;
    ubyte width;
    ubyte[11] _elf;
    ushort type;
    ushort machine;
    uint version_;
    uword entry;
    uword phoff;
    uword shoff;
    uint flags;
    ushort ehsize;
    ushort phentsize;
    ushort phnum;
    ushort shentsize;
    ushort shnum;
    ushort shstrndx;
}

struct ProgHeader {
    alias uword = ulong;

    uint type;
    uint flags;
    uword offset;
    uword vaddr;
    uword paddr;
    uword filesz;
    uword memsz;
    uword align_;
}

struct Auxv {
    ulong a_type;
    ulong a_val;
}

char* elfinterp(ubyte* buf) {
    FileHeader* hdr = cast(FileHeader*) buf;
    ProgHeader* phdr = cast(ProgHeader*) (buf + hdr.phoff);

    for (int x = 0; x < hdr.phnum; x++) {
        if (phdr[x].type == PT_INTERP) {
            return cast(char*) buf + phdr[x].offset;
        }
    }
    return null;
}
