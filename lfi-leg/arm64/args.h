#pragma once

struct arguments {
    char* input;
    char* output;
    bool poc;
    bool storesonly;
};

extern struct arguments args;
