jmp foo
>>>
.bundle_align_mode 5
.bundle_lock
leaq 512(%r12), %r12
jmp foo
.bundle_unlock
------
jz foo
>>>
.bundle_align_mode 5
.bundle_lock
leaq 512(%r12), %r12
jz foo
.bundle_unlock
------
jmpq *%rax
>>>
.bundle_align_mode 5
.bundle_lock
andl $0xffffffe0, %eax
orq %r14, %rax
leaq 512(%r12), %r12
jmpq *%rax
.bundle_unlock
------
call foo
>>>
.bundle_align_mode 5
.bundle_lock
leaq 512(%r12), %r12
callq foo
.bundle_unlock
.p2align 5
