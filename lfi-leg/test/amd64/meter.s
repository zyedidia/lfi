jmpq *%rax
>>>
.bundle_align_mode 4
.bundle_lock
andl $0xfffffff0, %eax
orq %r14, %rax
sub $0, %r12
jns 1024f
int3
1024:
jmpq *%rax
.bundle_unlock
------
jmp foo
>>>
.bundle_align_mode 4
.bundle_lock
leaq 0(%r12), %r12
pushq %rcx
movl $0x3f, %ecx
shrx %rcx, %r12, %rcx
jrcxz 1024f
int3
1024:
popq %rcx
jmp foo
.bundle_unlock
