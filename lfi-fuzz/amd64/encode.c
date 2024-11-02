#include <stdint.h>
#include <stdbool.h>

static uint32_t
xor32()
{
    static uint32_t y = 2463534242UL;
    y^=(y<<13); y^=(y>>17); return (y^=(y<<15));
}

static bool
randbool()
{
    return xor32() < UINT32_MAX / 2;
}

#include "codegram/x86.encode.c"

int x64_encode(uint8_t* input) {
    return cg_encode(input);
}
