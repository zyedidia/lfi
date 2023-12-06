#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

static __attribute((noinline)) long long unsigned time_ns() {
  struct timespec ts;
  if (clock_gettime(CLOCK_REALTIME, &ts)) {
    exit(1);
  }
  return ((long long unsigned)ts.tv_sec) * 1000000000LLU +
         (long long unsigned)ts.tv_nsec;
}

void yield_fast(int pid);

void __attribute__((noinline)) bench(int pid, long n) {
    for (long i = 0; i < n; i++) {
        yield_fast(pid);
    }
}

int main() {
    int pid = getpid();
    long n = 1000000000;
    const long long unsigned t1 = time_ns();
    bench(pid, n);
    const long long unsigned elapsed = time_ns() - t1;
    printf("%.3f\n", elapsed / (float) n);
}
