lfi-leg: lfi.c util.c
	clang $^ -o $@ -I. -D_GNU_SOURCE -O2 -g
%.c: %.leg
	leg -o $@ $<
install: lfi-leg
	install $< /usr/local/bin
