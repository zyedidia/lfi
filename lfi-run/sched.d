module sched;

import core.lib;

import arch.regs;

import queue;
import proc;

__gshared {
    Queue runq;
    Queue exitq;
    Queue waitq;
    Context schedctx;
    Proc* initp;
}

extern (C) void kswitch(Proc* p, Context* oldc, Context* newc);
extern (C) void kstart(Proc* p, Context* oldc, Context* newc);

Proc* schedrunnable() {
    while (true) {
        Proc* p = qpopb(&runq);
        if (p)
            return p;
        // TODO: handle empty runq by waiting
        assert(0, "runq is empty");
    }
}

void schedule(Proc* init) {
    initp = init;
    qpushf(&runq, init);

    while (true) {
        Proc* p = schedrunnable();
        kswitch(p, &schedctx, &p.ctx);
        if (init.state == PState.EXITED)
            exit(0);
        if (p.state == PState.RUNNABLE)
            qpushf(&runq, p);
    }
}
