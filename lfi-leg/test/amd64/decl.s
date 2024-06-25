shrq %rdi, %rax
>>>
.bundle_align_mode 4
.bundle_lock
andq $0x3f, %rdi
shrq %rdi, %rax
.bundle_unlock
------
shrl %edi, %eax
>>>
.bundle_align_mode 4
.bundle_lock
andl $0x1f, %edi
shrl %edi, %eax
.bundle_unlock
