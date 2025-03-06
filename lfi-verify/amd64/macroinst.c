struct MacroInst {
    int size;
    int ninstr;
};

static struct MacroInst macroinst_jmp(Verifier* v, uint8_t* buf, size_t size) {
    // andl $0xffffffe0, %eX
    // orq %r14, %rX
    // jmpq *%rX

    FdInstr i_and, i_or, i_jmp;
    if (fd_decode(&buf[0], size, 64, 0, &i_and) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_and.size], size - i_and.size, 64, 0, &i_or) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_and.size + i_or.size], size - i_and.size - i_or.size, 64, 0, &i_jmp) < 0)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_and) != FDI_AND ||
            FD_OP_TYPE(&i_and, 0) != FD_OT_REG ||
            FD_OP_SIZE(&i_and, 0) != 4 ||
            FD_OP_TYPE(&i_and, 1) != FD_OT_IMM ||
            FD_OP_IMM(&i_and, 1) != 0xffffffffffffffe0)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_or) != FDI_OR ||
            FD_OP_TYPE(&i_or, 0) != FD_OT_REG ||
            FD_OP_TYPE(&i_or, 1) != FD_OT_REG ||
            FD_OP_SIZE(&i_or, 0) != 8 ||
            FD_OP_SIZE(&i_or, 1) != 8 ||
            FD_OP_REG(&i_or, 1) != FD_REG_R14 ||
            FD_OP_REG(&i_or, 0) != FD_OP_REG(&i_and, 0))
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_jmp) != FDI_JMP ||
            FD_OP_TYPE(&i_jmp, 0) != FD_OT_REG ||
            FD_OP_REG(&i_jmp, 0) != FD_OP_REG(&i_and, 0))
        return (struct MacroInst){-1, 0};

    return (struct MacroInst){i_and.size + i_or.size + i_jmp.size, 3};
}

static bool okdisp(int64_t disp) {
    return (disp % 8 == 0) && (disp < 256);
}

static struct MacroInst macroinst_rtcall(Verifier* v, uint8_t* buf, size_t size) {
    // leaq 1f(%rip), %r11
    // jmpq *N(%r14)
    // 1:
    FdInstr i_lea, i_jmp;
    if (fd_decode(&buf[0], size, 64, 0, &i_lea) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_lea.size], size - i_lea.size, 64, 0, &i_jmp) < 0)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_lea) != FDI_LEA ||
            FD_OP_TYPE(&i_lea, 0) != FD_OT_REG ||
            FD_OP_REG(&i_lea, 0) != FD_REG_R11 ||
            FD_OP_TYPE(&i_lea, 1) != FD_OT_MEM ||
            FD_OP_BASE(&i_lea, 1) != FD_REG_IP)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_jmp) != FDI_JMP ||
            FD_OP_TYPE(&i_jmp, 0) != FD_OT_MEM ||
            FD_OP_BASE(&i_jmp, 0) != FD_REG_R14 ||
            FD_OP_INDEX(&i_jmp, 0) != FD_REG_NONE ||
            FD_OP_SCALE(&i_jmp, 0) != 0 ||
            !okdisp(FD_OP_DISP(&i_jmp, 0)))
        return (struct MacroInst){-1, 0};

    if (FD_OP_DISP(&i_lea, 1) != i_jmp.size)
        return (struct MacroInst){-1, 0};

    return (struct MacroInst){i_lea.size + i_jmp.size, 2};
}

static size_t bundle(Verifier* v) {
    switch (v->opts->bundle) {
    // case LFI_BUNDLE16:
    //     return 16;
    case LFI_BUNDLE32:
        return 32;
    default:
        assert(!"unreachable");
    }
}

static struct MacroInst macroinst_call(Verifier* v, uint8_t* buf, size_t size) {
    size_t bundlesize = bundle(v);

    // not allowed in position-oblivious-code
    if (v->opts->poc)
        return (struct MacroInst){-1, 0};

    // andl $0xffffffe0, %eX
    // orq %r14, %rX
    // nop*
    // callq *%rX

