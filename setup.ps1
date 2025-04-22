if (-not $env:GITHUB_SHA) {
    $env:GITHUB_SHA = (git rev-parse HEAD)
}

if (!(Test-Path -Path "$PSScriptRoot\build")) {
    mkdir build
    Set-Location build
    python ../configure.py --enable-optimize --hl2sdk-root "$PSScriptRoot\alliedmodders" --mms_path "$PSScriptRoot\alliedmodders\metamod" --hl2sdk-manifests "$PSScriptRoot\alliedmodders\hl2sdk-manifests" -s cs2
    Set-Location ..
}

Set-Location build
ambuild
Set-Location ..