#!/bin/bash
set -ex

export MAKEFLAGS="-j32"

ALL="gcc_r mcf_r x264_r omnetpp_r xalancbmk_r leela_r deepsjeng_r xz_r parest_r namd_r lbm_r povray_r imagick_r nab_r"

LOADER="lfi-run --no-verify" runcpu --action=run --size=ref $ALL --config=lfi-gcc
LFI_REWRITER="lfi-leg-amd64-baseline" LOADER="lfi-run --no-verify" runcpu --action=run --size=ref $ALL --config=lfi-gcc-baseline
runcpu --action=run --size=ref $ALL --config=gcc
