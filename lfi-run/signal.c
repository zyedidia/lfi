#include <stdio.h>
#include <signal.h>
#include <stdint.h>
#include <stdlib.h>

#include "lfi.h"

static sigset_t signal_set;

static void signal_handler(int sig, siginfo_t* si, ucontext_t* context) {
    (void) si;
    (void) context;

    switch (sig) {
    case SIGSEGV:
    case SIGBUS:
    case SIGILL:
        printf("killed\n");
        exit(0);
    case SIGALRM:
        thread_yield(&manager);
        break;
    case SIGINT:
        // TODO: deliver sigint, for now we just die
        printf("interrupted\n");
        exit(0);
    }
}

static void sigenter(int sig, siginfo_t* si, void* context) {
    ucontext_t* ctx = (ucontext_t*) context;
    uintptr_t* ptrs = (uintptr_t*) ctx->uc_mcontext.regs[21];
    uintptr_t kernel_tpidr = ptrs[16+1];
    uintptr_t user_tpidr;
    // save user tpidr and switch to kernel tpidr
    asm volatile ("mrs %0, tpidr_el0" : "=r"(user_tpidr));
    asm volatile ("msr tpidr_el0, %0" :: "r"(kernel_tpidr));

    signal_handler(sig, si, ctx);

    // reset tpidr
    asm volatile ("msr tpidr_el0, %0" :: "r"(user_tpidr));
}

static void sig_init(int signal, void (*handler)(int, siginfo_t*, void*)) {
    struct sigaction act;

    act.sa_sigaction = handler;
    act.sa_mask = signal_set;
    act.sa_flags = SA_SIGINFO | SA_ONSTACK | SA_NODEFER;

    if (sigaction(signal, &act, NULL) != 0)
        perror("signal handler");
}

void signal_setstack(void* stack, size_t size) {
    stack_t ss;
    ss.ss_sp = stack;
    ss.ss_size = size;
    ss.ss_flags = 0;

    if (sigaltstack(&ss, NULL) != 0)
        perror("sigaltstack");
}

void signal_enable() {
    sigprocmask(SIG_UNBLOCK, &signal_set, NULL);
}

void signal_disable() {
    sigprocmask(SIG_BLOCK, &signal_set, NULL);
}

void timer_setup(long us) {
    struct itimerval it;
    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = us;
    it.it_value = it.it_interval;
    if (setitimer(ITIMER_REAL, &it, NULL))
        perror("setitimer");
}

void signal_setup() {
    sig_init(SIGALRM, sigenter);
    sig_init(SIGILL, sigenter);
    sig_init(SIGSEGV, sigenter);
    sig_init(SIGINT, sigenter);
    sig_init(SIGBUS, sigenter);

    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGALRM);
    sigaddset(&signal_set, SIGINT);

    signal_disable();
}
