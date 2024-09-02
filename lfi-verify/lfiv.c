#include "lfiv.h"

bool
lfiv_verify(LFIVerifier* v, void* code, size_t size, uintptr_t addr)
{
    if (!v->verify)
        return false;
    return v->verify(code, size, addr, &v->opts);
}
