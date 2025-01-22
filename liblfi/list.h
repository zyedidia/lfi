#pragma once

#include <stddef.h>

#define LIST_CONTAINER(t, f, p) ((t*)(((char*)(p)) - offsetof(t, f)))

struct List {
    struct List* next;
    struct List* prev;
};

static inline void
list_init(struct List* l)
{
    l->next = l;
    l->prev = l;
}

struct List* list_first(struct List* list);

struct List* list_next(struct List* list, struct List* e);

void list_make_first(struct List** list, struct List* e);

void list_remove(struct List** list, struct List* e);
