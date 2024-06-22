ldr x0, [x1]
>>>
ldr x0, [x21, w1, uxtw]
------
ldp x9, x10, [x2]
>>>
add x18, x21, w2, uxtw
ldp x9, x10, [x18]
------
ldrh w12, [x16, w12, uxtw]
>>>
add x22, x16, w12, uxtw
ldrh w12, [x21, w22, uxtw]
------
ld1 { v16.s }[1], [x11]
>>>
add x18, x21, w11, uxtw
ld1 { v16.s }[1], [x18]
------
ldr x1, [x1, #4188]
>>>
add x18, x21, w1, uxtw
ldr x1, [x18, #4188]
------
ldr x1, [x1, #:lo12:map]
>>>
add x22, x1, #:lo12:map
ldr x1, [x21, w22, uxtw]
------
ldr x0, [x1, #-56]
>>>
add x22, x1, #-56
ldr x0, [x21, w22, uxtw]
------
ldr x19, [x9, :lo12:.L_MergedGlobals+456]
>>>
add x22, x9, :lo12:.L_MergedGlobals+456
ldr x19, [x21, w22, uxtw]
------
stur x8, [x29, #-8] // 8-byte Folded Spill
>>>
add x18, x21, w29, uxtw
stur x8, [x18, #-8]
------
stp xzr, xzr, [x8], #32
>>>
add x18, x21, w8, uxtw
stp xzr, xzr, [x18], #32
mov x8, x18
------
stp xzr, xzr, [x8, #32]!
>>>
add x18, x21, w8, uxtw
stp xzr, xzr, [x18, #32]!
mov x8, x18
------
ldp x29, x30, [sp], 16
>>>
ldp x29, x22, [sp], 16
add x30, x21, w22, uxtw
------
ldr x30, [sp, #16]
>>>
ldr x22, [sp, #16]
add x30, x21, w22, uxtw
------
ld1 { v0.s }[1], [x8], x10
>>>
add x18, x21, w8, uxtw
ld1 { v0.s }[1], [x18]
add x8, x8, x10
------
ldr x0, [x1, :lo12:foo]
ldr x0, [x1, :got_lo12:foo]
>>>
add x22, x1, :lo12:foo
ldr x0, [x21, w22, uxtw]
add x18, x21, w1, uxtw
ldr x0, [x18, :got_lo12:foo]
------
ldaxr x0, [x2]
>>>
add x18, x21, w2, uxtw
ldaxr x0, [x18]
------
swpal w0, w0, [x1]
>>>
add x18, x21, w1, uxtw
swpal w0, w0, [x18]
------
stlxr w15, w17, [x1]
>>>
add x18, x21, w1, uxtw
stlxr w15, w17, [x18]
------
0: ldaxr x0, [x1]
>>>
0:
add x18, x21, w1, uxtw
ldaxr x0, [x18]
------
ldr x0, [x0, #8]
>>>
add x22, x0, #8
ldr x0, [x21, w22, uxtw]
------
ldp x20, x18, [x0]
ldp x20, x21, [x0]
>>>
add x18, x21, w0, uxtw
ldp x20, xzr, [x18]
add x18, x21, w0, uxtw
ldp x20, xzr, [x18]
------
ld1r {v3.2d}, [x9]
>>>
add x18, x21, w9, uxtw
ld1r {v3.2d}, [x18]
------
ldp x29, x30, [x19, #0xAf]
>>>
add x18, x21, w19, uxtw
ldp x29, x22, [x18, #0xAf]
add x30, x21, w22, uxtw
------
str x30, [x0]
>>>
str x30, [x21, w0, uxtw]
------
stp x29, x30, [x0]
>>>
add x18, x21, w0, uxtw
stp x29, x30, [x18]
