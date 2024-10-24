// flags: --decl
.bundle_align_mode 4
foo:
add $8, %rax
nop
jz foo
ret
---
// flags: --decl
.bundle_align_mode 4
foo:
div %rdi, %rax
ret
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
