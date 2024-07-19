brk #0
>>>
brk #0
------
bl foo
>>>
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
mov x18, x30
blr x25
mov x30, x18
nop
nop
1000:
bl foo
------
blr x0
>>>
add x18, x21, w0, uxtw
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
mov x18, x30
blr x25
mov x30, x18
nop
1000:
bic x18, x18, 0xf
blr x18
------
br x0
>>>
add x18, x21, w0, uxtw
.p2align 4
sub x23, x23, #0
tbz x23, #63, 1000f
mov x18, x30
blr x25
mov x30, x18
1000:
br x18
------
.bundle_align
>>>
.p2align 4
------
.type foo, %function
>>>
.type foo, %function
.p2align 4
