#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>

static _Atomic(long) sum;

void* thread(void* ptr) {
    long id = (long) ptr;
    atomic_fetch_add(&sum, id);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread, (void*) 1);
    pthread_create(&t2, NULL, thread, (void*) 2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("done %ld\n", sum);
    return 0;
}
