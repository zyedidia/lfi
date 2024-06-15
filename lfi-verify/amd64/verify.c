#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <Zydis/Zydis.h>

enum {
    BUNDLE_SIZE = 16,
};

typedef struct context {
    ZydisDecoder decoder;
    ZydisDecoderContext zcontext;
    ZydisDecodedInstruction instr;
    ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT];

    uint8_t* insns;
    size_t n;
    size_t addr;
    size_t count;

    size_t s_addr;
    size_t s_count;
    ZydisDecodedInstruction s_instr;
    ZydisDecoderContext s_zcontext;
} Context;

static bool ctxnext(Context* ctx) {
    if (ctx->instr.length != 0) {
        ctx->addr += ctx->instr.length;
        ctx->count += ctx->instr.length;
    }
    ZyanStatus status = ZydisDecoderDecodeInstruction(&ctx->decoder, &ctx->zcontext, &ctx->insns[ctx->count], ctx->n - ctx->count, &ctx->instr);
    if (ZYAN_FAILED(status)) {
        return false;
    }
    if (ctx->addr / BUNDLE_SIZE != (ctx->addr + ctx->instr.length - 1) / BUNDLE_SIZE) {
        fprintf(stderr, "instruction crosses bundle boundary at %lx\n", ctx->addr);
        return false;
    }

    if (ctx->instr.length == 2 && ctx->insns[ctx->count] == 0 && ctx->insns[ctx->count + 1] == 0) {
        // ud2
        ctx->insns[ctx->count] = 0x0f;
        ctx->insns[ctx->count + 1] = 0xb;
        return ctxnext(ctx);
    }

    return true;
}

static void ctxsave(Context* ctx) {
    ctx->s_addr = ctx->addr;
    ctx->s_count = ctx->count;
    ctx->s_instr = ctx->instr;
    ctx->s_zcontext = ctx->zcontext;
}

static void ctxrestore(Context* ctx) {
    ctx->addr = ctx->s_addr;
    ctx->count = ctx->s_count;
    ctx->instr = ctx->s_instr;
    ctx->zcontext = ctx->s_zcontext;
}

static bool ctxoperands(Context* ctx) {
    ZyanStatus status = ZydisDecoderDecodeOperands(&ctx->decoder, &ctx->zcontext, &ctx->instr, ctx->operands, ctx->instr.operand_count);
    if (ZYAN_FAILED(status)) {
        return false;
    }
    return true;
}

static bool loreg(ZydisRegister reg) {
    switch (reg) {
    case ZYDIS_REGISTER_EAX:
    case ZYDIS_REGISTER_ECX:
    case ZYDIS_REGISTER_EDX:
    case ZYDIS_REGISTER_EBX:
    case ZYDIS_REGISTER_ESP:
    case ZYDIS_REGISTER_EBP:
    case ZYDIS_REGISTER_ESI:
    case ZYDIS_REGISTER_EDI:
    case ZYDIS_REGISTER_R8D:
    case ZYDIS_REGISTER_R9D:
    case ZYDIS_REGISTER_R10D:
    case ZYDIS_REGISTER_R11D:
    case ZYDIS_REGISTER_R12D:
    case ZYDIS_REGISTER_R13D:
    case ZYDIS_REGISTER_R14D:
    case ZYDIS_REGISTER_R15D:
        return true;
    }
    return false;
}

static ZydisRegister hi(ZydisRegister reg) {
    switch (reg) {
    case ZYDIS_REGISTER_EAX:
        return ZYDIS_REGISTER_RAX;
    case ZYDIS_REGISTER_ECX:
        return ZYDIS_REGISTER_RCX;
    case ZYDIS_REGISTER_EDX:
        return ZYDIS_REGISTER_RDX;
    case ZYDIS_REGISTER_EBX:
        return ZYDIS_REGISTER_RBX;
    case ZYDIS_REGISTER_ESP:
        return ZYDIS_REGISTER_RSP;
    case ZYDIS_REGISTER_EBP:
        return ZYDIS_REGISTER_RBP;
    case ZYDIS_REGISTER_ESI:
        return ZYDIS_REGISTER_RSI;
    case ZYDIS_REGISTER_EDI:
        return ZYDIS_REGISTER_RDI;
    case ZYDIS_REGISTER_R8D:
        return ZYDIS_REGISTER_R8;
    case ZYDIS_REGISTER_R9D:
        return ZYDIS_REGISTER_R9;
    case ZYDIS_REGISTER_R10D:
        return ZYDIS_REGISTER_R10;
    case ZYDIS_REGISTER_R11D:
        return ZYDIS_REGISTER_R11;
    case ZYDIS_REGISTER_R12D:
        return ZYDIS_REGISTER_R12;
    case ZYDIS_REGISTER_R13D:
        return ZYDIS_REGISTER_R13;
    case ZYDIS_REGISTER_R14D:
        return ZYDIS_REGISTER_R14;
    case ZYDIS_REGISTER_R15D:
        return ZYDIS_REGISTER_R15;
    }
    assert(0);
}

