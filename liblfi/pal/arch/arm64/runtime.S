#include "pal/arch/arm64/regs.h"

#define N_RTCALLS 256
#define PROC_REGS 16

// Puts Proc* in REG_BASE.
.macro GET_PROC
// On Apple Silicon we do not use thread-locals to keep track of the current
// process because the macOS TLS implementation has a terrible calling
// convention. Instead we require sysexternal on Apple, and use REG_SYS.
#ifdef __APPLE__
	ldr REG_BASE, [REG_SYS, 8*N_RTCALLS+8]
#else
	mrs	REG_BASE, tpidr_el0
	add	REG_BASE, REG_BASE, #:tprel_hi12:lfi_myctx, lsl #12
	add	REG_BASE, REG_BASE, #:tprel_lo12_nc:lfi_myctx
	ldr	REG_BASE, [REG_BASE]
#endif
.endm

// save caller-saved registers, assuming sandbox syspage is REG_BASE
.macro SAVE_PARTIAL_REGS
	GET_PROC
	stp x0, x1,   [REG_BASE, PROC_REGS+16*0]
	stp x2, x3,   [REG_BASE, PROC_REGS+16*1]
	stp x4, x5,   [REG_BASE, PROC_REGS+16*2]
	stp x6, x7,   [REG_BASE, PROC_REGS+16*3]
	stp x8, x9,   [REG_BASE, PROC_REGS+16*4]
	stp x10, x11, [REG_BASE, PROC_REGS+16*5]
	stp x12, x13, [REG_BASE, PROC_REGS+16*6]
	stp x14, x15, [REG_BASE, PROC_REGS+16*7]
	stp x16, x17, [REG_BASE, PROC_REGS+16*8]
	str x18,      [REG_BASE, PROC_REGS+16*9]
	mov x1, sp
	stp x30, x1,  [REG_BASE, PROC_REGS+16*15]
	// TODO: save SIMD registers
.endm

// lfi_ctx_entry(LFIContext* ctx, void** kstackp)
.p2align 4
.global lfi_ctx_entry
lfi_ctx_entry:
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

.p2align 4
lfi_restore_regs:
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
	ldp x0, x1, [x0, PROC_REGS+16*0]
	// NOTE: x30 must contain a valid sandbox address
	ret

// lfi_asm_ctx_exit(void* kstackp, uint64_t code)
.p2align 4
.global lfi_asm_ctx_exit
lfi_asm_ctx_exit:
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

// Accelerated return for library sandboxes.
.p2align 4
.globl lfi_ret
lfi_ret:
	GET_PROC
	// restore kernel stack
	ldr x22, [x21]
	mov sp, x22
	// restore callee-saved registers
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
	br x30

// Puts the sandbox's thread pointer in x0.
.p2align 4
.global lfi_get_tp
lfi_get_tp:
#ifdef __APPLE__
	ldr x0, [REG_SYS, 8*N_RTCALLS+8]
#else
	mrs	x0, tpidr_el0
	add	x0, x0, #:tprel_hi12:lfi_myctx, lsl #12
	add	x0, x0, #:tprel_lo12_nc:lfi_myctx
	ldr	x0, [x0]
#endif
	ldr x0, [x0, #8]
	add x30, REG_BASE, w30, uxtw
	ret

// Sets the sandbox's thread pointer to x0 and clobbers REG_TEMP.
.p2align 4
.global lfi_set_tp
lfi_set_tp:
#ifdef __APPLE__
	ldr REG_BASE, [REG_SYS, N_RTCALLS*8+8]
#else
	mrs	REG_BASE, tpidr_el0
	add	REG_BASE, REG_BASE, #:tprel_hi12:lfi_myctx, lsl #12
	add	REG_BASE, REG_BASE, #:tprel_lo12_nc:lfi_myctx
	ldr	REG_BASE, [REG_BASE]
#endif
	str x0, [REG_BASE, #8]
	// reload REG_BASE
	ldr REG_BASE, [REG_BASE, PROC_REGS+REG_BASE_OFFSET]
	add x30, REG_BASE, w30, uxtw
	ret

.p2align 4
.global lfi_syscall_entry
lfi_syscall_entry:
	SAVE_PARTIAL_REGS
	// REG_BASE now contains LFIContext*
	ldr x1, [REG_BASE] // load stack
	mov sp, x1
	str REG_BASE, [sp, #-16]!
	mov x0, REG_BASE
	bl lfi_syscall_handler
	ldr x0, [sp], 16
// Restore only caller-saved registers.
.globl lfi_restore_partial_regs
lfi_restore_partial_regs:
	ldp x2, x3,   [x0, PROC_REGS+16*1]
	ldp x4, x5,   [x0, PROC_REGS+16*2]
	ldp x6, x7,   [x0, PROC_REGS+16*3]
	ldp x8, x9,   [x0, PROC_REGS+16*4]
	ldp x10, x11, [x0, PROC_REGS+16*5]
	ldp x12, x13, [x0, PROC_REGS+16*6]
	ldp x14, x15, [x0, PROC_REGS+16*7]
	ldp x16, x17, [x0, PROC_REGS+16*8]
	ldr x18,      [x0, PROC_REGS+16*9]
	ldr REG_BASE, [x0, PROC_REGS+REG_BASE_OFFSET]
	ldp x30, x1,  [x0, PROC_REGS+16*15]
	// TODO: restore SIMD registers
	mov sp, x1
	ldp x0, x1,   [x0, PROC_REGS+16*0]
	add x30, REG_BASE, w30, uxtw
	ret
