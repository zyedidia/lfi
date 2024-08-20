#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "stub.h"

static SoboxFns myfns = (SoboxFns) {
    .dlopen = dlopen,
    .dlclose = dlclose,
    .dlsym = dlsym,
    .malloc = malloc,
    .free = free,
};

int
main()
{
    return 0;
    /* syscall(SOBOXDL, &myfns); */
}
