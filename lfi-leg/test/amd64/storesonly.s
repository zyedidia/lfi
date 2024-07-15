mov (%rsi), %rdi
>>>
.bundle_align_mode 4
mov (%rsi), %rdi
------
mov %rsi, (%rdi)
>>>
.bundle_align_mode 4
mov %rsi, %gs:(%edi)
------
mov (%rsi, %rdi), %rdi
mov 0x32(%rsi, %rdi), %rdi
>>>
.bundle_align_mode 4
mov (%rsi, %rdi), %rdi
mov 0x32(%rsi, %rdi), %rdi
------
fldt (%rdi)
>>>
.bundle_align_mode 4
fldt %gs:(%edi)
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 4
movq (%rax, %rdi, 4), %r15
.p2align 4
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
.byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
callq *%r15
.bundle_unlock
.p2align 4
------
jmpq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 4
movq (%rax, %rdi, 4), %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
jmpq *%r15
.bundle_unlock
