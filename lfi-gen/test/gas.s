bl foo
nop

foo:
	ret

blr x0

bar:
nop
nop
nop
nop
cmp x, y
b.cc foo, hi

tbnz x0, 1, foo
