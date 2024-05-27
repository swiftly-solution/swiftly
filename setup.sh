#!/bin/bash

export MMSOURCE20="$(pwd)/alliedmodders/metamod"
export HL2SDKCS2="$(pwd)/alliedmodders/hl2sdk"

if [ -z "${GITHUB_SHA}" ]; then
    export GITHUB_SHA=$(git rev-parse HEAD)
fi

if [ ! -d build ]; then
    mkdir build
    cd build
    CC=gcc CXX=g++ python ../configure.py --enable-optimize --symbol-files -s cs2
    cd ..
fi

cd build
ambuild
cd ..