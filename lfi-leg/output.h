#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct output {
    char* buf;
    size_t n;
    size_t cap;
};

static void outwritebuf(struct output* out, char* s, size_t len) {
    if (!s)
        return;
    if (len >= out->cap - out->n) {
        out->cap = out->cap * 2 + len;
        out->buf = realloc(out->buf, out->cap);
    }
    memcpy(&out->buf[out->n], s, len);
    out->n += len;
}

static void outwrite(struct output* out, char* s) {
    outwritebuf(out, s, strlen(s));
}

static void outwriteln(struct output* out, char* s) {
    outwrite(out, s);
    outwrite(out, "\n");
}

static void outsend(struct output* out, FILE* fout) {
    fwrite(out->buf, 1, out->n, fout);
    free(out->buf);
}

static char* outstr(struct output* out) {
    if (!out->buf)
        return "(null)";
    char* buf = malloc(out->n + 1);
    memcpy(buf, out->buf, out->n);
    buf[out->n] = 0;
    free(out->buf);
    return buf;
}
