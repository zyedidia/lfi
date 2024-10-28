mrs x1, tpidr_el0
>>>
mov w22, w30
stp x0, x22, [sp, #-16]!
ldr x30, [x21, #8]
blr x30
mov x1, x0
ldp x0, x22, [sp], 16
add x30, x21, w22, uxtw
------
mrs x0, tpidr_el0
>>>
mov w22, w30
str x22, [sp, #-16]!
ldr x30, [x21, #8]
blr x30
ldr x22, [sp], 16
add x30, x21, w22, uxtw
------
msr tpidr_el0, x1
>>>
mov w22, w30
stp x0, x22, [sp, #-16]!
str x20, [sp, #-16]!
mov x0, x1
ldr x30, [x21, #16]
blr x30
ldr x20, [sp], 16
ldp x0, x22, [sp], 16
add x30, x21, w22, uxtw
