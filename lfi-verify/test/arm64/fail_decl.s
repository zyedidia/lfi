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
