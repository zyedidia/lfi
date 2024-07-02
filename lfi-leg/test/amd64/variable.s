mov (%rsi), %rdx
>>>
.bundle_align_mode 4
movq %rsi, %r15
.bundle_lock
andq %r13, %r15
mov (%r14, %r15), %rdx
.bundle_unlock
------
callq *(%rsp)
>>>
.bundle_align_mode 4
movq (%rsp), %r15
.p2align 4
.bundle_lock
andq %r13, %r15
orq %r14, %r15
.byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
callq *%r15
.bundle_unlock
------
imulq $24, -88(%rsp), %rax
imulq $24, -88(%rdi), %rax
>>>
.bundle_align_mode 4
imulq $24, -88(%rsp), %rax
movq %rdi, %r15
.bundle_lock
andq %r13, %r15
imulq $24, -88(%r14, %r15), %rax
.bundle_unlock
------
movq %dh, (%rax)
>>>
.bundle_align_mode 4
movq %rdi, %r15
movq %rax, %rdi
.bundle_lock
andq %r13, %rdi
leaq (%r14, %rdi), %rdi
movq %dh, (%rdi)
.bundle_unlock
movq %r15, %rdi
------
rep stosq
>>>
.bundle_align_mode 4
.bundle_lock
andq %r13, %rdi
leaq (%r14, %rdi), %rdi
rep stosq
.bundle_unlock
