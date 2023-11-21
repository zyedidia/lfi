.globl yield_fast
yield_fast:
	mov x25, x30
	ldr x30, [x21, #8]
	blr x30
	mov x30, x25
	ret
