#include <bdd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <libgen.h>
#include <cassert>
#include <sys/wait.h>
#include <string.h>
#include <omp.h>
#include <chrono>

#include "lfiv.h"

// The name of the output file subBDD prefix
#define SUBFILE "lfi"
// Instruction range to be checked
const size_t n_verify = 0x0ffffffffULL + 1;

static bdd
add_value(uint32_t val)
{
    bdd total = bddtrue;
    for (size_t i = 0; i < 32; i++) {
        uint32_t bit = (val >> i) & 1;
        bdd var = bdd_ithvar(i);
        if (!bit) {
            var = bdd_not(var);
        }
        total &= var;
    }
    return total;
}

static bool
subbdd(int tid, std::vector<uint32_t>& insns, std::string& out)
{
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

    bdd full = bddfalse;
    size_t i = 0;
    for (uint32_t& insn : insns) {
        full |= add_value(insn);
        i++;
    }

    printf("%d: completed\n", tid);

    FILE* f = fopen(out.c_str(), "w");
    if (!f) {
        fprintf(stderr, "could not open %s\n", out.c_str());
        perror("open");
        return false;
    }
    bdd_save(f, full);
    fclose(f);
    return true;
}

int
main(int argc, char* argv[])
{
    if (argc <= 1) {
        printf("usage: %s out.bdd\n", argv[0]);
        printf("OR usage: %s out.bdd numProcs\n", argv[0]);
        return 1;
    }

    bool* valid = (bool*) calloc(1, n_verify * sizeof(bool));
    assert(valid);

    size_t nproc = omp_get_num_procs();
    if (argc > 2 && atoi(argv[2])>0) nproc = atoi(argv[2]);
    printf("nproc: %ld\n", nproc);

    omp_set_num_threads(nproc);

    printf("finding valid instructions...\n");
    
    auto start = std::chrono::steady_clock::now();

#pragma omp parallel
#pragma omp for
    for (uint64_t insn = 0; insn < n_verify; insn++) {
        if (lfiv_verify_insn_arm64((uint32_t) insn)) {
            valid[insn] = true;
        }
    }

    std::vector<uint32_t> valid_insns;

    for (uint64_t insn = 0; insn < n_verify; insn++) {
        if (valid[insn])
            valid_insns.push_back(insn);
    }

    assert(valid_insns.size() >= 1);

    while (valid_insns.size() % nproc != 0)
        valid_insns.push_back(valid_insns[0]);

    printf("valid: %ld\n", valid_insns.size());

    free(valid);

    printf("creating sub bdds...\n");

    pid_t children[nproc];
    for (size_t i = 0; i < nproc; i++) {
        if((children[i] = fork()) == 0) {
            std::string out_file_name = SUBFILE + std::to_string(i) + ".bdd";

            size_t n_insns = valid_insns.size();

            size_t start = (n_insns*i)/nproc, end = (n_insns*(i+1))/nproc;

            std::vector<uint32_t> sub(valid_insns.begin() + start, valid_insns.begin() + end);
            if (!subbdd(i, sub, out_file_name)) {
                fprintf(stderr, "error creating subdd");
                exit(1);
            }

            exit(0);
        }
    }

    for (size_t i = 0; i < nproc; i++) {
        int status;
        pid_t pid = waitpid(children[i], &status, 0);
        assert(pid == children[i]);
        assert(WIFEXITED(status));

        printf("%d: process finished\n", children[i]);
    }

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

    bdd full = bddfalse;

    for (size_t i = 0; i < nproc; i++) {
        bdd partial = bddfalse;
        std::string out_file_name = SUBFILE + std::to_string(i) + ".bdd";
        FILE* f = fopen(out_file_name.c_str(), "r");
        if (!f) {
            fprintf(stderr, "could not open %s\n", argv[1]);
            perror("open");
            return 1;
        }

        bdd root;
        if (bdd_load(f, root) < 0) {
            fprintf(stderr, "error loading bdd from file");
            fclose(f);
            return 1;
        }
        full |= root;
        fclose(f);
    }
    fprintf(stderr, "unified sub bdds\n");

    FILE* f = fopen(argv[1], "w");
    if (!f) {
        fprintf(stderr, "could not open %s\n", argv[1]);
        perror("open");
        return 1;
    }
    bdd_save(f, full);
    fclose(f);
    
    auto end = std::chrono::steady_clock::now();

    fprintf(stderr, "saved final bdd to output file\n");
    
    std::chrono::duration<double> duration = end - start;
    
    fprintf(stdout, "Time for program completion with [%ld] threads: %f \n", nproc, duration.count());
    
    

    return 0;
}
