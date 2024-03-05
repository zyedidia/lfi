bl foo
nop

foo:
	ret

blr x0

tbnz x0, 1, foo
