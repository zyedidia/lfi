#pragma once

#include <stdlib.h>

typedef struct result {
    char* val;
    char* pre;
    char* post;
    char* premulti[8];
    char* unmod;
} Result;

static void
rfree(Result r)
{
    free(r.pre);
    free(r.post);
    free(r.val);
    free(r.unmod);

    for (size_t i = 0; i < sizeof(r.premulti) / sizeof(*r.premulti); i++) {
        free(r.premulti[i]);
    }
}
