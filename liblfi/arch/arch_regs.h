#pragma once

#include "lfi_arch.h"
#include "lfi.h"

void regs_init(struct TuxRegs* regs, lfiptr_t entry, lfiptr_t sp);

uintptr_t* regs_return(struct TuxRegs* regs);

uintptr_t* regs_sp(struct TuxRegs* regs);
