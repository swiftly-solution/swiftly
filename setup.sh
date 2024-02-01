#!/bin/bash

export MMSOURCE112="$(pwd)/metamod"
export HL2SDKCS2="$(pwd)/hl2sdk"

mkdir build
cd build
CC=gcc CXX=g++ python3 ../configure.py --plugin-name=swiftly --plugin-alias=swift -s cs2 --enable-optimize
cd ..