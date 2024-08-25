mrs x1, tpidr_el0
>>>
stp x0, x30, [sp, #-16]!
ldr x30, [x21, #8]
blr x30
mov x1, x0
ldp x0, x22, [sp], 16
add x30, x21, w22, uxtw
------
mrs x0, tpidr_el0
>>>
mov x22, x30
ldr x30, [x21, #8]
blr x30
add x30, x21, w22, uxtw
------
msr tpidr_el0, x1
>>>
stp x0, x30, [sp, #-16]!
mov x0, x1
ldr x30, [x21, #16]
blr x30
ldp x0, x22, [sp], 16
add x30, x21, w22, uxtw
