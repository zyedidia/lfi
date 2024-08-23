#!/bin/bash

for i in {1..16}; do
    ../../build/lfi-veribdd/generator/genbdd out.bdd "$i" 2>/dev/null | sed '/Garbage collection/d'
done
