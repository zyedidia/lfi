#include <unistd.h>

static void yield_fast(int pid) {
    asm volatile (
        "ldr x30, [x21, #8];"
        "blr x30;" ::: "x30"
    );
}

int main() {
    int pid = getpid();

    for (int i = 0; i < 100000000; i++) {
        yield_fast(pid);
    }
}
