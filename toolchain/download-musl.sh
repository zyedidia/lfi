#!/bin/sh
VERSION=$1
wget https://musl.libc.org/releases/musl-$VERSION.tar.gz
tar -xf musl-$VERSION.tar.gz
