#include <assert.h>
#include <stdint.h>

#include "lfi.h"
#include "sys.h"
#include "syscalls/strace.h"
#include "syscalls/syscalls.h"

#include "arch_sys.h"

void
arch_syshandle(struct LFIContext* ctx)
{
    struct TuxThread* p = (struct TuxThread*) lfi_ctx_data(ctx);
    struct TuxRegs* regs = lfi_ctx_regs(ctx);

    switch (regs->x8) {
    default:
        // Generic syscalls.
        regs->x0 = syshandle(p, regs->x8, regs->x0, regs->x1, regs->x2,
                regs->x3, regs->x4, regs->x5);
    }
}
