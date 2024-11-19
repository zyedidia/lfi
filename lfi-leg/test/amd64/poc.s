call foo
>>>
.bundle_align_mode 4
.bundle_lock
leal 1024f(%rip), %r11d
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
leal 1024f(%rip), %r11d
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
leal x(%rip), %eax
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
------
leaq 4(%rsp), %rax
>>>
.bundle_align_mode 4
leal 4(%rsp), %eax
------
movq %rsp, %rax
>>>
.bundle_align_mode 4
movl %esp, %eax
------
addq %rsp, %rax
>>>
.bundle_align_mode 4
.bundle_lock
movl %esp, %r11d
addq %r11, %rax
.bundle_unlock
------
movq x@GOTPCREL(%rip), %rax
>>>
.bundle_align_mode 4
movl x@GOTPCREL(%rip), %eax
------
leaq (%rsp, %rax), %rax
>>>
.bundle_align_mode 4
leal (%rsp, %rax), %eax
------
leaq 0x18(%rbp), %rsp
>>>
.bundle_align_mode 4
.bundle_lock
leal 0x18(%ebp), %esp
leaq (%rsp, %r14), %rsp
.bundle_unlock
