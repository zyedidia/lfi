syscall
>>>
.bundle_align_mode 5
.bundle_lock
leaq 1024f(%rip), %r11
jmpq *0(%r14)
1024:
.bundle_unlock
