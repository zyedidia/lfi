mov %fs:0, %rdx
>>>
.bundle_align_mode 4
pushq %rax
.bundle_lock
leaq 1f(%rip), %r11
jmpq *8(%r14)
1:
.bundle_unlock
movq %rax, %rdx
popq %rax
------
mov %fs:0, %rax
>>>
.bundle_align_mode 4
.bundle_lock
leaq 1f(%rip), %r11
jmpq *8(%r14)
1:
.bundle_unlock
------
mov %fs:0x0, %rax
>>>
.bundle_align_mode 4
.bundle_lock
leaq 1f(%rip), %r11
jmpq *8(%r14)
1:
.bundle_unlock
