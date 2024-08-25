syscall
>>>
.bundle_align_mode 4
.bundle_lock
leaq 1f(%rip), %r11
jmpq *(%r14)
1:
.bundle_unlock
