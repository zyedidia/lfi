#include "lfi.bdd.h"

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define X(x,y) x ## _ ## y
#define XX(x,y) X(x,y)

#ifdef PREFIX_VERIBDD
#define EXPORT(a) XX(lfiveribdd, a)
#else
#define EXPORT(a) XX(lfi, a)
#endif

bool evaluate(uint32_t);

bool EXPORT(verify_insn)(uint32_t insn) {
    return evaluate(insn);
}

bool EXPORT(verify_bytes)(char* b, size_t size, void* error) {
    (void) error;

    uint32_t* insns = (uint32_t*) b;

    for (size_t i = 0; i < size / sizeof(uint32_t); i++) {
        if (!evaluate(insns[i]))
            return false;
    }
    return true;
}
