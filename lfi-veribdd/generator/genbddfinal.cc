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

#include "lfi.h"

// the name of the subprogram executable for BDD generation
#define SUBPROG "genbdd"
// The name of the output file subBDD prefix
#define SUBFILE "lfi"
// Number of processes to run concurrently
#define NPROCESSES 8
// Instruction range to be checked
const size_t n_verify = 0x0ffffffffULL + 1;

int
main(int argc, char* argv[])
{
    if (argc <= 1) {
        printf("usage: %s out.bdd\n", argv[0]);
        return 1;
    }

    fprintf(stderr, "Beginning Master BDD generation on instruction range \u001b[45m [0x%016lx, 0x%016lx) \u001b[0m\n", 0UL, n_verify);


    pid_t children[NPROCESSES];
    for(size_t i = 0; i < NPROCESSES; i++){
        if((children[i] = fork()) == 0) {
            char* cur_path = strdup(argv[0]);
            char* cur_dir = dirname(cur_path);
            std::string gen_bdd_sub_prog = std::string(cur_dir) + "/" + SUBPROG;
            std::string out_file_name = SUBFILE + std::to_string(i) + ".bdd";

            size_t start = (n_verify*i)/NPROCESSES, end = (n_verify*(i+1))/NPROCESSES;
            char startb[19];
            char endb[19];
            sprintf(startb, "%zx", start);
            sprintf(endb, "%zx", end);

            std::vector<char*> args;
            args.push_back(strdup(gen_bdd_sub_prog.c_str()));
            args.push_back(strdup(out_file_name.c_str()));
            args.push_back(startb);
            args.push_back(endb);

            
            execvp(args[0], args.data());


            fprintf(stderr, "Failed to execute subprocess for BDD generation, aborting\n");
            exit(0);
        }
    }

    for(size_t i = 0; i < NPROCESSES; i++){
        int status;
        pid_t pid = waitpid(children[i], &status, 0);
        assert(pid == children[i]);
        assert(WIFEXITED(status));

        fprintf(stderr, "\u001b[42m =============== Process with PID = %d finished =============== \u001b[0m \n", children[i]);
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

    
    for(size_t i = 0; i < NPROCESSES; i++){
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
            fprintf(stderr, "Error loading BDD from file");
            fclose(f);
            return 1;
        }
        // partial = *root;
        // bdd_load(f, &partial);
        full |= root;
        fclose(f);
    }
    fprintf(stderr, "\u001b[46m ----- Stitched Sub BDD's together ----- \u001b[0m \n");

    /* for (size_t i = start; i < end; i++) {
        if (i % 5000000 == 0) {
            fprintf(stderr, "%.1f\n", (float) i / (float) (end - start) * 100);
        }
        if (lfi_verify_insn((uint32_t) i)) {
            full |= add_value(i);
        }
    } */

    FILE* f = fopen(argv[1], "w");
    if (!f) {
        fprintf(stderr, "could not open %s\n", argv[1]);
        perror("open");
        return 1;
    }
    bdd_save(f, full);
    fclose(f);

    fprintf(stderr, "\u001b[42m ----- Saved final BDD to output file ----- \u001b[0m \n");

    return 0;
}
