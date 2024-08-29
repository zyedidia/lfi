svc #0
>>>
mov x22, x30
ldr x30, [x21]
blr x30
add x30, x21, w22, uxtw
------
ldr x21, [x0]
>>>
------
ldp x20, x21, [x0]
>>>
add x18, x21, w0, uxtw
ldp x20, xzr, [x18]
