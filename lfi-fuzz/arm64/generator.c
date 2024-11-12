#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lfiv.h"
#include "generator.h"

static LFIvOpts vopts = (LFIvOpts) {
    .nobranches = true,
    .noundefined = true,
    .decl = true,
    .poc = false,
};

static bool filterinsn(uint32_t);

static uint32_t
rnginsn()
{
    return rand_u32();
}

static size_t
min(size_t a, size_t b)
{
    return a < b ? a : b;
}

static size_t
max(size_t a, size_t b)
{
    return a > b ? a : b;
}

enum {
    BBMIN = 2,
    BBMAX = 16,
};

static size_t
rngbbsize(struct Options opts)
{
    (void) opts;
    return max(BBMIN, rand_u32() % BBMAX);
}

static bool
filterinsn(uint32_t insn)
{
    return lfiv_verify_insn_arm64(insn, &vopts);
}

static void
bbgen(uint32_t* insnbuf, size_t nbuf, struct Options opts)
{
    const size_t presize = 0;
    const size_t postsize = 0;

    assert(nbuf >= presize + postsize);

    if (presize) {
        // prologue
    }

    size_t i = 0;
    while (i < nbuf - (presize + postsize)) {
        uint32_t insn = rnginsn();
        if (filterinsn(insn)) {
            insnbuf[i] = insn;
            i++;
        }
    }

    if (postsize) {
        // epilogue
    }
}

enum {
    NOP = 0xd503201f,
};

size_t
codegen(uint8_t** o_buf, size_t ninsn, struct Options opts)
{
    uint8_t* buf = malloc(ninsn * sizeof(uint32_t));
    assert(buf);
    *o_buf = buf;
    uint32_t* insnbuf = (uint32_t*) buf;
    size_t i = 0;
    while (i < ninsn) {
        size_t bbsize = min(ninsn - i, rngbbsize(opts));
        if (bbsize < BBMIN)
            break;
        bbgen(&insnbuf[i], bbsize, opts);
        i += bbsize;
    }
    while (i < ninsn) {
        insnbuf[i] = NOP;
        i++;
    }
    while (i * sizeof(uint32_t) % getpagesize() != 0) {
        insnbuf[i] = NOP;
        i++;
    }
    assert(ninsn == i);
    return ninsn * sizeof(uint32_t);
}
