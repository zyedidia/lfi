// flags: --decl
ldxr x0, [x18]
---
// flags: --poc
mov x0, x18
---
// flags: --poc
mov x0, sp
---
// flags: --poc
mov x0, x30
---
// flags: --poc
str x18, [sp]
---
// flags: --poc
stp x0, x18, [sp]
---
// flags: --poc
ldr x18, [sp]
---
// flags: --meter=timer
br x18
---
// flags: --meter=timer
ret
---
// flags: --meter=timer
bic x24, x18, 0x1
---
// flags: --meter=timer
bic x24, xzr, 0x7
---
// flags: --poc
adr x0, .L0
.L0:
---
// flags: --poc
adrp x0, .L0
.L0:
---
// flags: --meter=timer
mov x23, x0
---
// flags: --meter=timer
ldr x23, [sp]
---
// flags: --meter=timer
nop
nop
sub x23, x23, #1
ret x24
---
// flags: --meter=timer
nop
sub x23, x23, #2
ret x24
---
// flags: --meter=timer
b foo
foo:
---
// flags: --meter=timer
mov x23, x0
sub  x23, x23, #3
cbnz x0, foo
foo:
---
// flags: --meter=timer
sub x23, x23, #2
b foo
nop
foo:
---
// flags: --meter=timer
nop
nop
foo:
nop
nop
sub x23, x23, #4
ret x24
sub x23, x23, #2
b foo
