module main;

import core.lib;
import core.math;

import proc;
import sched;
import lfi;
import sys;
import signal;

enum Arg {
    NOVERIFY = "no-verify",
    SHOWMAX  = "show-max-procs",
    POC      = "poc",
    P2SIZE   = "p2size",
    GAS      = "gas",
}

struct Flags {
    bool noverify;
    bool showmax;
    bool poc;
    int p2size;
    ulong gas;
}

__gshared {
    Flags flags;
}

void dofilemax() {
    // Raise file descriptor limit to the max.
    RLimit rlim;
    ensure(getrlimit(RLIMIT_NOFILE, &rlim) == 0);
    rlim.rlim_cur = rlim.rlim_max;
    ensure(setrlimit(RLIMIT_NOFILE, &rlim) == 0);
}

void usage(const(char)* name) {
    fprintf(stderr, "usage:\n");
    fprintf(stderr, "  %s [OPTIONS] FILE [ARGS]\n\n", name);
    fprintf(stderr, "options:\n");
    fprintf(stderr, "  --no-verify         do not perform verification\n");
    fprintf(stderr, "  --show-max-procs    show the maximum number of lfi processes\n");
    fprintf(stderr, "  --poc               enable position-oblivious code\n");
    fprintf(stderr, "  --p2size N          give sandboxes 2^n space\n");
    fprintf(stderr, "  --gas N             use N gas\n");
}

extern (C) bool lfiv_verify(void*, usize);

extern (C) int main(int argc, const(char)** argv) {
    dofilemax();

    int i;
    for (i = 1; i < argc; i++) {
        const(char)* arg = argv[i];
        if (arg[0] != '-')
            break;
        arg++;
        if (arg[0] == '-')
            arg++;
        if (strcmp(arg, Arg.NOVERIFY.ptr) == 0) {
            fprintf(stderr, "WARNING: verification disabled\n");
            flags.noverify = true;
        } else if (strcmp(arg, Arg.SHOWMAX.ptr) == 0) {
            flags.showmax = true;
        } else if (strcmp(arg, Arg.POC.ptr) == 0) {
            flags.poc = true;
        } else if (strcmp(arg, Arg.P2SIZE.ptr) == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "--p2size needs argument");
                continue;
            }
            i++;
            flags.p2size = atoi(argv[i]);
        } else if (strcmp(arg, Arg.GAS.ptr) == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "--gas needs argument");
                continue;
            }
            i++;
            flags.gas = atoll(argv[i]);
        } else {
            fprintf(stderr, "unknown flag: %s\n", argv[i]);
        }
    }

    if (i >= argc && !flags.showmax) {
        fprintf(stderr, "error: no program given\n");
        usage(argv[0]);
        return 0;
    }

    LFIOptions options;
    options.noverify = flags.noverify;
    options.pagesize = PAGESIZE;
    options.stacksize = mb(2);
    options.syshandler = &syscall;
    options.p2size = flags.p2size;
    options.gas = flags.gas;
    options.verifier = &lfiv_verify;

    lfiengine = lfi_new(options);
    if (!lfiengine) {
        fprintf(stderr, "error: failed to initialize LFI\n");
        return 1;
    }

    int err;
    if ((err = lfi_auto_add_vaspaces(lfiengine, 0)) < 0) {
        fprintf(stderr, "error: failed to add vaspaces: %d\n", err);
        return 1;
    }

    if (flags.showmax) {
        fprintf(stderr, "max procs: %ld\n", lfi_max_procs(lfiengine));
        return 0;
    }

    // sigsetup();

    const(char)* file = argv[i];
    Proc* p = procnewfile(file, argc - i, &argv[i]);
    if (!p) {
        fprintf(stderr, "error: could not load %s\n", argv[i]);
        return 1;
    }

    schedule(p);

    return 0;
}
