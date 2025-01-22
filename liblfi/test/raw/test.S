.p2align 5
.globl _start
_start:
#if defined(__aarch64__) || defined(_M_ARM64)
	mov x8, #42
	svc #0
	brk #0
#elif defined(__x86_64__) || defined(_M_X64)
	mov $42, %rax
	syscall
	int3
#endif
