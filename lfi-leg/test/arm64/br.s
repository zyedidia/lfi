br x0
>>>
add x18, x21, w0, uxtw
br x18
------
blr x0
>>>
add x18, x21, w0, uxtw
blr x18
------
ret
>>>
ret
------
.tlsdesccall _foo
blr x0
>>>
add x18, x21, w0, uxtw
.tlsdesccall _foo
blr x18
------
ret x15
>>>
add x18, x21, w15, uxtw
ret x18
