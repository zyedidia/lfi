#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "rand.h"
#include "lfiv.h"
#include "generator.h"

static LFIvOpts vopts = (LFIvOpts) {
    .nobranches = true,
    .noundefined = true,
    .decl = true,
    .poc = false,
};

static bool filterinsn(uint32_t);

struct InsnBuf {
    uint8_t* data;
    size_t size;
    size_t cap;
};

static void
ibufappend(struct InsnBuf* ibuf, uint32_t* data, size_t size)
{
    if (ibuf->size + size >= ibuf->cap) {
        ibuf->cap = ibuf->cap * 2 + ibuf->size + size;
        ibuf->data = realloc(ibuf->data, ibuf->cap);
    }
    memcpy(&ibuf->data[ibuf->size], data, size);
    ibuf->size += size;
}

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
bbgen(struct InsnBuf* ibuf, size_t nbuf, struct Options opts)
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
            ibufappend(ibuf, &insn, 4);
            i++;
        }
    }

    if (postsize) {
        // epilogue
    }
}

size_t
codegen(uint8_t** o_buf, size_t ninsn, struct Options opts)
{
    struct InsnBuf ibuf = {0};
    size_t i = 0;
    while (i < ninsn) {
        size_t bbsize = min(ninsn - i, rngbbsize(opts));
        if (bbsize < BBMIN)
            break;
        bbgen(&ibuf, bbsize, opts);
        i += bbsize;
    }
    uint32_t nop = 0xd503201f;
    while (i < ninsn) {
        ibufappend(&ibuf, &nop, sizeof(nop));
        i++;
    }
    while (i * sizeof(uint32_t) % getpagesize() != 0) {
        ibufappend(&ibuf, &nop, sizeof(nop));
        i++;
    }
    *o_buf = (uint8_t*) ibuf.data;
    return ibuf.size;
}