static bool check_instr(Context* ctx) {
    // TODO: switch this to a whitelist
    switch (ctx->instr.mnemonic) {
    case ZYDIS_MNEMONIC_RET:
    case ZYDIS_MNEMONIC_SYSCALL:
        return false;
    }
    return true;
}

static bool check_jump(Context* ctx) {
    switch (ctx->instr.mnemonic) {
    case ZYDIS_MNEMONIC_CALL:
    case ZYDIS_MNEMONIC_JB:
    case ZYDIS_MNEMONIC_JBE:
    case ZYDIS_MNEMONIC_JL:
    case ZYDIS_MNEMONIC_JLE:
    case ZYDIS_MNEMONIC_JMP:
    case ZYDIS_MNEMONIC_JNB:
    case ZYDIS_MNEMONIC_JNBE:
    case ZYDIS_MNEMONIC_JNL:
    case ZYDIS_MNEMONIC_JNLE:
    case ZYDIS_MNEMONIC_JNO:
    case ZYDIS_MNEMONIC_JNP:
    case ZYDIS_MNEMONIC_JNS:
    case ZYDIS_MNEMONIC_JNZ:
    case ZYDIS_MNEMONIC_JO:
    case ZYDIS_MNEMONIC_JP:
    case ZYDIS_MNEMONIC_JS:
    case ZYDIS_MNEMONIC_JZ:
        if (!ctxoperands(ctx)) {
            return false;
        }
        switch (ctx->operands[0].type) {
        case ZYDIS_OPERAND_TYPE_IMMEDIATE:
            size_t target = ctx->addr + ctx->operands[0].imm.value.u + ctx->instr.length;
            if (target % BUNDLE_SIZE != 0) {
                return false;
            }
            return true;
        case ZYDIS_OPERAND_TYPE_MEMORY:
            if (ctx->operands[0].mem.segment == ZYDIS_REGISTER_GS) {
                ZydisDecodedOperandMem* addr = &ctx->operands[0].mem;
                if (addr->type == ZYDIS_MEMOP_TYPE_MEM &&
                        addr->disp.value == 0 &&
                        addr->scale == 0 &&
                        addr->base == ZYDIS_REGISTER_NONE &&
                        addr->index == ZYDIS_REGISTER_NONE) {
                    // runtime call
                    return true;
                }
            }
            return false;
        case ZYDIS_OPERAND_TYPE_REGISTER:
            return false;
        }
    }

    return true;
}

static bool check_mem(Context* ctx) {
    if (ctx->instr.mnemonic == ZYDIS_MNEMONIC_NOP)
        return true;

    ctxoperands(ctx);

    for (size_t i = 0; i < ctx->instr.operand_count; i++) {
        if (ctx->operands[i].type != ZYDIS_OPERAND_TYPE_MEMORY)
            continue;
        if (ctx->operands[i].mem.type == ZYDIS_MEMOP_TYPE_AGEN || ctx->operands[i].mem.type == ZYDIS_MEMOP_TYPE_MIB)
            continue;

        if (ctx->operands[i].mem.base == ZYDIS_REGISTER_RSP) {
            // TODO
            continue;
        }
        if (ctx->operands[i].mem.base == ZYDIS_REGISTER_RIP) {
            // TODO
            continue;
        }
        if (ctx->operands[i].mem.segment == ZYDIS_REGISTER_FS) {
            // TODO
            continue;
        }
        if (ctx->operands[i].mem.segment != ZYDIS_REGISTER_GS) {
            // TODO
            return false;
        }
    }

    return true;
}

static bool check_mod() {
    return true;
}

static bool jump_sequence(Context* ctx) {
    size_t start = ctx->addr;
    if (ctx->addr % BUNDLE_SIZE != 0)
        return false;
    ctxsave(ctx);
    if (ctx->instr.mnemonic != ZYDIS_MNEMONIC_AND)
        goto fail;
    ctxoperands(ctx);
    if (ctx->operands[1].type != ZYDIS_OPERAND_TYPE_IMMEDIATE || ctx->operands[1].imm.value.u != 0xfffffffffffffff0)
        goto fail;
    if (ctx->operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER || !loreg(ctx->operands[0].reg.value))
        goto fail;
    ZydisRegister reg = ctx->operands[0].reg.value;
    if (!ctxnext(ctx))
        goto fail;

    if (ctx->instr.mnemonic != ZYDIS_MNEMONIC_OR)
        goto fail;
    ctxoperands(ctx);
    if (ctx->operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER || ctx->operands[0].reg.value != hi(reg))
        goto fail;
    if (ctx->operands[1].type != ZYDIS_OPERAND_TYPE_REGISTER || ctx->operands[1].reg.value != ZYDIS_REGISTER_R14)
        goto fail;
    
    if (!ctxnext(ctx))
        goto fail;
    if (ctx->instr.mnemonic == ZYDIS_MNEMONIC_NOP)
        if (!ctxnext(ctx))
            goto fail;

    if (ctx->addr - start >= BUNDLE_SIZE)
        goto fail;

    if (ctx->instr.mnemonic != ZYDIS_MNEMONIC_CALL && ctx->instr.mnemonic != ZYDIS_MNEMONIC_JMP)
        goto fail;
    ctxoperands(ctx);
    if (ctx->operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER || ctx->operands[0].reg.value != hi(reg))
        goto fail;

    return true;
fail:
    ctxrestore(ctx);
    return false;
}

