#include <stdint.h>
#include <stdio.h>

#include "test.h"

#define MAXINSTRBYTE 3

int main(int argc, char *argv[]){


    size_t counter = 0;

    fprintf(stdout, "Tesing all x86 instructions with byte lengths 1 to %d.\n", MAXINSTRBYTE);

    for (int instrByteNum = 1; instrByteNum <= MAXINSTRBYTE; instrByteNum++) {
        for (__uint128_t instr = 0; instr < 1ULL << (instrByteNum*8); instr++) {
            if (evaluate(instr)) counter++;
        }
    }

    fprintf(stdout, "%ld instructions returned a non-zero value after evaluation\n", counter);

    return 0;
}