eor x1, x1, x3, ror #(64 - 23)
subs x1, x1, 64 - 23
>>>
eor x1, x1, x3, ror #(64 - 23)
subs x1, x1, 64 - 23
------
fmov d10, 2.5e1-1
fmov d10, 2.5e1+1
>>>
fmov d10, 2.5e1-1
fmov d10, 2.5e1+1
------
add sp, sp, #16
>>>
add x22, sp, #16
add sp, x21, w22, uxtw
------
sub sp, sp, x0
>>>
sub x22, sp, x0
add sp, x21, w22, uxtw
------
mov sp, x0
>>>
add sp, x21, w0, uxtw
