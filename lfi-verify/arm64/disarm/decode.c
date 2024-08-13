
#include "disarm64.h"
#include <stdint.h>

static int64_t sext(uint64_t imm, unsigned bits) {
  uint64_t sign = 1 << (bits - 1);
  return imm & sign ? (imm ^ sign) - sign : imm;
}

static unsigned clz(uint32_t v, unsigned sz) {
  return v ? __builtin_clz(v) + sz - 32 : sz;
}

static unsigned ctz(uint32_t v) { return v ? __builtin_ctz(v) : 32; }

static uint64_t immlogical(unsigned sf, unsigned N, unsigned immr,
                           unsigned imms) {
  if (!N && imms == 0x3f)
    return 0;
  unsigned len = 31 - __builtin_clz((N << 6) | (~imms & 0x3f));
  unsigned levels = (1 << len) - 1;
  unsigned s = imms & levels;
  unsigned r = immr & levels;
  unsigned esize = 1 << len;
  uint64_t welem = ((uint64_t)1 << (s + 1)) - 1;
  // ROR(welem, r) as bits(esize)
  welem = (welem >> r) | (welem << (esize - r));
  if (esize < 64)
    welem &= ((uint64_t)1 << esize) - 1;
  // Replicate(ROR(welem, r))
  uint64_t wmask = 0;
  for (unsigned i = 0; i < (!sf ? 32 : 64); i += esize)
    wmask |= welem << i;
  return wmask;
}

static struct Da64Op OPreggp(unsigned idx, bool sf) {
  return (struct Da64Op){DA_OP_REGGP, .reg = idx, .reggp = {sf}};
}
static struct Da64Op OPreggpinc(unsigned idx) {
  return (struct Da64Op){DA_OP_REGGPINC, .reg = idx, .reggp = {true}};
}

static struct Da64Op OPreggpsp(unsigned idx, bool sf) {
  return (struct Da64Op){
      idx != 31 ? DA_OP_REGGP : DA_OP_REGSP,
      .reg = idx,
      .reggp = {sf},
  };
}

static struct Da64Op OPreggpmaysp(bool maysp, unsigned idx, bool sf) {
  return (struct Da64Op){
      idx < 31 || !maysp ? DA_OP_REGGP : DA_OP_REGSP,
      .reg = idx,
      .reggp = {sf},
  };
}
static struct Da64Op OPreggpprf(bool isprf, unsigned idx, bool sf) {
  return (struct Da64Op){
      isprf ? DA_OP_PRFOP : DA_OP_REGGP,
      .reg = idx,
      .reggp = {sf},
  };
}

