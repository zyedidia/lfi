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
---
// flags: --poc
adr x18, 0
---
// flags: --poc
adrp x18, foo
foo:
---
// flags: --poc
ret
---
// flags: --poc
add x18, x21, w22, uxtw
---
// flags: --poc
br x18
---
// flags: --poc
ldr x30, [x25]
---
// flags: --meter=timer --poc
blr x25
---
// flags: --meter=timer
nop
nop
foo:
nop
nop
sub x23, x23, #6
ret x24
sub x23, x23, #2
b foo
---
// flags: --meter=timer
nop
nop
nop
sub x23, x23, #4
foo:
nop
nop
sub x23, x23, #4
ret x24
sub x23, x23, #2
b foo
