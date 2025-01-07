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

static struct MacroInst macroinst_call(Verifier* v, uint8_t* buf, size_t size) {
    // andl $0xffffffe0, %eX
    // orq %r14, %rX
    // nop*
    // callq *%rX

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

static struct MacroInst macroinst_modsp(Verifier* v, uint8_t* buf, size_t size) {
    // movl/addl/subl ..., %esp
    // orq %r14, %rsp

    FdInstr i_mov, i_or;
    if (fd_decode(&buf[0], size, 64, 0, &i_mov) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_mov.size], size - i_mov.size, 64, 0, &i_or) < 0)
        return (struct MacroInst){-1, 0};

    printf("%d\n", FD_TYPE(&i_mov));

    // allow addl, subl, or movl
    if (FD_TYPE(&i_mov) != FDI_MOV &&
            FD_TYPE(&i_mov) != FDI_ADD &&
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
