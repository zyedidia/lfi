// flags: --decl
.bundle_align_mode 4
foo:
div %rdi, %rax
jz foo
nop
---
// flags: --decl
.bundle_align_mode 4
foo:
jz bar
.p2align 4
entry:
imul %rdi, %rax
jo foo
.p2align 4
bar:
---
.bundle_align_mode 4
cmp %eax, %eax
foo:
jz bar
.p2align 4
x:
jmp foo
.p2align 4
entry:
imul %rdi, %rax
jo x
.p2align 4
bar:
---
// flags: --poc
movq %r11, %gs:(%eax)
---
