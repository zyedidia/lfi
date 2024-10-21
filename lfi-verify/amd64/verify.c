#include <stdio.h>
#include <stdarg.h>

#include "lfiv.h"
#include "fadec.h"
#include "verifier.h"

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

static bool okmnem(FdInstr* instr) {
    return true;
/*     switch (FD_TYPE(instr)) { */
/* #include "base.instrs" */
/*     } */
/*  */
/*     return false; */
}

static void chkbranch(Verifier* v, FdInstr* instr, size_t bundlesize) {
    switch (FD_TYPE(instr)) {
    case FDI_JA:
    case FDI_JBE:
    case FDI_JC:
    case FDI_JCXZ:
    case FDI_JG:
    case FDI_JGE:
    case FDI_JL:
    case FDI_JLE:
    case FDI_JMP:
    case FDI_JNC:
    case FDI_JNO:
    case FDI_JNP:
    case FDI_JNS:
    case FDI_JNZ:
    case FDI_JO:
    case FDI_JP:
    case FDI_JS:
    case FDI_JZ:
    case FDI_CALL:
        if (FD_OP_TYPE(instr, 0) == FD_OT_OFF) {
            int64_t imm = FD_OP_IMM(instr, 0);
            uint64_t target = v->addr + FD_SIZE(instr) + imm;
            if (target % bundlesize == 0) {
                break;
            } else {
                verr(v, instr, "jump target is not bundle-aligned");
            }
        }
        break;
    default:
        break;
    }
}

static void vchkbundle(Verifier* v, uint8_t* buf, size_t size, size_t bundlesize) {
    size_t count = 0;

    while (count < bundlesize && count < size) {
        FdInstr instr;
        int ret = fd_decode(&buf[count], size - count, 64, 0, &instr);
        if (ret < 0) {
            verrmin(v, "%lx: unknown instruction", v->addr);
            return;
        }

        if (!okmnem(&instr))
            verr(v, &instr, "illegal instruction");

        chkbranch(v, &instr, bundlesize);

        if (count + ret > bundlesize) {
            verr(v, &instr, "instruction spans bundle boundary");
            v->abort = true; // not useful to give further errors
            return;
        }

        v->addr += ret;
        count += ret;
    }
}

bool lfiv_verify_amd64(void* code, size_t size, uintptr_t addr, LFIvOpts* opts) {
    uint8_t* insns = (uint8_t*) code;

    Verifier v = {
        .addr = addr,
        .err = opts->err,
        .opts = opts,
    };

    size_t bundlesize = 16;

    size_t count = 0;
    while (count < size) {
        vchkbundle(&v, &insns[count], size - count, bundlesize);
        count += bundlesize;

        // Exit early if there is no error reporter.
        if ((v.failed && v.err == NULL) || v.abort)
            return false;
    }

    return !v.failed;
}
