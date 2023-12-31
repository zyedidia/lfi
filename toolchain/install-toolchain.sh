#!/bin/sh

set -e

PREFIX=$1
mkdir -p $PREFIX

CC=$PWD/../compiler/lfi-nolib-clang
CXX=$PWD/../compiler/lfi-nolib-clang++
# CC=$PWD/../compiler/lfi-native-nolib-clang
# CXX=$PWD/../compiler/lfi-native-nolib-clang++

./download-llvm.sh
./download-musl.sh

./build-compiler-rt.sh $CC $CXX $PREFIX
./build-musl.sh $CC $PREFIX
./build-llvm-runtimes.sh $CC $CXX $PREFIX

cp -r ../compiler $PREFIX/bin
