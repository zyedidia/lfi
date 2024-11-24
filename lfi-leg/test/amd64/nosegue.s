mov (%rsi), %rdx
>>>
.bundle_align_mode 5
.bundle_lock
movl %esi, %r11d
mov (%r14, %r11), %rdx
.bundle_unlock
------
mov 0x8(%rsi, %rdi, 4), %rdx
>>>
.bundle_align_mode 5
leaq 0x8(%rsi, %rdi, 4), %r11
.bundle_lock
movl %r11d, %r11d
mov (%r14, %r11), %rdx
.bundle_unlock
------
imulq $24, -88(%rsp), %rax
imulq $24, -88(%rdi), %rax
>>>
.bundle_align_mode 5
imulq $24, -88(%rsp), %rax
.bundle_lock
movl %edi, %r11d
imulq $24, -88(%r14, %r11), %rax
.bundle_unlock
------
mov (%rax, %rdx), %dh
>>>
.bundle_align_mode 5
movq %rdi, %r11
.bundle_lock
leal (%eax, %edx), %edi
leaq (%r14, %rdi), %rdi
mov (%rdi), %dh
.bundle_unlock
movq %r11, %rdi
------
movq %dh, (%rax)
>>>
.bundle_align_mode 5
movq %rdi, %r11
.bundle_lock
movl %eax, %edi
leaq (%r14, %rdi), %rdi
movq %dh, (%rdi)
.bundle_unlock
movq %r11, %rdi
------
movq %rdi, 0x0
>>>
.bundle_align_mode 5
movq %rdi, 0x0(%r14)
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 5
.bundle_lock
leal (%eax, %edi, 4), %r11d
movq (%r14, %r11), %r11
.bundle_unlock
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 5
