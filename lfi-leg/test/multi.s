ldr x0, [x11]

ldp x9, x10, [x2]

ldrh w12, [x16, w12, uxtw]

ld1 { v16.s }[1], [x11]

eor x1, x1, x3, ror #(64 - 23)
subs x1, x1, 64 - 23

ldr x1, [x1, #4188]

fmov d10, 2.5e1-1
fmov d10, 2.5e1+1
ldr x1, [x1, #:lo12:map]

ldr x0, [x1, #-56]

ldr x19, [x9, :lo12:.L_MergedGlobals+456]

stur x8, [x29, #-8] // 8-byte Folded Spill

stp xzr, xzr, [x8], #32

stp xzr, xzr, [x8, #32]!

ldp x29, x30, [sp], 16

ldr x30, [sp, #16]

ld1 { v0.s }[1], [x8], x10

ldr x0, [x1, :lo12:foo]
ldr x0, [x1, :got_lo12:foo]

svc #0

ldaxr x0, [x2]

swpal w0, w0, [x1]

stlxr w15, w17, [x1]

stlxp w15, w14, w16, [x1]

0: ldaxr x0, [x1]

ldr x0, [x0, #8]

ldp x20, x18, [x0]

ldp x20, x21, [x0]
