.section .init
.global _init
.type _init,%function
_init:
	stp x29,x30,[sp,-16]!
	mov x29,sp
	.p2align 4

.section .fini
.global _fini
.type _fini,%function
_fini:
	stp x29,x30,[sp,-16]!
	mov x29,sp
	.p2align 4