    FdInstr i_and, i_or, i_jmp;
    if (fd_decode(&buf[0], size, 64, 0, &i_and) < 0)
        return (struct MacroInst){-1, 0};
    if (FD_TYPE(&i_and) != FDI_AND)
        return (struct MacroInst){-1, 0};

    if (fd_decode(&buf[i_and.size], size - i_and.size, 64, 0, &i_or) < 0)
        return (struct MacroInst){-1, 0};
    size_t count = i_and.size + i_or.size;
    size_t icount = 2;
    while (count < bundlesize) {
        if (fd_decode(&buf[count], size - count, 64, 0, &i_jmp) < 0)
            return (struct MacroInst){-1, 0};
        icount++;
        count += i_jmp.size;
        if (FD_TYPE(&i_jmp) != FDI_NOP)
            break;
    }

    if ((v->addr + count) % bundlesize != 0)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_and) != FDI_AND ||
            FD_OP_TYPE(&i_and, 0) != FD_OT_REG ||
            FD_OP_SIZE(&i_and, 0) != 4 ||
            FD_OP_TYPE(&i_and, 1) != FD_OT_IMM ||
            FD_OP_IMM(&i_and, 1) != 0xffffffffffffffe0)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_or) != FDI_OR ||
            FD_OP_TYPE(&i_or, 0) != FD_OT_REG ||
            FD_OP_TYPE(&i_or, 1) != FD_OT_REG ||
            FD_OP_SIZE(&i_or, 0) != 8 ||
            FD_OP_SIZE(&i_or, 1) != 8 ||
            FD_OP_REG(&i_or, 1) != FD_REG_R14 ||
            FD_OP_REG(&i_or, 0) != FD_OP_REG(&i_and, 0))
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_jmp) != FDI_CALL ||
            FD_OP_TYPE(&i_jmp, 0) != FD_OT_REG ||
            FD_OP_REG(&i_jmp, 0) != FD_OP_REG(&i_and, 0))
        return (struct MacroInst){-1, 0};

    return (struct MacroInst){count, icount};
}

static struct MacroInst macroinst_modsp(Verifier* v, uint8_t* buf, size_t size) {
    // movl/addl/subl/andl ..., %esp
    // orq %r14, %rsp

    FdInstr i_mov, i_or;
    if (fd_decode(&buf[0], size, 64, 0, &i_mov) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_mov.size], size - i_mov.size, 64, 0, &i_or) < 0)
        return (struct MacroInst){-1, 0};

    // allow addl, subl, or movl
    if (FD_TYPE(&i_mov) != FDI_MOV &&
            FD_TYPE(&i_mov) != FDI_ADD &&
            FD_TYPE(&i_mov) != FDI_AND &&
            FD_TYPE(&i_mov) != FDI_SUB)
        return (struct MacroInst){-1, 0};

    if (FD_OP_TYPE(&i_mov, 0) != FD_OT_REG ||
            FD_OP_SIZE(&i_mov, 0) != 4 ||
            FD_OP_REG(&i_mov, 0) != FD_REG_SP)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_or) != FDI_OR ||
            FD_OP_TYPE(&i_or, 0) != FD_OT_REG ||
            FD_OP_TYPE(&i_or, 1) != FD_OT_REG ||
            FD_OP_SIZE(&i_or, 0) != 8 ||
            FD_OP_SIZE(&i_or, 1) != 8 ||
            FD_OP_REG(&i_or, 0) != FD_REG_SP ||
            FD_OP_REG(&i_or, 1) != FD_REG_R14)
        return (struct MacroInst){-1, 0};

    return (struct MacroInst){i_mov.size + i_or.size, 2};
}

typedef struct MacroInst (*MacroFn)(Verifier*, uint8_t*, size_t);

static MacroFn mfns[] = {
    macroinst_jmp,
    macroinst_call,
    macroinst_rtcall,
    macroinst_modsp,
};

static struct MacroInst macroinst(Verifier* v, uint8_t* buf, size_t size) {
    for (size_t i = 0; i < sizeof(mfns) / sizeof(mfns[0]); i++) {
        struct MacroInst mi = mfns[i](v, buf, size);
        if (mi.size > 0)
            return mi;
    }
    return (struct MacroInst){-1, 0};
}
