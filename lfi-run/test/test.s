.globl _start
_start:
	mov x8, 5
	svc #0
	mov x8, 42
	svc #0
