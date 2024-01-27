module signal;

import core.lib;

import proc;
import schedule;
import sys;
import syscall;

extern (C) void signal_enter(int sig, void* si, void* context) {
    ucontext_t* ctx = cast(ucontext_t*) context;

    if (!manager.in_user(ctx.uc_mcontext.pc)) {
        // interrupted while in the runtime
        if (sig == SIGALRM)
            return;
        ksignal_handler(sig, si, ctx);
        return;
    }

    ulong base = ctx.uc_mcontext.regs[21];
    Proc* p = proc_at(base);

    uintptr saved_tpidr = SysReg.tpidr_el0;
    SysReg.tpidr_el0 = p.systable.kernel_tpidr;

    usignal_handler(p, sig, si, ctx);

    SysReg.tpidr_el0 = saved_tpidr;
}

void ksignal_handler(int sig, void* si, ucontext_t* ctx) {
    switch (sig) {
    case SIGINT:
        signal_deliver(mainp, sig);
        break;
    default:
        // TODO: attempt to recover by killing the current process
        fprintf(stderr, "fatal: kernel received signal %d (pc=%lx)\n", sig, ctx.uc_mcontext.pc);
        exit(1);
    }
}

void usignal_handler(Proc* p, int sig, void* si, ucontext_t* ctx) {
    switch (sig) {
    case SIGSEGV:
    case SIGBUS:
    case SIGILL:
        fprintf(stderr, "%d: killed %d (pc=%lx)\n", p.pid(), sig, ctx.uc_mcontext.pc);
        sys_exit(p, 1);
        break;
    case SIGALRM:
        p.yield();
        break;
    case SIGINT:
        signal_deliver(mainp, sig);
        break;
    default:
        assert(0, "unknown signal");
    }
}

void signal_deliver(Proc* p, int sig) {
    fprintf(stderr, "%d: received signal %d\n", mainp.pid, sig);
    sys_exit(mainp, 1);
}

__gshared sigset_t signal_set;

void signal_enable() {
    sigprocmask(SIG_UNBLOCK, &signal_set, null);
}

void signal_disable() {
    sigprocmask(SIG_BLOCK, &signal_set, null);
}

void signal_setstack(void* stack, usize size) {
    stack_t ss;
    ss.ss_sp = stack;
    ss.ss_size = size;
    ss.ss_flags = 0;

    if (sigaltstack(&ss, null) != 0)
        perror("sigaltstack");
}

alias SigHandler = extern (C) void function(int, void*, void*);

void signal_init(int signal, SigHandler handler) {
    SigAction act;

    act.sa_sigaction = handler;
    act.sa_mask = signal_set;
    act.sa_flags = SA_SIGINFO | SA_ONSTACK | SA_NODEFER;

    if (sigaction(signal, &act, null) != 0)
        perror("sigaction");
}

void signal_setup() {
    signal_init(SIGILL, &signal_enter);
    signal_init(SIGSEGV, &signal_enter);
    signal_init(SIGINT, &signal_enter);
    signal_init(SIGBUS, &signal_enter);
    signal_init(SIGALRM, &signal_enter);
}

enum TIME_SLICE = 10_000;

void timer_set(ulong us) {
    ITimerval it;
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = us;
    it.it_value = it.it_interval;
    if (setitimer(ITIMER_REAL, &it, null))
        perror("setitimer");
}

void timer_enable() {
    timer_set(TIME_SLICE);
}

void timer_disable() {
    timer_set(0);
}
