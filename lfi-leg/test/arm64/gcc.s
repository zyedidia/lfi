	.arch armv8-a
	.file	"test.c"
	.text
	.align	2
	.p2align 4,,11
	.global	foo
	.type	foo, %function
foo:
.LFB23:
	.cfi_startproc
	ldr	w0, [x0]
	ret
	.cfi_endproc
.LFE23:
	.size	foo, .-foo
	.align	2
	.p2align 4,,11
	.global	bar
	.type	bar, %function
bar:
.LFB24:
	.cfi_startproc
	str	w1, [x0]
	ret
	.cfi_endproc
.LFE24:
	.size	bar, .-bar
	.align	2
	.p2align 4,,11
	.global	global
	.type	global, %function
global:
.LFB25:
	.cfi_startproc
	adrp	x0, .LANCHOR0
	ldr	w0, [x0, #:lo12:.LANCHOR0]
	ret
	.cfi_endproc
.LFE25:
	.size	global, .-global
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align	3
.LC0:
	.string	"Hello world"
	.section	.text.startup,"ax",@progbits
	.align	2
	.p2align 4,,11
	.global	main
	.type	main, %function
main:
.LFB26:
	.cfi_startproc
	stp	x29, x30, [sp, -16]!
	.cfi_def_cfa_offset 16
	.cfi_offset 29, -16
	.cfi_offset 30, -8
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	mov	x29, sp
	bl	puts
	mov	w0, 0
	ldp	x29, x30, [sp], 16
	.cfi_restore 30
	.cfi_restore 29
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE26:
	.size	main, .-main
	.global	g
	.bss
	.align	2
	.set	.LANCHOR0,. + 0
	.type	g, %object
	.size	g, 4
g:
	.zero	4
	.ident	"GCC: (Ubuntu 13.2.0-4ubuntu3) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
>>>
.arch armv8-a
.file	"test.c"
.text
.align	2
.p2align 4,,11
.global	foo
.type	foo, %function
foo:
.LFB23:
.cfi_startproc
ldr w0, [x21, w0, uxtw]
ret
.cfi_endproc
.LFE23:
.size	foo, .-foo
.align	2
.p2align 4,,11
.global	bar
.type	bar, %function
bar:
.LFB24:
.cfi_startproc
str w1, [x21, w0, uxtw]
ret
.cfi_endproc
.LFE24:
.size	bar, .-bar
.align	2
.p2align 4,,11
.global	global
.type	global, %function
global:
.LFB25:
.cfi_startproc
adrp	x0, .LANCHOR0
add x22, x0, #:lo12:.LANCHOR0
ldr w0, [x21, w22, uxtw]
ret
.cfi_endproc
.LFE25:
.size	global, .-global
.section	.rodata.str1.8,"aMS",@progbits,1
.align	3
.LC0:
.string	"Hello world"
.section	.text.startup,"ax",@progbits
.align	2
.p2align 4,,11
.global	main
.type	main, %function
main:
.LFB26:
.cfi_startproc
stp	x29, x30, [sp, -16]!
.cfi_def_cfa_offset 16
.cfi_offset 29, -16
.cfi_offset 30, -8
adrp	x0, .LC0
add	x0, x0, :lo12:.LC0
mov	x29, sp
bl	puts
mov	w0, 0
ldp x29, x22, [sp], 16
add x30, x21, w22, uxtw
.cfi_restore 30
.cfi_restore 29
.cfi_def_cfa_offset 0
ret
.cfi_endproc
.LFE26:
.size	main, .-main
.global	g
.bss
.align	2
.set	.LANCHOR0,. + 0
.type	g, %object
.size	g, 4
g:
.zero	4
.ident	"GCC: (Ubuntu 13.2.0-4ubuntu3) 13.2.0"
.section	.note.GNU-stack,"",@progbits
