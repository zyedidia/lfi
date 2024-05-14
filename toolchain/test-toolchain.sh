#!/bin/sh

# usage: ./test-toolchain.sh $PWD/prefix

PREFIX=$1

export PATH=$PREFIX/bin:$PATH

$PREFIX/gcc/bin/aarch64_lfi-linux-musl-gcc lfi-run/test/hello.c -O2 -o /tmp/hello.lfi
lfi-run /tmp/hello.lfi
$PREFIX/clang/bin/lfi-clang lfi-run/test/hello.c -O2 -o /tmp/hello.lfi
lfi-run /tmp/hello.lfi
