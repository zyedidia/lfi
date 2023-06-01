test.bin: test.elf
	aarch64-none-elf-objcopy -O binary $< $@
test.elf: test.o
	aarch64-none-elf-ld $< -o $@
test.list: test.o
	aarch64-none-elf-objdump -D $< > $@
test.o: test_iso.s
	aarch64-none-elf-as $< -o $@
test_iso.s: test.s
	isolator $< > $@
test.s: test.c
	aarch64-none-elf-gcc -S $< -o $@ -ffixed-x21 -ffixed-x22
