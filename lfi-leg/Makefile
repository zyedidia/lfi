all: lfi-leg-arm64 lfi-leg-amd64

lfi-leg-%: lfi-%.c util.c ht.c op.c main.c
	$(CC) $^ -o $@ -I. -D_GNU_SOURCE -O2 -g
lfi-leg-amd64: lfi-amd64.c util.c ht.c op.c main.c
	$(CC) $^ -o $@ -I. -D_GNU_SOURCE -O2 -g -lkeystone -lstdc++ -lm
%.c: %.leg
	leg -P -o $@ $<
install: lfi-leg-arm64
	install $< /usr/local/bin
