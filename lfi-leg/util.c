#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char*
xasprintf(const char* fmt, ...)
{
    int error;
    va_list ap;
    char* strp = NULL;

    va_start(ap, fmt);
    error = vasprintf(&strp, fmt, ap);
    va_end(ap);
    
    if (error == -1) {
        perror("xasprintf");
        exit(1);
    }

    return strp;
}
