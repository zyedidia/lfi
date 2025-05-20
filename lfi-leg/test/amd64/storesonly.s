mov (%rsi), %rdi
>>>
.bundle_align_mode 5
mov (%rsi), %rdi
------
mov %rsi, (%rdi)
>>>
.bundle_align_mode 5
mov %rsi, %gs:(%edi)
------
mov (%rsi, %rdi), %rdi
mov 0x32(%rsi, %rdi), %rdi
>>>
.bundle_align_mode 5
mov (%rsi, %rdi), %rdi
mov 0x32(%rsi, %rdi), %rdi
------
fldt (%rdi)
>>>
.bundle_align_mode 5
fldt %gs:(%edi)
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 5
movq (%rax, %rdi, 4), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 5
------
jmpq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 5
movq (%rax, %rdi, 4), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
jmpq *%r11
.bundle_unlock
------
xchg (%rax), %rdi
>>>
.bundle_align_mode 5
xchg %gs:(%eax), %rdi
------
cmpb $0x0, (%rax)
>>>
.bundle_align_mode 5
cmpb $0x0, (%rax)
------
cmpb (%rax), $0x0
>>>
.bundle_align_mode 5
cmpb (%rax), $0x0
------
testb $0x0, (%rax)
>>>
.bundle_align_mode 5
testb $0x0, (%rax)
------
movsq
>>>
.bundle_align_mode 5
.bundle_lock
movl %edi, %edi
leaq (%r14, %rdi), %rdi
movsq
.bundle_unlock
