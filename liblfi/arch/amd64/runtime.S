#define N_RTCALLS 256
#define PROC_REGS 16

.text

// save caller-saved registers, assuming sandbox syspage is at %gs
.macro SAVE_PARTIAL_REGS
	mov %fs:lfi_myproc@tpoff, %rcx
	mov %rsp, PROC_REGS+8*0(%rcx)
	mov %rax, PROC_REGS+8*1(%rcx)
	// rcx clobbered
	mov %rdx, PROC_REGS+8*3(%rcx)
	mov %rbx, PROC_REGS+8*4(%rcx)
	mov %rbp, PROC_REGS+8*5(%rcx)
	mov %rsi, PROC_REGS+8*6(%rcx)
	mov %rdi, PROC_REGS+8*7(%rcx)
	mov %r8,  PROC_REGS+8*8(%rcx)
	mov %r9,  PROC_REGS+8*9(%rcx)
	mov %r10, PROC_REGS+8*10(%rcx)
    // TODO: save SIMD registers?
.endm

.macro RESTORE_INVOKE_REGS
	mov PROC_REGS+8*18(%rdi), %r11
	wrgsbase %r11
	mov PROC_REGS+8*0(%rdi), %rsp
	mov PROC_REGS+8*1(%rdi), %rax
	mov PROC_REGS+8*2(%rdi), %rcx
	mov PROC_REGS+8*3(%rdi), %rdx
	mov PROC_REGS+8*4(%rdi), %rbx
	mov PROC_REGS+8*5(%rdi), %rbp
	mov PROC_REGS+8*6(%rdi), %rsi
	mov PROC_REGS+8*8(%rdi), %r8
	mov PROC_REGS+8*9(%rdi), %r9
	// zero out other registers?
	mov PROC_REGS+8*14(%rdi), %r14
	mov PROC_REGS+8*15(%rdi), %r15
	mov PROC_REGS+8*7(%rdi), %rdi
.endm

// Adds %rax to the sandbox's thread pointer, loads the result, and puts it in
// %rax.
.p2align 4
.global lfi_get_tp
lfi_get_tp:
	pushq %rdi
	// %rdi = myproc
	movq %fs:lfi_myproc@tpoff, %rdi
	// clamp %rax to a signed 32-bit value
	movslq %eax, %rax
	// %rax = %rax + tp
	addq 8(%rdi), %rax
	// %rax = (%rax)
	movq (%rax), %rax
	popq %rdi
	jmp *%r11
	int3

// Sets the sandbox's thread pointer to %rax and clobbers %rdx. This function
// is not used on x86-64, since libc will set the thread pointer via an
// archprctl system call rather than wrfsbase.
.p2align 4
.global lfi_set_tp
lfi_set_tp:
	mov %fs:lfi_myproc@tpoff, %rdx
	mov %rax, 8(%rdx)
	jmp *%r11
	int3

// lfi_asm_invoke(Proc* p, void* fn, void** kstackp)
.p2align 4
.globl lfi_asm_invoke
lfi_asm_invoke:
	// save callee-saved registers to stack
	pushq %r15
	pushq %r14
	pushq %r13
	pushq %r12
	pushq %rbx
	pushq %rbp

	movq %rsi, %r12
	subq $16, %rsp
	movq %rsp, (%rdx)
	RESTORE_INVOKE_REGS
	jmpq *%r12
	int3

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
	subq $16, %rsp
	// save stack to kstackp
	mov %rsp, (%rsi)
	jmp lfi_restore_regs
	int3

// lfi_asm_proc_exit(void* kstackp, int code)
.p2align 4
.globl lfi_asm_proc_exit
lfi_asm_proc_exit:
	movq %rdi, %rsp
	movq %rsi, %rax
	addq $16, %rsp
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
	// Proc* is now in %rcx
	mov (%rcx), %rsp // load stack
	// syscall return address
	pushq %r11
	mov %rcx, %rdi
	call lfi_syscall_handler
	popq %r11
	mov %fs:lfi_myproc@tpoff, %rdi
	jmp lfi_restore_partial_regs
	int3

// Restore only caller-saved registers.
.p2align 4
.globl lfi_restore_partial_regs
lfi_restore_partial_regs:
    mov  PROC_REGS+8*0(%rdi), %rsp
	mov  PROC_REGS+8*1(%rdi), %rax
	mov  $0, %rcx // clobbered
	mov  PROC_REGS+8*3(%rdi), %rdx
	mov  PROC_REGS+8*4(%rdi), %rbx
	mov  PROC_REGS+8*5(%rdi), %rbp
	mov  PROC_REGS+8*6(%rdi), %rsi
	mov  PROC_REGS+8*8(%rdi), %r8
	mov  PROC_REGS+8*9(%rdi), %r9
	mov  PROC_REGS+8*10(%rdi), %r10
    mov  PROC_REGS+8*7(%rdi), %rdi
	jmpq *%r11
	int3

.p2align 4
.globl lfi_restore_regs
lfi_restore_regs:
    mov PROC_REGS+8*18(%rdi), %r11
    wrgsbase %r11
    mov PROC_REGS+8*0(%rdi), %rsp
    mov PROC_REGS+8*1(%rdi), %rax
    mov PROC_REGS+8*2(%rdi), %rcx
    mov PROC_REGS+8*3(%rdi), %rdx
    mov PROC_REGS+8*4(%rdi), %rbx
    mov PROC_REGS+8*5(%rdi), %rbp
    mov PROC_REGS+8*6(%rdi), %rsi
    mov PROC_REGS+8*8(%rdi), %r8
    mov PROC_REGS+8*9(%rdi), %r9
    mov PROC_REGS+8*10(%rdi), %r10
    mov PROC_REGS+8*11(%rdi), %r11
    mov PROC_REGS+8*12(%rdi), %r12
    mov PROC_REGS+8*13(%rdi), %r13
    mov PROC_REGS+8*14(%rdi), %r14
    mov PROC_REGS+8*15(%rdi), %r15
    mov PROC_REGS+8*7(%rdi), %rdi
    ret
