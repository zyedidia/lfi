call *%rax
>>>
.bundle_align_mode 5
.bundle_lock
andl $0xffffffe0, %eax
orq %r14, %rax
callq *%rax
.bundle_unlock
.p2align 5
------
call *32+output(%rip)
>>>
.bundle_align_mode 5
movq 32+output(%rip), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 5
------
jmp *(%rax)
>>>
.bundle_align_mode 5
movq %gs:(%eax), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
jmp *%r11
.bundle_unlock
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 5
movq %gs:(%eax, %edi, 4), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 5
------
notrack jmp *%rax
>>>
.bundle_align_mode 5
.bundle_lock
andl $0xffffffe0, %eax
orq %r14, %rax
notrack jmp *%rax
.bundle_unlock
------
callq *__cxa_finalize@GOTPCREL(%rip)
>>>
.bundle_align_mode 5
movq __cxa_finalize@GOTPCREL(%rip), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 5
------
callq foo
>>>
.bundle_align_mode 5
callq foo
.p2align 5
------
ret
>>>
.bundle_align_mode 5
popq %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
jmpq *%r11
.bundle_unlock
------
callq *(%rsp)
>>>
.bundle_align_mode 5
movq (%rsp), %r11
.bundle_lock
andl $0xffffffe0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 5
