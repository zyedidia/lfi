#include <unistd.h>

void yield_fast(int pid);

int main() {
    int pid = getpid();

    for (int i = 0; i < 100000000; i++) {
        yield_fast(pid);
    }
}
