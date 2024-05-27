#!/bin/bash

source ~/.xmake/profile

export MMSOURCE112="$(pwd)/alliedmodders/metamod"
export HL2SDKCS2="$(pwd)/alliedmodders/hl2sdk"

if [ -z "${GITHUB_SHA}" ]; then
    export GITHUB_SHA=$(git rev-parse HEAD)
fi

export XMAKE_ROOT=y
xmake -j $(nproc) -y