#pragma once

#include <string.h>
#include <stdbool.h>

enum {
    INPUTMAX = 128,
};

typedef struct {
    char* inputs[INPUTMAX];
    size_t ninputs;
    bool max_procs;
} Args;

extern Args args;
