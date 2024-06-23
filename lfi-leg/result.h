#pragma once

#include <stdlib.h>

typedef struct result {
    char* val;
    char* pre;
    char* post;
} Result;

static void
rfree(Result r)
{
    free(r.pre);
    free(r.post);
    free(r.val);
}
