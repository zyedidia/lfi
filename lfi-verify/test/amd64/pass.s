.bundle_align_mode 4
add $8, %rdi
---
.bundle_align_mode 4
add $8, %rdi
add $8, %rdi
add $8, %rdi
jmp foo
nop
add $8, %rdi
.p2align 4
foo:
