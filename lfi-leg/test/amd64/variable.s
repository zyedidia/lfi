mov (%rsi), %rdx
>>>
.bundle_align_mode 4
.bundle_lock
pext %r13, %rsi, %r15
mov (%r14, %r15), %rdx
.bundle_unlock
------
callq *(%rsp)
>>>
.bundle_align_mode 4
movq (%rsp), %r15
.bundle_lock
andq %r13, %r15
andq $0xfffffffffffffff0, %r15
orq %r14, %r15
callq *%r15
.bundle_unlock
.p2align 4
------
imulq $24, -88(%rsp), %rax
imulq $24, -88(%rdi), %rax
>>>
.bundle_align_mode 4
imulq $24, -88(%rsp), %rax
.bundle_lock
pext %r13, %rdi, %r15
imulq $24, -88(%r14, %r15), %rax
.bundle_unlock
------
movq %dh, (%rax)
>>>
.bundle_align_mode 4
movq %rdi, %r15
.bundle_lock
pext %r13, %rax, %rdi
leaq (%r14, %rdi), %rdi
movq %dh, (%rdi)
.bundle_unlock
movq %r15, %rdi
------
rep stosq
>>>
.bundle_align_mode 4
.bundle_lock
pext %r13, %rdi, %rdi
leaq (%r14, %rdi), %rdi
rep stosq
.bundle_unlock
