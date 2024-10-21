#include <assert.h>
#include <stdio.h>

#include "lfiv.h"
#include "generator.h"

static LFIvOpts vopts = (LFIvOpts) {
    .nobranches = true,
    .decl = true,
    .poc = false,
};

static uint32_t
xor32()
{
    static uint32_t y = 2463534242UL;
    y^=(y<<13); y^=(y>>17); return (y^=(y<<15));
}

static bool filterinsn(uint32_t);

static uint32_t
rnginsn()
{
    return xor32();
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
    return max(BBMIN, xor32() % BBMAX);
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

size_t
codegen(uint32_t* insnbuf, size_t nbuf, struct Options opts)
{
    size_t i = 0;
    while (i < nbuf) {
        size_t bbsize = min(nbuf - i, rngbbsize(opts));
        if (bbsize < BBMIN)
            break;
        bbgen(&insnbuf[i], bbsize, opts);
        i += bbsize;
    }
    return i;
}
