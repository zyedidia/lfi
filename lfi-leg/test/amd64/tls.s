mov %fs:0, %rdx
>>>
.bundle_align_mode 5
movq %rax, %rdx
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
xchgq %rax, %rdx
------
mov %fs:0, %rax
>>>
.bundle_align_mode 5
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
------
mov %fs:0x0, %rax
>>>
.bundle_align_mode 5
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
------
callq *x@TLSCALL(%rax)
>>>
.bundle_align_mode 5
.nops 13
callq *x@TLSCALL(%rax)
.p2align 5
------
add %fs:0x28, %rdx
>>>
.bundle_align_mode 5
pushq %rax
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
movq %rax, %r11
popq %rax
.bundle_lock
movl %r11d, %r11d
add 0x28(%r14, %r11), %rdx
.bundle_unlock
------
add %fs:(%rax), %rax
>>>
.bundle_align_mode 5
pushq %rax
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
movq %rax, %r11
leaq (%rax), %rax
leaq (%rax, %r11), %r11
popq %rax
.bundle_lock
movl %r11d, %r11d
add (%r14, %r11), %rax
.bundle_unlock
------
movl %fs:0, %ecx
>>>
.bundle_align_mode 5
pushq %rax
.bundle_lock
leaq .LFI_TLS0(%rip), %r11
jmpq *8(%r14)
.LFI_TLS0:
.bundle_unlock
movq %rax, %r11
popq %rax
.bundle_lock
movl %r11d, %r11d
movl 0(%r14, %r11), %ecx
.bundle_unlock
