module pipe;

import core.alloc;

import queue;
import file;
import proc;

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

    void close(bool writable) {
        if (writable) {
            writeopen = false;
            readq.wake_all();
        } else {
            readopen = false;
            writeq.wake_all();
        }
        if (!readopen && !writeopen) {
            allocated = false;
        }
    }
}

private Pipe[NPIPE] pipes;

bool pipe_new(ref VFile* f0, ref VFile* f1) {
    Pipe* pipe;
    for (usize i = 0; i < NPIPE; i++) {
        if (!pipes[i].allocated) {
            pipe = &pipes[i];
        }
    }
    if (!pipe)
        return false;
    pipe.readopen = true;
    pipe.writeopen = true;
    pipe.nwrite = 0;
    pipe.nread = 0;

    f0 = knew!(VFile)();
    if (!f0)
        return false;
    f1 = knew!(VFile)();
    if (!f1) {
        kfree(f0);
        return false;
    }
    f0.dev = pipe;
    f0.read = &pipe_read;
    f0.write = null;
    f1.dev = pipe;
    f1.read = null;
    f1.write = &pipe_write;

    return true;
}

ssize pipe_write(void* dev, Proc* p, ubyte* buf, usize n) {
    Pipe* pipe = cast(Pipe*) dev;

    ssize i = 0;
    while (i < n) {
        if (!pipe.readopen) {
            return -1;
        }
        if (pipe.nwrite == pipe.nread + PIPESZ) {
            pipe.readq.wake_all();
            p.block(&pipe.writeq, Proc.State.BLOCKED);
        } else {
            pipe.data[pipe.nwrite++ % PIPESZ] = buf[i];
            i++;
        }
    }
    pipe.readq.wake_all();
    return i;
}

ssize pipe_read(void* dev, Proc* p, ubyte* buf, usize n) {
    Pipe* pipe = cast(Pipe*) dev;
    while (pipe.nread == pipe.nwrite && pipe.writeopen) {
        p.block(&pipe.readq, Proc.State.BLOCKED);
    }
    ssize i;
    for (i = 0; i < n; i++) {
        if (pipe.nread == pipe.nwrite)
            break;
        buf[i] = pipe.data[pipe.nread++ % PIPESZ];
    }
    pipe.writeq.wake_all();
    return i;
}
