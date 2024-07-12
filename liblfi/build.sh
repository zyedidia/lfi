mkdir -p .arch/amd64
gcc -O2 -Wall -Wextra -mfsgsbase -MD -MF .buddy.dep -c buddy.c -o .buddy.o -I. -DARCH_amd64
gcc -O2 -Wall -Wextra -mfsgsbase -MD -MF .lfi.dep -c lfi.c -o .lfi.o -I. -DARCH_amd64
gcc -O2 -Wall -Wextra -mfsgsbase -MD -MF .proc.dep -c proc.c -o .proc.o -I. -DARCH_amd64
gcc -c arch/amd64/runtime.S -o .arch/amd64/runtime.o
ar rcs liblfi.a .buddy.o .lfi.o .proc.o .arch/amd64/runtime.o
