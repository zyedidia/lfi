#pragma once

#include "lfi.h"
#include "queue.h"

enum {
    NPIPE = 64,
    PIPESZ = 1024,
};

struct pipe {
    uint8_t data[PIPESZ];

    bool writeopen;
    bool readopen;
    bool allocated;

    size_t nread;
    size_t nwrite;

    struct queue readq;
    struct queue writeq;
};

bool pipe_new(struct file* f0, struct file* f1);
void pipe_close(struct pipe* pipe, bool writable);
