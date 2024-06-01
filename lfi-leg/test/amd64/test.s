mov (%rsi), %rdx
mov (%rsi), %rdx
movb	(%rsi,%rdx), %r10b
mov $1, (%rax)

fsub (%rax)

mov $1, (%rsp)

mov $1, 8(%rip)

imulq $24, -88(%rsp), %rax

vmovaps -0x30(%rsi), %xmm15; vmovaps -0x20(%rsi), %xmm14; vmovaps -0x10(%rsi), %xmm13; vmovaps (%rsi), %xmm12; vmovaps 0x10(%rsi), %xmm11; vmovaps 0x20(%rsi), %xmm10; vmovaps 0x30(%rsi), %xmm9 ; vmovaps 0x40(%rsi), %xmm8 ; vmovaps 0x50(%rsi), %xmm7 ; vmovaps 0x60(%rsi), %xmm6

mov %rbx,(%rdi)         /* rdi is jmp_buf, move registers onto it */

call *%rax

mov (%rax, %rdx), %dh

addq %rdi, %rsp

add $0xc0, %rsp

lock ; cmpxchg

call *32+output(%rip)
