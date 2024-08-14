#include <stdio.h>
#include <stdarg.h>

#include "lfiv.h"
#include "fadec.h"

enum {
    ERRMAX = 128,
};

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
verr(Verifier* v, FdInstr* inst, const char* msg)
{
    char fmtbuf[64];
    fd_format(inst, fmtbuf, sizeof(fmtbuf));
    verrmin(v, "%x: %s: %s", v->addr, fmtbuf, msg);
}

static void
vchkbundle(Verifier* v, uint8_t* buf, size_t size, size_t bundlesize)
{
    size_t count = 0;

    while (count < bundlesize && count < size) {
        FdInstr instr;
        int ret = fd_decode(&buf[count], size - count, 64, 0, &instr);
        if (ret < 0) {
            verrmin(v, "%lx: unknown instruction", v->addr);
            return;
        }

        if (count + ret > bundlesize) {
            verr(v, &instr, "instruction spans bundle boundary");
            v->abort = true; // not useful to give further errors
            return;
        }

        v->addr += ret;
        count += ret;
    }
}

bool
lfiv_verify_verbose_amd64(void* code, size_t size, uintptr_t addr, ErrFn err)
{
    uint8_t* insns = (uint8_t*) code;

    Verifier v = {
        .addr = addr,
        .err = err,
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

bool
lfiv_verify_amd64(void* code, size_t size)
{
    return lfiv_verify_verbose_amd64(code, size, 0, NULL);
}
