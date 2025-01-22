#pragma once

#include "lfi_tux.h"
#include "file.h"

struct Tux {
    struct LFIPlatform* plat;
    struct TuxOptions opts;

    struct FDFile* fstdin;
    struct FDFile* fstdout;
    struct FDFile* fstderr;
};
