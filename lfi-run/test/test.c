#include <stdlib.h>
#include <stdio.h>
int main() {
    int* p = malloc(1024 * 1024);
    if (!p) {
        printf("no alloc\n");
        return 0;
    }
    /* *p = 10; */
    printf("%p\n", p);
    free(p);

    return 0;
}
