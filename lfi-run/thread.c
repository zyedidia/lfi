#include <assert.h>
#include <stdio.h>

#include "lfi.h"

void* kswitch_asm(void* p, struct context* old, struct context* new);

// signals must be disabled when called
static void* kswitch(void* p, struct context* old, struct context* new) {
    signal_setstack(new->sp_base, KSTACK_SIZE);
    return kswitch_asm(p, old, new);
}

// Push a thread onto the front of the run queue.
void runq_push_front(struct manager* m, struct proc* n) {
    n->next = m->runq_front;
    n->prev = NULL;
    if (m->runq_front)
        m->runq_front->prev = n;
    else
        m->runq_back = n;
    m->runq_front = n;
}

// Push a thread onto the back of the run queue.
static void runq_push_back(struct manager* m, struct proc* n) {
    n->next = NULL;
    n->prev = m->runq_back;
    if (m->runq_back)
        m->runq_back->next = n;
    else
        m->runq_front = n;
    m->runq_back = n;
}

// Remove a thread from the run queue.
static void runq_remove(struct manager* m, struct proc* n) {
    if (n->next)
        n->next->prev = n->prev;
    else
        m->runq_back = n->prev;
    if (n->prev)
        n->prev->next = n->next;
    else
        m->runq_front = n->next;
}

struct context scheduler_ctx;

void schedule(struct manager* m) {
    while (m->runq_front != NULL) {
        struct proc* t = m->runq_front;
        runq_remove(m, t);
        if (t->state == STATE_RUNNABLE) {
            m->running = t;
            kswitch(t, &scheduler_ctx, &t->context);
            m->running = NULL;
        }

        if (t->state == STATE_RUNNABLE) {
            runq_push_back(m, t);
        } else {
            runq_remove(m, t);
            printf("%d: process exited\n", proc_getpid(t));
            // TODO: exit
        }
    }
}

bool thread_yield(struct manager* m) {
    assert(m->running != NULL);
    if (m->runq_front == NULL) {
        return false;
    }
    // kswitch_asm to avoid changing signal stack
    kswitch_asm(m->running, &m->running->context, &scheduler_ctx);
    return true;
}
