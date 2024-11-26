jmpq *%rax
>>>
.bundle_align_mode 5
.bundle_lock
andl $0xffffffe0, %eax
orq %r14, %rax
sub $0, %r12
.byte 0x79, 0x01
int3
jmpq *%rax
.bundle_unlock
------
jmp foo
>>>
.bundle_align_mode 5
.bundle_lock
.byte 0x4d, 0x8d, 0xa4, 0x24, 0x00, 0x00, 0x00, 0x00
movq %rcx, %r11
mov $0x3f, %cl
shrx %rcx, %r12, %rcx
jrcxz 1024f
int3
1024:
movq %r11, %rcx
jmp foo
.bundle_unlock
