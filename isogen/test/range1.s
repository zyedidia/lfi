.LBB2_20:
	bl	start_time
	add	x0, sp, #24
	bl	iterate
	bl	stop_time
	bl	get_time
	ldrh	w8, [sp, #24]
	mov	w26, w0
	mov	w1, wzr
	mov	w0, w8
	bl	crc16
	ldrh	w8, [sp, #26]
	mov	w1, w0
	mov	w0, w8
	bl	crc16
	ldrh	w8, [sp, #28]
	mov	w1, w0
	mov	w0, w8
	bl	crc16
	ldr	w8, [sp, #64]
	mov	w1, w0
	mov	w0, w8
	bl	crc16
	adrp	x28, :got:default_num_contexts
	mov	w19, #65535
	and	w9, w0, #0xffff
	mov	w8, #31492
	cmp	w9, w8
	ldr	x28, [x28, :got_lo12:default_num_contexts]
	str	x25, [sp, #16]
	str	w9, [x29, #24]
	str	w26, [sp, #12]
	b.le	.LBB2_29
	mov	w8, #59893
	cmp	w9, w8
	b.eq	.LBB2_32
	mov	w8, #35330
	cmp	w9, w8
	b.eq	.LBB2_44
	mov	w8, #31493
	cmp	w9, w8
	b.ne	.LBB2_47
	mov	w25, #1
	adrp	x0, .L.str.4
	add	x0, x0, :lo12:.L.str.4
	bl	ee_printf
	ldr	w8, [x28]
	cbnz	w8, .LBB2_33
	b	.LBB2_46
