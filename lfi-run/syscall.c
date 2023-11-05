#include <stdio.h>
#include <stdlib.h>

#include "lfi.h"

void syscall_handler(struct proc* proc) {
    printf("syscall %ld\n", proc->regs.x8);
    if (proc->regs.x8 == 42) {
        exit(0);
    }
}

void sandbox_exit(struct proc* proc) {
    printf("sandbox_exit\n");
}
