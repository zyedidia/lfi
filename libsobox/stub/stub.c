#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "stub.h"

extern void ret() asm ("ret");

static SoboxFns myfns = (SoboxFns) {
    .dlopen = dlopen,
    .dlclose = dlclose,
    .dlsym = dlsym,
    .malloc = malloc,
    .free = free,
    .ret = ret,
};

int
main()
{
    syscall(SYS_SBX_dl, &myfns);
}
