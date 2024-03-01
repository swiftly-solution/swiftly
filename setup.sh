#!/bin/bash

export MMSOURCE112="$(pwd)/metamod"
export HL2SDKCS2="$(pwd)/hl2sdk"
export HL2SDKMANIFEST="hl2sdk-manifests"
if [ -z "${GITHUB_SHA}" ]; then
    export GITHUB_SHA=$(git rev-parse HEAD)
fi

mkdir build
cd build
CC=gcc CXX=g++ python3 ../configure.py --plugin-name=swiftly --plugin-alias=swift -s cs2 --targets=x86_64 --enable-optimize --hl2sdk-manifests $HL2SDKMANIFEST
cd ..