mov sp, x0
>>>
add x18, x21, w0, uxtw
bic sp, x18, 0xf
------
add sp, sp, x29
>>>
add x22, sp, x29
add x18, x21, w22, uxtw
bic sp, x18, 0xf
