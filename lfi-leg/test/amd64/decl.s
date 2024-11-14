shrdq %cl, %rdi, %rax
>>>
.bundle_align_mode 4
.bundle_lock
andb $0x3f, %cl
shrdq %cl, %rdi, %rax
.bundle_unlock
------
shrdl %cl, %edi, %eax
>>>
.bundle_align_mode 4
.bundle_lock
andb $0x1f, %cl
shrdl %cl, %edi, %eax
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
