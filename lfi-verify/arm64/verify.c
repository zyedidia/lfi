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

    ERRMAX = 128, // maximum size for error
};

#define INSN_NOP 0xd503201f

static void
verrmin(Verifier* v, const char* fmt, ...)
{
    v->failed = true;

    if (!v->err)
        return;

    va_list ap;

    char errbuf[ERRMAX];

    va_start(ap, fmt);
    vsnprintf(errbuf, ERRMAX, fmt, ap);
    va_end(ap);

    v->err(errbuf, strlen(errbuf));
}

static void
verr(Verifier* v, struct Da64Inst* inst, const char* msg)
{
    char fmtbuf[128];
    da64_format(inst, fmtbuf);
    verrmin(v, "%x: %s: %s", v->addr, fmtbuf, msg);
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
basereg(uint8_t reg)
{
    return reg == 21;
}

static bool
retreg(uint8_t reg)
{
    return reg == 30;
}

static bool
fixedreg(uint8_t reg)
{
    return reg == 21;
}

static bool
addrreg(uint8_t reg, bool sp)
{
    if (sp)
        return reg == 31 || cfreg(reg);
    return cfreg(reg);
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

    switch (dinst->mnem) {
    // load pair instructions
    case DA64I_LDPW_POST:
    case DA64I_LDPW:
    case DA64I_LDPW_PRE:
    case DA64I_LDPSW_POST:
    case DA64I_LDPSW:
    case DA64I_LDPSW_PRE:
    case DA64I_LDPX_POST:
    case DA64I_LDPX:
    case DA64I_LDPX_PRE:
    case DA64I_LDNPW:
    case DA64I_LDNPX:
    case DA64I_LDXPW:
    case DA64I_LDXPX:
    case DA64I_LDAXPW:
    case DA64I_LDAXPX:
        return 2;
    // stores
    case DA64I_STR_IMM:
    case DA64I_STR_REG:
    case DA64I_STRX_PRE:
    case DA64I_STRX_POST:
    case DA64I_STPX_POST:
    case DA64I_STPX:
    case DA64I_STPX_PRE:
        return 0;
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
            verr(v, dinst, "indirect branch using illegal register");
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
            verr(v, dinst, "write to illegal sysreg");
        break;
    case DA64I_MRS:
        assert(dinst->ops[1].type == DA_OP_SYSREG);
        if (!sysreg(dinst->ops[1].sysreg))
            verr(v, dinst, "read from illegal sysreg");
        break;
    }
}

static bool
okmnem(struct Da64Inst* dinst)
{
    switch (dinst->mnem) {
#include "base.instrs"
    }

    return false;
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
        return addrreg(op->reg, true);
    case DA_OP_MEMSOFFPRE:
    case DA_OP_MEMSOFFPOST:
        return addrreg(op->reg, true);
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
            verr(v, dinst, "illegal memory operand");
    }
}

static bool
okmod(struct Da64Inst* dinst, struct Da64Op* op)
{
    if (op->type != DA_OP_REGGP &&
        op->type != DA_OP_REGGPINC &&
        op->type != DA_OP_REGGPEXT &&
        op->type != DA_OP_REGSP)
        return true;

    if (fixedreg(op->reg))
        return false;
    if (!addrreg(op->reg, op->type == DA_OP_REGSP))
        return true;

    if (dinst->mnem == DA64I_ADD_EXT) {
        // 'add addrreg, base, lo, uxtw' is allowed.
        if (addrreg(dinst->ops[0].reg, true) && basereg(dinst->ops[1].reg) &&
                dinst->ops[2].reggpext.ext == DA_EXT_UXTW &&
                dinst->ops[2].reggpext.sf == 0 && dinst->ops[2].reggpext.shift == 0)
            return true;
    }

    if (retreg(op->reg) && dinst->mnem == DA64I_LDR_IMM) {
        // 'ldr x30, [basereg]' is allowed.
        if (dinst->ops[1].type == DA_OP_MEMUOFF && dinst->ops[1].uimm16 == 0 && basereg(dinst->ops[1].reg))
            return true;
    }

    return false;
}

static void
vchk(Verifier* v, uint32_t insn)
{
    struct Da64Inst dinst;
    da64_decode(insn, &dinst);

    if (dinst.mnem == DA64I_UNKNOWN) {
        verrmin(v, "%lx: unknown instruction: %x", v->addr, insn);
        return;
    }

    if (insn == INSN_NOP)
        return;

    if (!okmnem(&dinst))
        verr(v, &dinst, "illegal instruction");

    chkbranch(v, &dinst);
    chksys(v, &dinst);
    chkmemops(v, &dinst);

    int n = nmod(&dinst);
    for (int i = 0; i < n; i++) {
        if (!okmod(&dinst, &dinst.ops[i]))
            verr(v, &dinst, "illegal modification of reserved register");
    }
}

bool
lfiv_verify_insn_arm64(uint32_t insn)
{
    Verifier v = {0};
    vchk(&v, insn);
    return !v.failed;
}

bool
lfiv_verify_verbose_arm64(void* code, size_t size, uintptr_t addr, ErrFn err)
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
lfiv_verify_arm64(void* code, size_t size)
{
    return lfiv_verify_verbose_arm64(code, size, 0, NULL);
}
