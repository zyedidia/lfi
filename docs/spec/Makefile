SRCS = lfi-spec.tex \
	   introduction.tex \
	   arm64/verifier.tex \
	   arm64/runtime.tex \
	   arm64/assembler.tex \
	   x64/verifier.tex \
	   x64/runtime.tex \
	   x64/assembler.tex \
	   riscv/verifier.tex

lfi-spec.pdf: $(SRCS)
	latexmk -pdf lfi-spec.tex

clean:
	latexmk -C

.PHONY: clean
