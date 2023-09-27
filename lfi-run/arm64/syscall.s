.macro PROLOGUE
stp x0, x1,   [sp, #0+16*0]
stp x2, x3,   [sp, #0+16*1]
stp x4, x5,   [sp, #0+16*2]
stp x6, x7,   [sp, #0+16*3]
stp x8, x9,   [sp, #0+16*4]
stp x10, x11, [sp, #0+16*5]
stp x12, x13, [sp, #0+16*6]
stp x14, x15, [sp, #0+16*7]
stp x16, x17, [sp, #0+16*8]
stp x18, x29, [sp, #0+16*9]
stp x21, x22, [sp, #0+16*10]
stp x30, x24, [sp, #0+16*11]
mrs x0, nzcv
mrs x1, fpsr
stp x0, x1, [sp, #0+16*28]
.endm

.macro EPILOGUE
ldp x0, x1,   [sp, #0+16*28]
msr nzcv, x0
msr fpsr, x1
ldp x0, x1,   [sp, #0+16*0]
ldp x2, x3,   [sp, #0+16*1]
ldp x4, x5,   [sp, #0+16*2]
ldp x6, x7,   [sp, #0+16*3]
ldp x8, x9,   [sp, #0+16*4]
ldp x10, x11, [sp, #0+16*5]
ldp x12, x13, [sp, #0+16*6]
ldp x14, x15, [sp, #0+16*7]
ldp x16, x17, [sp, #0+16*8]
ldp x18, x29, [sp, #0+16*9]
ldp x21, x22, [sp, #0+16*10]
ldp x30, x24, [sp, #0+16*11]
.endm

.text
.align 4
.globl instcall_entry
.type instcall_entry,@function
instcall_entry:
    sub sp, sp, #464
    PROLOGUE
    mov x0, sp
    bl instcall_handler
    EPILOGUE
    add sp, sp, #464
    ret

.text
.align 4
.globl syscall_entry
.type syscall_entry,@function
syscall_entry:
	// TODO: optimize by only saving/restoring for hooked syscalls (mmap, brk)
	sub sp, sp, #464
	PROLOGUE
    mov x0, sp
	bl syscall_handler
    cbnz x0, handled
	EPILOGUE
	add sp, sp, #464
    svc #0
    ret
handled:
    EPILOGUE
    add sp, sp, #464
    ret
