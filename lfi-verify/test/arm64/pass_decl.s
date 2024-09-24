// flags: --poc
mov w0, w30
---
// flags: --meter=timer
sub x23, x23, #2
br x24
---
// flags: --meter=timer
sub x23, x23, #2
ret x24
---
// flags: --meter=timer
bic x24, x18, 0x7
---
// flags: --meter=branch
bic x24, x18, 0xf
---
// flags: --meter=timer
bic x24, x30, 0x7
---
// flags: --meter=timer
nop
nop
sub x23, x23, #4
ret x24
