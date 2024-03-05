#pragma once

#include <capstone/capstone.h>

bool verify_init();
bool verify_insn(uint32_t insn);
