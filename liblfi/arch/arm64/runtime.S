#define N_RTCALLS 256
#define PROC_REGS 16

.text

// Puts Proc* in x21.
.macro GET_PROC
// On Apple Silicon we do not use thread-locals to keep track of the current
// process because the macOS TLS implementation has a terrible calling
// convention. Instead we require sysexternal on Apple, and use x25.
#ifdef __APPLE__
	ldr x21, [x25, N_RTCALLS*8+8]
#else
	mrs	x21, tpidr_el0
	add	x21, x21, #:tprel_hi12:lfi_myproc, lsl #12
	add	x21, x21, #:tprel_lo12_nc:lfi_myproc
	ldr	x21, [x21]
#endif
.endm

// save caller-saved registers, assuming sandbox syspage is x21
.macro SAVE_PARTIAL_REGS
	GET_PROC
	stp x0, x1,   [x21, PROC_REGS+16*0]
	stp x2, x3,   [x21, PROC_REGS+16*1]
	stp x4, x5,   [x21, PROC_REGS+16*2]
	stp x6, x7,   [x21, PROC_REGS+16*3]
	stp x8, x9,   [x21, PROC_REGS+16*4]
	stp x10, x11, [x21, PROC_REGS+16*5]
	stp x12, x13, [x21, PROC_REGS+16*6]
	stp x14, x15, [x21, PROC_REGS+16*7]
	stp x16, x17, [x21, PROC_REGS+16*8]
	str x18,      [x21, PROC_REGS+16*9]
	mov x1, sp
	stp x30, x1,  [x21, PROC_REGS+16*15]
	mrs x0, nzcv
	mrs x1, fpsr
	stp x0, x1, [x21, PROC_REGS+8*34]
.endm

.macro RESTORE_INVOKE_REGS
	ldp x2, x3,   [x0, PROC_REGS+16*1]
	ldp x4, x5,   [x0, PROC_REGS+16*2]
	ldp x6, x7,   [x0, PROC_REGS+16*3]
	ldp x8, x9,   [x0, PROC_REGS+16*4]
	ldp x10, x11, [x0, PROC_REGS+16*5]
	ldp x12, x13, [x0, PROC_REGS+16*6]
	ldp x14, x15, [x0, PROC_REGS+16*7]
	ldp x16, x17, [x0, PROC_REGS+16*8]
	ldr x18,      [x0, PROC_REGS+16*9]
	ldr x21,      [x0, PROC_REGS+16*10+8]
	ldp x30, x1,  [x0, PROC_REGS+16*15]
	mov sp, x1
	ldp x0, x1,   [x0, PROC_REGS+16*0]
.endm

// Puts the sandbox's thread pointer in x0.
.p2align 4
.global lfi_get_tp
lfi_get_tp:
#ifdef __APPLE__
	ldr x0, [x25, N_RTCALLS*8+8]
#else
	mrs	x0, tpidr_el0
	add	x0, x0, #:tprel_hi12:lfi_myproc, lsl #12
	add	x0, x0, #:tprel_lo12_nc:lfi_myproc
	ldr	x0, [x0]
