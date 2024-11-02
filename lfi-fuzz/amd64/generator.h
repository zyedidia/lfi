#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct Options {
    bool _x;
};

size_t codegen(uint8_t** o_buf, size_t ninsn, struct Options opts);

void dumpasm(uint8_t* buf, size_t size, size_t n);
