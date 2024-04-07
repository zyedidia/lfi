#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <sys/mman.h>
#include "elf.h"

#include <capstone/capstone.h>

enum {
    NOP = 0xd503201f,
    OP_SUB = (0b110100010UL << 23),
    OP_ADD = (0b100100010UL << 23),
};

static uint32_t arm64_sub_x23(int64_t imm) {
    if (imm < 4096) {
        return OP_SUB | (imm << 10) | (23 << 5) | (23);
    }
    // TODO: ceil the immediate correctly
    return OP_SUB | (1 << 22) | ((imm >> 12) << 10) | (23 << 5) | (23);
}

static uint32_t arm64_add_x23(int64_t imm) {
    if (imm < 4096) {
        return OP_ADD | (imm << 10) | (23 << 5) | (23);
    }
    return OP_ADD | (1 << 22) | ((imm >> 12) << 10) | (23 << 5) | (23);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "no input binary\n");
        exit(1);
    }

    FILE* f = fopen(argv[1], "r+");
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

    csh handle;
    if (cs_open(CS_ARCH_AARCH64, CS_MODE_ARM, &handle) != CS_ERR_OK) {
        return false;
    }
    cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);

    struct elf_file_header* ehdr = (struct elf_file_header*) buf;
    struct elf_prog_header* phdr = (struct elf_prog_header*) &buf[ehdr->phoff];
    
    for (int i = 0; i < ehdr->phnum; i++) {
        struct elf_prog_header* p = &phdr[i];
        if (p->type != PT_LOAD) {
            continue;
        }
        if ((p->flags & PF_X) == 0) {
            continue;
        }

        uint32_t* insns = (uint32_t*) (&buf[p->offset]);
        size_t n = p->filesz / sizeof(uint32_t);

        for (size_t i = 0; i < n; i++) {
            // disasm instruction
            cs_insn* csi;
            size_t count = cs_disasm(handle, (const uint8_t*) &insns[i], sizeof(uint32_t), p->vaddr + i * 4, 1, &csi);
            if (count != 1) {
                continue;
            }

            // direct branches: check forward or backward
            int64_t target = 0;
            switch (csi->id) {
            case AArch64_INS_B:
            case AArch64_INS_BL:
                target = csi->detail->aarch64.operands[0].imm;
                break;
            case AArch64_INS_CBZ:
            case AArch64_INS_CBNZ:
                target = csi->detail->aarch64.operands[1].imm;
                break;
            case AArch64_INS_TBZ:
            case AArch64_INS_TBNZ:
                if (csi->detail->aarch64.operands[0].reg == AArch64_REG_X23) {
                    continue;
                }
                target = csi->detail->aarch64.operands[2].imm;
                break;
            default:
                continue;
            }
            if (insns[i - 1] != 0xd4200000) {
                printf("BAD: %lx, %x\n", csi->address, insns[i]);
                continue;
            }
            if ((target - (int64_t) csi->address) > 0) {
                // forward branches: turn tbz check into nops
                insns[i - 1] = NOP;
                insns[i - 2] = NOP;
                insns[i - 3] = arm64_add_x23((target - (int64_t) csi->address) >> 2);
            } else {
                insns[i - 3] = arm64_sub_x23(((int64_t) csi->address - target) >> 2);
            }
        }
    }

    munmap(buf, sz);
    fclose(f);

    return 0;
}
