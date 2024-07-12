gcc -O3 -c verifier.c -o verifier.o
go run generator/bdd.go generator/lfi.bdd.txt > lfi.bdd.c
gcc -O3 -c lfi.bdd.c -o lfi.bdd.o
ar rcs liblfiveribdd.a verifier.o lfi.bdd.o
gcc lfi-verify.c liblfiveribdd.a -O2 -o lfi-verify
