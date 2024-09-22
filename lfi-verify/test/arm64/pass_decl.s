// flags: --poc
mov w0, w30
---
// flags: --meter=timer
br x24
---
// flags: --meter=timer
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
