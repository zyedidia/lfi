mov (%rsi), %rdx
mov (%rsi), %rdx
movb	(%rsi,%rdx), %r10b
mov $1, (%rax)
fsub (%rax)
>>>
.bundle_align_mode 5
mov %gs:(%esi), %rdx
mov %gs:(%esi), %rdx
movb %gs:(%esi, %edx), %r10b
mov $1, %gs:(%eax)
fsub %gs:(%eax)
------
mov $1, (%rsp)
>>>
.bundle_align_mode 5
mov $1, (%rsp)
------
mov $1, 8(%rip)
>>>
.bundle_align_mode 5
mov $1, 8(%rip)
------
imulq $24, -88(%rsp), %rax
imulq $24, -88(%rdi), %rax
>>>
.bundle_align_mode 5
imulq $24, -88(%rsp), %rax
imulq $24, %gs:-88(%edi), %rax
------
mov %rbx,(%rdi)         /* rdi is jmp_buf, move registers onto it */
>>>
.bundle_align_mode 5
mov %rbx, %gs:(%edi)
------
mov (%rax, %rdx), %dh
>>>
.bundle_align_mode 5
mov %gs:(%eax, %edx), %dh
------
cmpl $44, 352(%rsp,%rax,4) # imm = 0x100
>>>
.bundle_align_mode 5
cmpl $44, %gs:352(%esp, %eax, 4)
------
movq %rdi, 0x0
>>>
.bundle_align_mode 5
movq %rdi, 0x0(%r14)
------
fldt	8(%rsp)
>>>
.bundle_align_mode 5
fldt 8(%rsp)
------
movl	(%rdx,%rsi,4), %edx
>>>
.bundle_align_mode 5
movl %gs:(%edx, %esi, 4), %edx
------
orl     $1, 12+__cpu_model(%rip)
>>>
.bundle_align_mode 5
orl $1, 12+__cpu_model(%rip)
------
mov (,%rax,8),%rdx
>>>
.bundle_align_mode 5
mov %gs:(, %eax, 8), %rdx
------
mov (,%rax),%rdx
>>>
.bundle_align_mode 5
mov %gs:(, %eax), %rdx
------
vmovaps -0x30(%rsi), %xmm15; vmovaps -0x20(%rsi), %xmm14; vmovaps -0x10(%rsi), %xmm13; vmovaps (%rsi), %xmm12; vmovaps 0x10(%rsi), %xmm11; vmovaps 0x20(%rsi), %xmm10; vmovaps 0x30(%rsi), %xmm9 ; vmovaps 0x40(%rsi), %xmm8 ; vmovaps 0x50(%rsi), %xmm7 ; vmovaps 0x60(%rsi), %xmm6
>>>
.bundle_align_mode 5
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
------
movq 32+output(%rip), %rdi
>>>
.bundle_align_mode 5
movq 32+output(%rip), %rdi
------
leaq (%rbx, %r15), %r15
>>>
.bundle_align_mode 5
leaq (%rbx, %r15), %r15
------
movslq -36(%rsp), %rax
>>>
.bundle_align_mode 5
movslq -36(%rsp), %rax
------
rep bsfq (%rsi), %rdi
>>>
.bundle_align_mode 5
rep bsfq %gs:(%esi), %rdi
------
vextracti128 $0x1, %ymm12, -736(%rbp)
>>>
.bundle_align_mode 5
vextracti128 $0x1, %ymm12, %gs:-736(%ebp)
------
movaps %xmm0, _ZN3std3sys3pal4unix14stack_overflow3imp5GUARD29_$u7b$$u7b$constant$u7d$$u7d$28_$u7b$$u7b$closure$u7d$$u7d$3VAL17h5082f51ad7913d78E@TPOFF(%rax)
>>>
.bundle_align_mode 5
movaps %xmm0, %gs:_ZN3std3sys3pal4unix14stack_overflow3imp5GUARD29_$u7b$$u7b$constant$u7d$$u7d$28_$u7b$$u7b$closure$u7d$$u7d$3VAL17h5082f51ad7913d78E@TPOFF(%eax)
