module main;

import core.lib;

import sys;
import proc;
import schedule;

extern (C) int main(int argc, const(char)** argv, const(char)** envp) {
    if (argc <= 1) {
        fprintf(stderr, "no input\n");
        return 1;
    }

    manager.setup(gb(8), gb(512));

    const(char)* file = argv[1];
    Proc* proc = Proc.make_from_file(file, argc - 1, &argv[1], envp);
    if (!proc) {
        fprintf(stderr, "error: could not load %s\n", argv[1]);
        return 1;
    }

    scheduler(proc);

    return 0;
}
