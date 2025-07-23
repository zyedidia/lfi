#!/bin/bash
set -ex

export MAKEFLAGS="-j32"

ALL="gcc_r mcf_r x264_r omnetpp_r xalancbmk_r leela_r deepsjeng_r xz_r parest_r namd_r lbm_r povray_r imagick_r nab_r"

LOADER="lfi-run -- " runcpu --action=run --size=ref $ALL --config=lfi-clang --iterations=1
LOADER="lfi-run -- " runcpu --action=run --size=ref $ALL --config=lfi-stores-clang --iterations=1
LOADER="lfi-run -- " runcpu --action=run --size=ref $ALL --config=native-clang --iterations=1
