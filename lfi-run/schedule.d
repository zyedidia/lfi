module schedule;

import core.lib;
import core.alloc;

import buddy;
import regs;
import sys;
import proc;
import queue;

struct ProcManager {
    void* allocator;

    uintptr va_base;
    usize va_size;

    enum PROC_ALIGN = gb(4);

    void setup(uintptr va_base, uintptr va_end) {
        va_size = va_end - va_base;

        ubyte* meta = kalloc(buddy_sizeof_alignment(va_size, PROC_ALIGN)).ptr;
        ensure(meta != null);
        allocator = buddy_init_alignment(meta, cast(void*) va_base, va_size, PROC_ALIGN);
        ensure(allocator != null);

        this.va_base = va_base;
        this.va_size = va_size;
    }

    bool in_user(uintptr addr) {
        return addr >= va_base && addr < va_base + va_size;
    }

    uintptr make() {
        return cast(uintptr) buddy_malloc(allocator, PROC_SIZE);
    }

    void free(uintptr base) {
        ensure(buddy_safe_free(allocator, cast(void*) base, PROC_SIZE));
    }

    bool full() {
        return buddy_is_full(allocator);
    }

    usize maxproc() {
        return va_size / PROC_SIZE;
    }
}

// Returns the next process available to run, or blocks waiting for a process
// to become available.
Proc* runnable_proc() {
    while (true) {
        Proc* p = runq.pop_back();
        if (p) {
            return p;
        }
        // TODO: handle empty runq by waiting
        assert(0, "runq is empty");
    }
}

extern (C) void kswitch(Proc* p, Context* old, Context* new_);
// old is unused by kswitch_nosave
extern (C) void kswitch_nosave(Proc* p, Context* old, Context* new_);

__gshared {
    Queue runq;
    Queue exitq;
    Queue waitq;
    Context schedctx;
    Proc* mainp;
    ProcManager manager;
}

void scheduler(Proc* m) {

    runq.push_front(m);
    mainp = m;

    while (true) {
        Proc* p = runnable_proc();

        kswitch(p, &schedctx, &p.context);

        if (mainp.state == Proc.State.EXITED) {
            kfree(mainp);
            exit(0);
        }

        if (p.state == Proc.State.RUNNABLE) {
            runq.push_front(p);
        }
    }
}