#endif
	ldr x0, [x0, #8]
	add x30, x21, w30, uxtw
	ret

// Sets the sandbox's thread pointer to x0.
.p2align 4
.global lfi_set_tp
lfi_set_tp:
#ifdef __APPLE__
	ldr x21, [x25, N_RTCALLS*8+8]
#else
	mrs	x21, tpidr_el0
	add	x21, x21, #:tprel_hi12:lfi_myproc, lsl #12
	add	x21, x21, #:tprel_lo12_nc:lfi_myproc
	ldr	x21, [x21]
#endif
	str x0, [x21, #8]
	// reload x21 from offset 16 from struct LFIProc
	ldr x21, [x21, PROC_REGS+8*21]
	add x30, x21, w30, uxtw
	ret

// Accelerated return for library sandboxes.
.p2align 4
.globl lfi_ret
lfi_ret:
	// TODO
	brk #0

// lfi_asm_invoke(Proc* p, void* fn, void** kstackp)
.p2align 4
.globl lfi_asm_invoke
lfi_asm_invoke:
	// save callee-saved registers to stack
	stp d8, d9,   [sp, #-16]!
	stp d10, d11, [sp, #-16]!
	stp d12, d13, [sp, #-16]!
	stp d14, d15, [sp, #-16]!
	stp x19, x20, [sp, #-16]!
	stp x21, x22, [sp, #-16]!
	stp x23, x24, [sp, #-16]!
	stp x25, x26, [sp, #-16]!
	stp x27, x28, [sp, #-16]!
	stp x29, x30, [sp, #-16]!
	// save stack to kstackp
	mov x22, x1
	mov x3, sp
	str x3, [x2]
	RESTORE_INVOKE_REGS
	br x22
	brk #0

// lfi_proc_entry(Proc* p, void** kstackp)
.p2align 4
.globl lfi_proc_entry
lfi_proc_entry:
	// save callee-saved registers to stack
	stp d8, d9,   [sp, #-16]!
	stp d10, d11, [sp, #-16]!
	stp d12, d13, [sp, #-16]!
	stp d14, d15, [sp, #-16]!
	stp x19, x20, [sp, #-16]!
	stp x21, x22, [sp, #-16]!
	stp x23, x24, [sp, #-16]!
	stp x25, x26, [sp, #-16]!
	stp x27, x28, [sp, #-16]!
	stp x29, x30, [sp, #-16]!
	// save stack to kstackp
	mov x2, sp
	str x2, [x1]
	b lfi_restore_regs
	brk #0

// lfi_asm_proc_exit(uintptr kstackp)
.p2align 4
.globl lfi_asm_proc_exit
lfi_asm_proc_exit:
	mov sp, x0
	mov x0, x1
	ldp x29, x30, [sp], 16
	ldp x27, x28, [sp], 16
	ldp x25, x26, [sp], 16
	ldp x23, x24, [sp], 16
	ldp x21, x22, [sp], 16
	ldp x19, x20, [sp], 16
	ldp d14, d15, [sp], 16
	ldp d12, d13, [sp], 16
	ldp d10, d11, [sp], 16
	ldp d8, d9,   [sp], 16
	ret

.p2align 4
.globl lfi_syscall_entry
lfi_syscall_entry:
	SAVE_PARTIAL_REGS
	// x21 now contains Proc*
	ldr x1, [x21]         // load stack
	mov sp, x1
	str x21, [sp, #-16]!
	mov x0, x21
	bl lfi_syscall_handler
	ldr x0, [sp], 16
	b  lfi_restore_partial_regs
	brk #0

.p2align 4
.globl lfi_yield_entry
lfi_yield_entry:
	brk #0

// Restore only caller-saved registers.
.p2align 4
.globl lfi_restore_partial_regs
lfi_restore_partial_regs:
	// TODO: I think we can skip saving/restoring nzcv/fpsr for syscalls
	ldp x1, x2, [x0, PROC_REGS+8*34]
	msr nzcv, x1
	msr fpsr, x2
	ldp x2, x3,   [x0, PROC_REGS+16*1]
	ldp x4, x5,   [x0, PROC_REGS+16*2]
	ldp x6, x7,   [x0, PROC_REGS+16*3]
	ldp x8, x9,   [x0, PROC_REGS+16*4]
	ldp x10, x11, [x0, PROC_REGS+16*5]
	ldp x12, x13, [x0, PROC_REGS+16*6]
	ldp x14, x15, [x0, PROC_REGS+16*7]
	ldp x16, x17, [x0, PROC_REGS+16*8]
	ldr x18,      [x0, PROC_REGS+16*9]
	ldr x21,      [x0, PROC_REGS+16*10+8]
	ldp x30, x1,  [x0, PROC_REGS+16*15]
	mov sp, x1
	ldp x0, x1,   [x0, PROC_REGS+16*0]
	add x30, x21, w30, uxtw
	ret

// lfi_restore_regs(Proc* p)
// Restores registers from the given Proc struct.
// This function does not return.
.p2align 4
.globl lfi_restore_regs
lfi_restore_regs:
	ldp x1, x2, [x0, PROC_REGS+8*34]
	msr nzcv, x1
	msr fpsr, x2
	ldp x2, x3,   [x0, PROC_REGS+16*1]
	ldp x4, x5,   [x0, PROC_REGS+16*2]
	ldp x6, x7,   [x0, PROC_REGS+16*3]
	ldp x8, x9,   [x0, PROC_REGS+16*4]
	ldp x10, x11, [x0, PROC_REGS+16*5]
	ldp x12, x13, [x0, PROC_REGS+16*6]
	ldp x14, x15, [x0, PROC_REGS+16*7]
	ldp x16, x17, [x0, PROC_REGS+16*8]
	ldp x18, x19, [x0, PROC_REGS+16*9]
	ldp x20, x21, [x0, PROC_REGS+16*10]
	ldp x22, x23, [x0, PROC_REGS+16*11]
	ldp x24, x25, [x0, PROC_REGS+16*12]
	ldp x26, x27, [x0, PROC_REGS+16*13]
	ldp x28, x29, [x0, PROC_REGS+16*14]
	ldp x30, x1,  [x0, PROC_REGS+16*15]
	// clobber caller-saved registers
	movi v0.2D, #0
	movi v1.2D, #0
	movi v2.2D, #0
	movi v3.2D, #0
	movi v4.2D, #0
	movi v5.2D, #0
	movi v6.2D, #0
	movi v7.2D, #0
	ldp q8, q9,   [x0, PROC_REGS+16*18+8*16]
	ldp q10, q11, [x0, PROC_REGS+16*18+10*16]
	ldp q12, q13, [x0, PROC_REGS+16*18+12*16]
	ldp q14, q15, [x0, PROC_REGS+16*18+14*16]
	movi v16.2D, #0
	movi v17.2D, #0
	movi v18.2D, #0
	movi v19.2D, #0
	movi v20.2D, #0
	movi v21.2D, #0
	movi v22.2D, #0
	movi v23.2D, #0
	movi v24.2D, #0
	movi v25.2D, #0
	movi v26.2D, #0
	movi v27.2D, #0
	movi v28.2D, #0
	movi v29.2D, #0
	movi v30.2D, #0
	movi v31.2D, #0
	mov sp, x1
	ldp x0, x1,   [x0, PROC_REGS+16*0]
	add x30, x21, w30, uxtw
	ret
