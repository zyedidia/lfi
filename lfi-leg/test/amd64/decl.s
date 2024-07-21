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
movq %gs:(%eax), %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
cmpq %rax, %rax
callq *%r15
.bundle_unlock
.p2align 4
