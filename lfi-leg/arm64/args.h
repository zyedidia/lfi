#pragma once

struct arguments {
    char* input;
    char* output;
    bool poc;
    bool storesonly;
    bool sysexternal;
    bool noguardelim;
};

extern struct arguments args;
