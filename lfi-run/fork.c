#include <stdlib.h>

#include "lfi.h"

void sys_fork(struct proc* p) {
    struct proc* child = calloc(1, sizeof(struct proc));
    if (!child) {
        p->regs.x0 = -1;
    }
    // * find free base
    uintptr_t base = proc_newbase(&manager);
    if (!base)
        goto err;
    // * copy/share regions
    // * initialize/protect sys page
    // * copy registers, change base
err:
    p->regs.x0 = -1;
}
