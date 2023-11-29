#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lfi.h"
#include "queue.h"
#include "pipe.h"

static struct pipe pipes[NPIPE];

static int pipe_read(void* p, void* pipe, uint8_t* buf, int n);
static int pipe_write(void* p, void* pipe, uint8_t* buf, int n);

bool pipe_new(struct file* f0, struct file* f1) {
    struct pipe* pipe = NULL;
    for (size_t i = 0; i < NPIPE; i++) {
        if (!pipes[i].allocated) {
            pipe = &pipes[i];
        }
    }
    if (!pipe) {
        return false;
    }
    pipe->readopen = true;
    pipe->writeopen = true;
    pipe->nwrite = 0;
    pipe->nread = 0;

    f0->device = pipe;
    f0->read = &pipe_read;
    f0->write = NULL;
    f1->device = pipe;
    f1->read = NULL;
    f1->write = &pipe_write;

    return true;
}

void pipe_close(struct pipe* pipe, bool writable) {
    if (writable) {
        pipe->writeopen = false;
        queue_wake_all(&pipe->readq);
    } else {
        pipe->readopen = false;
        queue_wake_all(&pipe->writeq);
    }
    if (!pipe->readopen && !pipe->writeopen) {
        pipe->allocated = false;
    }
}

static int pipe_write(void* vp, void* vpipe, uint8_t* buf, int n) {
    struct proc* p = (struct proc*) vp;
    struct pipe* pipe = (struct pipe*) vpipe;

    int i = 0;
    while (i < n) {
        if (!pipe->readopen) {
            return -1;
        }
        if (pipe->nwrite == pipe->nread + PIPESZ) {
            queue_wake_all(&pipe->readq);
            proc_wait(p, &pipe->writeq, STATE_BLOCKED);
        } else {
            pipe->data[pipe->nwrite++ % PIPESZ] = buf[i];
            i++;
        }
    }
    queue_wake_all(&pipe->readq);
    return i;
}

static int pipe_read(void* vp, void* vpipe, uint8_t* buf, int n) {
    struct proc* p = (struct proc*) vp;
    struct pipe* pipe = (struct pipe*) vpipe;
    while (pipe->nread == pipe->nwrite && pipe->writeopen) {
        proc_wait(p, &pipe->readq, STATE_BLOCKED);
    }
    int i;
    for (i = 0; i < n; i++) {
        if (pipe->nread == pipe->nwrite)
            break;
        buf[i] = pipe->data[pipe->nread++ % PIPESZ];
    }
    queue_wake_all(&pipe->writeq);
    return i;
}
