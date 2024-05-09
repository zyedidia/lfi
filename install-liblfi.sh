#!/bin/sh

# usage: ./install.sh $PREFIX # must be absolute path

set -ex

PREFIX=$1

mkdir -p $PREFIX/include
mkdir -p $PREFIX/lib

cp LICENSE $PREFIX
cp README.md $PREFIX

(cd liblfi && knit && mv liblfi.a $PREFIX/lib && cp lfi.h $PREFIX/include)
(cd lfi-verify && cargo build --release && mv ./target/release/liblfiverify.a $PREFIX/lib)
(cd lfi-veribdd && knit && mv liblfiveribdd.a $PREFIX/lib)