static bool mov_lea_sequence(Context* ctx, ZydisRegister reg) {
    if (ctx->instr.mnemonic != ZYDIS_MNEMONIC_MOV)
        return false;
    ctxoperands(ctx);
    if (ctx->operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER || ctx->operands[0].reg.value != reg)
        return false;
    if (ctx->operands[1].type != ZYDIS_OPERAND_TYPE_REGISTER || ctx->operands[1].reg.value != reg)
        return false;
    if (!ctxnext(ctx))
        return false;

    if (ctx->instr.mnemonic != ZYDIS_MNEMONIC_LEA)
        return false;
    ctxoperands(ctx);
    if (ctx->operands[0].type != ZYDIS_OPERAND_TYPE_REGISTER || ctx->operands[0].reg.value != hi(reg))
        return false;
    if (ctx->operands[1].type != ZYDIS_OPERAND_TYPE_MEMORY)
        return false;
    ZydisDecodedOperandMem* mem = &ctx->operands[1].mem;
    if (mem->base != ZYDIS_REGISTER_R14 || mem->index != hi(reg) || mem->scale != 1)
        return false;
    return true;
}

static bool movs_sequence(Context* ctx) {
    size_t start = ctx->addr;
    if (ctx->addr % BUNDLE_SIZE != 0)
        return false;
    ctxsave(ctx);
    if (!mov_lea_sequence(ctx, ZYDIS_REGISTER_EDI))
        goto fail;
    if (!ctxnext(ctx))
        goto fail;
    if (!mov_lea_sequence(ctx, ZYDIS_REGISTER_ESI))
        goto fail;
    
    if (!ctxnext(ctx))
        goto fail;
    if (ctx->instr.mnemonic != ZYDIS_MNEMONIC_MOVSW &&
            ctx->instr.mnemonic != ZYDIS_MNEMONIC_MOVSQ &&
            ctx->instr.mnemonic != ZYDIS_MNEMONIC_MOVSD &&
            ctx->instr.mnemonic != ZYDIS_MNEMONIC_MOVSB)
        goto fail;

    return true;

fail:
    ctxrestore(ctx);
    return false;
}

static bool stos_sequence(Context* ctx) {
    size_t start = ctx->addr;
    if (ctx->addr % BUNDLE_SIZE != 0)
        return false;
    ctxsave(ctx);
    if (!mov_lea_sequence(ctx, ZYDIS_REGISTER_EDI))
        goto fail;
    
    if (!ctxnext(ctx))
        goto fail;
    if (ctx->instr.mnemonic != ZYDIS_MNEMONIC_STOSW &&
            ctx->instr.mnemonic != ZYDIS_MNEMONIC_STOSQ &&
            ctx->instr.mnemonic != ZYDIS_MNEMONIC_STOSD &&
            ctx->instr.mnemonic != ZYDIS_MNEMONIC_STOSB)
        goto fail;

    return true;

fail:
    ctxrestore(ctx);
    return false;
}

bool verify(uint8_t* insns, size_t n, size_t baddr) {
    Context ctx = (Context) {
        .insns = insns,
        .n = n,
        .addr = baddr,
    };
    ZydisDecoderInit(&ctx.decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);

    bool failed = false;

    while (ctxnext(&ctx)) {
        if (!check_instr(&ctx)) {
            fprintf(stderr, "check_instr: error at %lx\n", ctx.addr);
            failed = true;
            continue;
        }

        if (jump_sequence(&ctx)) {
            continue;
        }
        if (stos_sequence(&ctx)) {
            continue;
        }
        if (movs_sequence(&ctx)) {
            continue;
        }

        if (!check_jump(&ctx)) {
            failed = true;
            fprintf(stderr, "check_jump: error at %lx\n", ctx.addr);
            continue;
        }
        if (!check_mem(&ctx)) {
            fprintf(stderr, "check_mem: error at %lx\n", ctx.addr);
            return false;
        }
        /* if (check_mod(&instr)) { */
        /*     return false; */
        /* } */
    }

    if (failed) {
        return false;
    } else if (ctx.count != ctx.n) {
        fprintf(stderr, "stopped decoding at %lx\n", ctx.addr);
        return false;
    }

    return true;
}
