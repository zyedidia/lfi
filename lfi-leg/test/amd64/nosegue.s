mov (%rsi), %rdx
>>>
.bundle_align_mode 4
.bundle_lock
movl %esi, %r15d
mov (%r14, %r15), %rdx
.bundle_unlock
------
mov 0x8(%rsi, %rdi, 4), %rdx
>>>
.bundle_align_mode 4
leaq 0x8(%rsi, %rdi, 4), %r15
.bundle_lock
movl %r15d, %r15d
mov (%r14, %r15), %rdx
.bundle_unlock
------
imulq $24, -88(%rsp), %rax
imulq $24, -88(%rdi), %rax
>>>
.bundle_align_mode 4
imulq $24, -88(%rsp), %rax
.bundle_lock
movl %edi, %r15d
imulq $24, -88(%r14, %r15), %rax
.bundle_unlock
------
mov (%rax, %rdx), %dh
>>>
.bundle_align_mode 4
movq %rdi, %r15
.bundle_lock
leal (%eax, %edx), %edi
leaq (%r14, %rdi), %rdi
mov (%rdi), %dh
.bundle_unlock
movq %r15, %rdi
------
movq %dh, (%rax)
>>>
.bundle_align_mode 4
movq %rdi, %r15
.bundle_lock
movl %eax, %edi
leaq (%r14, %rdi), %rdi
movq %dh, (%rdi)
.bundle_unlock
movq %r15, %rdi
------
movq %rdi, 0x0
>>>
.bundle_align_mode 4
movq %rdi, 0x0(%r14)
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 4
.bundle_lock
leal (%eax, %edi, 4), %r15d
movq (%r14, %r15), %r15
.bundle_unlock
.p2align 4
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
callq *%r15
.bundle_unlock
.p2align 4
