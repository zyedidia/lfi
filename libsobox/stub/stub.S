#include "stubasm.h"

.p2align 5
.globl ret
ret:
	mov %rax, %rdi
	mov $SYS_SBX_ret, %rax
	syscall

.section .note.GNU-stack,"",@progbits
