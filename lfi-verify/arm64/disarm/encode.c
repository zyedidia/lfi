
#include "disarm64.h"
#include <stdint.h>

uint32_t da_immadd(int64_t value) {
  uint32_t inst = 0;
  uint64_t uval = value;
  if (value < 0) {
    inst = 0x40000000; // flip add/sub
    uval = -uval;
  }
  if ((uval & 0xfff) == uval)
    return inst | uval << 10;
  if ((uval & 0xfff000) == uval)
    return inst | 1 << 22 | uval >> 2;
  return 0xffffffff;
}

uint32_t da_immlogical(uint64_t value, unsigned is64) {
  if (!is64)
    value = value | (value << 32);

  if (value == 0 || ~value == 0)
    goto fail;

  int clz = __builtin_clzll(value);
  int iclz = __builtin_clzll(~value);
  int ctz = __builtin_ctzll(value);
  int ictz = __builtin_ctzll(~value);
  int popcount = __builtin_popcountll(value);

  int elog = 0;
  int shift = 64;
  uint32_t imms = (0x1780) | (popcount - 1);
  while (elog < 6) {
    if (clz + ctz == shift - popcount)
      return (((ctz ? shift - ctz : 0) << 6) | (imms & 0x103f)) << 10;
    else if (iclz + ictz == popcount)
      return ((iclz << 6) | (imms & 0x103f)) << 10;

    elog += 1;
    popcount >>= 1;
    shift >>= 1;
    imms >>= 1;
    uint64_t mask = (1ull << shift) - 1;
    if ((value & mask) != (value >> shift & mask))
      goto fail;
  }

  __builtin_unreachable();

fail:
  return 0xffffffff;
}

uint32_t da_immfmov32(float value) {
  // clang-format off
  uint32_t vi = (union { uint32_t i; float f; }){.f = value}.i;
  // clang-format on
  if (!(vi & 0x7ffff) && (uint32_t)((vi >> 25 & 0x3f) - 0x1f) <= 1)
    return (vi >> 19 & 0x7f) | (vi >> 24 & 0x80);
  return 0xffffffff;
}

uint32_t da_immfmov64(double value) {
  // clang-format off
  uint64_t vi = (union { uint64_t i; double f; }){.f = value}.i;
  // clang-format on
  if (!(vi & 0xffffffffffff) && (uint64_t)((vi >> 54 & 0x1ff) - 0xff) <= 1)
    return (vi >> 48 & 0x7f) | (vi >> 56 & 0x80);
  return 0xffffffff;
}

uint32_t da_immsimdmovi(uint64_t value) {

#define moviencode(imm8, op, cmode)                                            \
  (((op) ? 0x20000000 : 0) | ((cmode) << 12) | (((imm8) << 11) & 0x70000) |    \
   (((imm8) << 5) & 0x3e0))

  // Handle this early, so that clz/ctz work.
  if (value == 0 || ~value == 0)
    goto imm8;
  if ((value & 0xffffffff) != value >> 32)
    goto mask64;
  if ((value & 0xffff) != (value >> 16 & 0xffff)) { // attempt 32 bit lsl/msl
    uint32_t value32 = value;
    int clz = __builtin_clz(value32) >> 3;
    int iclz = __builtin_clz(~value32) >> 3;
    int ctz = __builtin_ctz(value32) >> 3;
    int ictz = __builtin_ctz(~value32) >> 3;
    if (clz + ctz >= 3) // MOVI 32-bit LSL ctz*8
      return moviencode(value >> ctz * 8, 0, ctz * 2);
    if (iclz + ictz >= 3) // MVNI 32-bit LSL ictz*8
      return moviencode(~value >> ictz * 8, 1, ictz * 2);
    if (clz + ictz >= 3) // MOVI 32-bit MSL ictz*8
      return moviencode(value >> ictz * 8, 0, 0xc + ictz - 1);
    if (iclz + ctz >= 3) // MVNI 32-bit MSL ctz*8
      return moviencode(~value >> ctz * 8, 1, 0xc + ctz - 1);
    goto mask64;
  }
  if ((value & 0xff) != (value >> 8 & 0xff)) { // attempt 16 bit lsl
    unsigned low8 = value & 0xff;
    unsigned high8 = value >> 8 & 0xff;
    if (high8 == 0) // MOVI 16-bit LSL 0
      return moviencode(low8, 0, 0x8);
    if (high8 == 0xff) // MVNI 16-bit LSL 0
      return moviencode(~low8, 1, 0x8);
    if (low8 == 0) // MOVI 16-bit LSL 8
      return moviencode(high8, 0, 0xa);
    if (low8 == 0xff) // MVNI 16-bit LSL 8
      return moviencode(~high8, 1, 0xa);
    goto mask64;
  }
imm8:
  // MOVI 8-bit
  return moviencode(value & 0xff, 0, 0xe);
mask64:;
  // attempt MOVI 64-bit mask
  unsigned imm8 = 0;
  for (unsigned i = 0; i < 8; i++) {
    unsigned byte = value >> 8 * i & 0xff;
    if (byte == 0xff)
      imm8 |= 1 << i;
    else if (byte != 0)
      goto fail;
  }
  return moviencode(imm8, 1, 0xe); // MOVI 64-bit
fail:
  return 0xffffffff;
#undef moviencode
}

#define DA64_ENCODER
#include "disarm64-private.inc"
#undef DA64_ENCODER

unsigned de64_MOVconst(uint32_t* buf, DA_GReg reg, uint64_t cnst) {
  if (cnst < 0x10000) {
    buf[0] = de64_MOVZx(reg, (uint16_t)cnst);
    return 1;
  } else if (cnst >= 0xffffffffffff0000) {
    buf[0] = de64_MOVNx(reg, (uint16_t)~cnst);
    return 1;
  }
  int clz = __builtin_clzll(cnst) >> 4;
  int iclz = __builtin_clzll(~cnst) >> 4;
  int ctz = __builtin_ctzll(cnst) >> 4;
  int ictz = __builtin_ctzll(~cnst) >> 4;
  if (clz + ctz == 3) { // Simple MOVZ shifted by ctz
    buf[0] = de64_MOVZx_shift(reg, cnst >> (ctz * 16), ctz);
    return 1;
  } else if (iclz + ictz == 3) { // Simple MOVN shifted by ictz
    buf[0] = de64_MOVNx_shift(reg, ~cnst >> (ictz * 16), ictz);
    return 1;
  } else if ((buf[0] = de64_ORRxi(reg, DA_ZR, cnst))) {
    return 1;
  } else if (clz == 2 && (__builtin_clz(~cnst) >> 4) + ictz >= 1) { // MOVNw
    buf[0] = de64_MOVNw_shift(reg, (uint32_t)~cnst >> (ictz * 16), ictz);
    return 1;
  }

  // XXX: maybe add two-instruction sequences, e.g. to ORRs or MOVZ+ORR?
  // XXX: try inversion to reduce number of instructions
  buf[0] = de64_MOVZx_shift(reg, cnst >> (16 * ctz) & 0xffff, ctz);
  unsigned cnt = 1;
  for (unsigned i = ctz + 1; i < 4; i++) {
    if (cnst >> 16 * i & 0xffff)
      buf[cnt++] = de64_MOVKx_shift(reg, cnst >> 16 * i & 0xffff, i);
  }
  return cnt;
}
