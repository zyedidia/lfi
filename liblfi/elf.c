#include <elf.h>
#include <stdint.h>
#include <stdlib.h>

void
elf_headers(uint8_t* buffer)
{

}

char* elf_section(uint8_t* buffer, Elf64_Shdr sh)
{
	char* buf = malloc(sh.sh_size);
	if (!buf) {
        return NULL;
	}

	assert(lseek(fd, (off_t)sh.sh_offset, SEEK_SET) == (off_t)sh.sh_offset);
	assert(read(fd, (void *)buff, sh.sh_size) == sh.sh_size);

	return buff;
}
