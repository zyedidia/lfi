module elf;

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

    PF_X = 1 << 0,
    PF_W = 1 << 1,
    PF_R = 1 << 2,

    ELFCLASS64 = 2,

    EV_CURRENT = 1,
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

char* elf_interp(ubyte* buf) {
    FileHeader* hdr = cast(FileHeader*) buf;
    ProgHeader* phdr = cast(ProgHeader*) (buf + hdr.phoff);

    for (int x = 0; x < hdr.phnum; x++) {
        if (phdr[x].type == PT_INTERP) {
            return cast(char*) buf + phdr[x].offset;
        }
    }
    return null;
}
