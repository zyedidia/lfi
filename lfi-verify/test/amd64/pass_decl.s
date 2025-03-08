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
leaq 1023f(%rip), %r11
1023:
---
// flags: --poc
movl %r11d, %gs:(%eax)
---
// flags: --poc
movq %gs:(%eax), %r11
---
// flags: --poc
movl %edi, %edi
leaq (%r14, %rdi), %rdi
rep stosq
movl %edi, %edi
---
// flags: --poc
movl %edi, %edi
leaq (%r14, %rdi), %rdi
movl %esi, %esi
leaq (%r14, %rsi), %rsi
rep movsq
movl %edi, %edi
movl %esi, %esi
