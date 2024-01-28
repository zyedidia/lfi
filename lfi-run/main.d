module main;

import core.lib;

import sys;
import proc;
import schedule;

void show_maps() {
    void* maps = fopen("/proc/self/maps".ptr, "r".ptr);
    assert(maps);
    ubyte[PAGESIZE] buf;
    while (fread(buf.ptr, 1, buf.length, maps) > 0) {
        write(fileno(stdout), buf.ptr, buf.length);
    }
    fclose(maps);
}

extern (C) int main(int argc, const(char)** argv, const(char)** envp) {
    // Linux maps the stack at 262140 GiB, so we are ending the proc space at
    // 262100 to be safe (we could increase this to get a few more sandboxes).
    manager.setup(gb(8), gb(262100));

    if (argc <= 1) {
        fprintf(stderr, "no input\n");
        return 1;
    }

    const(char)* file = argv[1];
    Proc* proc = Proc.make_from_file(file, argc - 1, &argv[1], envp);
    if (!proc) {
        fprintf(stderr, "error: could not load %s\n", argv[1]);
        return 1;
    }

    scheduler(proc);

    return 0;
}
