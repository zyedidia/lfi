#include <stdio.h>

int foo(int* x) {
    return *x;
}

void bar(int* x, int y) {
    *x = y;
}

int g;

int global() {
    return g;
}

int main() {
    printf("Hello world\n");
    return 0;
}
