#include <bdd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <thread>
#include <mutex>

#include "lfi.h"

#define NTHREADS 8
const size_t n_verify = 0x0fffffffULL + 1; // 0x0ffffffffULL + 1;

// using namespace std;

std::mutex bdd_mutex;

bdd
add_value(uint32_t val)
{
    bdd total = bddtrue;
    for (size_t i = 0; i < 32; i++) {
        uint32_t bit = (val >> i) & 1;
        bdd_mutex.lock();
        bdd var = bdd_ithvar(i);
        if (!bit) {
            var = bdd_not(var);
        }
        bdd_mutex.unlock();
        total &= var;
    }
    return total;
}


void
add_value_range(uint32_t start, uint32_t end, bdd &result){
    // bdd full = bddfalse;
    for (size_t i = start; i < end; i++) {
        if (i % 5000000 == 0) {
            std::cerr << "Thread ID: " << std::this_thread::get_id() << " - ";
            fprintf(stderr, "%.1f\n", (float) i / (float) n_verify * 100);
        }
        if (lfi_verify_insn(i)) {
            result |= add_value(i);
        }
    }
    // return result;
}

int
main(int argc, char* argv[])
{
    if (argc <= 1) {
        printf("usage: %s out.bdd\n", argv[0]);
        return 1;
    }

    // size_t n_verify = 0x0ffffffffULL + 1;

    bdd_init(10000000, 10000);
    bdd_setvarnum(32);

    int order[] = {
        31,
        25, 26, 27, 28,
        29, 30,
        24, 23, 22, 21, 20, 19, 18, 17, 16,
        15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };
    bdd_setvarorder(order);

    // bdd full = bddfalse;
    std::thread threads[NTHREADS];
    bdd results[NTHREADS];

    for(int i = 0; i < NTHREADS; i++) results[i] = bddfalse;


    for(int i = 0; i < NTHREADS; i++){
        threads[i] = std::thread(add_value_range, (uint32_t) (n_verify*i)/NTHREADS, (uint32_t) (n_verify*(i+1))/NTHREADS, std::ref(results[i]));
    }

    for(int i = 0; i < NTHREADS; i++) threads[i].join();
    fprintf(stderr, "Finished all threads\n");

    bdd full = bddfalse;
    for(int i = 0; i < NTHREADS; i++) full |= results[i];


    /* for (size_t i = 0; i < n_verify; i++) {
        if (i % 5000000 == 0) {
            fprintf(stderr, "%.1f\n", (float) i / (float) n_verify * 100);
        }
        if (lfi_verify_insn((uint32_t) i)) {
            full |= add_value(i);
        }
    }*/

    FILE* f = fopen(argv[1], "w");
    if (!f) {
        fprintf(stderr, "could not open %s\n", argv[1]);
        perror("open");
        return 1;
    }
    bdd_save(f, full);
    fclose(f);

    return 0;
}
