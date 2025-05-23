ldr x0, [x0]
---
br x0
---
mov sp, x0
---
mov x21, x0
---
mov x18, x0
---
mov x30, x0
---
ret x0
---
str x0, [x1]
---
svc #0
---
svc #12
---
.long 0b01001010000000001000000000000000 // undefined eor encoding
---
.long 0b10011011110000000111100000000000 // umulh with incorrect SBO
---
ldr x30, [sp]
---
add x30, x21, x30
---
ldr x0, [x21], #16
---
// ldr x0, [x0], #16
.long 0xf8410400
---
wfi
---
ldr x0, #0
---
dc cvau, x0
---
adr x18, foo
foo:
---
msr	s3_5_c12_c9_4, x18
---
mrs	x18, tpidr_el0
---
.long 0x09fa09f2
---
ld4 { v29.2s, v30.2s, v31.2s, v0.2s }, [x0]
---
.long 0xc4ff8005
---
swplb w20, w21, [x18]
---
swpal x20, x21, [x18]
---
ldadd x20, x21, [x18]
---
caspl x20, x21, x0, x1, [x21]
---
add x21, sp, #0xc20
---
ldr x0, [x21, 16]!
---
mrs x0, tpidr_el0
---
msr tpidr_el0, x0
---
ldr x30, [x21, 24]
---
// ldp x0, x0, [x18]
.long 0xa9400240
---
ldp x0, x18, [x18]
---
add w18, w21, w7, uxtw #0
---
// ldp w11, w18, [x18], #-0x28
.long 0x28fb4a4b
---
// stp w11, w18, [x18], #-0x28
.long 0x28bb4a4b
---
.inst   0x48207e43
---
// flags: --sandbox=stores
ldr x0, [x21], #16
---
// flags: --sandbox=stores
str x0, [x1]
