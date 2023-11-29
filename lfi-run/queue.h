#pragma once

#include "lfi.h"

void queue_push_front(struct queue* q, struct proc* p);

void queue_remove(struct queue* q, struct proc* p);

struct proc* queue_pop_back(struct queue* q);

void queue_wake_all(struct queue* q);

void queue_wake(struct queue* q, struct proc* p);
