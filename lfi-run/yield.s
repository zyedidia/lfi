// kswitch_asm(void* p, context* old, context* new)
.globl kswitch_asm
kswitch_asm:
	mov x9, sp
	stp lr, x9,   [x1, #0+16*0]
	stp x19, x20, [x1, #0+16*1]
	stp x21, x22, [x1, #0+16*2]
	stp x23, x24, [x1, #0+16*3]
	stp x25, x26, [x1, #0+16*4]
	stp x27, x28, [x1, #0+16*5]
	mrs x3, nzcv
	mrs x4, fpsr
	stp x3, x4,   [x1, #0+16*6]
	stp d8, d9,   [x1, #0+16*7]
	stp d10, d11, [x1, #0+16*8]
	stp d12, d13, [x1, #0+16*9]
	stp d14, d15, [x1, #0+16*10]

	ldp lr, x9,   [x2, #0+16*0]
	ldp x19, x20, [x2, #0+16*1]
	ldp x21, x22, [x2, #0+16*2]
	ldp x23, x24, [x2, #0+16*3]
	ldp x25, x26, [x2, #0+16*4]
	ldp x27, x28, [x2, #0+16*5]
	ldp x3, x4,   [x2, #0+16*6]
	msr nzcv, x3
	msr fpsr, x4
	ldp d8, d9,   [x2, #0+16*7]
	ldp d10, d11, [x2, #0+16*8]
	ldp d12, d13, [x2, #0+16*9]
	ldp d14, d15, [x2, #0+16*10]
	mov sp, x9

	ret
