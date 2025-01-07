static struct MacroInst macroinst_jmp(Verifier* v, uint8_t* buf, size_t size) {
    // andq $0xffffffffffffffe0, %rXX
    // jmpq *%rXX

    FdInstr i_and, i_jmp;
    if (fd_decode(&buf[0], size, 64, 0, &i_and) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_and.size], size - i_and.size, 64, 0, &i_jmp) < 0)
        return (struct MacroInst){-1, 0};
    if (FD_TYPE(&i_and) != FDI_AND ||
            FD_OP_TYPE(&i_and, 0) != FD_OT_REG ||
            FD_OP_TYPE(&i_and, 1) != FD_OT_IMM ||
            FD_OP_IMM(&i_and, 1) != 0xffffffffffffffe0)
        return (struct MacroInst){-1, 0};

    if (FD_TYPE(&i_jmp) != FDI_JMP ||
            FD_OP_TYPE(&i_jmp, 0) != FD_OT_REG ||
            FD_OP_REG(&i_jmp, 0) != FD_OP_REG(&i_and, 0))
        return (struct MacroInst){-1, 0};

    return (struct MacroInst){i_and.size + i_jmp.size, 2};
}

static struct MacroInst macroinst_call(Verifier* v, uint8_t* buf, size_t size) {
    // andq $0xffffffffffffffe0, %rXX
    // callq *%rXX

    FdInstr i_and, i_call;
    if (fd_decode(&buf[0], size, 64, 0, &i_and) < 0)
        return (struct MacroInst){-1, 0};
    if (fd_decode(&buf[i_and.size], size - i_and.size, 64, 0, &i_call) < 0)
        return (struct MacroInst){-1, 0};
    if (FD_TYPE(&i_and) != FDI_AND ||
            FD_OP_TYPE(&i_and, 0) != FD_OT_REG ||
            FD_OP_TYPE(&i_and, 1) != FD_OT_IMM ||
            FD_OP_IMM(&i_and, 1) != 0xffffffffffffffe0)
        return (struct MacroInst){-1, 0};

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
