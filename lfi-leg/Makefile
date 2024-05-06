lfi-leg: lfi.c util.c ht.c op.c
	clang $^ -o $@ -I. -D_GNU_SOURCE -O2 -g
%.c: %.leg
	leg -P -o $@ $<
install: lfi-leg
	install $< /usr/local/bin
