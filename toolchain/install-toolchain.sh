#!/bin/sh

set -e

PREFIX=$1
mkdir -p $PREFIX

./download-llvm.sh
./download-musl.sh

./build-compiler-rt.sh $PREFIX
./build-musl.sh $PREFIX
./build-llvm-runtimes.sh $PREFIX

cp -r ../compiler $PREFIX/bin
