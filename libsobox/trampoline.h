#pragma once

#include <stdint.h>

#include "proc.h"

uint8_t* sbx_trampoline_gen(SoboxProc* proc, void* fn);
