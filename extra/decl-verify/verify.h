#pragma once

#include <capstone/capstone.h>

int verify(csh handle, uint32_t* insns, size_t n, uintptr_t addr);
