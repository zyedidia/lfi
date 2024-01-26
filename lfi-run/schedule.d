module schedule;

import core.lib;

import regs;
import proc;
import queue;

// Returns the next process available to run, or blocks waiting for a process
// to become available.
Proc* runnable_proc() {
    while (true) {
        Proc* p = runq.pop_back();
        if (p) {
            return p;
        }
        assert(0, "runq is empty");
    }
}

extern (C) void kswitch(Proc* p, Context* old, Context* new_);

__gshared {
    Queue runq;
    Queue exitq;
    Queue waitq;
    Context schedctx;
    Proc* mainp;
}

void scheduler() {
    assert(mainp, "main process does not exist");

    while (true) {
        Proc* p = runnable_proc();

        kswitch(p, &schedctx, &p.context);

        if (mainp.state == Proc.State.EXITED) {
            exit(0);
        }

        if (p.state == Proc.State.RUNNABLE) {
            runq.push_front(p);
        }
    }
}
