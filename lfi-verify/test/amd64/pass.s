add $8, %rdi
---
.bundle_align_mode 5
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
add $8, %rdi
jmp foo
nop
add $8, %rdi
.p2align 5
foo:
---
mov %gs:(%eax), %rax
---
mov %gs:12(%eax, %edi, 4), %rax
---
leaq 8(%rax), %rax
---
mov 12(%rsp), %rax
---
mov 12(%rip), %rax
---
andl $0xffffffe0, %eax
orq %r14, %rax
jmp *%rax
---
movl %eax, %esp
orq %r14, %rsp
---
add $12, %esp
orq %r14, %rsp
---
andl $0xfffffff0, %esp
orq %r14, %rsp
---
cmp %rsp, %rsp
---
andl $0xffffffe0, %eax
orq %r14, %rax
.nops 24
callq *%rax
---
.nops 2
andl $0xffffffe0, %eax
orq %r14, %rax
.nops 22
callq *%rax
---
leaq 1f(%rip), %r11
jmpq *(%r14)
1:
---
leaq 1f(%rip), %r11
jmpq *8(%r14)
1:
