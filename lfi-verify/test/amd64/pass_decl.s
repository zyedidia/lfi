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
