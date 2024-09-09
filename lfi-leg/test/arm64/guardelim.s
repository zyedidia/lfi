stur x0, [x1, #1]
stur x0, [x1, #2]
stur x0, [x1, #3]
stur x0, [x1, #4]
>>>
add x18, x21, w1, uxtw
stur x0, [x18, #1]
stur x0, [x18, #2]
stur x0, [x18, #3]
stur x0, [x18, #4]
------
stur x0, [x1, #1]
stur x0, [x1, #2]
tbnz foo
stur x0, [x1, #3]
stur x0, [x1, #4]
>>>
add x18, x21, w1, uxtw
stur x0, [x18, #1]
stur x0, [x18, #2]
tbnz foo
add x18, x21, w1, uxtw
stur x0, [x18, #3]
stur x0, [x18, #4]
------
stur x0, [x1, #1]
stur x0, [x1, #2]
label:
stur x0, [x1, #3]
stur x0, [x1, #4]
>>>
add x18, x21, w1, uxtw
stur x0, [x18, #1]
stur x0, [x18, #2]
label:
add x18, x21, w1, uxtw
stur x0, [x18, #3]
stur x0, [x18, #4]
------
stur x0, [x1, #1]
stur x0, [x1, #2]
mov x1, x2
stur x0, [x1, #3]
stur x0, [x1, #4]
>>>
add x18, x21, w1, uxtw
stur x0, [x18, #1]
stur x0, [x18, #2]
mov x1, x2
add x18, x21, w1, uxtw
stur x0, [x18, #3]
stur x0, [x18, #4]
------
stp x3, x3, [x1, #16]
adrp x18, underflow
add x3, x3, #0x38
stp x2, x2, [x1, #32]
>>>
add x18, x21, w1, uxtw
stp x3, x3, [x18, #16]
adrp x18, underflow
add x3, x3, #0x38
add x18, x21, w1, uxtw
stp x2, x2, [x18, #32]
------
stur x0, [x1, #16]
ldp x0, x1, [sp]
stur x0, [x1, #16]
>>>
add x18, x21, w1, uxtw
stur x0, [x18, #16]
ldp x0, x1, [sp]
add x18, x21, w1, uxtw
stur x0, [x18, #16]
