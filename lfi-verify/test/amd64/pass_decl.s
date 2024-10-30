// flags: --decl
.bundle_align_mode 4
foo:
add $8, %rax
nop
jz foo
nop
---
// flags: --decl
.bundle_align_mode 4
foo:
div %rdi, %rax
nop
---
// flags: --decl
.bundle_align_mode 4
foo:
test %eax, %eax
js .L1
jne .L2
.p2align 4
.L1:
nop
.p2align 4
.L2:
nop
---
// flags: --decl
.bundle_align_mode 4
foo:
bt %esi, %ecx
jae foo
---
// flags: --decl
.bundle_align_mode 4
jmp entry
.p2align 4
foo:
je bar
.p2align 4
entry:
cmp %eax, %eax
jge foo
.p2align 4
bar:
---
// flags: --decl
.bundle_align_mode 4
test %bl, %bl
jle .foo
nop
.p2align 4
.foo:
je .bar
.p2align 4
.bar:
