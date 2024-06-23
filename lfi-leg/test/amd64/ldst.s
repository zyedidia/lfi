mov (%rsi), %rdx
mov (%rsi), %rdx
movb	(%rsi,%rdx), %r10b
mov $1, (%rax)
fsub (%rax)
>>>
.bundle_align_mode 4
mov %gs:(%esi), %rdx
mov %gs:(%esi), %rdx
movb %gs:(%esi, %edx), %r10b
mov $1, %gs:(%eax)
fsub %gs:(%eax)
------
mov $1, (%rsp)
>>>
.bundle_align_mode 4
mov $1, (%rsp)
------
mov $1, 8(%rip)
>>>
.bundle_align_mode 4
mov $1, 8(%rip)
------
imulq $24, -88(%rsp), %rax
imulq $24, -88(%rdi), %rax
>>>
.bundle_align_mode 4
imulq $24, -88(%rsp), %rax
imulq $24, %gs:-88(%edi), %rax
------
mov %rbx,(%rdi)         /* rdi is jmp_buf, move registers onto it */
>>>
.bundle_align_mode 4
mov %rbx, %gs:(%edi)
------
mov (%rax, %rdx), %dh
>>>
.bundle_align_mode 4
movq %rdi, %r15
leaq (%eax, %edx), %rdi
mov %gs:(%edi), %dh
movq %r15, %rdi
------
cmpl $44, 352(%rsp,%rax,4) # imm = 0x100
>>>
.bundle_align_mode 4
cmpl $44, %gs:352(%esp, %eax, 4)
------
movq %rdi, 0x0
>>>
.bundle_align_mode 4
movq %rdi, %gs:0x0
------
fldt	8(%rsp)
>>>
.bundle_align_mode 4
fldt	8(%rsp)
------
movl	(%rdx,%rsi,4), %edx
>>>
.bundle_align_mode 4
movl %gs:(%edx, %esi, 4), %edx
------
orl     $1, 12+__cpu_model(%rip)
>>>
.bundle_align_mode 4
orl     $1, 12+__cpu_model(%rip)
------
mov (,%rax,8),%rdx
>>>
.bundle_align_mode 4
mov %gs:(, %eax, 8), %rdx
------
vmovaps -0x30(%rsi), %xmm15; vmovaps -0x20(%rsi), %xmm14; vmovaps -0x10(%rsi), %xmm13; vmovaps (%rsi), %xmm12; vmovaps 0x10(%rsi), %xmm11; vmovaps 0x20(%rsi), %xmm10; vmovaps 0x30(%rsi), %xmm9 ; vmovaps 0x40(%rsi), %xmm8 ; vmovaps 0x50(%rsi), %xmm7 ; vmovaps 0x60(%rsi), %xmm6
>>>
.bundle_align_mode 4
vmovaps %gs:-0x30(%esi), %xmm15
vmovaps %gs:-0x20(%esi), %xmm14
vmovaps %gs:-0x10(%esi), %xmm13
vmovaps %gs:(%esi), %xmm12
vmovaps %gs:0x10(%esi), %xmm11
vmovaps %gs:0x20(%esi), %xmm10
vmovaps %gs:0x30(%esi), %xmm9
vmovaps %gs:0x40(%esi), %xmm8
vmovaps %gs:0x50(%esi), %xmm7
vmovaps %gs:0x60(%esi), %xmm6
