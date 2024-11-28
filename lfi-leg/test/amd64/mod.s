addq %rdi, %rsp
>>>
.bundle_align_mode 5
.bundle_lock
addl %edi, %esp
orq %r14, %rsp
.bundle_unlock
------
add $0xc0, %rsp
>>>
.bundle_align_mode 5
.bundle_lock
add $0xc0, %esp
orq %r14, %rsp
.bundle_unlock
------
leaq -0x18(%rbp), %rsp
>>>
.bundle_align_mode 5
.bundle_lock
leal -0x18(%ebp), %esp
leaq (%rsp, %r14), %rsp
.bundle_unlock
------
leaq -0x10(%rsp), %rsp
>>>
.bundle_align_mode 5
.bundle_lock
leal -0x10(%esp), %esp
leaq (%rsp, %r14), %rsp
.bundle_unlock
------
mov (%rdi), %rsp
>>>
.bundle_align_mode 5
.bundle_lock
mov %gs:(%edi), %esp
orq %r14, %rsp
.bundle_unlock
------
mov 14(%rdi), %rsp
>>>
.bundle_align_mode 5
.bundle_lock
mov %gs:14(%edi), %esp
orq %r14, %rsp
.bundle_unlock
