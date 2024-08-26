#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "out.h"


int main(int argc, char *argv[]){

    size_t num_cycle = 10000;

    if (argc < 2) {
        fprintf(stdout, "Usage: largex86 out.bin\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Calculate file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    uint8_t *buffer = (uint8_t *)malloc(file_size * sizeof(uint8_t));
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    size_t read_size = fread(buffer, sizeof(uint8_t), file_size, file);
    if (read_size != file_size) {
        perror("Failed to read the entire file");
        free(buffer);
        fclose(file);
        return 1;
    }

    uint8_t *curInstr = buffer;
    size_t counter = 0;

    fprintf(stdout, "Testing entire x86 instruction set.\n");

    while (curInstr < buffer + file_size) {
        // fprintf(stdout, "%d ", evaluate(curInstr));
        if (!evaluate(curInstr)) {
            counter++;
            curInstr++;
        } else {
            curInstr += evaluate(curInstr);
        }
    }

    fprintf(stdout, "\n%ld instructions returned a ZERO value after evaluation.\n", counter);

    uint8_t *testBuffer = (uint8_t *)malloc(file_size * num_cycle * sizeof(uint8_t));

    uint8_t *testLoc = testBuffer;

    for (int i = 0; i < num_cycle; i++) {
        memcpy(testLoc, buffer, file_size);
        testLoc += file_size;
    }

    testLoc = testBuffer;

    fprintf(stdout, "Testing entire x86 instruction set %ld times.\n", num_cycle);

    clock_t begin = clock();

    while (testLoc < testBuffer + file_size * num_cycle) {
        if (!evaluate(testLoc)) {
            counter++;
            testLoc++;
        } else {
            testLoc += evaluate(testLoc);
        }
        // testLoc += evaluate(testLoc);
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    fprintf(stdout, "\n%ld instructions returned a ZERO value after evaluation.\n", counter);
    fprintf(stdout, "Test size: %ld bytes (%.3f MiB)\n", file_size * num_cycle, (file_size * num_cycle) / 1024.0 / 1024);
    fprintf(stdout, "time: %.3f, %.3f MiB/s\n", time_spent, ((file_size * num_cycle) / 1024 / 1024) / time_spent);


    free(testBuffer);
    free(buffer);
    fclose(file);

    return 0;
}