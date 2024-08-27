syscall
>>>
.bundle_align_mode 4
.bundle_lock
leaq .LFI_SYS0(%rip), %r11
jmpq *(%r14)
.LFI_SYS0:
.bundle_unlock
