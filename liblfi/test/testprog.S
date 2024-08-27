.p2align 5
.globl _start
_start:
#if defined(__aarch64__) || defined(_M_ARM64)
	mov x8, #42
	ldr x30, [x21]
	blr x30
	brk #0
#elif defined(__x86_64__) || defined(_M_X64)
	mov $42, %rax
	.p2align 5
	leaq 1f(%rip), %r11
	jmpq *(%r14)
1:
	int3
#endif
