rep stosq
>>>
.bundle_align_mode 5
.bundle_lock
movl %edi, %edi
leaq (%r14, %rdi), %rdi
rep stosq
.bundle_unlock
------
rep movsq
>>>
.bundle_align_mode 5
.bundle_lock
movl %edi, %edi
leaq (%r14, %rdi), %rdi
movl %esi, %esi
leaq (%r14, %rsi), %rsi
rep movsq
.bundle_unlock
