test.bin: test.elf
	aarch64-none-elf-objcopy -O binary $< $@
test.list: test.elf
	aarch64-none-elf-objdump -D $< > $@
test.elf: test.o
	aarch64-none-elf-ld $< -o $@
test.o: test.s
	aarch64-none-elf-as $< -o $@
test.s: test.c
	isocc -S $< -o $@
