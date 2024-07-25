gcc -c main.c -o main.o -O2 -DZYDIS_STATIC_BUILD
gcc -c amd64.c -o amd64.o -O2 -DZYDIS_STATIC_BUILD
gcc -c arm64.c -o arm64.o -O2 -DZYDIS_STATIC_BUILD
gcc main.o amd64.o arm64.o -o lfi-postlink -lZydis -lcapstone -static
