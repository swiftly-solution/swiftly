$env:MMSOURCE112 = "$PSScriptRoot\metamod"
$env:HL2SDKCS2 = "$PSScriptRoot\hl2sdk"
if (-not $env:GITHUB_SHA) {
    $env:GITHUB_SHA = (git rev-parse HEAD)
}

mkdir build
Set-Location build
python3 ../configure.py --plugin-name=swiftly --plugin-alias=swift -s cs2 --targets=x86_64 --enable-optimize --hl2sdk-manifests "$PSScriptRoot\hl2sdk-manifests"
Set-Location ..