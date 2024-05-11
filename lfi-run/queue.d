module queue;

import proc;
import sched;

struct Queue {
    Proc* front;
    Proc* back;
    usize size;

    int opApply(scope int delegate(ref Proc*) dg) {
        Proc* n = this.front;
        while (n) {
            int r = dg(n);
            if (r) return r;
            n = n.next;
        }
        return 0;
    }
}

void qpushf(Queue* q, Proc* p) {
    p.next = q.front;
    p.prev = null;
    if (q.front != null) {
        q.front.prev = p;
    } else {
        q.back = p;
    }
    q.front = p;
    q.size++;
}

void qremove(Queue* q, Proc* p) {
    if (p.next != null) {
        p.next.prev = p.prev;
    } else {
        q.back = p.prev;
    }
    if (p.prev != null) {
        p.prev.next = p.next;
    } else {
        q.front = p.next;
    }
    q.size--;
}

Proc* qpopb(Queue* q) {
    if (q.back == null) {
        return null;
    }
    Proc* b = q.back;
    qremove(q, b);
    return b;
}

void qwakeall(Queue* q) {
    while (q.front) {
        qwake(q, q.front);
    }
}

void qwake(Queue* q, Proc* p) {
    assert(p.state == PState.BLOCKED);
    qremove(q, p);
    p.state = PState.RUNNABLE;
    qpushf(&runq, p);
}
