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
cp meta.h musl-$VERSION/src/malloc/mallocng/meta.h

export CC=$CC
export CFLAGS="--rtlib=compiler-rt -resource-dir $COMPRT -DMMAP_THRESHOLD=4294967296"
cd musl-$VERSION
make clean
./configure --prefix=$SYSROOT --syslibdir=$SYSROOT/lib
make
make install
