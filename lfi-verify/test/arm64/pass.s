ldr x0, [x18]
---
add x18, x21, w0, uxtw
---
ldr x0, [x21, w0, uxtw]
---
b foo
foo:
---
br x18
---
ret
---
foo:
bl foo
---
ldr x0, [sp]
---
ldr x0, [sp], #16
---
ldr x0, [sp, 16]!
---
add sp, x21, w0, uxtw
---
nop
---
ldr x0, [x18, #4096]
---
str x0, [x18, #4096]
---
ld4 { v29.2s, v30.2s, v31.2s, v0.2s }, [x18]
---
brk #0x181a
---
str w28, [sp, #0x3a38]
---
movk x1, #0x9ec0, lsl #32
---
uaddl2 v12.4s, v2.8h, v19.8h
---
tbx v19.16b, { v26.16b }, v14.16b
---
extr x1, x8, x15, #0
---
stp s24, s9, [sp], #-0x10
---
ands x16, x30, #0x8f8f8f8f8f8f8f8f
---
str q0, [x18, #55696]
---
stp x29, x30, [sp], #16
---
ldr x30, [x21]
---
ldr x30, [x21, #8]
---
ldr x30, [x21, #16]
---
str w18, [x18]
---
stp xzr, xzr, [sp, #-0x10]!
---
swpal w0, w0, [x18]
---
ldadd w0, w0, [x18]
---
// flags: --sandbox=stores
ldr x0, [x1]
---
// flags: --sandbox=stores
ldr x0, [x1], #16
