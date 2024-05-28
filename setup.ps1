$env:MMSOURCE20 = "$PSScriptRoot\alliedmodders\metamod"
$env:HL2SDKCS2 = "$PSScriptRoot\alliedmodders\hl2sdk"
if (-not $env:GITHUB_SHA) {
    $env:GITHUB_SHA = (git rev-parse HEAD)
}

if (!(Test-Path -Path "$PSScriptRoot\build")) {
    mkdir build
    Set-Location build
    python ../configure.py --enable-optimize -s cs2
    Set-Location ..
}

Set-Location build
ambuild
Set-Location ..