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
------
str x30, [x0, #0xf0]
>>>
add x18, x21, w0, uxtw
mov w22, w30
str x22, [x18, #0xf0]
------
mov x29, sp
>>>
mov w29, wsp
------
add x0, sp, #0x20
>>>
add w0, wsp, #0x20
