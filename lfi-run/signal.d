module signal;

import core.lib;

import sys;
import proc;
import lfi;

extern (C) void sighandler(int sig, void* si, void* context) {
    ucontext_t* ctx = cast(ucontext_t*) context;

    // if (!manager.in_user(ctx.uc_mcontext.pc)) {
    //     // interrupted while in the runtime
    //     // TODO: timer interrupts received while in the runtime are ignored
    //     // but they should probably be deferred instead.
    //     if (sig == SIGALRM)
    //         return;
    //     sigkernel(sig, si, ctx);
    //     return;
    // }

    version (arm64) {
        ulong base = ctx.uc_mcontext.regs[21];
    } else version (amd64) {
        ulong base;
        asm {
            "rdgsbase %0" : "=r"(base);
        }
    }
    printf("Received signal %lx\n", base);
    Proc* p = cast(Proc*) lfi_sys_ctx(base);

    ulong saved = lfi_signal_start(base);

    siguser(p, sig, si, ctx);

    lfi_signal_end(saved);
}

void sigkernel(int sig, void* si, ucontext_t* ctx) {
    switch (sig) {
    case SIGINT:
        // TODO:
        // sigdeliver(mainp, sig);
        break;
    default:
        // TODO: attempt to recover by killing the current process
        fprintf(stderr, "fatal: kernel received signal %d (pc=%lx)\n", sig, ctx.uc_mcontext.pc);
        exit(1);
    }
}

void siguser(Proc* p, int sig, void* si, ucontext_t* ctx) {
    switch (sig) {
    case SIGSEGV:
    case SIGBUS:
    case SIGILL:
        fprintf(stderr, "%d: killed %d (pc=%lx)\n", procpid(p), sig, ctx.uc_mcontext.pc);
        sysexit(p, 1);
        break;
    case SIGALRM:
        procyield(p);
        break;
    case SIGINT:
        sigdeliver(p, sig);
        break;
    default:
        assert(0, "unknown signal");
    }
}

alias SigHandler = extern (C) void function(int, void*, void*);

__gshared {
    sigset_t signal_set;
}

void sigstack(void* stack, usize size) {
    stack_t ss;
    ss.ss_sp = stack;
    ss.ss_size = size;
    ss.ss_flags = 0;

    if (sigaltstack(&ss, null) != 0)
        perror("sigaltstack");
}

void sigenable(int sig, SigHandler handler) {
    SigAction act;

    act.sa_sigaction = handler;
    act.sa_mask = signal_set;
    act.sa_flags = SA_SIGINFO | SA_ONSTACK | SA_NODEFER;

    if (sigaction(sig, &act, null) != 0)
        perror("sigaction");
}

void sigsetup() {
    sigenable(SIGILL, &sighandler);
    sigenable(SIGSEGV, &sighandler);
    sigenable(SIGINT, &sighandler);
    sigenable(SIGBUS, &sighandler);
    sigenable(SIGALRM, &sighandler);
}

void sigdeliver(Proc* p, int sig) {
    fprintf(stderr, "%d: received signal %d\n", procpid(p), sig);
    sysexit(p, 1);
}
