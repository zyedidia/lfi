syscall
>>>
.bundle_align_mode 4
.bundle_lock
leaq 1024f(%rip), %r11
jmpq *(%r14)
1024:
.bundle_unlock
