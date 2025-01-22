#pragma once

#include <pthread.h>
#include <stdint.h>

#include "list.h"
#include "config.h"

#define FUTEX_CONTAINER(e) LIST_CONTAINER(struct Futex, elem, e)

struct Futex {
    uintptr_t addr;
    int waiters;
    struct List elem;
    pthread_cond_t cond;
    pthread_mutex_t lock;
};

struct Futexes {
    struct List* active;
    struct List* free;
    pthread_mutex_t lock;
    struct Futex mem[CONFIG_MAX_FUTEX];
};
