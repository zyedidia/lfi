module main;

import core.lib;

import sys;
import proc;
import schedule;

struct Flags {
    enum {
        NOVERIFY = "no-verify",
    }

    bool noverify;
}

__gshared Flags flags;

void show_maps() {
    void* maps = fopen("/proc/self/maps".ptr, "r".ptr);
    assert(maps);
    ubyte[PAGESIZE] buf;
    while (fread(buf.ptr, 1, buf.length, maps) > 0) {
        write(fileno(stdout), buf.ptr, buf.length);
    }
    fclose(maps);
}

void set_nofile_max() {
    // Raise file descriptor limit to the max.
    RLimit rlim;
    ensure(getrlimit(RLIMIT_NOFILE, &rlim) == 0);
    rlim.rlim_cur = rlim.rlim_max;
    ensure(setrlimit(RLIMIT_NOFILE, &rlim) == 0);
}

void usage() {
    fprintf(stderr, "usage: lfi-run [OPTIONS] FILE [ARGS]\n\n");
    fprintf(stderr, "\t--no-verify\tdo not perform verification\n");
}

extern (C) int main(int argc, const(char)** argv, const(char)** envp) {
    set_nofile_max();

    // Linux maps the stack at 262140 GiB, so we are ending the proc space at
    // 262100 to be safe (we could increase this to get a few more sandboxes).
    // TODO: increase this back to 262100.
    manager.setup(gb(8), gb(128));

    if (argc <= 1) {
        usage();
        return 0;
    }

    int i = 1;
    for (i = 1; i < argc; i++) {
        const(char)* arg = argv[i];
        if (arg[0] != '-') {
            break;
        }
        arg++;
        if (arg[0] == '-') arg++;
        if (strncmp(arg, Flags.NOVERIFY.ptr, Flags.NOVERIFY.length) == 0) {
            fprintf(stderr, "WARNING: verification disabled\n");
            flags.noverify = true;
        }
    }

    const(char)* file = argv[i];
    Proc* proc = Proc.make_from_file(file, argc - i, &argv[i], envp);
    if (!proc) {
        fprintf(stderr, "error: could not load %s\n", argv[i]);
        return 1;
    }

    scheduler(proc);

    return 0;
}
