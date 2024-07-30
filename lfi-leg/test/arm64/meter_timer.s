bl foo
>>>
.bundle_align_mode 3
.p2align 3
.bundle_lock
sub x23, x23, #0
bl foo
.bundle_unlock
------
blr x0
>>>
.bundle_align_mode 3
add x18, x21, w0, uxtw
bic x24, x18, 0x7
.p2align 3
.bundle_lock
sub x23, x23, #0
blr x24
.bundle_unlock
------
br x0
>>>
.bundle_align_mode 3
add x18, x21, w0, uxtw
bic x24, x18, 0x7
.bundle_lock
sub x23, x23, #0
br x24
.bundle_unlock
