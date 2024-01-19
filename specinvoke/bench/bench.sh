#!/bin/sh

set -ex

WASM="xz_r nab_r deepsjeng_r lbm_r namd_r mcf_r x264_r"
ALL="gcc_r omnetpp_r mcf_r xalancbmk_r deepsjeng_r leela_r xz_r namd_r parest_r povray_r lbm_r imagick_r nab_r x264_r"

# --- lfi ---

LFIFLAGS=-O0 LOADER=lfi-run runcpu --config=lfi-lto --size=ref $ALL --action=run --rebuild
LFIFLAGS=-O1 LOADER=lfi-run runcpu --config=lfi-lto --size=ref $ALL --action=run --rebuild
LFIFLAGS=-O2 LOADER=lfi-run runcpu --config=lfi-lto --size=ref $ALL --action=run --rebuild
LFIFLAGS=--no-loads LOADER=lfi-run runcpu --config=lfi-lto --size=ref $ALL --action=run --rebuild

# --- native ---

LOADER=lfi-run runcpu --config=lfi-native-lto --size=ref $ALL --action=run --rebuild

# --- w2c2 ---

# POSTLINKCMD='wasm2bin --flags "-O3 -fomit-frame-pointer"' runcpu --config=wasm-native --size=ref xz_r nab_r deepsjeng_r lbm_r namd_r mcf_r x264_r --action=run --rebuild

# --- wasm2c ---

# POSTLINKCMD='wasm2bin --wasm2c --flags "-O3 -fomit-frame-pointer -ffixed-x21"' runcpu --config=wasm-native --size=ref $WASM --action=run --rebuild

# POSTLINKCMD='wasm2bin --wasm2c --flags "-O3 -fomit-frame-pointer"' runcpu --config=wasm-native --size=ref $WASM --action=run --rebuild

# --- w2c2-lfi ---

# LOADER=lfi-run WASM2BIN=~/programming/wasm2bin-lfi POSTLINKCMD='wasm2bin --cc lfi-clang --flags "-O3 -fomit-frame-pointer"' runcpu --config=wasm-native --size=ref $WASM --action=run

# --- wasmtime ---

# LOADER="wasmtime run --allow-precompiled --dir=. --dir=/home --" POSTLINKCMD="wasmtime compile" runcpu --config=wasm-native --size=ref --action=run --rebuild $WASM

# --- wamr ---

# LOADER="iwasm --dir=. --dir=/home" POSTLINKCMD="wamrc" runcpu --config=wasm-native --size=ref --action=run --rebuild $WASM
