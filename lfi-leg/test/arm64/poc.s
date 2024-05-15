adr x0, hello
>>>
adr x18, hello
mov w0, w18
------
str x30, [x0]
>>>
mov w22, w30
str x22, [x21, w0, uxtw]
------
str x30, [sp]
>>>
mov w22, w30
str x22, [sp]
------
stp x29, x30, [sp]
>>>
mov w22, w30
stp x29, x22, [sp]
