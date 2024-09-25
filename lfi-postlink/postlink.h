#pragma once

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

enum meter {
    METER_NONE,
    METER_BRANCH,
    METER_FP,
    METER_TIMER,
};

struct arguments {
    char* input;
    char* arch;
    int bundle;
    enum meter meter;
    bool noprefix;
    bool precise;
};

extern struct arguments args;

void amd64_postlink(uint8_t* buf, size_t sz);
void arm64_postlink(uint8_t* buf, size_t sz);
