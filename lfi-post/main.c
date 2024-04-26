#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdbool.h>
#include "elf.h"

#include <capstone/capstone.h>

enum {
    NOP = 0xd503201f,
    BTI_JC = 0xd50324df,
    OP_SUB = (0b110100010UL << 23),
    OP_ADD = (0b100100010UL << 23),
};

static uint32_t ceilimm(uint32_t imm, uint32_t align) {
    uint32_t mask = align - 1;
    return (imm + mask) & ~mask;
}

static uint32_t arm64_sub_x23(int64_t imm) {
    if (imm < 4096) {
        return OP_SUB | (imm << 10) | (23 << 5) | (23);
    }
    if (imm % 4096 != 0) {
        imm = ceilimm(imm, 4096);
    }
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

    bool gasrel = false;
    bool gasdir = false;
    bool precise = false;
    bool aligned = false;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "--gas-rel") == 0) {
            gasrel = true;
        } else if (strcmp(argv[i], "--gas") == 0) {
            gasdir = true;
        } else if (strcmp(argv[i], "--precise") == 0) {
            precise = true;
        } else if (strcmp(argv[i], "--aligned") == 0) {
            aligned = true;
        }
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

        bool* leaders = malloc(sizeof(bool) * n);
        assert(leaders);

        // first instruction is a leader
        leaders[0] = true;

        if (gasdir) {
            // calculate basic blocks
            for (size_t i = 0; i < n; i++) {
                cs_insn* csi;
                size_t count = cs_disasm(handle, (const uint8_t*) &insns[i], sizeof(uint32_t), i * 4, 1, &csi);
                if (count != 1) {
                    continue;
                }

                // target of a branch is a leader
                int64_t target = 0;
                switch (csi->id) {
                case AArch64_INS_B:
                case AArch64_INS_BL:
                    target = csi->detail->aarch64.operands[0].imm;
                    leaders[target / 4] = true;
                    break;
                case AArch64_INS_CBZ:
                case AArch64_INS_CBNZ:
                    target = csi->detail->aarch64.operands[1].imm;
                    leaders[target / 4] = true;
                    break;
                case AArch64_INS_TBZ:
                case AArch64_INS_TBNZ:
                    if (csi->detail->aarch64.operands[0].reg == AArch64_REG_X23) {
                        continue;
                    }
                    target = csi->detail->aarch64.operands[2].imm;
                    leaders[target / 4] = true;
                    break;
                case AArch64_INS_BLR:
                case AArch64_INS_BR:
                case AArch64_INS_RET:
                    break;
                case AArch64_BTI_JC:
                case AArch64_BTI_C:
                case AArch64_BTI_J:
                    // rewrite bti c and bti j into bti jc
                    insns[i] = BTI_JC;
                    leaders[i] = true;
                    cs_free(csi, 1);
                    continue;
                default:
                    cs_free(csi, 1);
                    continue;
                }
                // instruction immediately following a branch is a leader
                if (i + 1 < n) {
                    leaders[i + 1] = true;
                }

                cs_free(csi, 1);
            }
        }

        size_t cur_leader = 0;
        for (size_t i = 0; i < n; i++) {
            // disasm instruction
            cs_insn* csi;
            size_t count = cs_disasm(handle, (const uint8_t*) &insns[i], sizeof(uint32_t), p->vaddr + i * 4, 1, &csi);
            if (count != 1) {
                continue;
            }

            if (leaders[i]) {
                cur_leader = i;
            }

            // direct branches: check forward or backward
            int64_t target = 0;
            bool cond = false;
            bool branch = false;
            bool indbranch = false;
            switch (csi->id) {
            case AArch64_INS_B:
                cond = csi->detail->aarch64.cc != AArch64CC_AL && csi->detail->aarch64.cc != AArch64CC_NV && csi->detail->aarch64.cc != AArch64CC_Invalid;
                target = csi->detail->aarch64.operands[0].imm;
                branch = true;
                break;
            case AArch64_INS_BL:
                target = csi->detail->aarch64.operands[0].imm;
                branch = true;
                break;
            case AArch64_INS_CBZ:
            case AArch64_INS_CBNZ:
                target = csi->detail->aarch64.operands[1].imm;
                cond = true;
                branch = true;
                break;
            case AArch64_INS_TBZ:
            case AArch64_INS_TBNZ:
                if (csi->detail->aarch64.operands[0].reg == AArch64_REG_X23) {
                    cs_free(csi, 1);
                    continue;
                }
                target = csi->detail->aarch64.operands[2].imm;
                cond = true;
                branch = true;
                break;
            default:
                if (gasrel) {
                    // relative gas doesn't need to anything for non-direct branches
                    cs_free(csi, 1);
                    continue;
                }
                switch (csi->id) {
                    case AArch64_INS_BR:
                    case AArch64_INS_BLR:
                    case AArch64_INS_RET:
                        if (csi->id == AArch64_INS_BLR && csi->detail->aarch64.operands[0].reg == AArch64_REG_X30) {
                            cs_free(csi, 1);
                            continue;
                        }
                        indbranch = true;
                        branch = true;
                        break;
                }
            }
            if (gasrel) {
                assert(branch);
            }
            size_t idx = i;
            if (gasdir) {
                if (branch) {
                    // current instruction is a branch
                } else if (i + 1 < n && leaders[i + 1]) {
                    // next instruction is a leader
                    idx = i + 1;
                } else {
                    cs_free(csi, 1);
                    continue;
                }
            }
            if (!indbranch && insns[idx - 1] != 0xd4200000) {
                printf("error, %d did not see brk #0 before direct branch: %lx, %x %d\n", branch, csi->address, insns[idx], leaders[idx]);
                /* insns[idx - 1] = 0; */
                leaders[idx] = false;
                cs_free(csi, 1);
                continue;
            }
            if (indbranch && gasdir) {
                // calculate direct gas immediate
                int64_t imm = idx - cur_leader - 1 + (branch ? 1 : 0);
                if (aligned) {
                    insns[idx - 7] = arm64_sub_x23(imm);
                } else {
                    insns[idx - 3] = arm64_sub_x23(imm);
                }
            } else if ((target - (int64_t) csi->address) > 0) {
                // forward branches: turn tbz check into nops
                insns[idx - 1] = NOP;
                insns[idx - 2] = NOP;
                if (gasrel && precise) {
                    insns[idx - 3] = NOP;
                }
                if (cond && gasrel) {
                    // relative gas cannot refund a forwards conditional branch
                    insns[idx - 3] = NOP;
                    if (precise) {
                        // precise version uses double sub
                        if (((insns[idx - 4] >> 23) & 0b111111) != 0b100010) {
                            assert(!"bad");
                        }
                        if (((insns[idx - 5] >> 23) & 0b111111) != 0b100010) {
                            assert(!"bad");
                        }
                        insns[idx - 4] = NOP;
                        insns[idx - 5] = NOP;
                        assert(!aligned && branch && !indbranch);
                    }
                } else if (gasrel) {
                    // calculate relative gas immediate
                    int64_t imm = ((target - (int64_t) csi->address) >> 2) - 1;
                    if (precise) {
                        // precise version uses double sub
                        if (((insns[idx - 4] >> 23) & 0b111111) != 0b100010) {
                            printf("%lx\n", csi->address);
                            assert(!"bad");
                        }
                        if (((insns[idx - 5] >> 23) & 0b111111) != 0b100010) {
                            assert(!"bad");
                        }
                        insns[idx - 4] = arm64_add_x23(imm / 4096 * 4096);
                        insns[idx - 5] = arm64_add_x23(imm % 4096);
                        assert(!aligned);
                    } else {
                        insns[idx - 3] = arm64_add_x23(imm);
                    }
                } else if (gasdir) {
                    // calculate direct gas immediate
                    int64_t imm = idx - cur_leader + (branch ? 1 : 0);
                    insns[idx - 3] = arm64_sub_x23(imm);
                }
            } else {
                if (gasrel) {
                    // calculate relative gas immediate
                    int64_t imm = ((int64_t) csi->address - target) >> 2;
                    if (precise) {
                        // precise version uses double sub
                        if (((insns[idx - 4] >> 23) & 0b111111) != 0b100010) {
                            assert(!"bad");
                        }
                        if (((insns[idx - 5] >> 23) & 0b111111) != 0b100010) {
                            assert(!"bad");
                        }
                        insns[idx - 4] = arm64_sub_x23(imm / 4096 * 4096);
                        insns[idx - 5] = arm64_sub_x23(imm % 4096);
                        assert(!aligned);
                    } else {
                        insns[idx - 3] = arm64_sub_x23(imm);
                    }
                } else if (gasdir) {
                    // calculate direct gas immediate
                    int64_t imm = idx - cur_leader - 1 + (branch ? 1 : 0); // don't charge for the brk #0

                    insns[idx - 3] = arm64_sub_x23(imm);
                }
            }
            cs_free(csi, 1);
        }
        free(leaders);
    }

    munmap(buf, sz);
    fclose(f);

    return 0;
}
