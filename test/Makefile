test.list: test.o
	aarch64-none-elf-objdump -D $< > $@
test.o: test_iso.s
	aarch64-none-elf-as $< -o $@
test_iso.s: test.s
	isolator $< > $@
test.s: test.c
	aarch64-none-elf-gcc -S $< -o $@ -falign-jumps=16 -falign-functions=16 -ffixed-x19 -ffixed-x20 -ffixed-x21
