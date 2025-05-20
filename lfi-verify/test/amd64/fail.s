mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
mov %rdi, %rdi
---
jmp foo
nop
foo:
nop
---
jmpq *%rax
---
mov %gs:(%rax), %rax
---
mov (%rsp, %rax), %rax
---
mov (%rax), %rax
---
mov (%esp), %rax
---
jmp *%rax
---
andl $0xffffffff, %eax
orq %r14, %rax
jmp *%rax
---
andq $0xffffffffffffffe0, %rax
orq %r14, %rax
jmp *%rax
---
andl $0xffffffe0, %eax
jmp *%rax
---
andl $0xffffffe0, %eax
orl %r14d, %eax
jmp *%rax
---
mov %rax, %r14
---
mov $0, %r14
---
mov %rax, %rsp
---
mov $0, %rsp
---
add $12, %rsp
---
xchg %r14, %rax
---
callq *%rax
---
andl $0xffffffe0, %eax
orq %r14, %rax
.nops 28
callq *%rax
---
andl $0xffffffe0, %eax
orq %r14, %rax
callq *%rax
---
jmpq *(%r14)
---
leaq 1f(%rip), %r11
jmpq *(%r14)
nop
1:
---
leaq 1f(%rip), %r12
jmpq *(%r14)
1:
---
leaq 1f(%rip), %r11
jmpq *4(%r14)
1:
---
leaq 1f(%rip), %r11
jmpq *(%r14, %rax)
1:
---
mov %fs:0, %rax
---
mov %fs:(%rsp), %rax
---
mov %fs:(%rip), %rax
---
mov %gs, %rax
---
mov %rax, %gs
