#include <assert.h>
#include <stdatomic.h>
#include <limits.h>

#include "syscalls/syscalls.h"

static void
clearctid(struct TuxThread* p)
{
#ifdef CONFIG_THREADS
    _Atomic(int)* ctid;
    if (p->ctid) {
        ctid = (_Atomic(int)*) procaddr(p->proc, p->ctid);
        atomic_store_explicit(ctid, 0, memory_order_seq_cst);
    }
    sys_futex(p, p->ctid, TUX_FUTEX_WAKE, INT_MAX, 0, 0, 0);
#endif
}

uintptr_t
sys_exit(struct TuxThread* p, uint64_t code)
{
    clearctid(p);
    if (p->proc->tux->opts.pause_on_exit)
        lfi_ctx_pause(p->p_ctx, code);
    else
        lfi_ctx_exit(p->p_ctx, code);
    assert(!"unreachable");
}

uintptr_t
sys_exit_group(struct TuxThread* p, uint64_t code)
{
    // TODO: exit all threads
    if (p->proc->tux->opts.pause_on_exit)
        lfi_ctx_pause(p->p_ctx, code);
    else
        lfi_ctx_exit(p->p_ctx, code);
    assert(!"unreachable");
}
