#!/bin/sh

set -e

PREFIX=$1
mkdir -p $PREFIX

VERSION=15.0.7

CC=$PWD/../compiler/lfi-nolib-clang
CXX=$PWD/../compiler/lfi-nolib-clang++
# CC=$PWD/../compiler/lfi-native-nolib-clang
# CXX=$PWD/../compiler/lfi-native-nolib-clang++

./download-llvm.sh $VERSION
./download-musl.sh

./build-compiler-rt.sh $CC $CXX $PREFIX $VERSION
./build-musl.sh $CC $PREFIX
./build-llvm-runtimes.sh $CC $CXX $PREFIX $VERSION

cp -r ../compiler $PREFIX/bin
