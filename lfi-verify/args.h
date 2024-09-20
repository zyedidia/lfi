#pragma once

#include <string.h>
#include <stdbool.h>

enum {
    INPUTMAX = 128,
};

typedef struct {
    int n;
    char* inputs[INPUTMAX];
    size_t ninputs;
    char* arch;
    bool poc;
    bool decl;
} Args;

extern Args args;
