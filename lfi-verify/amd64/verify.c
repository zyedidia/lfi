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


    if (v->opts->decl) {
        switch (FD_TYPE(instr)) {
#include "decl.instrs"
        default:
            break;
        }
    } else {
        // TODO:
        return true;
    }
    return false;
}

static void chkbranch(Verifier* v, FdInstr* instr, size_t bundlesize) {
    int64_t target;
    bool indirect, cond;
    bool branch = branchinfo(v, instr, &target, &indirect, &cond);
    if (branch && !indirect) {
        if (target % bundlesize != 0)
            verr(v, instr, "jump target is not bundle-aligned");
    }
}

static size_t vchkbundle(Verifier* v, uint8_t* buf, size_t size, size_t bundlesize) {
    size_t count = 0;
    size_t ninstr = 0;

    while (count < bundlesize && count < size) {
        FdInstr instr;
        int ret = fd_decode(&buf[count], size - count, 64, 0, &instr);
        if (ret < 0) {
            verrmin(v, "%lx: unknown instruction", v->addr);
            return ninstr;
        }

        if (!okmnem(v, &instr))
            verr(v, &instr, "illegal instruction");

        chkbranch(v, &instr, bundlesize);

        if (count + ret > bundlesize) {
            verr(v, &instr, "instruction spans bundle boundary");
            v->abort = true; // not useful to give further errors
            return ninstr;
        }

        v->addr += ret;
        count += ret;
        ninstr++;
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

    size_t bundlesize = 32;

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
