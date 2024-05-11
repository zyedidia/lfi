module sched;

import core.lib;

import queue;
import proc;

struct Context {
    ulong x30;
    ulong sp;
    ulong x19;
    ulong x20;
    ulong x21;
    ulong x22;
    ulong x23;
    ulong x24;
    ulong x25;
    ulong x26;
    ulong x27;
    ulong x28;
    ulong x29;
    ulong d8;
    ulong d9;
    ulong d10;
    ulong d11;
    ulong d12;
    ulong d13;
    ulong d14;
    ulong d15;
    void* spbase;
}

Context taskctx(void* sp, void* entry, void* spbase) {
    Context ctx;
    ctx.sp = cast(uintptr) sp;
    ctx.x30 = cast(uintptr) entry;
    ctx.spbase = spbase;
    return ctx;
}

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
