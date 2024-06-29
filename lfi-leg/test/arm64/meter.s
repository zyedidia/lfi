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
