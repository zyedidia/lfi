#include <stdint.h>

extern uint64_t lfi_go_cb(void*, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

uint64_t lfi_cb(void* ctxp, uint64_t num, uint64_t args[6]) {
    return lfi_go_cb(ctxp, num, args[0], args[1], args[2], args[3], args[4], args[5]);
}
