#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "out.h"


int main(int argc, char *argv[]){

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


    free(buffer);
    fclose(file);

    return 0;
}