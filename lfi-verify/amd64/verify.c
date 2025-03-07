#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "lfiv.h"
#include "fadec.h"
#include "verifier.h"
#include "flags.h"

enum {
    ERRMAX = 128,
};

static void verrmin(Verifier* v, const char* fmt, ...) {
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

static void verr(Verifier* v, FdInstr* inst, const char* msg) {
    char fmtbuf[64];
    fd_format(inst, fmtbuf, sizeof(fmtbuf));
    verrmin(v, "%x: %s: %s", v->addr, fmtbuf, msg);
}

// return the number of modified operands
static int nmod(FdInstr* instr) {
    switch (FD_TYPE(instr)) {
    case FDI_CMP:
        return 0;
    case FDI_XCHG:
        return 2;
    default:
        return 1;
    }
}

// returns a bitmask of the operands that are read from.
// This is designed to be conservative, and not an exhaustive list
// of all instructions.  We merely want to allow some instructions to read
// from certain registers in specific cases (e.g. r11d under poc),
// but considering a register written to is strictly more restrictive
// than considering it read from.
static uint8_t readmod_mask(FdInstr* instr) {
    switch(FD_TYPE(instr)) {
        case FDI_LEA:
            return 0b01;
    default:
        return 0;
    }
}

static bool reserved(Verifier* v, FdInstr* instr, int op_index) {
    FdReg reg = FD_OP_REG(instr, op_index);

    if (reg == FD_REG_R14 || reg == FD_REG_SP)
        return true;


    if (v->opts->poc && reg == FD_REG_R11) {
        uint8_t read_mask = readmod_mask(instr);
        
        bool is_read_op = ((read_mask >> op_index) & 1) == 1;

        // write ops to r11 are allowed, but reads are only allowed to r11d
        if (!is_read_op) {
            return true;
        }
        // reads from r11d are allowed
        if (FD_OP_SIZE(instr, op_index) != 4) {
            return true;
        }

        return false;
    }
    return false;
}

static bool branchinfo(Verifier* v, FdInstr* instr, int64_t* target, bool* indirect, bool* cond) {
    *target = 0;
    *indirect = false;
    *cond = false;

    // TODO: don't count runtime calls as branches

    bool branch = true;
    switch (FD_TYPE(instr)) {
    case FDI_JA:
    case FDI_JBE:
    case FDI_JC:
    case FDI_JCXZ:
    case FDI_JG:
    case FDI_JGE:
    case FDI_JL:
    case FDI_JLE:
    case FDI_JNC:
    case FDI_JNO:
    case FDI_JNP:
    case FDI_JNS:
    case FDI_JNZ:
    case FDI_JO:
    case FDI_JP:
    case FDI_JS:
    case FDI_JZ:
        *cond = true;
    case FDI_JMP:
    case FDI_CALL:
    case FDI_RET:
        if (FD_OP_TYPE(instr, 0) == FD_OT_OFF) {
            int64_t imm = FD_OP_IMM(instr, 0);
            *target = v->addr + FD_SIZE(instr) + imm;
        } else {
            *indirect = true;
        }
        break;
    default:
        branch = false;
        break;
    }
    return branch;
}

static bool okdeclinstr(Verifier* v, FdInstr* instr) {
    assert(v->opts->decl);
    switch (FD_TYPE(instr)) {
#include "decl.instrs"
    default:
        return false;
    }
}

static bool oklfiinstr(Verifier* v, FdInstr* instr) {
    // TODO: what instructions are allowed in the LFI configuration (decl=false)
    // that are not allowed in the decl configuration?
    switch (FD_TYPE(instr)) {
#include "decl.instrs"
    default:
        return false;
    }
}

static bool okpocinstr(Verifier* v, FdInstr* instr) {
    assert(v->opts->poc);

    // We could make this its own table.  For now, this appears simpler.
    if (FD_TYPE(instr) == FDI_CALL) {
        return false;
    }

    // TODO: Perhaps redundant.  In what cases do we have opts->poc but not opts->decl?
    switch (FD_TYPE(instr)) {
#include "decl.instrs"
    default:
        return false;
    }
}

static bool okmnem(Verifier* v, FdInstr* instr) {
    if (v->opts->nobranches) {
        bool indirect, cond;
        int64_t target;
        bool branch = branchinfo(v, instr, &target, &indirect, &cond);
        if (branch)
            return false;
    }

    if (v->opts->nomemops) {
        switch (FD_TYPE(instr)) {
        case FDI_PUSH:
        case FDI_POP:
        case FDI_STOS:
        case FDI_MOVS:
            return false;
        default:
            break;
        }
        for (size_t i = 0; i < 4; i++) {
            if (FD_OP_TYPE(instr, i) == FD_OT_MEM && FD_TYPE(instr) != FDI_LEA) {
                return false;
            }
        }
    }

    if (v->opts->noundefined) {
        switch (FD_TYPE(instr)) {
        case FDI_UD0:
        case FDI_UD1:
        case FDI_UD2:
            return false;
        default:
            break;
        }
    }

    if (!oklfiinstr(v, instr))
        return false;

    if (v->opts->decl && !okdeclinstr(v, instr))
        return false;

    if (v->opts->poc && !okpocinstr(v, instr))
        return false;

    return true;
}

static void chkmem(Verifier* v, FdInstr* instr) {
    if (FD_TYPE(instr) == FDI_LEA || FD_TYPE(instr) == FDI_NOP)
        return;

    for (size_t i = 0; i < 4; i++) {
        if (FD_OP_TYPE(instr, i) == FD_OT_MEM) {
            if (FD_SEGMENT(instr) == FD_REG_GS) {
                if (FD_ADDRSIZE(instr) != 4)
                    verr(v, instr, "segmented memory access must use 32-bit address");
                continue;
            } else if (FD_SEGMENT(instr) == FD_REG_FS) {
                verr(v, instr, "use of %%fs is not permitted");
                continue;
            }

            if (FD_ADDRSIZE(instr) != 8)
                verr(v, instr, "non-segmented memory access must use 64-bit address");
            if (FD_OP_BASE(instr, i) != FD_REG_SP &&
                    FD_OP_BASE(instr, i) != FD_REG_IP)
                verr(v, instr, "invalid base register for memory access");
            if (FD_OP_INDEX(instr, i) != FD_REG_NONE)
                verr(v, instr, "invalid index register for memory access");
        }
    }
}

static void chkmod(Verifier* v, FdInstr* instr) {
    if (FD_TYPE(instr) == FDI_NOP)
        return;

    int n = nmod(instr);
    assert(n <= 4);
    for (size_t i = 0; i < n; i++) {
        if (FD_OP_TYPE(instr, i) == FD_OT_REG && reserved(v, instr, i))
            verr(v, instr, "modification of reserved register");
    }
}

static void chkbranch(Verifier* v, FdInstr* instr, size_t bundlesize) {
    int64_t target;
    bool indirect, cond;
    bool branch = branchinfo(v, instr, &target, &indirect, &cond);
    if (branch && !indirect) {
        if (target % bundlesize != 0)
            verr(v, instr, "jump target is not bundle-aligned");
    } else if (branch && indirect) {
        verr(v, instr, "invalid indirect branch");
    }
}

#include "macroinst.c"

static size_t vchkbundle(Verifier* v, uint8_t* buf, size_t size, size_t bundlesize) {
    size_t count = 0;
    size_t ninstr = 0;

    while (count < bundlesize && count < size) {
        struct MacroInst mi = macroinst(v, &buf[count], size - count);
        if (mi.size < 0) {
            FdInstr instr;
            int ret = fd_decode(&buf[count], size - count, 64, 0, &instr);
            if (ret < 0) {
                verrmin(v, "%lx: unknown instruction", v->addr);
                return ninstr;
            }
            mi.size = ret;
            mi.ninstr = 1;

            if (!okmnem(v, &instr))
                verr(v, &instr, "illegal instruction");

            chkbranch(v, &instr, bundlesize);
            chkmem(v, &instr);
            chkmod(v, &instr);
        }

        if (count + mi.size > bundlesize) {
            FdInstr instr;
            fd_decode(&buf[count], size - count, 64, 0, &instr);
            verr(v, &instr, "instruction spans bundle boundary");
            v->abort = true; // not useful to give further errors
            return ninstr;
        }

        v->addr += mi.size;
        count += mi.size;
        ninstr += mi.ninstr;
    }
    return ninstr;
}

#include "flags.c"

bool lfiv_verify_amd64(void* code, size_t size, uintptr_t addr, LFIvOpts* opts) {
    uint8_t* insns = (uint8_t*) code;

    Verifier v = {
        .addr = addr,
        .err = opts->err,
        .opts = opts,
    };

    size_t bundlesize;
    switch (opts->bundle) {
    // we may choose to enable BUNDLE16 in the future, for some configurations.
    // case LFI_BUNDLE16:
    //     bundlesize = 16;
    //     break;
    case LFI_BUNDLE32:
        bundlesize = 32;
        break;
    default:
        verrmin(&v, "bundle size must be 32");
        return false;
    }

    size_t count = 0;
    size_t ninstr = 0;
    while (count < size) {
        ninstr += vchkbundle(&v, &insns[count], size - count, bundlesize);
        count += bundlesize;

        // Exit early if there is no error reporter.
        if ((v.failed && v.err == NULL) || v.abort)
            return false;
    }

    if (v.opts->decl) {
        // Check flags.
        FdInstr* instrs = malloc(sizeof(FdInstr) * ninstr);
        assert(instrs);
        count = 0;
        size_t i = 0;
        while (count < size) {
            int ret = fd_decode(&insns[count], size - count, 64, 0, &instrs[i++]);
            // must have decoded earlier
            assert(ret >= 0);
            count += ret;
        }

        analyzecfg(&v, instrs, ninstr, addr);
        free(instrs);
    }

    return !v.failed;
}
