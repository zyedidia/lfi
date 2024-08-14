#!/bin/sh

# usage: ./install-toolchain.sh $PREFIX # must be absolute path

set -ex

git submodule update --init

PREFIX=$1
TARGET_ARCH=$2

mkdir -p $PREFIX
mkdir -p $PREFIX/clang
mkdir -p $PREFIX/gcc

cp LICENSE $PREFIX
cp README.md $PREFIX

meson setup build-toolchain --prefix $PREFIX
ninja -C build-toolchain install
rm -rf build-toolchain

export PATH=$PREFIX/bin:$PATH

# install clang
if [ "$TARGET_ARCH" != x86_64 ]; then
    (cd toolchain/lfi-clang && ./install-toolchain.sh $PREFIX/clang $TARGET_ARCH)
fi

# install gcc
(cd toolchain/lfi-gcc && ./install-toolchain.sh $PREFIX/gcc $TARGET_ARCH)
