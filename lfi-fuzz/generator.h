#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

struct Options {
    bool _x;
};

size_t codegen(uint32_t* insnbuf, size_t nbuf, struct Options opts);
