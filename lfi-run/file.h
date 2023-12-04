#pragma once

#include "lfi.h"

struct filedev {
    int fd;
};

void filedev_init(struct file* file, int fd);
