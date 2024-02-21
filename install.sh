#!/bin/sh

set -ex

PREFIX=$1

mkdir -p $PREFIX
mkdir -p $PREFIX/bin
mkdir -p $PREFIX/toolchain

go build -o $PREFIX/bin ./lfi-gen
go build -o $PREFIX/bin ./lfi-compile
go build -o $PREFIX/bin ./specinvoke

export PATH=$PREFIX/bin:$PATH

(cd lfi-verify && cargo build --release && mv ./target/release/lfi-verify $PREFIX/bin)

(cd lfi-run && knit && mv lfi-run $PREFIX/bin)

(cd toolchain && ./install-toolchain.sh $PREFIX/toolchain)
