// flags: --decl
.bundle_align_mode 4
foo:
div %rdi, %rax
jz foo
nop
---
// flags: --decl
.bundle_align_mode 4
start:
jmp s1
nop
s1:
jmp foo
nop
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
start:
jmp s1
nop
s1:
jmp foo
nop
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
movq %r11, %rax
---
// flags: --poc
movq %r11, %gs:(%eax) // this is probably technically allowed, since only the lowbits are read, but it's fine to reject
---
// flags: --poc
stosq
---
// flags: --poc
movsq
