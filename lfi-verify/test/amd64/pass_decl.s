// flags: --decl
.bundle_align_mode 5
foo:
add $8, %rax
nop
jz foo
nop
---
// flags: --decl
.bundle_align_mode 5
foo:
div %rdi, %rax
nop
---
// flags: --decl
.bundle_align_mode 5
foo:
test %eax, %eax
js .L1
jne .L2
.p2align 5
.L1:
nop
.p2align 5
.L2:
nop
---
// flags: --decl
.bundle_align_mode 5
foo:
bt %esi, %ecx
jae foo
---
// flags: --decl
.bundle_align_mode 5
jmp entry
.p2align 5
foo:
je bar
.p2align 5
entry:
cmp %eax, %eax
jge foo
.p2align 5
bar:
---
// flags: --decl
.bundle_align_mode 5
test %bl, %bl
jle .foo
nop
.p2align 5
.foo:
je .bar
.p2align 5
.bar:
---
// flags: --poc
leal 1023f(%rip), %r11
movq %gs:(%eax), %r11
---
// flags: --poc
movq %r11d, %gs:(%eax)
---

