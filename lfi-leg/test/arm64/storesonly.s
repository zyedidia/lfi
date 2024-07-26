ldr x0, [x1]
>>>
ldr x0, [x1]
------
str x0, [x1]
>>>
str x0, [x21, w1, uxtw]
------
ldadd x0, x1, [x2]
>>>
add x18, x21, w2, uxtw
ldadd x0, x1, [x18]
