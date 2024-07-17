#pragma once

#include <stdint.h>
#include <string.h>

struct arguments {
    char* input;
    char* arch;
    int bundle;
};

extern struct arguments args;

void amd64_postlink(uint8_t* buf, size_t sz);
