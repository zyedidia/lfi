brk #0
>>>
brk #0
------
bl foo
>>>
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
blr x25
1000:
bl foo
------
blr x0
>>>
add x18, x21, w0, uxtw
bic x24, x18, 0xf
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
blr x25
1000:
blr x24
------
br x0
>>>
add x18, x21, w0, uxtw
bic x24, x18, 0xf
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
blr x25
1000:
br x24
------
.bundle_align
>>>
.p2align 4
------
.type foo, %function
>>>
.type foo, %function
.p2align 4
