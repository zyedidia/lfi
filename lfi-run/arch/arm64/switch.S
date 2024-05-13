// kswitch(void* p, context* old, context* new)
.globl kswitch
kswitch:
	mov x9, sp
	stp lr, x9,   [x1, #0+16*0]
	stp x19, x20, [x1, #0+16*1]
	stp x21, x22, [x1, #0+16*2]
	stp x23, x24, [x1, #0+16*3]
	stp x25, x26, [x1, #0+16*4]
	stp x27, x28, [x1, #0+16*5]
	str x29,      [x1, #0+16*6]
	stp d8, d9,   [x1, #8+16*6]
	stp d10, d11, [x1, #8+16*7]
	stp d12, d13, [x1, #8+16*8]
	stp d14, d15, [x1, #8+16*9]

.globl kstart
kstart:
	ldp lr, x9,   [x2, #0+16*0]
	ldp x19, x20, [x2, #0+16*1]
	ldp x21, x22, [x2, #0+16*2]
	ldp x23, x24, [x2, #0+16*3]
	ldp x25, x26, [x2, #0+16*4]
	ldp x27, x28, [x2, #0+16*5]
	ldr x29,      [x2, #0+16*6]
	ldp d8, d9,   [x2, #8+16*6]
	ldp d10, d11, [x2, #8+16*7]
	ldp d12, d13, [x2, #8+16*8]
	ldp d14, d15, [x2, #8+16*9]
	mov sp, x9

	ret
