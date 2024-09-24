mrs x1, tpidr_el0
>>>
str x0, [sp, #-16]!
mov w22, w30
ldr x30, [x21, #8]
blr x30
mov x1, x0
ldr x0, [sp], 16
add x30, x21, w22, uxtw
------
mrs x0, tpidr_el0
>>>
mov w22, w30
ldr x30, [x21, #8]
blr x30
add x30, x21, w22, uxtw
------
msr tpidr_el0, x1
>>>
str x0, [sp, #-16]!
mov w22, w30
mov x0, x1
ldr x30, [x21, #16]
blr x30
ldr x0, [sp], 16
add x30, x21, w22, uxtw
