#include <stdint.h>

void _start() {
    /* asm volatile ("str x0, [%0]" :: "r"(0)); */
    /*  */
    register uint64_t num asm("x8") = 0;
    register uint64_t msg asm("x0") = (uint64_t) "hello!";
    asm volatile ("svc #0" :: "r"(num), "r"(msg));
}
