bl foo
>>>
.p2align 3
sub x23, x23, #0
bl foo
------
blr x0
>>>
add x18, x21, w0, uxtw
bic x19, x18, 0x7
.p2align 3
sub x23, x23, #0
blr x19
------
br x0
>>>
add x18, x21, w0, uxtw
bic x19, x18, 0x7
.p2align 3
sub x23, x23, #0
br x19
