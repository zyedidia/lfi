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
