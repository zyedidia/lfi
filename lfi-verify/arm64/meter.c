static ssize_t max(ssize_t a, ssize_t b) {
    return a > b ? a : b;
}

static bool gasmod(Verifier* v, struct Da64Inst* dinst, struct Da64Op* op) {
    if (op->type != DA_OP_REGGP &&
        op->type != DA_OP_REGGPINC &&
        op->type != DA_OP_REGGPEXT &&
        op->type != DA_OP_REGSP)
        return false;
    if (!gasreg(op->reg))
        return false;
    return true;
}

static uint32_t ceilimm(uint32_t imm, uint32_t align) {
    uint32_t mask = align - 1;
    return (imm + mask) & ~mask;
}

static uint32_t subx23(int64_t imm) {
    const uint32_t OP_SUB = 0b110100010UL << 23;
    if (imm < 4096) {
        return OP_SUB | (imm << 10) | (23 << 5) | (23);
    }
    if (imm % 4096 != 0) {
        imm = ceilimm(imm, 4096);
    }
    return OP_SUB | (1 << 22) | ((imm >> 12) << 10) | (23 << 5) | (23);
}

static bool gasupdate(Verifier* v, struct Da64Inst* dinst) {
    int n = nmod(dinst);
    for (int i = 0; i < n; i++) {
        if (gasmod(v, dinst, &dinst->ops[i]))
            return true;
    }
    return false;
}

static void vchkmeter(Verifier* v, uint32_t* insns, size_t n) {
    bool* branches = calloc(sizeof(bool) * n, 1);
    if (!branches) {
        verrmin(v, "cannot allocate: out of memory");
        return;
    }

    bool* updates = calloc(sizeof(bool) * n, 1);
    if (!updates) {
        free(branches);
        verrmin(v, "cannot allocate: out of memory");
        return;
    }

    struct Da64Inst* insts = calloc(sizeof(struct Da64Inst) * n, 1);
    if (!insts) {
        free(branches);
        free(updates);
        verrmin(v, "cannot allocate: out of memory");
        return;
    }

    uintptr_t addr = v->addr;

    for (size_t i = 0; i < n; i++) {
        da64_decode(insns[i], &insts[i]);
        assert(insts[i].mnem != DA64I_UNKNOWN);
        struct Da64Inst dinst = insts[i];
        if (gasupdate(v, &dinst))
            updates[i] = true;
        int64_t target;
        bool indirect;
        if (branchinfo(v, &insts[i], &target, &indirect))
            branches[i] = true;
    }

    ssize_t lastbranch = -1;
    ssize_t lastupdate = -1;
    for (size_t i = 0; i < n; i++) {
        struct Da64Inst dinst = insts[i];
        v->addr = addr + i * INSN_SIZE;

        if (branches[i]) {
            if (i == 0) {
                verr(v, &dinst, "branch not preceded by metering sequence");
                continue;
            }
            int64_t bbsize = i - max(lastbranch, lastupdate);
            if (insns[i - 1] != subx23(bbsize)) {
                verr(v, &dinst, "branch not preceded by correct metering sequence");
                continue;
            }
            lastbranch = i;
            printf("lastbranch: %ld\n", i);
        }

        if (updates[i]) {
            // not followed by a branch
            if (i + 1 >= n || !branches[i + 1]) {
                int64_t bbsize = i - max(lastbranch, lastupdate);
                if (insns[i] != subx23(bbsize)) {
                    verr(v, &dinst, "incorrect gas update");
                    continue;
                }
                lastupdate = i;
            }
        }

        // Make sure that branches only occur at the end of a bundle.
        int64_t target;
        bool indirect;
        bool branch = branchinfo(v, &dinst, &target, &indirect);
        if (!branch)
            continue;

        size_t ibundlesize = bundlesize(v) / INSN_SIZE;
        if (i % ibundlesize != ibundlesize - 1) {
            verr(v, &dinst, "branch must occur at the end of a bundle");
            continue;
        }
    }

    for (size_t i = 0; i < n; i++) {
        struct Da64Inst dinst = insts[i];
        v->addr = addr + i * INSN_SIZE;

        if (updates[i])
            continue;
        if (gasupdate(v, &dinst))
            verr(v, &dinst, "illegal modification of gas register");
    }

    free(branches);
    free(updates);
    free(insts);
}