static struct Da64Op OPreggpext(unsigned idx, bool sf, enum Da64Ext ext,
                                unsigned shift) {
  return (struct Da64Op){DA_OP_REGGPEXT, .reg = idx,
                         .reggpext = {sf, ext, shift}};
}
static struct Da64Op OPregfp(unsigned idx, unsigned size) {
  return (struct Da64Op){DA_OP_REGFP, .reg = idx, .regfp = {size}};
}
static struct Da64Op OPregvec(unsigned idx, unsigned esize, bool Q) {
  return (struct Da64Op){DA_OP_REGVEC, .reg = idx,
                         .regvec = {(esize << 1) + Q}};
}
static struct Da64Op OPregvidx(unsigned idx, unsigned esize, unsigned elem) {
  return (struct Da64Op){DA_OP_REGVIDX, .reg = idx, .regvidx = {esize, elem}};
}
static struct Da64Op OPregvtbl(unsigned idx, unsigned esize, bool Q,
                               unsigned cnt) {
  return (struct Da64Op){DA_OP_REGVTBL, .reg = idx,
                         .regvtbl = {(esize << 1) + Q, cnt}};
}
static struct Da64Op OPregvtblidx(unsigned idx, unsigned esize, unsigned elem,
                                  unsigned cnt) {
  return (struct Da64Op){DA_OP_REGVTBLIDX, .reg = idx,
                         .regvtblidx = {esize, elem, cnt}};
}
static struct Da64Op OPmemuoff(unsigned idx, uint16_t off) {
  return (struct Da64Op){DA_OP_MEMUOFF, .reg = idx, .uimm16 = off};
}
static struct Da64Op OPmemsoff(unsigned idx, int16_t off) {
  return (struct Da64Op){DA_OP_MEMSOFF, .reg = idx, .simm16 = off};
}
static struct Da64Op OPmemsoffpre(unsigned idx, int16_t off) {
  return (struct Da64Op){DA_OP_MEMSOFFPRE, .reg = idx, .simm16 = off};
}
static struct Da64Op OPmemsoffpost(unsigned idx, int16_t off) {
  return (struct Da64Op){DA_OP_MEMSOFFPOST, .reg = idx, .simm16 = off};
}
static struct Da64Op OPmemreg(unsigned idx, unsigned offreg, enum Da64Ext ext,
                              bool scale, unsigned shift) {
  return (struct Da64Op){DA_OP_MEMREG, .reg = idx,
                         .memreg = {scale, ext, shift, offreg}};
}
static struct Da64Op OPmemregsimdpost(unsigned idx, unsigned offreg,
                                      unsigned constoff) {
  if (offreg == 31)
    return (struct Da64Op){DA_OP_MEMSOFFPOST, .reg = idx, .simm16 = constoff};
  return (struct Da64Op){DA_OP_MEMREGPOST, .reg = idx,
                         .memreg = {0, DA_EXT_UXTX, 0, offreg}};
}
static struct Da64Op OPmeminc(unsigned idx) {
  return (struct Da64Op){DA_OP_MEMINC, .reg = idx, .uimm16 = 0};
}
static struct Da64Op OPimmsmall(unsigned imm6) {
  return (struct Da64Op){DA_OP_IMMSMALL, {0}, .uimm16 = imm6};
}
static struct Da64Op OPsimm(int16_t imm) {
  return (struct Da64Op){DA_OP_SIMM, {0}, .simm16 = imm};
}
static struct Da64Op OPuimm(uint16_t imm) {
  return (struct Da64Op){DA_OP_UIMM, {0}, .uimm16 = imm};
}
static struct Da64Op OPuimmshift(uint16_t imm, bool msl, unsigned shift) {
  return (struct Da64Op){DA_OP_UIMMSHIFT, .immshift = {msl, shift},
                         .uimm16 = imm};
}
static struct Da64Op OPreladdr(struct Da64Inst* ddi, int64_t imm) {
  ddi->imm64 = imm;
  return (struct Da64Op){DA_OP_IMMLARGE, {0}, .uimm16 = 0};
}
static struct Da64Op OPimmlogical(struct Da64Inst* ddi, unsigned sf, unsigned N,
                                  unsigned immr, unsigned imms) {
  ddi->imm64 = immlogical(sf, N, immr, imms);
  return (struct Da64Op){DA_OP_IMMLARGE, {0}, .uimm16 = sf};
}
static struct Da64Op OPimmsimdmask(struct Da64Inst* ddi, uint8_t imm8) {
  uint64_t res = 0;
  for (unsigned i = 0; i < 8; i++)
    res += imm8 & (1 << i) ? (uint64_t)0xff << (i * 8) : 0;
  ddi->imm64 = res;
  return (struct Da64Op){DA_OP_IMMLARGE, {0}, .uimm16 = 1};
}
static struct Da64Op OPimmfloatzero(struct Da64Inst* ddi) {
  ddi->float8 = 0.0f;
  return (struct Da64Op){DA_OP_IMMFLOAT, {0}, .uimm16 = 0x100};
}
static struct Da64Op OPimmfloat(struct Da64Inst* ddi, uint8_t imm8) {
  uint32_t res = (uint32_t)(imm8 & 0x80) << 24;
  res |= imm8 & 0x40 ? 0x3e000000 : 0x40000000;
  res |= (imm8 & 0x3f) << 19;
  // clang-format off
  ddi->float8 = (union { uint32_t i; float f; }){.i = res}.f;
  // clang-format on
  return (struct Da64Op){DA_OP_IMMFLOAT, {0}, .uimm16 = imm8};
}
static struct Da64Op OPsysreg(unsigned reg) {
  return (struct Da64Op){DA_OP_SYSREG, {0}, .sysreg = reg};
}
static struct Da64Op OPcond(unsigned cond) {
  return (struct Da64Op){DA_OP_COND, {0}, .cond = cond};
}

void da64_decode(uint32_t inst, struct Da64Inst* ddi) {
  for (unsigned i = 0; i < sizeof(ddi->ops) / sizeof(ddi->ops[0]); i++)
    ddi->ops[i] = (struct Da64Op){0};
  unsigned mnem = da64_classify(inst);
  ddi->mnem = mnem;
  switch (DA64_GROUP(mnem)) {
    // Needs variables mnem, inst, and ddi.
#define DA64_DECODER
#include "disarm64-private.inc"
#undef DA64_DECODER
  }
}
