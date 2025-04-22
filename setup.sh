#!/bin/bash

LPATH=$(pwd)

if [ -z "${GITHUB_SHA}" ]; then
    export GITHUB_SHA=$(git rev-parse HEAD)
fi

if [ ! -d build ]; then
    mkdir build
    cd build
    CC=gcc CXX=g++ python ../configure.py --enable-optimize --hl2sdk-root "${LPATH}/alliedmodders" --mms_path "${LPATH}/alliedmodders/metamod" --hl2sdk-manifests "${LPATH}/alliedmodders/hl2sdk-manifests" -s cs2
    cd ..
fi

cd build
ambuild
cd ..