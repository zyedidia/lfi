#include "lfi_arch.h"

void lfi_regs_init(struct TuxRegs* regs, struct LFIAddrSpace* as, struct LFIContext* ctx);

uintptr_t* lfi_regs_entry(struct TuxRegs* regs);

uintptr_t* lfi_regs_arg0(struct TuxRegs* regs);
