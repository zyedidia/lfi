.globl jumpto
jumpto:
	pushq %r15
	pushq %r14
	pushq %r13
	pushq %r12
	pushq %rbx
	pushq %rbp

	mov %rsp, savedrsp(%rip)
	mov 8*0(%rdi), %rsp
	mov 8*1(%rdi), %rax
	mov 8*2(%rdi), %rcx
	mov 8*3(%rdi), %rdx
	mov 8*4(%rdi), %rbx
	mov 8*5(%rdi), %rbp
	mov 8*6(%rdi), %rsi
	// rdi
	mov 8*8(%rdi), %r8
	mov 8*9(%rdi), %r9
	mov 8*10(%rdi), %r10
	mov 8*11(%rdi), %r11
	mov 8*12(%rdi), %r12
	mov 8*13(%rdi), %r13
	mov 8*14(%rdi), %r14
	mov 8*15(%rdi), %r15

	movaps 8*16+16*0(%rdi), %xmm0
	movaps 8*16+16*1(%rdi), %xmm1
	movaps 8*16+16*2(%rdi), %xmm2
	movaps 8*16+16*3(%rdi), %xmm3
	movaps 8*16+16*4(%rdi), %xmm4
	movaps 8*16+16*5(%rdi), %xmm5
	movaps 8*16+16*6(%rdi), %xmm6
	movaps 8*16+16*7(%rdi), %xmm7
	movaps 8*16+16*8(%rdi), %xmm8
	movaps 8*16+16*9(%rdi), %xmm9
	movaps 8*16+16*10(%rdi), %xmm10
	movaps 8*16+16*11(%rdi), %xmm11
	movaps 8*16+16*12(%rdi), %xmm12
	movaps 8*16+16*13(%rdi), %xmm13
	movaps 8*16+16*14(%rdi), %xmm14
	movaps 8*16+16*15(%rdi), %xmm15

	mov 8*7(%rdi), %rdi

	// set all flags
	cmp %eax, %eax
	jmpq *%r11
	int3

.globl finish
finish:
	mov %rsp, regs+8*0(%rip)
	mov %rax, regs+8*1(%rip)
	mov %rcx, regs+8*2(%rip)
	mov %rdx, regs+8*3(%rip)
	mov %rbx, regs+8*4(%rip)
	mov %rbp, regs+8*5(%rip)
	mov %rsi, regs+8*6(%rip)
	mov %rdi, regs+8*7(%rip)
	mov %r8, regs+8*8(%rip)
	mov %r9, regs+8*9(%rip)
	mov %r10, regs+8*10(%rip)
	mov %r11, regs+8*11(%rip)
	mov %r12, regs+8*12(%rip)
	mov %r13, regs+8*13(%rip)
	mov %r14, regs+8*14(%rip)
	mov %r15, regs+8*15(%rip)
	
	movaps %xmm0, regs+8*16+16*0(%rip)
	movaps %xmm1, regs+8*16+16*1(%rip)
	movaps %xmm2, regs+8*16+16*2(%rip)
	movaps %xmm3, regs+8*16+16*3(%rip)
	movaps %xmm4, regs+8*16+16*4(%rip)
	movaps %xmm5, regs+8*16+16*5(%rip)
	movaps %xmm6, regs+8*16+16*6(%rip)
	movaps %xmm7, regs+8*16+16*7(%rip)
	movaps %xmm8, regs+8*16+16*8(%rip)
	movaps %xmm9, regs+8*16+16*9(%rip)
	movaps %xmm10, regs+8*16+16*10(%rip)
	movaps %xmm11, regs+8*16+16*11(%rip)
	movaps %xmm12, regs+8*16+16*12(%rip)
	movaps %xmm13, regs+8*16+16*13(%rip)
	movaps %xmm14, regs+8*16+16*14(%rip)
	movaps %xmm15, regs+8*16+16*15(%rip)

	mov savedrsp(%rip), %rsp

	popq %rbp
	popq %rbx
	popq %r12
	popq %r13
	popq %r14
	popq %r15

	ret

.data

savedrsp:
	.quad 0
