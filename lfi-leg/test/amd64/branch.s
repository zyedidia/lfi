call *%rax
>>>
.bundle_align_mode 4
movq %rax, %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 4
------
call *32+output(%rip)
>>>
.bundle_align_mode 4
movq 32+output(%rip), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 4
------
jmp *(%rax)
>>>
.bundle_align_mode 4
movq %gs:(%eax), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
jmp *%r11
.bundle_unlock
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 4
movq %gs:(%eax, %edi, 4), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 4
------
notrack jmp *%rax
>>>
.bundle_align_mode 4
.bundle_lock
andl $0xfffffff0, %eax
orq %r14, %rax
notrack jmp *%rax
.bundle_unlock
------
callq *__cxa_finalize@GOTPCREL(%rip)
>>>
.bundle_align_mode 4
movq __cxa_finalize@GOTPCREL(%rip), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 4
------
callq foo
>>>
.bundle_align_mode 4
callq foo
.p2align 4
------
ret
>>>
.bundle_align_mode 4
popq %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
jmpq *%r11
.bundle_unlock
------
callq *(%rsp)
>>>
.bundle_align_mode 4
movq (%rsp), %r11
.bundle_lock
andl $0xfffffff0, %r11d
orq %r14, %r11
callq *%r11
.bundle_unlock
.p2align 4
------
.type   _ZNSt8auto_ptrI9GameStateED2Ev, @function
>>>
.bundle_align_mode 4
.type   _ZNSt8auto_ptrI9GameStateED2Ev, @function
.p2align 4
