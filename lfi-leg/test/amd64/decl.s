shrdq %cl, %rdi, %rax
>>>
.bundle_align_mode 5
.bundle_lock
andb $0x3f, %cl
shrdq %cl, %rdi, %rax
.bundle_unlock
------
shrdl %cl, %edi, %eax
>>>
.bundle_align_mode 5
.bundle_lock
andb $0x1f, %cl
shrdl %cl, %edi, %eax
.bundle_unlock
------
callq *(%rax)
>>>
.bundle_align_mode 5
movq %gs:(%eax), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 5
------
bsr %eax, %eax
>>>
.bundle_align_mode 5
.bundle_lock
test %eax, %eax
jz 1024f
bsr %eax, %eax
.bundle_unlock
1024:
