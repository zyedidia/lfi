module queue;

import proc;
import schedule;

struct Queue {
    Proc* front;
    Proc* back;
    usize size;

    void push_front(Proc* p) {
        p.next = front;
        p.prev = null;
        if (front != null) {
            front.prev = p;
        } else {
            back = p;
        }
        front = p;
        size++;
    }

    void remove(Proc* p) {
        if (p.next != null) {
            p.next.prev = p.prev;
        } else {
            back = p.prev;
        }
        if (p.prev != null) {
            p.prev.next = p.next;
        } else {
            front = p.next;
        }
        size--;
    }

    Proc* pop_back() {
        if (back == null) {
            return null;
        }
        Proc* b = back;
        remove(b);
        return b;
    }

    void wake_all() {
        while (front) {
            // removes front from the queue
            wake(front);
        }
    }

    void wake(Proc* p) {
        assert(p.state == Proc.State.BLOCKED);
        remove(p);
        p.state = Proc.State.RUNNABLE;
        runq.push_front(p);
    }

    int opApply(scope int delegate(ref Proc*) dg) {
        Proc* n = front;
        while (n) {
            int r = dg(n);
            if (r) return r;
            n = n.next;
        }
        return 0;
    }
}
