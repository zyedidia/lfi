brk #0
>>>
brk #0
------
bl foo
>>>
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
brk #0
1000:
bl foo
------
blr foo
>>>
add x18, x21, w0, uxtw
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
nop
nop
brk #0
nop
1000:
bic x18, x18, 0xf
blr x18
