jmpq *%rax
>>>
.bundle_align_mode 5
.bundle_lock
andl $0xffffffe0, %eax
orq %r14, %rax
sub $512, %r12
nop
nop
nop
jmpq *%rax
.bundle_unlock
------
jmp foo
>>>
.bundle_align_mode 5
.bundle_lock
leaq 512(%r12), %r12
movq %rcx, %r11
mov $0x3f, %cl
shrx %rcx, %r12, %rcx
nop
nop
nop
movq %r11, %rcx
jmp foo
.bundle_unlock
