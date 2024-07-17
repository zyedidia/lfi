call *%rax
>>>
.bundle_align_mode 4
movq %rax, %r15
.p2align 4
.bundle_lock
andq $0xfffffffffffffff0, %r15
callq *%r15
.bundle_unlock
.p2align 4
------
mov (%rsi), %rdi
>>>
.bundle_align_mode 4
mov (%rsi), %rdi
------
mov %rsi, (%rdi)
>>>
.bundle_align_mode 4
mov %rsi, (%rdi)
------
ret
>>>
.bundle_align_mode 4
popq %r15
.bundle_lock
andq $0xfffffffffffffff0, %r15
jmpq *%r15
.bundle_unlock
------
jmp *(%rax)
>>>
.bundle_align_mode 4
movq (%rax), %r15
.bundle_lock
andq $0xfffffffffffffff0, %r15
jmp *%r15
.bundle_unlock
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 4
movq (%rax, %rdi, 4), %r15
.p2align 4
.bundle_lock
andq $0xfffffffffffffff0, %r15
callq *%r15
.bundle_unlock
.p2align 4
