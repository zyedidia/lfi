#ifndef DYNARMIC_H
#define DYNARMIC_H

#include "lfi_internal.h" // struct lfi_proc

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int lfi_proc_entry_dynarmic(struct lfi_proc* proc);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // DYNARMIC_H

