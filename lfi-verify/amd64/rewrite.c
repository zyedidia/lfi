#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <Zydis/Zydis.h>

enum {
    BUNDLE_SIZE = 16,
};

void rewrite(uint8_t* insns, size_t n, size_t addr) {
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

    ZydisDecoderContext context;
    ZydisDecodedInstruction instr;
    size_t count = 0;
    while (count < n) {
        ZyanStatus status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count], n-count, &instr);
        if (ZYAN_FAILED(status)) {
            printf("failed %lx\n", addr);
            return false;
        }

        if (instr.mnemonic == ZYDIS_MNEMONIC_CALL) {
            ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT];
            status = ZydisDecoderDecodeOperands(&decoder, &context, &instr,
                    operands, instr.operand_count);

            if (operands[0].type == ZYDIS_OPERAND_TYPE_MEMORY && operands[0].mem.segment == ZYDIS_REGISTER_GS) {
            } else {
                if ((addr + instr.length) % BUNDLE_SIZE != 0) {
                    ZydisDecodedInstruction next;
                    status = ZydisDecoderDecodeInstruction(&decoder, &context, &insns[count+instr.length], n-count-instr.length, &next);
                    assert(!ZYAN_FAILED(status) && next.mnemonic == ZYDIS_MNEMONIC_NOP);

                    char* nop = malloc(next.length);
                    memcpy(nop, &insns[count+instr.length], next.length);

                    char* call = malloc(instr.length);
                    memcpy(call, &insns[count], instr.length);

                    if (operands[0].type == ZYDIS_OPERAND_TYPE_IMMEDIATE && instr.length == 5) {
                        operands[0].imm.value.u -= next.length;
                        ZydisEncoderRequest req;
                        memset(&req, 0, sizeof(req));
                        ZydisEncoderDecodedInstructionToEncoderRequest(&instr, operands, instr.operand_count_visible, &req);
                        ZyanUSize encoded_length = instr.length;
                        if (ZYAN_FAILED(ZydisEncoderEncodeInstruction(&req, call, &encoded_length))) {
                            fprintf(stderr, "error: zyan failed\n");
                            exit(1);
                        }
                    }

                    memcpy(&insns[count], nop, next.length);
                    memcpy(&insns[count+next.length], call, instr.length);
                    addr += next.length;
                    count += next.length;
                }
            }
        }

        addr += instr.length;
        count += instr.length;
    }
}
