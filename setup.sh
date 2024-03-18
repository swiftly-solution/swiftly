#!/bin/bash

source ~/.xmake/profile

export MMSOURCE112="$(pwd)/metamod"
export HL2SDKCS2="$(pwd)/hl2sdk"
export HL2SDKMANIFEST="hl2sdk-manifests"
if [ -z "${GITHUB_SHA}" ]; then
    export GITHUB_SHA=$(git rev-parse HEAD)
fi

export XMAKE_ROOT=y
xmake -j $(nproc) -y
