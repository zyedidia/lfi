#pragma once

#include <string.h>

enum {
    INPUTMAX = 128,
};

typedef struct {
    int n;

    char* inputs[INPUTMAX];
    size_t ninputs;
} Args;

extern Args args;
