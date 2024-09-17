mov %fs:0, %rdx
>>>
.bundle_align_mode 4
pushq %rax
xor %eax, %eax
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
movq %rax, %rdx
popq %rax
------
mov %fs:0, %rax
>>>
.bundle_align_mode 4
xor %eax, %eax
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
------
mov %fs:0x0, %rax
>>>
.bundle_align_mode 4
xor %eax, %eax
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
------
callq *x@TLSCALL(%rax)
>>>
.bundle_align_mode 4
movq %gs:(%eax), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 4
------
add %fs:0x28, %rax
>>>
.bundle_align_mode 4
pushq %rax
movq $0x28, %rax
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
movq %rax, %r11
popq %rax
add %r11, %rax
