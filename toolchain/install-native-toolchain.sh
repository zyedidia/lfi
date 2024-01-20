#!/bin/sh

set -e

PREFIX=$1
mkdir -p $PREFIX

LLVM_VERSION=15.0.7
MUSL_VERSION=1.2.4

CC=$PWD/../compiler/lfi-native-nolib-clang
CXX=$PWD/../compiler/lfi-native-nolib-clang++

if [ ! -d llvm-project-$LLVM_VERSION.src ]; then
    ./download-llvm.sh $LLVM_VERSION
fi

if [ ! -d musl-$MUSL_VERSION ]; then
    ./download-musl.sh $MUSL_VERSION
fi

./build-compiler-rt.sh $CC $CXX $PREFIX $LLVM_VERSION
./build-musl.sh $CC $PREFIX $MUSL_VERSION
./build-llvm-runtimes.sh $CC $CXX $PREFIX $LLVM_VERSION

cp -r ../compiler $PREFIX/bin
