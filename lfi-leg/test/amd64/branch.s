call *%rax
>>>
.bundle_align_mode 4
movq %rax, %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
callq *%r15
.bundle_unlock
.p2align 4
------
call *32+output(%rip)
>>>
.bundle_align_mode 4
movq 32+output(%rip), %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
callq *%r15
.bundle_unlock
.p2align 4
------
jmp *(%rax)
>>>
.bundle_align_mode 4
movq %gs:(%eax), %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
jmp *%r15
.bundle_unlock
------
callq *(%rax, %rdi, 4)
>>>
.bundle_align_mode 4
movq %gs:(%eax, %edi, 4), %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
callq *%r15
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
movq __cxa_finalize@GOTPCREL(%rip), %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
callq *%r15
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
popq %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
jmpq *%r15
.bundle_unlock
------
callq *(%rsp)
>>>
.bundle_align_mode 4
movq (%rsp), %r15
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
callq *%r15
.bundle_unlock
.p2align 4
------
.type   _ZNSt8auto_ptrI9GameStateED2Ev, @function
>>>
.bundle_align_mode 4
.type   _ZNSt8auto_ptrI9GameStateED2Ev, @function
.p2align 4
