#include <assert.h>
#include <stdint.h>

#include "lfi.h"
#include "sys.h"
#include "syscalls/strace.h"
#include "syscalls/syscalls.h"

#include "arch_sys.h"

enum {
    TUX_ARCH_SET_FS = 0x1002,
};

static int
sys_arch_prctl(struct TuxThread* p, int code, lfiptr_t addr)
{
    switch (code) {
    case TUX_ARCH_SET_FS:
        lfi_ctx_tpset(p->p_ctx, procaddr(p->proc, addr));
        return 0;
    default:
        return -TUX_EINVAL;
    }
}

static const char*
arch_sysname(uint64_t sysno)
{
    switch (sysno) {
    STRACE_CASE(arch_prctl)
    STRACE_CASE(readlink)
    STRACE_CASE(access)
    }
    return NULL;
}

void
arch_syshandle(struct LFIContext* ctx)
{
    struct TuxThread* p = (struct TuxThread*) lfi_ctx_data(ctx);
    struct TuxProc* proc = p->proc;
    struct TuxRegs* regs = lfi_ctx_regs(ctx);

    uint64_t orig_rax = regs->rax;

    switch (regs->rax) {
    case TUX_SYS_arch_prctl:
        regs->rax = sys_arch_prctl(p, regs->rdi, regs->rsi);
        break;
    case TUX_SYS_readlink:
        regs->rax = sys_readlink(proc, regs->rdi, regs->rsi, regs->rdx);
        break;
    case TUX_SYS_access:
        regs->rax = sys_access(proc, regs->rdi, regs->rsi);
        break;
    case TUX_SYS_unlink:
        regs->rax = sys_unlink(proc, regs->rdi);
        break;
    case TUX_SYS_time:
        regs->rax = sys_time(proc, regs->rdi);
        break;
    case TUX_SYS_chown:
        regs->rax = sys_chown(proc, regs->rdi, regs->rsi, regs->rdx);
        break;
    case TUX_SYS_chmod:
        regs->rax = sys_chmod(proc, regs->rdi, regs->rsi);
        break;
    case TUX_SYS_rename:
        regs->rax = sys_rename(proc, regs->rdi, regs->rsi);
        break;
    case TUX_SYS_mkdir:
        regs->rax = sys_mkdir(proc, regs->rdi, regs->rsi);
        break;
    case TUX_SYS_open:
        regs->rax = sys_open(proc, regs->rdi, regs->rsi, regs->rdx);
        break;
    case TUX_SYS_stat:
        regs->rax = sys_stat(proc, regs->rdi, regs->rsi);
        break;
    case TUX_SYS_lstat:
        regs->rax = sys_lstat(proc, regs->rdi, regs->rsi);
        break;
    default:
        // Generic syscalls.
        regs->rax = syshandle(p, regs->rax, regs->rdi, regs->rsi, regs->rdx,
                regs->r10, regs->r8, regs->r9);
    }

    if (proc->tux->opts.strace) {
        const char* name = arch_sysname(orig_rax);
        if (!name)
            name = sysname(orig_rax);
        if (name)
            fprintf(stderr, "strace: %s = %lx\n", name, regs->rax);
        else
            fprintf(stderr, "strace: %ld = %lx\n", orig_rax, regs->rax);
    }
}
