lfi-leg: lfi.c util.c
	clang $^ -o $@ -I. -D_GNU_SOURCE -O2
%.c: %.leg
	leg -o $@ $<
