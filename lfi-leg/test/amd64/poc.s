call foo
>>>
.bundle_align_mode 4
.bundle_lock
leaq 1024f(%rip), %r11
movl %r11d, %r11d
.bundle_unlock
pushq %r11
jmp foo
.p2align 4
1024:
------
callq *%rax
>>>
.bundle_align_mode 4
.bundle_lock
andl $0xfffffff0, %eax
orq %r14, %rax
leaq 1024f(%rip), %r11
pushq %r11
jmpq *%rax
.p2align 4
1024:
.bundle_unlock
------
leaq x(%rip), %rax
>>>
.bundle_align_mode 4
.bundle_lock
leaq x(%rip), %rax
movl %eax, %eax
.bundle_unlock
------
rep stosq
>>>
.bundle_align_mode 4
.bundle_lock
movl %edi, %edi
leaq (%r14, %rdi), %rdi
rep stosq
movl %edi, %edi
.bundle_unlock
------
rep movsq
>>>
.bundle_align_mode 4
.bundle_lock
movl %edi, %edi
leaq (%r14, %rdi), %rdi
movl %esi, %esi
leaq (%r14, %rsi), %rsi
rep movsq
movl %edi, %edi
movl %esi, %esi
.bundle_unlock
------
syscall
>>>
.bundle_align_mode 4
.bundle_lock
leaq 1024f(%rip), %r11
jmpq *(%r13)
1024:
.bundle_unlock
