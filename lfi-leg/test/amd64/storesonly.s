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
movq (%rax, %rdi, 4), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 4
------
jmpq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 4
movq (%rax, %rdi, 4), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
jmpq *%r11
.bundle_unlock
