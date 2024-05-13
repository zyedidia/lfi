module main;

import core.lib;

import proc;
import sched;
import lfi;
import sys;

enum Arg {
    NOVERIFY = "no-verify",
}

struct Flags {
    bool noverify;
}

__gshared Flags flags;

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
    fprintf(stderr, "  --no-verify\tdo not perform verification\n");
}

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
        if (strncmp(arg, Arg.NOVERIFY.ptr, Arg.NOVERIFY.length) == 0) {
            fprintf(stderr, "WARNING: verification disabled\n");
            flags.noverify = true;
        } else {
            fprintf(stderr, "unknown flag: %s\n", argv[i]);
        }
    }

    if (i >= argc) {
        fprintf(stderr, "error: no program given\n");
        usage(argv[0]);
        return 0;
    }

    LFIOptions options;
    options.noverify = flags.noverify;
    options.pagesize = PAGESIZE;
    options.stacksize = 2 * 1024 * 1024;
    options.syshandler = &syscall;

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

    // fprintf(stderr, "max procs: %ld\n", lfi_max_procs(lfiengine));

    const(char)* file = argv[i];
    Proc* p = procnewfile(file, argc - i, &argv[i]);
    if (!p) {
        fprintf(stderr, "error: could not load %s\n", argv[i]);
        return 1;
    }

    schedule(p);

    return 0;
}
