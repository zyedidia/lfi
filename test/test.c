int f1() {
    return 42;
}

int f2(int* x) {
    *x = 42;
    return *x;
}

int f3(void* x) {
    void (*fn)(void) = (void(*)(void)) x;
    fn();
    return 0;
}

int global;

int f4() {
    return global;
}

int f5() {
    return f4();
}
