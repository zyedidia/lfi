#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lfi.h"
#include "queue.h"

void* kswitch_asm(void* p, struct context* old, struct context* new);

// signals must be disabled when called
static void* kswitch(void* p, struct context* old, struct context* new) {
    signal_setstack(new->sp_base, KSTACK_SIZE);
    return kswitch_asm(p, old, new);
}

static struct proc* runnable(struct manager* m) {
    signal_enable();

    while (1) {
        struct proc* p = queue_pop_back(&m->runq);
        if (p) {
            return p;
        }
        pause();
    }
}

struct context scheduler_ctx;

void schedule(struct manager* m) {
    while (1) {
        struct proc* p = runnable(m);

        signal_disable();

        m->running = p;
        kswitch(p, &scheduler_ctx, &p->context);
        m->running = NULL;

        if (p->state == STATE_RUNNABLE) {
            queue_push_front(&m->runq, p);
        } else if (m->runq.front == NULL && m->waitq.front == NULL) {
            exit(0);
        }
    }
}

void proc_yield() {
    assert(manager.running != NULL);
    // kswitch_asm to avoid changing signal stack
    kswitch_asm(NULL, &manager.running->context, &scheduler_ctx);
}

void proc_wait(struct proc* p, struct queue* q, enum procstate state) {
    p->state = state;
    p->wq = (void*) q;
    queue_push_front(q, p);
    proc_yield();
}
