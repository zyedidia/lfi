#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "lfiv.h"
#include "generator.h"

int x64_encode(uint8_t*);

struct InsnBuf {
    uint8_t* data;
    size_t size;
    size_t cap;
};

static void
ibufappend(struct InsnBuf* ibuf, uint8_t* data, size_t size)
{
    if (ibuf->size + size >= ibuf->cap) {
        ibuf->cap = ibuf->cap * 2 + ibuf->size + size;
        ibuf->data = realloc(ibuf->data, ibuf->cap);
    }
    memcpy(&ibuf->data[ibuf->size], data, size);
    ibuf->size += size;
}

static LFIvOpts vopts = (LFIvOpts) {
    .nobranches = true,
    .noundefined = true,
    .nomemops = true,
    .decl = true,
    .poc = false,
};

static uint32_t
xor32()
{
    static uint32_t y = 2463534242UL;
    y^=(y<<13); y^=(y>>17); return (y^=(y<<15));
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
    BBMAX = 6,
};

static size_t
rngbbsize(struct Options opts)
{
    (void) opts;
    return max(BBMIN, xor32() % BBMAX);
}

static void
bbgen(struct InsnBuf* buf, size_t ninsn, struct Options opts)
{
    const size_t presize = 0;
    const size_t postsize = 0;

    assert(ninsn >= presize + postsize);

    if (presize) {
        // prologue
    }

    size_t i = 0;
    uint8_t insn[15];
    while (i < ninsn - (presize + postsize)) {
        size_t n = x64_encode(&insn[0]);
        assert(n > 0);
        ibufappend(buf, insn, n);
        i++;
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
        struct InsnBuf bb;
        while (true) {
            bb = (struct InsnBuf) {0};
            // generate basic blocks until one passes verification
            bbgen(&bb, bbsize, opts);
            if (lfiv_verify_amd64(bb.data, bb.size, 0, &vopts)) {
                break;
            }
        }
        ibufappend(&ibuf, bb.data, bb.size);
        i += bbsize;
    }
    uint8_t nop = 0x90;
    while (i < ninsn) {
        ibufappend(&ibuf, &nop, 1);
        i++;
    }
    while (ibuf.size % getpagesize() != 0) {
        ibufappend(&ibuf, &nop, 1);
        i++;
    }
    *o_buf = ibuf.data;
    return ibuf.size;
}