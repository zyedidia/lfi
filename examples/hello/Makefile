ARCH ?= aarch64

hello: hello.c
	$(ARCH)-lfi-linux-musl-clang $< -O2 -static-pie -o $@

run: hello
	lfi-run -v hello

clean:
	rm -f hello

.PHONY: clean run
