#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#include "lfiv.h"
#include "disarm64.h"

enum {
    INSN_SIZE = 4,

    ERRMAX = 64, // maximum size for error
};

static void
verr(Verifier* v, const char* fmt, ...)
{
    v->failed = true;

    if (!v->err)
        return;

    va_list ap;

    char buf[ERRMAX];

    va_start(ap, fmt);
    vsnprintf(buf, ERRMAX, fmt, ap);
    va_end(ap);

    v->err(buf, strlen(buf));
}

enum {
    SYS_tpidr_el0        = 0xde82,
    SYS_fpsr             = 0xda21,
    SYS_fpcr             = 0xda20,
    SYS_id_aa64pfr0_el1  = 0xc020,
    SYS_id_aa64pfr1_el1  = 0xc021,
    SYS_id_aa64zfr0_el1  = 0xc024, // requires SVE
    SYS_id_aa64isar0_el1 = 0xc030,
    SYS_id_aa64isar1_el1 = 0xc031,
};

static bool
cfreg(uint8_t reg)
{
    return reg == 18 || reg == 30;
}

static bool
datareg(uint8_t reg)
{
    return reg == 18 || reg == 31; // sp
}

static bool
basereg(uint8_t reg)
{
    return reg == 21;
}

static bool
sysreg(uint16_t sysreg)
{
    return sysreg == SYS_tpidr_el0 ||
        sysreg == SYS_fpsr ||
        sysreg == SYS_fpcr ||
        sysreg == SYS_id_aa64pfr0_el1 ||
        sysreg == SYS_id_aa64pfr1_el1 ||
        sysreg == SYS_id_aa64zfr0_el1 ||
        sysreg == SYS_id_aa64isar0_el1 ||
        sysreg == SYS_id_aa64isar1_el1;
}

static int
nmod(struct Da64Inst* dinst)
{
    switch (DA64_GROUP(dinst->mnem)) {
    case DA64G_BRANCH:
    case DA64G_BCOND:
    case DA64G_BRANCHREG:
        return 0;
    case DA64G_LDATOMIC:
    case DA64G_SWP:
    case DA64G_CASP:
    case DA64G_CAS:
        return 2;
    }

    return 1;
}

static void
chkbranch(Verifier* v, struct Da64Inst* dinst)
{
    switch (dinst->mnem) {
    case DA64I_BLR:
    case DA64I_BR:
    case DA64I_RET:
        assert(dinst->ops[0].type == DA_OP_REGGP);
        if (!cfreg(dinst->ops[0].reg)) {
            verr(v, "%lx: indirect branch using illegal register", v->addr);
        }
        break;
    default:
        assert(DA64_GROUP(dinst->mnem) != DA64G_BRANCHREG);
        break;
    }
}

static void
chksys(Verifier* v, struct Da64Inst* dinst)
{
    switch (dinst->mnem) {
    case DA64I_MSR:
        assert(dinst->ops[0].type == DA_OP_SYSREG);
        if (!sysreg(dinst->ops[0].sysreg))
            verr(v, "%lx: write to illegal sysreg", v->addr);
        break;
    case DA64I_MRS:
        assert(dinst->ops[1].type == DA_OP_SYSREG);
        if (!sysreg(dinst->ops[1].sysreg))
            verr(v, "%lx: read from illegal sysreg", v->addr);
        break;
    }
}

static void
chkmnem(Verifier* v, struct Da64Inst* dinst)
{
    switch (dinst->mnem) {
    case DA64I_LDR_LIT:
    case DA64I_LDRW_LIT:
    case DA64I_LDRSW_LIT:
    case DA64I_PRFM_LIT:
    case DA64I_LDR_LIT_FP:
        verr(v, "%lx: illegal read", v->addr);
        break;
    }
}

static bool
okmemop(struct Da64Op* op)
{
    switch (op->type) {
    case DA_OP_MEMUOFF:
    case DA_OP_MEMSOFF:
        // runtime call
        if (basereg(op->reg) && op->simm16 == 0)
            return true;
        return datareg(op->reg);
    case DA_OP_MEMSOFFPRE:
    case DA_OP_MEMSOFFPOST:
        return datareg(op->reg);
    case DA_OP_MEMREG:
        return basereg(op->reg) && op->memreg.ext == DA_EXT_UXTW &&
            op->memreg.sc == 0;
        break;
    case DA_OP_MEMREGPOST:
        return false;
    case DA_OP_MEMINC:
        return false;
    default:
        return true;
    }
}

static void
chkmemops(Verifier* v, struct Da64Inst* dinst)
{
    for (size_t i = 0; i < sizeof(dinst->ops) / sizeof(struct Da64Op); i++) {
        if (!okmemop(&dinst->ops[i]))
            verr(v, "%lx: illegal memory operand", v->addr);
    }
}

static bool
okmod(Verifier* v, struct Da64Inst* dinst, struct Da64Op* op)
{
    // TODO: check if op type is GP register
    if (fixedreg(op.reg))
        return false;
    if (!resreg(op.reg))
        return true;

    if (dinst->mnem == DA64I_ADD_EXT) {
        // 'add resreg, base, lo, uxtw' is allowed.
        // TODO
    }

    if (retreg(op.reg)) {
        // 'ldr x30, [basereg]' is allowed.
        // TODO
    }

    return false;
}

static void
vchk(Verifier* v, uint32_t insn)
{
    struct Da64Inst dinst;
    da64_decode(insn, &dinst);

    if (dinst.mnem == DA64I_UNKNOWN) {
        verr(v, "%lx: unknown instruction: %x", v->addr, insn);
        return;
    }

    chkmnem(v, &dinst);
    chkbranch(v, &dinst);
    chksys(v, &dinst);
    chkmemops(v, &dinst);

    int nmod = nmod(&dinst);
    for (int i = 0; i < nmod; i++) {
        if (!okmod(v, &dinst, &dinst->ops[i]))
            verr(v, "%lx: illegal modification of reserved register", v->addr);
    }
}

bool
lfiv_verify_verbose(void* code, size_t size, uintptr_t addr, ErrFn err)
{
    if (size % INSN_SIZE != 0)
        return false;

    uint32_t* insns = (uint32_t*) code;

    Verifier v = {
        .addr = addr,
        .err = err,
    };

    for (size_t i = 0; i < size / INSN_SIZE; i++) {
        vchk(&v, insns[i]);
        v.addr += INSN_SIZE;
        // Exit early if there is no error reporter.
        if (v.failed && v.err == NULL)
            return false;
    }

    return !v.failed;
}

bool
lfiv_verify(void* code, size_t size, uintptr_t addr)
{
    return lfiv_verify_verbose(code, size, addr, NULL);
}
