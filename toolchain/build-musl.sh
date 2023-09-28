#!/bin/sh

# Usage: build-musl.sh PREFIX

set -e
set -x

VERSION=1.2.4
PREFIX=$1
SYSROOT=$PREFIX/sysroot
COMPRT=$PREFIX/compiler-rt

CC=$PWD/../compiler/lfi-nolib-clang

cp memset.S musl-$VERSION/src/string/aarch64/memset.S
cp getopt.c musl-$VERSION/src/misc/getopt.c

export CC=$CC
export CFLAGS="--rtlib=compiler-rt -resource-dir $COMPRT"
cd musl-$VERSION
make clean
./configure --prefix=$SYSROOT --syslibdir=$SYSROOT/lib
make
make install
