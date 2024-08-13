# Disarm — Fast AArch64 Decode/Encoder

Disarm is a fast and lightweight decoder and encoder for AArch64. It has a focus on performance, zero-dependencies (not even the C standard library), and a reasonably small size.

## Encoder

The encoder generally exposes one macro/function per instruction mnemonic/form/operation size/etc., e.g., `de64_ADDw_uxtw(Rd,Rn,Rm,imm)` for 32-bit `add` with `uxtw` extension or `de64_STRwu(Rt,Rn,imm)` for 32-bit `str` with an unsigned immediate offset. When invalid arguments (e.g., out-of-range immediate) are passed and the instruction is not encodable, functions return zero. The API is designed to be usable like this:

```c++
if (uint32_t inst = da_ADDxi(ra, rb, imm)) {
    *buf++ = inst;
} else {
    DA_GReg tmp = allocTempReg();
    buf += da_MOVconst(buf, tmp, imm);
    *buf++ = da_ADDx(ra, rb, tmp);
    freeTempReg();
}
```

Register classes are exposed as data types. General-purpose registers (`DA_GP(num)`) that are not `sp`/`xzr` have type `DA_GReg`, `DA_ZR` has type `DA_GRegZR`, `DA_SP` has type `DA_GRegSP`, and floating-point/SIMD registers `DA_V(num)` have type `DA_VReg`. Whenever a GP-or-ZR/GP-or-SP is accepted, functions accept both `DA_GReg` and `DA_GRegZR`/`DA_GRegSP` (C uses `_Generic`, C++ uses implicit constructors). If this type system causes problems, disable it by defining `DA_NOSTRUCT` before `#include <disarm64.h>`.

There are a few functions, which operate differently than standard assembler instructions:

- `de64_MOVconst(uint32_t* buf, DA_GReg, uint64_t)` produces a sequence of up to 4 instructions into the buffer to materialize the constant in the general-purpose register. The function returns the number of instructions written.
- `add/sub` with immediate (`de64_ADDxi` etc.) shift the immediate as required and also convert between `add`/`sub` as required, so encoding `add x0, x1, -1` will succeed and be transparently encoded as `sub x0, x1, 1`. This also works (and is correct) when flags are updated.
- `de64_ADR(DA_GReg, uintptr_t codeAddr, uintptr_t targetAddr)` takes the address of the instruction and the target as parameters and computes the difference itself. Code is not position-dependent at all.
- `de64_ADRP(DA_GReg, uintptr_t codeAddr, uintptr_t targetAddr)` takes the address of the instruction and the target as parameters and computes the difference itself. The offset of the code in the current page must be fixed. Usage example:

    ```c
    uintptr_t codeAddr = (uintptr_t) codeBuf; // Address where ADRP will be placed
    uintptr_t targetAddr = codeAddr + 0x2f3a; // Target address x0 should point to
    *codeBuf++ = de64_ADRP(DA_GP(0), codeaddr, targetAddr);
    *codeBuf++ = de64_ADDxi(DA_GP(0), DA_GP(0), targetAddr & 0xfff);
    ```

- `de64_MOVId/de64_MOVI2d(DA_VReg, uint64_t)` tries to materialize the constant in a single `MOVI` instruction using an appropriate encoding.
- Assembly aliases (e.g., `lsl`, `cmp`) are provided in most cases. `mov` to/from `sp` is named `de64_MOV_SPx` for disambiguation.

**API/ABI stability:** ABI and API should be fairly stable in its current form. Prefer static linking and consider using Link-Time Optimization (LTO).

## Decoder

The decoder consists of three separate stages:

- Instruction validation and classification (`da64_classify`). Takes one instruction (a `uint32_t`) and, if the instruction is valid, returns the instruction kind (`enum Da64InstKind`, e.g., `DA64I_ADD_IMM`).
- Operand decoding (`da64_decode`). Takes one instruction, classifies the instruction, and decodes operands into a `struct Da64Inst`. Different encodings of immediates, register numbers, vector element indices, etc. are unified. Note that AArch64 has a large amount of different operand types (see `enum Da64OpType` in [disarm64.h](disarm64.h)).
- Formatting (`da64_format`). Takes a `struct Da64Inst` and formats the instruction as string. Currently, preferred disassembly aliases are not used, but this might change in future.

```c
// Example for da64_classify
enum Da64InstKind kind = da64_classify(0x0b204c00);
assert(kind == DA64I_ADD_EXT);

// Example for da64_decode
struct Da64Inst inst;
da64_decode(0x0b204c00, &inst);
// inst.mnem is DA64I_UNKNOWN for an unrecognized/invalid instruction
assert(inst.mnem == DA64I_ADD_EXT); // Result from da64_classify
// Note that ADD_EXT can encode SP instead of ZR.
// A stand-alone SP always has type DA_OP_REGSP.
assert(inst.ops[0].type == DA_OP_REGGP);
assert(inst.ops[0].reg == 0 && inst.ops[0].reggp.sf == 0); // first operand: w0
assert(inst.ops[1].type == DA_OP_REGGP);
assert(inst.ops[1].reg == 0 && inst.ops[1].reggp.sf == 0); // second operand: w0
assert(inst.ops[2].type == DA_OP_REGGPEXT); // extended register
assert(inst.ops[2].reg == 0 && inst.ops[2].reggpext.sf == 0 &&
       inst.ops[2].reggpext.ext == DA_EXT_UXTW &&
       inst.ops[2].reggpext.shift == 3); // third operand: w0, uxtw #3

// Example for da64_format
char fmtbuf[128]; // fixed-size buffer, must be at least 128 bytes
da64_format(&inst, fmtbuf);
assert(!strcmp(fmtbuf, "add w0, w0, w0, uxtw #3"));
```

**API/ABI stability:** the API is mostly stable, but minor API breakages might occur for mnemonic names. There is no ABI stability, as all mnemonics auto-generated and structure layout may change to easily accommodate further ISA extensions. Please link statically.

## Supported Extensions

Roughly all ISA extensions introduced in ARMv8.8 and earlier are currently supported, with the exception of SVE (+F32MM/F64MM). Some more recent extensions are also supported. See [feat.txt](feat.txt) for a full list, all listed extensions that have no `incomplete:` line are fully supported.
