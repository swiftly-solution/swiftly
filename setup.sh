#!/bin/bash

source ~/.xmake/profile
LPATH=$(pwd)

export HL2SDK="${LPATH}/alliedmodders/hl2sdk-cs2"
export MMSOURCE="${LPATH}/alliedmodders/metamod"

if [ -z "${GITHUB_SHA}" ]; then
    export GITHUB_SHA=$(git rev-parse HEAD)
fi

export XMAKE_ROOT=y
xmake -j $(nproc)