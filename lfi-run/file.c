#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#include "file.h"

static int file_read(void* proc, void* dev, uint8_t* buf, int n) {
    (void) proc;
    struct filedev* f = (struct filedev*) dev;
    return read(f->fd, buf, n);
}

static int file_write(void* proc, void* dev, uint8_t* buf, int n) {
    (void) proc;
    struct filedev* f = (struct filedev*) dev;
    return write(f->fd, buf, n);
}

static off_t file_lseek(void* proc, void* dev, off_t off, unsigned int whence) {
    (void) proc;
    struct filedev* f = (struct filedev*) dev;
    off_t o = lseek(f->fd, off, whence);
    return o;
}

static int file_close(void* proc, void* dev) {
    (void) proc;
    struct filedev* f = (struct filedev*) dev;
    return close(f->fd);
}

void filedev_init(struct file* file, int fd) {
    struct filedev* dev = malloc(sizeof(struct filedev));
    assert(dev);
    dev->fd = fd;
    *file = (struct file){
        .allocated = true,
        .device = (void*) dev,
        .read = file_read,
        .write = file_write,
        .lseek = file_lseek,
        .close = file_close,
        .is_file = true,
    };
}
