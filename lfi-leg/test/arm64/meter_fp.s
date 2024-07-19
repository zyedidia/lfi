bl foo
>>>
.p2align 4
sub x23, x23, #0
fmov d31, x23
fneg d31, d31
bl foo
------
blr x0
>>>
add x18, x21, w0, uxtw
bic x24, x18, 0xf
.p2align 4
sub x23, x23, #0
fmov d31, x23
fneg d31, d31
blr x24
------
br x0
>>>
add x18, x21, w0, uxtw
bic x24, x18, 0xf
.p2align 4
sub x23, x23, #0
fmov d31, x23
fneg d31, d31
br x24
