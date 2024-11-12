#include <stdio.h>
#include <stdint.h>
#include "args.h"

static uint32_t y;

void
rand_init()
{
    y = args.seed;
}

/* static uint32_t y = 1; */

uint32_t
rand_u32()
{
    y^=(y<<13); y^=(y>>17);
    return (y^=(y<<15));
}
