#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "rand.h"

static bool
randbool()
{
    return rand_u32() < UINT32_MAX / 2;
}

#include "codegram/x86.encode.c"

int x64_encode(uint8_t* input) {
    return cg_encode(input);
}
