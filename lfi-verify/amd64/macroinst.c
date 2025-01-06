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
    if (fd_decode(&buf[0], size, 64, 0, &i_and) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_and.size], size - i_and.size, 64, 0, &i_call) < 0)
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
    FdInstr i_test, i_jz, i_bsx;
    if (fd_decode(&buf[0], size, 64, 0, &i_test) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_test.size], size - i_test.size, 64, 0, &i_jz) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_test.size + i_jz.size], size - i_test.size - i_jz.size, 64, 0, &i_bsx) < 0)
        return (struct MacroInst){-1, 0};

    // test %rXX, %rXX
    // jz .SKIP
    // bsx
    // .SKIP:
    return (struct MacroInst){-1, 0};
}

static struct MacroInst macroinst_modsp(Verifier* v, uint8_t* buf, size_t size) {
    // movl/addl/subl ..., %esp
    // orq %r14, %rsp

    FdInstr i_mov, i_or;
    if (fd_decode(&buf[0], size, 64, 0, &i_mov) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_mov.size], size - i_mov.size, 64, 0, &i_or) < 0)
        return (struct MacroInst){-1, 0};

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
    macroinst_call,
    macroinst_shxd,
    macroinst_bsx,
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
