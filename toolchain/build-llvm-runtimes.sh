#!/bin/sh

# Usage: build-compiler-rt.sh PREFIX

set -e
set -x

VERSION=15.0.7
PREFIX=/tmp/toolchain
SYSROOT=$PREFIX/sysroot
COMPRT=$PREFIX/compiler-rt

CC=$PWD/../compiler/lfi-nolib-clang
CXX=$PWD/../compiler/lfi-nolib-clang++

rm -rf llvm-project-$VERSION.src/build-runtimes

# llvm c++ libraries
cd llvm-project-$VERSION.src/
mkdir build-runtimes
cd build-runtimes
export ASMFLAGS="-flfi-O1"
export CXXFLAGS="--sysroot $SYSROOT -nostdlib -nostdlibinc -isystem $SYSROOT/include -isystem /usr/include -I../libunwind/include -resource-dir $COMPRT --rtlib=compiler-rt"
export CFLAGS="--sysroot $SYSROOT -Wno-unused-command-line-argument -nostdlib -nostdlibinc -isystem $SYSROOT/include -isystem /usr/include -I../libunwind/include -resource-dir $COMPRT --rtlib=compiler-rt"
cmake ../runtimes -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=$CC \
    -DCMAKE_CXX_COMPILER=$CXX \
    -DLIBCXX_HAS_MUSL_LIBC=YES \
    -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi;libunwind" \
    -DCMAKE_INSTALL_PREFIX=$SYSROOT \
    -DLIBCXX_ENABLE_SHARED=NO \
    -DLIBCXXABI_ENABLE_SHARED=NO \
    -DLIBUNWIND_ENABLE_SHARED=NO \
    -DLIBCXXABI_LINK_TESTS_WITH_SHARED_LIBCXX=OFF \
    -DLIBCXX_ENABLE_ABI_LINKER_SCRIPT=OFF \
    -DLIBCXX_LINK_TESTS_WITH_SHARED_LIBCXXABI=OFF \
    -DLIBCXX_LINK_TESTS_WITH_SHARED_LIBCXX=OFF
ninja unwind cxxabi cxx
ninja install
