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
