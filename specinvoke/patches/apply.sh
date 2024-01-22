#!/bin/bash

PATCH=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

patch -p0 < $PATCH/prm.c.patch
patch -p0 < $PATCH/molio.c.patch
patch -p0 < $PATCH/configfile.h.patch
patch -p0 < $PATCH/configfile.c.patch
