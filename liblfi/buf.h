#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "lfi_tux.h"

typedef struct {
    uint8_t* data;
    size_t size;
} buf_t;

static inline bool
bufwrite(buf_t* buf, uint8_t* data, size_t size)
{
    uint8_t* b = realloc(buf->data, buf->size + size);
    if (!b)
        return false;
    buf->data = b;
    memcpy(&buf->data[buf->size], data, size);
    buf->size += size;
    return true;
}

static inline size_t
bufread(buf_t buf, void* to, size_t count, off_t offset)
{
    if (offset + count > buf.size)
        count = buf.size - offset;
    memcpy(to, &buf.data[offset], count);
    return count;
}

buf_t bufreadfile(struct Tux* tux, const char* filename);
