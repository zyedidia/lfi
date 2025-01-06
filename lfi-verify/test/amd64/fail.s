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
