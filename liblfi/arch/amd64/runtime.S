#define N_RTCALLS 256

.text

// save caller-saved registers, assuming sandbox syspage is at %gs
.macro SAVE_PARTIAL_REGS
	mov %gs:(N_RTCALLS*8), %rcx
	mov %rsp, 8*1(%rcx)
	mov %rax, 8*2(%rcx)
	// rcx clobbered
	mov %rdx, 8*4(%rcx)
	mov %rbx, 8*5(%rcx)
	mov %rbp, 8*6(%rcx)
	mov %rsi, 8*7(%rcx)
	mov %rdi, 8*8(%rcx)
	mov %r8,  8*9(%rcx)
	mov %r9,  8*10(%rcx)
	mov %r10, 8*11(%rcx)
    rdfsbase %r11
    mov %r11, 8*17(%rcx) // fs
    // TODO: save SIMD registers?
.endm

// lfi_proc_entry(Proc* p, void** kstackp)
.p2align 4
.globl lfi_proc_entry
lfi_proc_entry:
	// save callee-saved registers to stack
	pushq %r15
	pushq %r14
	pushq %r13
	pushq %r12
	pushq %rbx
	pushq %rbp
	sub $8, %rsp
	// save stack to kstackp
	mov %rsp, (%rsi)
	jmp lfi_restore_regs
	int3

// lfi_asm_proc_exit(uintptr kstackp, int code)
.p2align 4
.globl lfi_asm_proc_exit
lfi_asm_proc_exit:
	mov %rdi, %rsp
	mov %rsi, %rax
	add $8, %rsp
	popq %rbp
	popq %rbx
	popq %r12
	popq %r13
	popq %r14
	popq %r15
	ret

.p2align 4
.globl lfi_syscall_entry
lfi_syscall_entry:
	SAVE_PARTIAL_REGS
	mov %gs:(N_RTCALLS*8+8), %rdi // load kernel fs
	wrfsbase %rdi
	mov %gs:(N_RTCALLS*8), %rdi // load Proc*
	mov (%rdi), %rsp // load stack
	call lfi_syscall_handler
	mov %gs:(N_RTCALLS*8), %rdi
	jmp lfi_restore_partial_regs
	int3

// Restore only caller-saved registers.
.p2align 4
.globl lfi_restore_partial_regs
lfi_restore_partial_regs:
    mov 8*1(%rdi), %rsp
	mov 8*2(%rdi), %rax
	mov $0, %rcx // clobbered
	mov 8*4(%rdi), %rdx
	mov 8*5(%rdi), %rbx
	mov 8*6(%rdi), %rbp
	mov 8*7(%rdi), %rsi
	mov 8*9(%rdi), %r8
	mov 8*10(%rdi), %r9
	mov 8*11(%rdi), %r10
    mov 8*17(%rdi), %r11
    wrfsbase %r11 // fs
	mov $0, %r11 // clobbered
    mov 8*8(%rdi), %rdi
	ret

.p2align 4
.globl lfi_restore_regs
lfi_restore_regs:
    mov 8*17(%rdi), %r11
    wrfsbase %r11
    mov 8*18(%rdi), %r11
    wrgsbase %r11
    mov 8*1(%rdi), %rsp
    mov 8*2(%rdi), %rax
    mov 8*3(%rdi), %rcx
    mov 8*4(%rdi), %rdx
    mov 8*5(%rdi), %rbx
    mov 8*6(%rdi), %rbp
    mov 8*7(%rdi), %rsi
    mov 8*9(%rdi), %r8
    mov 8*10(%rdi), %r9
    mov 8*11(%rdi), %r10
    mov 8*12(%rdi), %r11
    mov 8*13(%rdi), %r12
    mov 8*14(%rdi), %r13
    mov 8*15(%rdi), %r14
    mov 8*16(%rdi), %r15
    mov 8*8(%rdi), %rdi
    ret
