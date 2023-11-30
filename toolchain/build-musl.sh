#!/bin/sh

# Usage: build-musl.sh CC PREFIX

set -e
set -x

VERSION=1.2.4
PREFIX=$2
SYSROOT=$PREFIX/sysroot
COMPRT=$PREFIX/compiler-rt

CC=$1

cp memset.S musl-$VERSION/src/string/aarch64/memset.S
cp getopt.c musl-$VERSION/src/misc/getopt.c

export CC=$CC
export CFLAGS="--rtlib=compiler-rt -resource-dir $COMPRT"
cd musl-$VERSION
make clean
./configure --prefix=$SYSROOT --syslibdir=$SYSROOT/lib
make
make install
