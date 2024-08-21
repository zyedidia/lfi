#include "stubasm.h"

#if defined(__x86_64__) || defined(_M_X64)
.p2align 5
.globl ret
ret:
	mov %rax, %rdi
	mov $SYS_SBX_ret, %rax
	syscall
#elif defined(__aarch64__) || defined(_M_ARM64)
.p2align 4
.globl ret
ret:
	mov x8, #SYS_SBX_ret
	svc #0
#endif


.section .note.GNU-stack,"",@progbits
