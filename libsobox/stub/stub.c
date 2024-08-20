#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "stub.h"

extern void dlret() asm ("dlret");

static SoboxFns myfns = (SoboxFns) {
    .dlopen = dlopen,
    .dlclose = dlclose,
    .dlsym = dlsym,
    .malloc = malloc,
    .free = free,
    .dlret = dlret,
};

int
main()
{
    syscall(SYS_SBX_dl, &myfns);
}
