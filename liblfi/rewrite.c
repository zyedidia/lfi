#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <Zydis/Zydis.h>

enum {
    BUNDLE_SIZE = 32,
};

void lfi_rewrite_code(uint8_t* insns, size_t n, size_t addr) {
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

    ZydisDecoderContext context;
    ZydisDecodedInstruction instr;
    size_t count = 0;
    size_t curbundle = 0;
    while (count < n) {
        ZyanStatus status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count], n-count, &instr);
        if (ZYAN_FAILED(status)) {
            fprintf(stderr, "failed %lx\n", addr);
            return;
        }

        if (instr.mnemonic == ZYDIS_MNEMONIC_CALL) {
            ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT];
            status = ZydisDecoderDecodeOperands(&decoder, &context, &instr,
                    operands, instr.operand_count);

            if (operands[0].type == ZYDIS_OPERAND_TYPE_MEMORY && operands[0].mem.segment == ZYDIS_REGISTER_GS) {
            } else {
                if ((addr + instr.length) % BUNDLE_SIZE != 0) {
                    ZydisDecodedInstruction next;
                    size_t noplen = 0;
                    do {
                        status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count+instr.length+noplen], n-count-instr.length-noplen, &next);
                        assert(!ZYAN_FAILED(status));
                        if (next.mnemonic != ZYDIS_MNEMONIC_NOP) {
                            fprintf(stderr, "%lx: error: expected nop after unaligned call\n", addr);
                            exit(1);
                        }
                        noplen += next.length;
                    } while ((addr + instr.length + noplen) % BUNDLE_SIZE != 0);

                    char* nop = malloc(noplen);
                    memcpy(nop, &insns[count+instr.length], noplen);

                    char* call = malloc(instr.length);
                    memcpy(call, &insns[count], instr.length);

                    if (operands[0].type == ZYDIS_OPERAND_TYPE_IMMEDIATE && instr.length == 5) {
                        operands[0].imm.value.u -= noplen;
                        ZydisEncoderRequest req;
                        memset(&req, 0, sizeof(req));
                        ZydisEncoderDecodedInstructionToEncoderRequest(&instr, operands, instr.operand_count_visible, &req);
                        ZyanUSize encoded_length = instr.length;
                        if (ZYAN_FAILED(ZydisEncoderEncodeInstruction(&req, call, &encoded_length))) {
                            fprintf(stderr, "error: zyan failed\n");
                            exit(1);
                        }
                    }

                    memcpy(&insns[count], nop, noplen);
                    memcpy(&insns[count+noplen], call, instr.length);
                    addr += noplen;
                    count += noplen;
                }
            }
        }

        addr += instr.length;
        count += instr.length;

        if (count - curbundle >= BUNDLE_SIZE) {
            addr = addr - (addr % BUNDLE_SIZE);
            count = count - (count % BUNDLE_SIZE);
            curbundle = count;
        }
    }
}
