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
