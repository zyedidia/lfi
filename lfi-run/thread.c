#include <assert.h>
#include <stdio.h>

#include "lfi.h"

void* kswitch_asm(void* p, struct context* old, struct context* new);

// signals must be disabled when called
static void* kswitch(void* p, struct context* old, struct context* new) {
    signal_setstack(new->sp_base, KSTACK_SIZE);
    return kswitch_asm(p, old, new);
}

struct proc* runq_front;
struct proc* runq_back;

// Push a thread onto the front of the run queue.
void runq_push_front(struct proc* n) {
    n->next = runq_front;
    n->prev = NULL;
    if (runq_front)
        runq_front->prev = n;
    else
        runq_back = n;
    runq_front = n;
}

// Push a thread onto the back of the run queue.
static void runq_push_back(struct proc* n) {
    n->next = NULL;
    n->prev = runq_back;
    if (runq_back)
        runq_back->next = n;
    else
        runq_front = n;
    runq_back = n;
}

// Remove a thread from the run queue.
static void runq_remove(struct proc* n) {
    if (n->next)
        n->next->prev = n->prev;
    else
        runq_back = n->prev;
    if (n->prev)
        n->prev->next = n->next;
    else
        runq_front = n->next;
}

struct context scheduler_ctx;
struct proc* running;

void schedule() {
    if (running) {
        runq_push_back(running);
    }

    while (runq_front != NULL) {
        struct proc* t = runq_front;
        runq_remove(t);
        if (t->state == STATE_RUNNABLE) {
            running = t;
            kswitch(t, &scheduler_ctx, &t->context);
            running = NULL;
        }

        if (t->state == STATE_RUNNABLE) {
            runq_push_back(t);
        } else {
            printf("process exited\n");
            // TODO: exit
        }
    }
}

void thread_new(threadfn_t fn, void* arg) {

}

bool thread_yield() {
    assert(running != NULL);
    if (runq_front == NULL) {
        return false;
    }
    // kswitch_asm to avoid changing signal stack
    kswitch_asm(running, &running->context, &scheduler_ctx);
    return true;
}
