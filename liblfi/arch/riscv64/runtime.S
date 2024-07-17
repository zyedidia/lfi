#define N_RTCALLS 256

.text


// same caller-saved registers, assuming sandbox syspage is at tp

.macro SAVE_PARTIAL_REGS
	la t6, N_RTCALLS*8(tp)
    
	sd ra, 8*1(t6)
	sd sp, 8*2(t6)
	
	sd t0, 8*3(t6)
	sd t1, 8*4(t6)
	sd t2, 8*5(t6)
	sd a0, 8*8(t6)
	sd a1, 8*9(t6)
	sd a2, 8*10(t6)
	sd a3, 8*11(t6)
	sd a4, 8*12(t6)
	sd a5, 8*13(t6)
	sd a6, 8*14(t6)
	sd a7, 8*15(t6)
	sd t3, 8*16(t6)
	sd t4, 8*17(t6)
	sd t5, 8*18(t6)
	sd t6, 8*19(t6)
    // TODO: save SIMD registers?
.endm


// lfi_proc_entry(Proc* p, void** kstackp)
.p2align 4
.globl lfi_proc_entry
lfi_proc_entry:
	// Allocate space on stack for callee saved registers
	addi sp, sp, -(8*13)
	// save callee-saved registers to stack
	sd s0, 8*0(sp)
	sd s1, 8*1(sp)
	sd s2, 8*2(sp)
	sd s3, 8*3(sp)
	sd s4, 8*4(sp)
	sd s5, 8*5(sp)
	sd s6, 8*6(sp)
	sd s7, 8*7(sp)
	sd s8, 8*8(sp)
	sd s9, 8*9(sp)
	sd s10, 8*10(sp)
	sd s11, 8*11(sp)
	sd tp, 8*12(sp)
	
	
	addi sp, sp, -8
	// save stack to kstackp
	sd sp, (a1)
	jr lfi_restore_regs


// lfi_asm_proc_exit(uintptr kstackp, int code)
.p2align 4
.globl lfi_asm_proc_exit
lfi_asm_proc_exit:
	ld sp, (a0)
	ld a0, (a1)
	addi sp, sp, 8
	// load callee-saved registers from stack
	ld s0, 8*0(sp)
	ld s1, 8*1(sp)
	ld s2, 8*2(sp)
	ld s3, 8*3(sp)
	ld s4, 8*4(sp)
	ld s5, 8*5(sp)
	ld s6, 8*6(sp)
	ld s7, 8*7(sp)
	ld s8, 8*8(sp)
	ld s9, 8*9(sp)
	ld s10, 8*10(sp)
	ld s11, 8*11(sp)
	ld tp, 8*12(sp)
	addi sp, sp, 8*13
	
	ret


.p2align 4
.globl lfi_syscall_entry
lfi_syscall_entry:
	SAVE_PARTIAL_REGS
	ld tp, N_RTCALLS*8+8(x21) // load kernel tp
	
	ld a0, N_RTCALLS*8(x21) // load Proc*
	ld sp, (a0) // load stack
	call lfi_syscall_handler
	ld a0, N_RTCALLS*8(x21)
	jr lfi_restore_partial_regs


// Restore only caller-saved registers.
.p2align 4
.globl lfi_restore_partial_regs
lfi_restore_partial_regs:
	// store the base adress into the last RISC-V temporary register
	ld t6, (a0)
	// Restore all the temporary registers
	ld ra, 8*1(t6)
	ld sp, 8*2(t6)
	
	ld t0, 8*3(t6)
	ld t1, 8*4(t6)
	ld t2, 8*5(t6)
	ld a0, 8*8(t6)
	ld a1, 8*9(t6)
	ld a2, 8*10(t6)
	ld a3, 8*11(t6)
	ld a4, 8*12(t6)
	ld a5, 8*13(t6)
	ld a6, 8*14(t6)
	ld a7, 8*15(t6)
	ld t3, 8*16(t6)
	ld t4, 8*17(t6)
	ld t5, 8*18(t6)
	ld t6, 8*19(t6)
	
	ld a0, N_RTCALLS*8(x21) // fs
	
	ret


.p2align 4
.globl lfi_restore_regs
lfi_restore_regs:
	ld t6, 8*33(a0)
	ld t6, N_RTCALLS*8(x21) // fs
	ld t6, 8*34(a0)
	ld t6, N_RTCALLS*8(x21) // fs
	
	// Restore all registers
	
	ld x0, 8*1(a0)
	ld x1, 8*2(a0)
	ld x2, 8*3(a0)
	ld x3, 8*1(a0)
	ld x4, 8*5(a0)
	ld x5, 8*6(a0)
	ld x6, 8*7(a0)
	ld x7, 8*8(a0)
	ld x8, 8*9(a0)
	ld x9, 8*10(a0)
	ld x11, 8*12(a0)
	ld x12, 8*13(a0)
	ld x13, 8*14(a0)
	ld x14, 8*15(a0)
	ld x15, 8*16(a0)
	ld x16, 8*17(a0)
	ld x17, 8*18(a0)
	ld x18, 8*19(a0)
	ld x19, 8*20(a0)
	ld x20, 8*21(a0)
	ld x21, 8*22(a0)
	ld x22, 8*23(a0)
	ld x23, 8*24(a0)
	ld x24, 8*25(a0)
	ld x25, 8*26(a0)
	ld x26, 8*27(a0)
	ld x27, 8*28(a0)
	ld x28, 8*29(a0)
	ld x29, 8*30(a0)
	ld x30, 8*31(a0)
	ld x31, 8*32(a0)
	ld x10, 8*11(a0)
	ret
	

