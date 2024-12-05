struct MacroInst {
    int size;
    int ninstr;
};

static struct MacroInst macroinst_jmp(Verifier* v, uint8_t* buf, size_t size) {
    FdInstr i_and, i_jmp;
    if (fd_decode(&buf[0], size, 64, 0, &i_and) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_and.size], size - i_and.size, 64, 0, &i_jmp) < 0)
        return (struct MacroInst){-1, 0};
    // andq $0xffffffffffffffe0, %rXX
    if (FD_TYPE(&i_and) != FDI_AND ||
            FD_OP_TYPE(&i_and, 0) != FD_OT_REG ||
            FD_OP_TYPE(&i_and, 1) != FD_OT_IMM ||
            FD_OP_IMM(&i_and, 1) != 0xffffffffffffffe0)
        return (struct MacroInst){-1, 0};

    // jmpq *%rXX
    if (FD_TYPE(&i_jmp) != FDI_JMP ||
            FD_OP_TYPE(&i_jmp, 0) != FD_OT_REG ||
            FD_OP_REG(&i_jmp, 0) != FD_OP_REG(&i_and, 0))
        return (struct MacroInst){-1, 0};

    return (struct MacroInst){i_and.size + i_jmp.size, 2};
}

static struct MacroInst macroinst_call(Verifier* v, uint8_t* buf, size_t size) {
    FdInstr i_and, i_call;
    if (fd_decode(&buf[0], size, 64, 0, &i_and))
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_and.size], size - i_and.size, 64, 0, &i_call))
        return (struct MacroInst){-1, 0};
    // andq $0xffffffffffffffe0, %rXX
    if (FD_TYPE(&i_and) != FDI_AND ||
            FD_OP_TYPE(&i_and, 0) != FD_OT_REG ||
            FD_OP_TYPE(&i_and, 1) != FD_OT_IMM ||
            FD_OP_IMM(&i_and, 1) != 0xffffffffffffffe0)
        return (struct MacroInst){-1, 0};

    // callq *%rXX
    if (FD_TYPE(&i_call) != FDI_CALL ||
            FD_OP_TYPE(&i_call, 0) != FD_OT_REG ||
            FD_OP_REG(&i_call, 0) != FD_OP_REG(&i_and, 0))
        return (struct MacroInst){-1, 0};

    return (struct MacroInst){i_and.size + i_call.size, 2};
}

static struct MacroInst macroinst_shxd(Verifier* v, uint8_t* buf, size_t size) {
    return (struct MacroInst){-1, 0};
}

static struct MacroInst macroinst_bsx(Verifier* v, uint8_t* buf, size_t size) {
    // test %rXX, %rXX
    // jz .SKIP
    // bsx
    // .SKIP:
    return (struct MacroInst){-1, 0};
}

typedef struct MacroInst (*MacroFn)(Verifier*, uint8_t*, size_t);

static MacroFn mfns[] = {
    macroinst_jmp,
    macroinst_call,
    macroinst_shxd,
    macroinst_bsx,
};

static struct MacroInst macroinst(Verifier* v, uint8_t* buf, size_t size) {
    for (size_t i = 0; i < sizeof(mfns) / sizeof(mfns[0]); i++) {
        struct MacroInst mi = macroinst_jmp(v, buf, size);
        if (mi.size > 0)
            return mi;
    }
    return (struct MacroInst){-1, 0};
}
