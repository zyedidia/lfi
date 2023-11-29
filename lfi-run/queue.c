#include <assert.h>

#include "queue.h"

void queue_push_front(struct queue* q, struct proc* p) {
    p->next = q->front;
    p->prev = NULL;
    if (q->front) {
        q->front->prev = p;
    } else {
        q->back = p;
    }
    q->front = p;
    q->size++;
}

void queue_remove(struct queue* q, struct proc* p) {
    if (p->next) {
        p->next->prev = p->prev;
    } else {
        q->back = p->prev;
    }
    if (p->prev) {
        p->prev->next = p->next;
    } else {
        q->front = p->next;
    }
    q->size--;
}

struct proc* queue_pop_back(struct queue* q) {
    if (!q->back)
        return NULL;
    struct proc* b = q->back;
    queue_remove(q, b);
    return b;
}

void queue_wake(struct queue* q, struct proc* p) {
    assert(p->state == STATE_BLOCKED);
    queue_remove(q, p);
    p->state = STATE_RUNNABLE;
    queue_push_front(&manager.runq, p);
}

void queue_wake_all(struct queue* q) {
    while (q->front) {
        queue_wake(q, q->front);
    }
}
