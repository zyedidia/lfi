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
	stp q8, q9,   [x1, #0+16*7]
	stp q10, q11, [x1, #0+16*8]
	stp q12, q13, [x1, #0+16*9]
	stp q14, q15, [x1, #0+16*10]

	ldp lr, x9,   [x2, #0+16*0]
	ldp x19, x20, [x2, #0+16*1]
	ldp x21, x22, [x2, #0+16*2]
	ldp x23, x24, [x2, #0+16*3]
	ldp x25, x26, [x2, #0+16*4]
	ldp x27, x28, [x2, #0+16*5]
	ldp x3, x4,   [x2, #0+16*6]
	msr nzcv, x3
	msr fpsr, x4
	ldp q8, q9,   [x2, #0+16*7]
	ldp q10, q11, [x2, #0+16*8]
	ldp q12, q13, [x2, #0+16*9]
	ldp q14, q15, [x2, #0+16*10]
	mov sp, x9

	ret
