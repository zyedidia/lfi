.globl kswitch
kswitch:
	movq %rsp, 0x0(%rsi)
	movq %r15, 8(%rsi)
	movq %r14, 16(%rsi)
	movq %r13, 24(%rsi)
	movq %r12, 32(%rsi)
	movq %rbx, 40(%rsi)
	movq %rbp, 48(%rsi)

.globl kstart
kstart:
	movq 0(%rdx), %rsp
	movq 8(%rdx), %r15
	movq 16(%rdx), %r14
	movq 24(%rdx), %r13
	movq 32(%rdx), %r12
	movq 40(%rdx), %rbx
	movq 48(%rdx), %rbp
	movq %rdi, %rax
	ret
