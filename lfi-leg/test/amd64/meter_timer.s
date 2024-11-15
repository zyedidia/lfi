jmp foo
>>>
.bundle_align_mode 4
.bundle_lock
leaq 0(%r12), %r12
jmp foo
.bundle_unlock
------
jz foo
>>>
.bundle_align_mode 4
.bundle_lock
leaq 0(%r12), %r12
jz foo
.bundle_unlock
------
jmpq *%rax
>>>
.bundle_align_mode 4
.bundle_lock
andl $0xfffffff0, %eax
orq %r14, %rax
leaq 0(%r12), %r12
jmpq *%rax
.bundle_unlock
------
call foo
>>>
.bundle_align_mode 4
.bundle_lock
leaq 0(%r12), %r12
callq foo
.bundle_unlock
.p2align 4
