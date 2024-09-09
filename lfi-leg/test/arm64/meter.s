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
sub x23, x23, #0
tbz x23, #63, 1000f
blr x25
1000:
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
sub x23, x23, #0
tbz x23, #63, 1000f
blr x25
1000:
blr x24
.bundle_unlock
------
br x0
>>>
.bundle_align_mode 4
add x18, x21, w0, uxtw
bic x24, x18, 0xf
.bundle_lock
sub x23, x23, #0
tbz x23, #63, 1000f
blr x25
1000:
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
sub x23, x23, #0
tbz x23, #63, 1000f
blr x25
1000:
ret x24
.bundle_unlock
------
b foo
foo:
>>>
.bundle_align_mode 4
.bundle_lock
sub x23, x23, #0
1000:
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
sub x23, x23, #0
1000:
cbnz x0, foo
.bundle_unlock
foo:
