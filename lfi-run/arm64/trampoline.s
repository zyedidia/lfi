.text
.align 4
.globl trampoline
.type trampoline,@function
trampoline:
	mov sp, x1
	mov x1, x0
	mov x0, x2
	mov x15, #0
	mov x14, #0
	mov x24, #0
	mov x21, x3
	br  x1
