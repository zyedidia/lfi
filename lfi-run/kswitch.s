.section .text.kswitch
.globl kswitch
kswitch:
	mov x9, sp
	stp lr, x9,   [x1, #0+16*0]
	stp x19, x20, [x1, #0+16*1]
	stp x21, x22, [x1, #0+16*2]
	stp x23, x24, [x1, #0+16*3]
	stp x25, x26, [x1, #0+16*4]
	stp x27, x28, [x1, #0+16*5]

	ldp lr, x9,   [x2, #0+16*0]
	ldp x19, x20, [x2, #0+16*1]
	ldp x21, x22, [x2, #0+16*2]
	ldp x23, x24, [x2, #0+16*3]
	ldp x25, x26, [x2, #0+16*4]
	ldp x27, x28, [x2, #0+16*5]
	mov sp, x9

	ret
