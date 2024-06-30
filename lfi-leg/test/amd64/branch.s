call *%rax
>>>
.bundle_align_mode 4
movq %rax, %r15
.p2align 4
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
.byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
callq *%r15
.bundle_unlock
------
call *32+output(%rip)
>>>
.bundle_align_mode 4
movq 32+output(%rip), %r15
.p2align 4
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
.byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
callq *%r15
.bundle_unlock
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
.p2align 4
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
.byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
callq *%r15
.bundle_unlock
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
.p2align 4
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
.byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
callq *%r15
.bundle_unlock
------
callq foo
>>>
.bundle_align_mode 4
.p2align 4
.byte 0x66, 0x66, 0x2e, 0x0f, 0x1f, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00
callq foo
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
.p2align 4
.bundle_lock
andl $0xfffffff0, %r15d
orq %r14, %r15
.byte 0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00
callq *%r15
.bundle_unlock
