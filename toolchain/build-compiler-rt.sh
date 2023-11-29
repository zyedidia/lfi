#!/bin/sh

# Usage: build-compiler-rt.sh PREFIX

set -x
set -e

VERSION=15.0.7
PREFIX=$1
SYSROOT=$PREFIX/sysroot
COMPRT=$PREFIX/compiler-rt

CC=$PWD/../compiler/lfi-nolib-clang
CXX=$PWD/../compiler/lfi-nolib-clang++
# CC=clang
# CXX=clang++

rm -rf llvm-project-$VERSION.src/build-compiler-rt

# compiler-rt
cd llvm-project-$VERSION.src/
mkdir build-compiler-rt
cd build-compiler-rt
cmake ../compiler-rt -G Ninja \
    -DCMAKE_C_COMPILER=$CC \
    -DCMAKE_CXX_COMPILER=$CXX \
    -DLLVM_TARGET_TRIPLE='aarch64-unknown-linux-gnu' \
    -DCOMPILER_RT_BUILD_BUILTINS=ON \
    -DCOMPILER_RT_BUILD_LIBFUZZER=OFF \
    -DCOMPILER_RT_BUILD_MEMPROF=OFF \
    -DCOMPILER_RT_BUILD_PROFILE=OFF \
    -DCOMPILER_RT_BUILD_SANITIZERS=OFF \
    -DCOMPILER_RT_BUILD_XRAY=OFF \
    -DCOMPILER_RT_BUILD_ORC=OFF \
    -DCMAKE_C_COMPILER_WORKS=ON \
    -DCMAKE_CXX_COMPILER_WORKS=ON \
    -DCMAKE_INSTALL_PREFIX=$COMPRT
ninja
ninja install
