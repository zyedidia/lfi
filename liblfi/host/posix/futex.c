#include <assert.h>

#include "syscalls/syscalls.h"
#include "print.h"
#include "futex.h"
#include "proc.h"

static struct Futex*
futexfind(struct TuxProc* proc, uintptr_t addr)
{
    struct List* e;
    for (e = list_first(proc->futexes.active); e; e = list_next(proc->futexes.active, e)) {
        if (FUTEX_CONTAINER(e)->addr == addr) {
            return FUTEX_CONTAINER(e);
        }
    }
    return NULL;
}

static struct Futex*
futexnew(struct TuxProc* proc, uintptr_t addr)
{
    struct List* e;
    if (!(e = list_first(proc->futexes.free))) {
        WARN("ran out of futexes");
        return NULL;
    }
    list_remove(&proc->futexes.free, e);
    struct Futex* f = FUTEX_CONTAINER(e);
    f->waiters = 1;
    f->addr = addr;
    return f;
}

static void
futexfree(struct TuxProc* proc, struct Futex* f)
{
    list_make_first(&proc->futexes.free, &f->elem);
}

long
host_futexwait(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val, uintptr_t timeoutp)
{
    if (timeoutp) {
        assert(!"unimplemented: futexwait with timeout");
    }

    struct Futex* f;
    {
        LOCK_WITH_DEFER(&p->proc->futexes.lock, lk_futexes);
        // TODO: check that load(uaddrp) == val
        if ((f = futexfind(p->proc, (uintptr_t) uaddr))) {
            LOCK_WITH_DEFER(&f->lock, lk_f);
            f->waiters++;
        }
        if (!f) {
            if ((f = futexnew(p->proc, (uintptr_t) uaddr))) {
                list_make_first(&p->proc->futexes.active, &f->elem);
            } else {
                return -1;
            }
        }
    }

    VERBOSE(p->proc->tux, "tid=%d is waiting at address %p", p->tid, (void*) uaddr);

    /* do { */
    /*     LOCK_WITH_DEFER(&f->lock, lk_f); */
    /* } while (rc == ETIMEDOUT && ...) */

    LOCK_WITH_DEFER(&p->proc->futexes.lock, lk_futexes);
    lock(&f->lock);
    if (--f->waiters == 0) {
        list_remove(&p->proc->futexes.active, &f->elem);
        unlock(&f->lock);
        futexfree(p->proc, f);
    } else {
        unlock(&f->lock);
    }

    return -1;
}

long
host_futexwake(struct TuxThread* p, uint32_t* uaddr, int op, uint32_t val)
{
    assert(!"unimplemented: posix futexwake");
}
