module pipe;

import core.alloc;

import queue;
import file;
import proc;
import fd;

enum {
    NPIPE = 64,
    PIPESZ = 1024,
}

struct Pipe {
    ubyte[PIPESZ] data;

    bool writeopen;
    bool readopen;
    bool allocated;

    usize nread;
    usize nwrite;

    Queue readq;
    Queue writeq;
}

void pipeclose(Pipe* p, bool writable) {
    if (writable) {
        p.writeopen = false;
        qwakeall(&p.readq);
    } else {
        p.readopen = false;
        qwakeall(&p.writeq);
    }
    if (!p.readopen && !p.writeopen) {
        p.allocated = false;
    }
}

__gshared {
    private Pipe[NPIPE] pipes;
}

bool pipenew(ref FDFile* f0, ref FDFile* f1) {
    Pipe* pipe;
    for (usize i = 0; i < NPIPE; i++) {
        if (!pipes[i].allocated)
            pipe = &pipes[i];
    }
    if (!pipe)
        return false;
    pipe.readopen = true;
    pipe.writeopen = true;
    pipe.nwrite = 0;
    pipe.nread = 0;

    f0 = knew!(FDFile)();
    if (!f0)
        return false;
    f1 = knew!(FDFile)();
    if (!f1) {
        kfree(f0);
        return false;
    }
    f0.dev = pipe;
    f0.read = &piperead;
    f0.write = null;
    f1.dev = pipe;
    f1.read = null;
    f1.write = &pipewrite;

    return true;
}

ssize pipewrite(void* dev, Proc* p, ubyte[] buf) {
    Pipe* pipe = cast(Pipe*) dev;

    ssize i = 0;
    while (i < buf.length) {
        if (!pipe.readopen)
            return -1;
        if (pipe.nwrite == pipe.nread + PIPESZ) {
            qwakeall(&pipe.readq);
            procblock(p, &pipe.writeq, PState.BLOCKED);
        } else {
            pipe.data[pipe.nwrite++ % PIPESZ] = buf[i];
            i++;
        }
    }
    qwakeall(&pipe.readq);
    return i;
}

ssize piperead(void* dev, Proc* p, ubyte[] buf) {
    Pipe* pipe = cast(Pipe*) dev;
    while (pipe.nread == pipe.nwrite && pipe.writeopen)
        procblock(p, &pipe.readq, PState.BLOCKED);
    ssize i;
    for (i = 0; i < buf.length; i++) {
        if (pipe.nread == pipe.nwrite)
            break;
        buf[i] = pipe.data[pipe.nread++ % PIPESZ];
    }
    qwakeall(&pipe.writeq);
    return i;
}
