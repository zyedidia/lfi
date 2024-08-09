shrq %rdi, %rax
>>>
.bundle_align_mode 4
.bundle_lock
andq $0x3f, %rdi
shrq %rdi, %rax
.bundle_unlock
------
shrl %edi, %eax
>>>
.bundle_align_mode 4
.bundle_lock
andl $0x1f, %edi
shrl %edi, %eax
.bundle_unlock
------
callq *(%rax)
>>>
.bundle_align_mode 4
movq %gs:(%eax), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
cmpq %rax, %rax
callq *%r11
.bundle_unlock
.p2align 4
------
syscall
>>>
.bundle_align_mode 4
syscall
