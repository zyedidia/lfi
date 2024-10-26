#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

bool
stackpush(Stack* s, LFIProc* p)
{
    if (s->size >= s->cap) {
        if (s->cap == 0)
            s->cap = 1;
        else
            s->cap *= 2;
        s->elements = realloc(s->elements, sizeof(LFIProc*) * s->cap);
        if (!s->elements)
            return false;
    }
    s->elements[s->size++] = p;
    return true;
}

LFIProc*
stackpop(Stack* s)
{
    if (s->size == 0)
        return NULL;
    LFIProc* p = s->elements[--s->size];
    return p;
}
