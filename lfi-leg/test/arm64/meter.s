brk #0
>>>
.bundle_align_mode 4
brk #0
------
bl foo
>>>
.bundle_align_mode 4
.p2align 4
.bundle_lock
1000:
sub x23, x23, #0
tbz x23, #63, 1000b+12
blr x25
bl foo
.bundle_unlock
------
blr x0
>>>
.bundle_align_mode 4
add x18, x21, w0, uxtw
bic x24, x18, 0xf
.p2align 4
.bundle_lock
1000:
sub x23, x23, #0
tbz x23, #63, 1000b+12
blr x25
blr x24
.bundle_unlock
------
br x0
>>>
.bundle_align_mode 4
add x18, x21, w0, uxtw
bic x24, x18, 0xf
.bundle_lock
1000:
sub x23, x23, #0
tbz x23, #63, 1000b+12
blr x25
br x24
.bundle_unlock
------
.bundle_align
>>>
.bundle_align_mode 4
.p2align 4
------
ret
>>>
.bundle_align_mode 4
bic x24, x30, 0xf
.bundle_lock
1000:
sub x23, x23, #0
tbz x23, #63, 1000b+12
blr x25
ret x24
.bundle_unlock
------
b foo
foo:
>>>
.bundle_align_mode 4
.bundle_lock
1000:
sub x23, x23, #0
b foo
.bundle_unlock
foo:
>>>
------
cbnz x0, foo
foo:
>>>
.bundle_align_mode 4
.bundle_lock
1000:
sub x23, x23, #0
cbnz x0, foo
.bundle_unlock
foo:
