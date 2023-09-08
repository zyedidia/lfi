hi:
ldr x0, [x0]
str x0, [x0]
ldr x0, [x0, 17]
str x0, [x0, 17]
ldr x1, [x0], 17
ldr x1, [x0, 42]!

ldr x1, [x0, x1]
ldr x1, [x0, w1, uxtw #2]
ldr x1, [x0, x1, lsl #1]

ldaxr x1, [x0, #8]
ldaxr x1, [x0]

ldp x0, x1, [x0]
ldp x0, x1, [x0, #16]

ldr x0, [sp]
ldr x0, [sp, #28]
ldr x0, [sp, #28]!
ldr x0, [sp], #28
ldr x0, [sp, x1]

ldp x0, x1, [x0], #16

// 29 "./arch" 1

ldr x1, [x1, #:lo12:map]
fmov d10, 2.5e1-1
fmov d10, 2.5e1+1

ldr x1, [x1, #4188]

eor x1, x1, x3, ror #(64 - 23)
subs x1, x1, 64 - 23

label: // yes
stur x1, [x2, #-8]

1: ldr x1, [x0]

mov sp,x9 ; br x8

.string "hello // world ; sdafkj"

ldrh w12, [x16, w12, uxtw]

ld1	{ v16.s }[1], [x11]

ldur x0, [x1, 10]

add sp, sp, 16
ldp x20, x30, [x0]
