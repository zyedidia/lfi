#include "stubasm.h"

.p2align 5
.globl dlret
dlret:
	mov %rax, %rdi
	mov $SYS_SBX_dlret, %rax
	syscall

.section .note.GNU-stack,"",@progbits
